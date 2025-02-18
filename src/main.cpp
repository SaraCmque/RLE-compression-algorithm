#include "file_operations.h" // Incluir el archivo de cabecera para operaciones de archivos
#include "rle.h"             // Incluir el archivo de cabecera para RLE
#include <iostream>
#include <fcntl.h> // Para open()
#include <unistd.h> // Para close()
#include <cstring>  // Para strcmp()

// Versión del programa
const std::string VERSION = "1.0";

// Función para mostrar la ayuda
void mostrarAyuda() {
    std::cout << "Uso: rle [OPCIÓN]... [ARCHIVO]...\n"
              << "Comprime, descomprime, encripta o desencripta archivos usando RLE.\n\n"
              << "Opciones:\n"
              << "  -h, --help          Muestra esta ayuda y termina.\n"
              << "  -v, --version       Muestra la versión del programa y termina.\n"
              << "  -c, --compress      Comprime el archivo indicado.\n"
              << "  -x, --decompress    Descomprime el archivo indicado.\n"
              << "  -e, --encrypt       Encripta el archivo indicado.\n"
              << "  -d, --decrypt       Desencripta el archivo indicado.\n";
}

// Función principal
int main(int argc, char* argv[]) {
    // Verificar si no se proporcionaron argumentos
    if (argc == 1) {
        std::cerr << "Error: No se proporcionaron argumentos.\n";
        mostrarAyuda();
        return 1;
    }

    // Procesar los argumentos de línea de comandos
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        // Mostrar ayuda
        if (arg == "-h" || arg == "--help") {
            mostrarAyuda();
            return 0;
        }

        // Mostrar versión
        if (arg == "-v" || arg == "--version") {
            std::cout << "rle (Run-Length Encoding) versión " << VERSION << "\n";
            return 0;
        }

        // Comprimir un archivo
        if (arg == "-c" || arg == "--compress") {
            if (i + 1 < argc) {
                std::string archivoEntrada = argv[i + 1];
                std::string archivoSalida = archivoEntrada + ".rle";

                // Abrir el archivo de entrada
                int fd = open(archivoEntrada.c_str(), O_RDONLY);
                if (fd == -1) {
                    perror("Error abriendo el archivo");
                    return 1;
                }

                // Leer y comprimir el archivo
                std::string contenido = leerArchivo(fd);
                std::string comprimido = comprimirRLE(contenido);

                // Escribir el archivo comprimido
                escribirArchivo(archivoSalida, comprimido);

                std::cout << "Archivo comprimido guardado como: " << archivoSalida << "\n";
                return 0;
            } else {
                std::cerr << "Error: Falta el nombre del archivo para comprimir.\n";
                return 1;
            }
        }

        // Descomprimir un archivo
        if (arg == "-x" || arg == "--decompress") {
            if (i + 1 < argc) {
                std::string archivoEntrada = argv[i + 1];
                std::string archivoSalida = archivoEntrada + ".txt";

                // Abrir el archivo comprimido
                int fd = open(archivoEntrada.c_str(), O_RDONLY);
                if (fd == -1) {
                    perror("Error abriendo el archivo");
                    return 1;
                }

                // Leer y descomprimir el archivo
                std::string contenido = leerArchivo(fd);
                std::string descomprimido = descomprimirRLE(contenido);

                // Escribir el archivo descomprimido
                escribirArchivo(archivoSalida, descomprimido);

                std::cout << "Archivo descomprimido guardado como: " << archivoSalida << "\n";
                return 0;
            } else {
                std::cerr << "Error: Falta el nombre del archivo para descomprimir.\n";
                return 1;
            }
        }

        // Encriptar un archivo (implementación pendiente)
        if (arg == "-e" || arg == "--encrypt") {
            std::cerr << "Error: Encriptación no implementada aún.\n";
            return 1;
        }

        // Desencriptar un archivo (implementación pendiente)
        if (arg == "-d" || arg == "--decrypt") {
            std::cerr << "Error: Desencriptación no implementada aún.\n";
            return 1;
        }
    }

    // Si no se reconoce la opción
    std::cerr << "Error: Opción no reconocida.\n";
    mostrarAyuda();
    return 1;
}