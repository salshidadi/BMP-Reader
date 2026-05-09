# BMP Header Parser

A C-based tool for reading and parsing the metadata of a `.bmp` file. This project focuses on understanding binary file structures, memory alignment, and low-level data handling.

## Features

* **Binary Parsing**: Directly reads `.bmp` file headers into memory.
* **Memory Alignment**: Implements compiler directives to match real-world binary layouts.
* **Hexadecimal & Decimal Output**: Displays file metadata in human-readable formats.
* **Resource Efficiency**: Uses minimal memory and standard C libraries.

## Technical Implementation

The project addresses the "Structure Padding" behavior of C compilers. Because the BMP header contains a 2-byte signature followed by a 4-byte integer, a standard struct would insert a 2-byte gap to align the memory. This tool overrides that behavior to ensure byte-perfect mapping.

### Key Components

* **`#pragma pack(push, 1)`**: Disables data alignment gaps to ensure the struct size is exactly 6 bytes (2 for signature + 4 for size).
* **`fread`**: Reads the packed struct from the file stream in a single operation.
* **Formatting**: Uses `%.2s` to handle non-null-terminated character arrays for the signature.

## Header Mapping

The tool extracts data based on the following offsets:

| Offset | Length | Property | Description |
| --- | --- | --- | --- |
| 0 | 2 bytes | Signature | Magic Number (should be 'BM') |
| 2 | 4 bytes | File Size | Total size of the file in bytes |
| 18 | 4 bytes | Width | Image width in pixels |
| 22 | 4 bytes | Height | Image height in pixels |

## How to Run

### 1. Requirements

* A C compiler (e.g., GCC or Clang).
* A Linux-based environment (like Linux Mint) or a Windows environment supporting C.

### 2. Execution

Compile the source code:

```bash
gcc bmp_reader.c -o bmp_parser

```

### 3. Usage

Place a file named `photo.bmp` in the same directory as the executable and run:

```bash
./bmp_parser

```

## Resources

The implementation is based on the BMP format specification provided by the [BMP Reader](https://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm).
