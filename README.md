
# Custom `_printf` Implementation

## Overview

This project implements a simplified version of the standard C library function `printf`. The custom `_printf` function formats and outputs data to the standard output (stdout) based on a specified format string. It supports various format specifiers, including characters, strings, integers, unsigned integers, hexadecimal values, and pointers.

## Features

- **Character Printing**: Supports printing single characters.
- **String Printing**: Handles null-terminated strings, including `(null)` for null pointers.
- **Integer Printing**: Converts integers to base 10 and prints them.
- **Unsigned Integer Printing**: Supports printing unsigned integers in decimal, octal, and hexadecimal formats.
- **Pointer Address Printing**: Prints memory addresses in hexadecimal format, prefixed with `0x`.
- **Unknown Specifiers Handling**: If an unknown format specifier is encountered, it prints the specifier as is.

## Function Descriptions

### `_printf`

```c
int _printf(const char *format, ...);
```

- **Parameters**:
  - `format`: A string that specifies the format of the output.
  - `...`: A variable number of arguments that correspond to format specifiers in the format string.

- **Returns**: The total number of characters printed (excluding the null byte) or `-1` if an error occurs.

### `print_char`

```c
int print_char(char c);
```

- **Parameters**:
  - `c`: The character to be printed.

- **Returns**: Always returns `1`, indicating that one character has been printed.

### `print_string`

```c
int print_string(char *s);
```

- **Parameters**:
  - `s`: A pointer to the string to be printed.

- **Returns**: The number of characters printed. If the string is `NULL`, it prints `(null)`.

### `print_number`

```c
int print_number(int n);
```

- **Parameters**:
  - `n`: The integer to be converted and printed.

- **Returns**: The number of characters printed.

### `handle_format`

```c
int handle_format(const char **format, va_list args);
```

- **Parameters**:
  - `format`: A pointer to the current position in the format string.
  - `args`: A list of variable arguments corresponding to format specifiers.

- **Returns**: The number of characters printed for the current format specifier.

## Usage

To use this custom `_printf` function:

1. Include the header file where the function prototypes are declared (`main.h`).
2. Call `_printf` with a format string and corresponding arguments.

### Compilation

You need to use this compile command to create a executable files :
```c
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
```

### Example

```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "World");
    _printf("Character: %c\n", 'A');
    _printf("Number: %d\n", 42);
    _printf("Pointer address: %p\n", (void*)&main);
    return 0;
}
```

## Flowchart

You can add your flowchart here to visually represent the logic of the `_printf` function and its components.

![Flowchart](/img/FlowChart.png)

## Authors
- Jayson Pasquier
- Huslen Dauvet