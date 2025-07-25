#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // Inicializar estructuras a cero
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Comando para abrir la calculadora
    char cmd[] = "C:\\Windows\\System32\\calc.exe";

    // Crear el proceso
    BOOL success = CreateProcessA(
        NULL,        // Nombre del módulo (NULL si se usa cmd completo en cmdLine)
        cmd,         // Línea de comandos
        NULL,        // Atributos de seguridad del proceso
        NULL,        // Atributos de seguridad del hilo
        FALSE,       // Heredar handles
        0,           // Flags de creación
        NULL,        // Bloque de entorno (NULL = hereda del padre)
        NULL,        // Directorio actual (NULL = hereda del padre)
        &si,         // Información de inicio
        &pi          // Información del proceso (salida)
    );

    if (!success) {
        printf("Error al crear el proceso. Código: %lu\n", GetLastError());
        return 1;
    }

    // Esperar a que el proceso termine (opcional)
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Cerrar handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
     printf("Has creado el proceso n: %lu - %p - %p - %lu - \n", si.dwProcessId, pi.hProcess,pi.hThread, pi.dwThreadId  );
    return 0;
}
