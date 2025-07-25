    #include <pthread.h>
    #include <stdio.h>


sem_t mi_semaforo;

void *hilo(void *arg) {
    printf("Hilo esperando...\n");
    sem_wait(&mi_semaforo);
    printf("Hilo despertado!\n");
    sem_post(&mi_semaforo);
    pthread_exit(NULL);
}

int main() {
    pthread_t hilo1;
    sem_init(&mi_semaforo, 0, 0); // Inicializado en 0 (bloqueado)

    pthread_create(&hilo1, NULL, hilo, NULL);

    printf("Esperando 2 segundos...\n");
    sleep(2);

    printf("Liberando el semáforo...\n");
    sem_post(&mi_semaforo); // Desbloquea el hilo

    pthread_join(hilo1, NULL);
    sem_destroy(&mi_semaforo);
    return 0;
}