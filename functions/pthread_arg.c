#include <stdio.h>
#include <pthread.h>

#define _DEBUG 1

typedef struct arg {
    int *array;
    int len;
}   t_arg;

void *sort2(void *ptr);


int main(void) {
    pthread_t firstThread;

    int first[5] = {3,5,19,6,1};
    int first_size = 5;
    t_arg arg = {.array = first, .len = first_size}; // assign your variable to the variable arg which is a t_arg struct
    pthread_create( &firstThread, NULL, &sort2, &arg); // give the struct address to pthread_create
    pthread_join(firstThread, NULL);
}

struct sorting
  {
      int* ptr;
      int size;
  };

void *sort2(void *arg)
  {
       struct sorting *s = (struct sorting)arg;
       int* point;
       int length;
       point = s->ptr;
       length = s->size;

      int i,j,t;
    for (i = 0; i < length; i++)
    {
    for (j = i + 1; j <length; j++)
    {
        if(*(point +j) < *(point+i))
        {
            t = *(point + i);
            *(point + i) = *(point +j);
            *(point +j) = t;
        }
    }
  }
  for (i = 0; i < length; i++)
        printf("%d ", *(point + i));
  }

void *sort(void *ptr) {
    t_arg *arg = ptr; // get
    int n = arg->len; // now you can work with your function
    int *a = arg->array;

    int i, tmp, j;
    for (i = 1; i < n; i++) {
        tmp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > tmp) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = tmp;
    }
    #ifdef _DEBUG
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        putchar('\n');
    #endif
    return (void *)1; // to compile with -Wall -Wextra -Werror
}