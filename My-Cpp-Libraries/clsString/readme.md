# clsString.h

## Overview
`clsString.h` is a utility header file that provides a collection of string manipulation functions in C++. It simplifies common string operations such as validation, formatting, and conversion.

## Features
- **Trimming**: Remove leading and trailing whitespace.
- **Conversion**: Convert strings to uppercase or lowercase.
- **Validation**: Check if a string is numeric, alphabetic, or alphanumeric.
- **Splitting**: Split strings based on a delimiter.
- **Joining**: Join multiple strings into one.
- **Reversing**: Reverse a given string.

## Usage
To use `clsString.h` in your C++ project, include the header file:

```cpp
#include "clsString.h"
```

### Example
```cpp
#include <iostream>
#include "clsString.h"

int main() {
    std::string text = "  Hello, World!  ";
    std::cout << "Trimmed: " << clsString::Trim(text) << std::endl;
    std::cout << "Uppercase: " << clsString::ToUpper(text) << std::endl;
    std::cout << "Lowercase: " << clsString::ToLower(text) << std::endl;
    return 0;
}
```

## Installation
1. Download `clsString.h` and place it in your project directory.
2. Include it in your source files where needed.

## Requirements
- C++11 or later.

## License
This project is licensed under the MIT License.

## Author
Developed by Mohamed Idrissi Alami .

