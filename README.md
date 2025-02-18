# File Compressor and Decompressor with RLE

## Description
This program implements the **Run-Length Encoding (RLE)** algorithm to compress and decompress files. It also includes options for future encryption and decryption functionalities.

## What is RLE?
Run-Length Encoding (RLE) is a lossless compression algorithm that replaces consecutive repeated characters with a single character followed by the number of repetitions.

Example:
- Input: `AAAABBBCCDAA`
- Output: `A4B3C2D1A2`

This method is useful for compressing data with many consecutive repetitions.

## Installation
To compile the program, use the **g++** compiler:

```bash
 g++ main.cpp file.cpp rle.cpp -o rle
```

## Usage
The program is executed from the terminal using the following syntax:

```bash
 ./rle [OPTION] [FILE]
```

### Available Options:
- `-h, --help` → Displays help information.
- `-v, --version` → Displays the program version.
- `-c, --compress [file]` → Compresses the specified file.
- `-x, --decompress [file]` → Decompresses the specified file.

### Usage Examples
To compress a file:
```bash
 ./rle -c file.txt
```
This will generate a compressed file named `file.txt.rle`.

To decompress a file:
```bash
 ./rle -x file.txt.rle
```
This will generate a file `file.txt` with the original content.

## Project Files
- `main.cpp` → Contains the main logic and argument handling.
- `file_operations.h` / `file.cpp` → Functions for reading and writing files.
- `rle.h` / `rle.cpp` → Implementation of the RLE algorithm.

## RLE Implementation
### `rle.h`
Defines the functions for compressing and decompressing text using RLE:
```cpp
#ifndef RLE_H
#define RLE_H

#include <string>

std::string compressRLE(const std::string& text);
std::string decompressRLE(const std::string& compressedText);

#endif // RLE_H
```

### `rle.cpp`
Implements the RLE algorithm:
```cpp
#include "rle.h"
#include <iostream>

std::string compressRLE(const std::string& text) {
    std::string compressed;
    int length = text.length();

    for (int i = 0; i < length; i++) {
        int count = 1;
        while (i < length - 1 && text[i] == text[i + 1]) {
            count++;
            i++;
        }
        compressed += text[i] + std::to_string(count);
    }

    return compressed;
}

std::string decompressRLE(const std::string& compressedText) {
    std::string decompressed;
    int length = compressedText.length();

    for (int i = 0; i < length; i++) {
        char character = compressedText[i];
        std::string numberStr;

        while (i + 1 < length && isdigit(compressedText[i + 1])) {
            numberStr += compressedText[i + 1];
            i++;
        }

        int repetitions = std::stoi(numberStr);
        decompressed.append(repetitions, character);
    }

    return decompressed;
}
```
 Receiving file type : .txt

 

## Notes
- Currently, encryption and decryption are not implemented.
- The program requires read and write permissions for the files used.

## Authors

Made by **Sara Cortés**, **Camilo Córdoba**, and **Paulina Cerón** for the Operating Systems course.
