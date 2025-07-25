#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(pi));

    // Ruta completa al ejecutable de Word
    // Asegúrate de que esta ruta sea válida en tu sistema
    char cmdLine[] = "\"C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE\"";

    if (CreateProcessA(
            NULL,
            cmdLine,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi)) {

        printf("✅ Microsoft Word lanzado exitosamente.\n");
        printf("🔹 PID (Process ID):  %lu\n", pi.dwProcessId);
        printf("🔹 TID (Thread ID):   %lu\n", pi.dwThreadId);
        printf("🔹 hProcess:          %p\n", pi.hProcess);
        printf("🔹 hThread:           %p\n\n", pi.hThread);

        printf("🔎 Puedes verificar el PID con:\n");
        printf("   tasklist | findstr WINWORD.EXE\n");
        printf("   powershell \"Get-Process WINWORD | Format-Table Id, ProcessName\"\n\n");

        // Esperar a que Word se cierre
        WaitForSingleObject(pi.hProcess, INFINITE);

        // Cerrar handles
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        printf("❌ Error al iniciar Word. Código: %lu\n", GetLastError());
    }

    return 0;
}
