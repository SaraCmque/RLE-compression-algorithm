#include <iostream>
#include <string>

// Función para comprimir usando Run-Length Encoding (RLE)
std::string comprimirRLE(const std::string& texto) {
    std::string comprimido;
    int longitud = texto.length();

    for (int i = 0; i < longitud; i++) {
        int contador = 1;
        while (i < longitud - 1 && texto[i] == texto[i + 1]) {
            contador++;
            i++;
        }
        comprimido += texto[i] + std::to_string(contador);
    }

    return comprimido;
}

int main() {
    std::string texto = "AAABBBCCCC";
    std::string comprimido = comprimirRLE(texto);

    std::cout << "Texto original: " << texto << "\n";
    std::cout << "Texto comprimido: " << comprimido << "\n";

    return 0;
}