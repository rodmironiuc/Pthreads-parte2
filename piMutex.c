#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long thread_count = 100;

double sum = 0.0;
long n = 1000000;
pthread_mutex_t mutex;

void* Thread_sum(void* rank){
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n/thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;
    double temp_sum = 0.0;

    if (my_first_i % 2 == 0)
        factor = 1.0;
    else
        factor = -1.0;

    for (i = my_first_i; i < my_last_i; i++, factor = -factor){
        temp_sum += factor/(2*i+1);
    }

    pthread_mutex_lock(&mutex);
    sum += temp_sum;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    long thread;
    pthread_t* thread_handles;

    thread_handles = malloc(thread_count * sizeof(pthread_t));
    pthread_mutex_init(&mutex, NULL);

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*)thread);
    }

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    printf("PI aproximado:: %f\nQuantidade de threads: %ld\n", 4*sum,thread_count);

    pthread_mutex_destroy(&mutex);
    free(thread_handles);

    return 0;
}
