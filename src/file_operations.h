#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <iostream>    // Para entrada/salida estándar (std::cout, std::cerr)
#include <vector>      // Para manejar estructuras de datos dinámicas
#include <string>      // Para manejar cadenas de texto
#include <fcntl.h>     // Para usar `open()`, `O_RDONLY`, `O_WRONLY`, `O_CREAT`
#include <unistd.h>    // Para usar `read()`, `write()`, `close()`
#include <bitset>      // Para representar cada byte en su forma binaria (8 bits)
#include <cstdint>     // Para usar tipos de datos de tamaño fijo como uint8_t

class file_op {
    private:
        std::vector<uint8_t> datos;  // Vector para almacenar el contenido del archivo en bytes
        std::vector<std::string> bits; // Vector para almacenar la representación en bits de cada byte
    
    public:
        bool leerArchivo(const std::string& nombreArchivo);  // Lee el archivo y almacena los bytes
        void convertirABits();   // Convierte los bytes almacenados en bits
        void escribirArchivo(const std::string& nombreSalida);  // Escribe los datos en otro archivo
        void mostrarBits() const;  // Muestra en pantalla los bits de cada byte
        std::vector<std::vector<int>> matrizBits();  // Devuelve la matriz de bits (8 bits por fila)
    };

#endif // FILE_OPERATIONS_H