#include <iostream>
#include <string>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//Función para abrir y leer el archivo de texto plano

std::string leerArchivo(int fd) {
    std::string contenido;
    //int fd = open(nombreArchivo, O_RDONLY);
    if (fd == -1) {
        perror("Error abriendo el archivo");
        return "";
    }
    
    char buffer[128];
    ssize_t bytes_leidos;
    // Se lee el archivo en bloques hasta llegar al final
    while ((bytes_leidos = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_leidos] = '\0'; // Asegurar la terminación de la cadena
        contenido += buffer;
    }
    
    close(fd);
    return contenido;
}



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


int main(int argc, char* argv[])
{
    // if file does not have in directory
    // then file foo.txt is created.
    int fd = open("text.txt", O_RDONLY);

    printf("fd = %d\n", fd);

    if (fd == -1) {
        // print which type of error have in a code
        printf("Error Number % d\n", errno);

        // print program detail "Success or failure"
        perror("Program");
    }
    else {
        printf("File opened successfully\n");
    }

    std::string contenido = leerArchivo(fd);
    std::string comprimido = comprimirRLE(contenido);
    printf("Contenido del archivo:\n%s\n", contenido.c_str());
    printf("Contenido comprimido:\n%s\n", comprimido.c_str());
}