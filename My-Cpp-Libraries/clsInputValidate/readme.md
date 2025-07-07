# clsInputValidate

A C++ utility library for input validation, providing functions to validate numbers, dates, and ensure user input is correctly formatted.

## Features
- Validate if a number is within a given range.
- Read and validate integer and floating-point numbers from user input.
- Validate if a date is within a specific range.
- Ensure user inputs are valid before proceeding.

## Dependencies
This library depends on:
- `clsString.h`
- `clsDate.h`

Make sure these dependencies are included in your project.

## Installation
Simply include `clsInputValidate.h` in your C++ project:

```cpp
#include "clsInputValidate.h"
```

## Usage
### Checking if a number is within a range
```cpp
#include "clsInputValidate.h"

int main() {
    int num = 15;
    if (clsInputValidate::IsNumberBetween(num, 10, 20)) {
        std::cout << "Number is within range." << std::endl;
    } else {
        std::cout << "Number is out of range." << std::endl;
    }
    return 0;
}
```

### Reading and validating user input
```cpp
#include "clsInputValidate.h"

int main() {
    std::cout << "Enter a valid integer: ";
    int userInput = clsInputValidate::ReadIntNumber();
    std::cout << "You entered: " << userInput << std::endl;
    return 0;
}
```

### Reading a number within a range
```cpp
#include "clsInputValidate.h"

int main() {
    std::cout << "Enter a number between 1 and 100: ";
    int num = clsInputValidate::ReadIntNumberBetween(1, 100);
    std::cout << "Valid number: " << num << std::endl;
    return 0;
}
```

### Validating a Date
```cpp
#include "clsInputValidate.h"
#include "clsDate.h"

int main() {
    clsDate date(2024, 5, 10);
    clsDate from(2023, 1, 1);
    clsDate to(2025, 12, 31);
    
    if (clsInputValidate::IsDateBetween(date, from, to)) {
        std::cout << "Date is within range." << std::endl;
    } else {
        std::cout << "Date is out of range." << std::endl;
    }
    return 0;
}
```

## License
This library is open-source. Feel free to modify and use it in your projects.

## Author
Mohamed Idrissi Alami

