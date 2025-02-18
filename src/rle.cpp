#include "rle.h"
#include <fcntl.h>      // Para open()
#include <unistd.h>     // Para read(), write() y close()
#include <iostream>     // Para std::cerr


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


std::string descomprimirRLE(const std::string& textoComprimido) {
    std::string descomprimido;
    int longitud = textoComprimido.length();

    for (int i = 0; i < longitud; i++) {
        char caracter = textoComprimido[i];
        std::string numeroStr;

        // Extraer el número que representa la cantidad de repeticiones
        while (i + 1 < longitud && isdigit(textoComprimido[i + 1])) {
            numeroStr += textoComprimido[i + 1];
            i++;
        }

        // Convertir el número de repeticiones a entero
        int repeticiones = std::stoi(numeroStr);

        // Agregar el carácter repetido a la cadena descomprimida
        descomprimido.append(repeticiones, caracter);
    }

    return descomprimido;
}