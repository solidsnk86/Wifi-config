#include <iostream>
#include <curl/curl.h>

int main() {
    // Inicializar cURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL *curl = curl_easy_init();

    if (curl) {
        std::string url = "http://192.168.1.1/login";

        // Datos de inicio de sesión de la app web
        std::string post_data = "username=admin&password=admin";

        // Configurar la solicitud POST
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, post_data.length());

        // Realizar la solicitud PoST
        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "Error al realizar la solicitud: " << curl_easy_strerror(res) << std::endl;
        }

        // Limpieza
        curl_easy_cleanup(curl);
    }

    // Finalizar cURL
    curl_global_cleanup();

    return 0;
}
