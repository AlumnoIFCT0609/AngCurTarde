// semaforo.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

#define SEM1 "/s1"
#define SEM2 "/s2"
#define SEM3 "/s3"
#define SEM4 "/s4"

// Función para borrar semáforos si existen
void limpiar_semaforos() {
    sem_unlink(SEM1);
    sem_unlink(SEM2);
    sem_unlink(SEM3);
    sem_unlink(SEM4);
}

int main() {
    limpiar_semaforos(); // Asegura una ejecución limpia

    // Crear semáforos con valor inicial 0
    sem_t *s1 = sem_open(SEM1, O_CREAT | O_EXCL, 0644, 0);
    sem_t *s2 = sem_open(SEM2, O_CREAT | O_EXCL, 0644, 0);
    sem_t *s3 = sem_open(SEM3, O_CREAT | O_EXCL, 0644, 0);
    sem_t *s4 = sem_open(SEM4, O_CREAT | O_EXCL, 0644, 0);

    if (s1 == SEM_FAILED || s2 == SEM_FAILED || s3 == SEM_FAILED || s4 == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    pid_t p1 = fork();
    if (p1 == 0) {
        // Proceso 1
        printf("1\n");
        sem_post(s3);     // signal(&s3)
        printf("2\n");
        sem_post(s2);     // signal(&s2)
        sem_post(s1);     // signal(&s1)
        exit(0);
    }

    pid_t p2 = fork();
    if (p2 == 0) {
        // Proceso 2
        sem_wait(s1);     // wait(&s1)
        printf("4\n");
        sem_wait(s3);     // wait(&s3)
        sem_post(s4);     // signal(&s4)
        sem_wait(s3);     // wait(&s3) → ¡potencial interbloqueo aquí!
        exit(0);
    }

    pid_t p3 = fork();
    if (p3 == 0) {
        // Proceso 3
        sem_wait(s2);     // wait(&s2)
        sem_wait(s4);     // wait(&s4)
        printf("3\n");
        printf("8\n");
        sem_post(s3);     // signal(&s3)
        exit(0);
    }

    // Esperar a que los 3 procesos terminen
    wait(NULL);
    wait(NULL);
    wait(NULL);

    // Cerrar y eliminar semáforos
    sem_close(s1); sem_unlink(SEM1);
    sem_close(s2); sem_unlink(SEM2);
    sem_close(s3); sem_unlink(SEM3);
    sem_close(s4); sem_unlink(SEM4);

    return 0;
}
