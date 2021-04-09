// You can have asynchronous programming in C using [pthread](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)
// NB:  gcc -O3 pthread.c -lpthread && time ./a.out  => 0.647s
// gcc pthread.c -lpthread && time ./a.out  => 1.140s

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define bool    unsigned char
#define true    1
#define false   0

typedef struct my_ptr {
    long n;
    long i;
}   t_my_ptr;

void *sum_primes(void *ptr) {
    t_my_ptr *my_ptr = ptr;
    if (my_ptr->n < 0 ) // handle misused of function
        return (void *)-1;
    bool isPrime[my_ptr->i + 1];
    memset(isPrime, true, my_ptr->i + 1);

    if (my_ptr->n >= 2) { // only one even number can be prime: 2
        my_ptr->n += 2;
    }
    for (long i = 3; i <= my_ptr->i ; i+=2) { // after what only odd numbers can be prime numbers
        if (isPrime[i]) {
            my_ptr->n += i;
        }
        for (long j = i * i; j <= my_ptr->i; j+=i*2) // Eratosthenes' Algo, sieve all multiples of current prime, skipping even numbers.
            isPrime[j] = false;
    }
    //printf("%s: %ld\n", __func__, my_ptr->n); // a) if both 'a' and 'b' activated you will notice that both functions are computed asynchronously.
}

void *sum_square(void *ptr) {
    t_my_ptr *my_ptr = ptr;
        if (my_ptr->n < 0 ) // handle misused of function
            return (void *)-1;
        bool isPrime[my_ptr->i + 1];
        memset(isPrime, true, my_ptr->i + 1);

        if (my_ptr->n >= 2) { // only one even number can be prime: 2
            my_ptr->n += 2;
        }
        for (long i = 3; i <= my_ptr->i ; i+=2) { // after what only odd numbers can be prime numbers
            if (isPrime[i]) {
                my_ptr->n += i;
            }
            for (long j = i * i; j <= my_ptr->i; j+=i*2) // Eratosthenes' Algo, sieve all multiples of current prime, skipping even numbers.
                isPrime[j] = false;
        }
    //printf("%s: %ld\n", __func__, my_ptr->n); // b) if both 'a' and 'b' activated you will notice that both functions are computed asynchronously.
}

void *sum_add_modulo_three(void *ptr) {
    t_my_ptr *my_ptr = ptr;
        if (my_ptr->n < 0 ) // handle misused of function
            return (void *)-1;
        bool isPrime[my_ptr->i + 1];
        memset(isPrime, true, my_ptr->i + 1);

        if (my_ptr->n >= 2) { // only one even number can be prime: 2
            my_ptr->n += 2;
        }
        for (long i = 3; i <= my_ptr->i ; i+=2) { // after what only odd numbers can be prime numbers
            if (isPrime[i]) {
                my_ptr->n += i;
            }
            for (long j = i * i; j <= my_ptr->i; j+=i*2) // Eratosthenes' Algo, sieve all multiples of current prime, skipping even numbers.
                isPrime[j] = false;
        }
}

void *sum_add_modulo_thirteen(void *ptr) {
    t_my_ptr *my_ptr = ptr;
        if (my_ptr->n < 0 ) // handle misused of function
            return (void *)-1;
        bool isPrime[my_ptr->i + 1];
        memset(isPrime, true, my_ptr->i + 1);

        if (my_ptr->n >= 2) { // only one even number can be prime: 2
            my_ptr->n += 2;
        }
        for (long i = 3; i <= my_ptr->i ; i+=2) { // after what only odd numbers can be prime numbers
            if (isPrime[i]) {
                my_ptr->n += i;
            }
            for (long j = i * i; j <= my_ptr->i; j+=i*2) // Eratosthenes' Algo, sieve all multiples of current prime, skipping even numbers.
                isPrime[j] = false;
        }
}

void *sum_add_twice(void *ptr) {
    t_my_ptr *my_ptr = ptr;
        if (my_ptr->n < 0 ) // handle misused of function
            return (void *)-1;
        bool isPrime[my_ptr->i + 1];
        memset(isPrime, true, my_ptr->i + 1);

        if (my_ptr->n >= 2) { // only one even number can be prime: 2
            my_ptr->n += 2;
        }
        for (long i = 3; i <= my_ptr->i ; i+=2) { // after what only odd numbers can be prime numbers
            if (isPrime[i]) {
                my_ptr->n += i;
            }
            for (long j = i * i; j <= my_ptr->i; j+=i*2) // Eratosthenes' Algo, sieve all multiples of current prime, skipping even numbers.
                isPrime[j] = false;
        }
}

void *sum_times_five(void *ptr) {
    t_my_ptr *my_ptr = ptr;
        if (my_ptr->n < 0 ) // handle misused of function
            return (void *)-1;
        bool isPrime[my_ptr->i + 1];
        memset(isPrime, true, my_ptr->i + 1);

        if (my_ptr->n >= 2) { // only one even number can be prime: 2
            my_ptr->n += 2;
        }
        for (long i = 3; i <= my_ptr->i ; i+=2) { // after what only odd numbers can be prime numbers
            if (isPrime[i]) {
                my_ptr->n += i;
            }
            for (long j = i * i; j <= my_ptr->i; j+=i*2) // Eratosthenes' Algo, sieve all multiples of current prime, skipping even numbers.
                isPrime[j] = false;
        }
}

void *sum_times_thirteen(void *ptr) {
    t_my_ptr *my_ptr = ptr;
        if (my_ptr->n < 0 ) // handle misused of function
            return (void *)-1;
        bool isPrime[my_ptr->i + 1];
        memset(isPrime, true, my_ptr->i + 1);

        if (my_ptr->n >= 2) { // only one even number can be prime: 2
            my_ptr->n += 2;
        }
        for (long i = 3; i <= my_ptr->i ; i+=2) { // after what only odd numbers can be prime numbers
            if (isPrime[i]) {
                my_ptr->n += i;
            }
            for (long j = i * i; j <= my_ptr->i; j+=i*2) // Eratosthenes' Algo, sieve all multiples of current prime, skipping even numbers.
                isPrime[j] = false;
        }
}

void *sum_times_seventeen(void *ptr) {
    t_my_ptr *my_ptr = ptr;
        if (my_ptr->n < 0 ) // handle misused of function
            return (void *)-1;
        bool isPrime[my_ptr->i + 1];
        memset(isPrime, true, my_ptr->i + 1);

        if (my_ptr->n >= 2) { // only one even number can be prime: 2
            my_ptr->n += 2;
        }
        for (long i = 3; i <= my_ptr->i ; i+=2) { // after what only odd numbers can be prime numbers
            if (isPrime[i]) {
                my_ptr->n += i;
            }
            for (long j = i * i; j <= my_ptr->i; j+=i*2) // Eratosthenes' Algo, sieve all multiples of current prime, skipping even numbers.
                isPrime[j] = false;
        }
}

#define THREADS_NB 8

int main(void)
{
    pthread_t thread[THREADS_NB];
    void *(*fptr[THREADS_NB]) (void *ptr) =  {sum_primes, sum_square,sum_add_modulo_three, \
    sum_add_modulo_thirteen, sum_add_twice, sum_times_five, sum_times_thirteen, sum_times_seventeen};
    t_my_ptr arg[THREADS_NB];
    memset(arg, 0, sizeof(arg));
   // long  iret[THREADS_NB];
  //  pthread_mutex_t lock[THREADS_NB];

/*
    for (int j = 0; j < THREADS_NB; j++) {
        if (pthread_mutex_init(&lock[j], NULL) != 0) {
                printf("\n mutex init has failed\n");
                return 1;
            }
    }
*/
    for (volatile long i = 0; i < 100000; i++) {
        //print_sum_primes(&prime_arg);
        //print_sum_square(&square_arg);
        for (int j = 0; j < THREADS_NB; j++) {
            //pthread_mutex_lock(&lock[j]);
            arg[j].i = i;
            //pthread_mutex_unlock(&lock[j]);
            //fptr[j](&arg[j]);
            pthread_create( &thread[j], NULL, (void *)fptr[j], &arg[j]); // https://man7.org/linux/man-pages/man3/pthread_create.3.html
        }

        // Wait till threads are complete before main continues. Unless we
        // wait we run the risk of executing an exit which will terminate
        // the process and all threads before the threads have completed.

        for (int j = 0; j < THREADS_NB; j++)
            pthread_join(thread[j], NULL);
        //pthread_join( thread1, NULL);
        //pthread_join( thread2, NULL);

        //printf("Thread 1 returns: %ld\n",iret1); // if we care about the return value
        //printf("Thread 2 returns: %ld\n",iret2);
    }
    for (int j = 0; j < THREADS_NB; j++)
        printf("Function %d: %ld\n", j, arg[j].n);

  //  for (int j = 0; j < THREADS_NB; j++)
    //    pthread_mutex_destroy(&lock[j]);
    return 0;
}