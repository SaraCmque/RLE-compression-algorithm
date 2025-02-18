#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <string>

// Declaración de la función para leer un archivo
std::string leerArchivo(int fd);

// Declaración de la función para escribir en un archivo
void escribirArchivo(const std::string& nombreSalida, const std::string& datos);

#endif // FILE_OPERATIONS_H