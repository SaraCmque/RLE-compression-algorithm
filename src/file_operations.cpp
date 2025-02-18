#include "file_operations.h"
#include <fcntl.h>      // Para open()
#include <unistd.h>     // Para read(), write() y close()
#include <iostream>     // Para std::cerr

// Implementación de la función para leer un archivo
std::string leerArchivo(int fd) {
    std::string contenido;
    if (fd == -1) {
        perror("Error abriendo el archivo");
        return "";
    }

    char buffer[128];
    ssize_t bytes_leidos;
    while ((bytes_leidos = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_leidos] = '\0'; // Asegurar la terminación de la cadena
        contenido += buffer;
    }

    close(fd);
    return contenido;
}

// Implementación de la función para escribir en un archivo
void escribirArchivo(const std::string& nombreSalida, const std::string& datos) {
    int fd = open(nombreSalida.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        std::cerr << "Error: No se pudo abrir el archivo de salida " << nombreSalida << std::endl;
        return;
    }

    ssize_t bytesEscritos = write(fd, datos.data(), datos.size());

    if (bytesEscritos == -1) {
        std::cerr << "Error: No se pudo escribir en el archivo " << nombreSalida << std::endl;
    } else {
        std::cout << "Archivo guardado exitosamente: " << nombreSalida << std::endl;
    }

    close(fd);
}