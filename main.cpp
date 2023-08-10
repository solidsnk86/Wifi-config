#include <windows.h>

// Declaración de la función de ventana
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Registrar la clase de ventana
    const wchar_t CLASS_NAME[]  = L"Sample Window Class";

    WNDCLASS wc = {0};

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Crear la ventana
    HWND hwnd = CreateWindowEx(
        0,                              // Estilo adicional
        CLASS_NAME,                     // Clase de ventana
        L"Ventana con Diálogo",         // Título de la ventana
        WS_OVERLAPPEDWINDOW,            // Estilo de la ventana
        CW_USEDEFAULT, CW_USEDEFAULT,    // Posición de la ventana
        800, 600,                       // Tamaño de la ventana
        NULL,                           // Ventana padre
        NULL,                           // Menú
        hInstance,                      // Instancia de la aplicación
        NULL                            // Datos de creación adicionales
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Bucle de mensajes
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Procedimiento de la ventana
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}
