#include <stdio.h>  // printf
#include <stdlib.h> // rand()
#include <time.h>   // time
#include <xmmintrin.h>  // 128 bits register _m128

float m128_max_float(__m128 src) {
    __m128 n[4];

    n[0] = _mm_shuffle_ps(src, src, _MM_SHUFFLE(0,0,3,2));    // a) n[0] = src >> 64                                  So lets say src is composed of floats a b c d, it becomes 0 0 a b
    n[1] = _mm_max_ps(src, n[0]);                             // b) n[1] = {max(a,0), max(b,0) max(a,c) max(b,d)}     NB: actually we don't care about the two highest float at this point, I will call them 'x': {x, x max(a,c) max(b,d)}
    n[2] = _mm_shuffle_ps(n[1], n[1], _MM_SHUFFLE(0,0,0,1));  // c) n[2] = n[1] >> 32                                 So n2 become {0 x x max(a,c)}
    n[3] = _mm_max_ps(n[1], n[2]);                            // d) n[3] = {x x x max(max(a,c), max(b,d))}

    return _mm_cvtss_f32(n[3]);   // d) Hence max(a,b,c,d), stored in the lowest 32 bits of n[3], is loaded into a float that we return. We don't care about the other bits
}

float m128_min_float(__m128 src) {
    __m128 n[4];

    n[0] = _mm_shuffle_ps(src, src, _MM_SHUFFLE(0,0,3,2));
    n[1] = _mm_min_ps(src, n[0]);
    n[2] = _mm_shuffle_ps(n[1], n[1], _MM_SHUFFLE(0,0,0,1));
    n[3] = _mm_min_ps(n[1], n[2]);

    return _mm_cvtss_f32(n[3]);
}

#define SIZE  1000000000L // 1 billion. Yes.

void  get_min_max(long i, float array[i]) {
  __m128 max;
  __m128 min;
  
  max = _mm_loadu_ps(array); // will load first 4 float into max
  min = _mm_loadu_ps(array); // will load first 4 float into min
  while ((i -= 4L))
  {
    __m128 tmp = _mm_loadu_ps(array + i);
    max = _mm_max_ps(max, tmp);
    min = _mm_min_ps(min, tmp);
  }

  printf("Max value: %f\t Min value: %f\n", m128_max_float(max), m128_min_float(min));
}

void  get_min_max_like_bocalian(long size, float array[size]) {
  float max;
  float min;
  int i;

  max = array[0];
  min = array[0];
  i = 1L;
  while (i < size)
  {
    float tmp = array[i++];
    max = tmp < max ? max : tmp;
    min = tmp > min ? min : tmp;
  }

  printf("Max value: %f\t Min value: %f\n", max, min);
}

int main()
{
  long i;
  float *data;
  clock_t time;

  srand(time(NULL));  // seed
  data = (float *)malloc(SIZE * sizeof(float));
  i = -1L;
  while (++i < SIZE) {
    data[i] = (float)rand() / (float)(RAND_MAX) * 1000.0f;
   /* printf("%.02f\t\t", data[i]);     // I commented these lines because it slows considerably the program.
    if (!(i & 15))
      printf("\n");*/
  }

  time = clock();
  get_min_max(SIZE, data);
  time = clock() - time;
  double elapsed_time = ((double)time) / CLOCKS_PER_SEC;
  printf("Executed in %f seconds\n", elapsed_time);

  time = clock();
  get_min_max_like_bocalian(SIZE, data);
  time = clock() - time;
  elapsed_time = ((double)time) / CLOCKS_PER_SEC;
  printf("Executed in %f seconds\n", elapsed_time); 

  return 0;
}