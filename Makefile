# Compilador y banderas
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Directorio de los archivos fuente
SRC_DIR = src

# Nombre del ejecutable
TARGET = rle

# Archivos fuente
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Archivos objeto
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, %.o, $(SRC_FILES))

# Regla principal
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los archivos objeto
%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Limpiar archivos generados
clean:
	rm -f $(OBJ_FILES) $(TARGET)

.PHONY: all clean