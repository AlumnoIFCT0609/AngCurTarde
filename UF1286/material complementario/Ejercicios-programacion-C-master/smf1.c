#include <windows.h>
#include <stdio.h>

HANDLE semaforo; // Semáforo binario

DWORD WINAPI proceso(LPVOID lpParam) {
    char* nombre = (char*)lpParam;
    int i=0;
    while (i< 6) {
        // Esperar acceso al semáforo
        
        i++;
        WaitForSingleObject(semaforo, INFINITE);

        // Sección crítica
        printf("vuelta %i Proceso %s en seccion critica. Tiene medio segundo para terminar su trabajo\n ", i, nombre);

        // Liberar el semáforo
        ReleaseSemaphore(semaforo, 1, NULL);

        // Sección no crítica (opcional)
        Sleep(500); // Espera de 1 segundo para simular trabajo

    }

    return 0;
}

int main() {
    HANDLE hP, hQ;
    DWORD idP, idQ;

    // Crear semáforo binario con valor inicial 1 (exclusión mutua)
    semaforo = CreateSemaphore(NULL, 1, 1, NULL);
    if (semaforo == NULL) {
        printf("Error al crear el semáforo\n");
        return 1;
    }

    // Crear hilos para los "procesos" p y q
    hP = CreateThread(NULL, 0, proceso, "P", 0, &idP);
    hQ = CreateThread(NULL, 0, proceso, "Q", 0, &idQ);

    // Esperar a que los hilos finalicen (nunca lo harán en este ejemplo)
    WaitForSingleObject(hP, INFINITE);
    WaitForSingleObject(hQ, INFINITE);

    // Liberar recursos
    CloseHandle(hP);
    CloseHandle(hQ);
    CloseHandle(semaforo);

    return 0;
}
