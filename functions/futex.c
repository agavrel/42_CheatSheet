#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <pthread.h>

struct {
    pthread_cond_t cond;
    pthread_mutex_t mutex;
} *shm;

void a() {
    // create shm and broadcast every second
    int shm_fd = shm_open("/my_shm", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(*shm));
    shm = mmap(0, sizeof(*shm), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    close(shm_fd);

    pthread_mutexattr_t mutexattr;
    pthread_mutexattr_init(&mutexattr);
    pthread_mutexattr_setpshared(&mutexattr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&shm->mutex, &mutexattr);
    pthread_mutex_consistent(&shm->mutex);

    pthread_condattr_t condattr;
    pthread_condattr_init(&condattr);
    pthread_condattr_setpshared(&condattr, PTHREAD_PROCESS_SHARED);
    pthread_cond_init(&shm->cond, &condattr);

    for (int i = 0; 1; ++i) {
        pthread_mutex_lock(&shm->mutex);
        pthread_cond_broadcast(&shm->cond);
        pthread_mutex_unlock(&shm->mutex);
        sleep(1);
        printf("broadcast %d\n", i);
    }
}

void b() {
    // open shm and listen for events
    int shm_fd = shm_open("/my_shm", O_RDWR, 0666);
    shm = mmap(0, sizeof(*shm), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    close(shm_fd);
    for (int i = 0; 1; ++i) {
        pthread_mutex_lock(&shm->mutex);
        pthread_cond_wait(&shm->cond, &shm->mutex);
        pthread_mutex_unlock(&shm->mutex);
        printf("receive %d\n", i);
    }
}

int main(int argc, char** argv) {
    if (argc != 2)
        return -1;
    switch (argv[1][0]) {
    case 'a':
        a();
        break;
    case 'b':
        b();
        break;
    default:
        return -1;
    }
    return 0;
}