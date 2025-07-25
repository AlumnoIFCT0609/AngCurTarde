#include <stdio.h>
#include <windows.h>

#define numThreads 10

DWORD WINAPI threadFunc(LPVOID lpParam) {
    int id = *(int*)lpParam;
    printf("La  hebra ->  %d -> en \n", id);
    return 0;
}

int main() {
    int tNum[numThreads];
    HANDLE hThread[numThreads];

    for (int i = 0; i < numThreads; i++) {
        tNum[i] = i;
        hThread[i] = CreateThread(
            NULL,
            0,
            threadFunc,
            &tNum[i],
            0,
            NULL
        );
    }

    // Esperar a que todos terminen
   WaitForMultipleObjects(numThreads, hThread, TRUE, INFINITE);
    
    // Cerrar los handles
    for (int i = 0; i < numThreads; i++) {
        CloseHandle(hThread[i]);
    }

    return 0;
}
