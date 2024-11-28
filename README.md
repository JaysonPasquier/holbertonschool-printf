
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

I do local teste with this main.c files :

```c
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
```

and it should print something like that

```c
Length:[-638184872, -638184856]
Length:[32, 32]
Length:[-1, -1]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]
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