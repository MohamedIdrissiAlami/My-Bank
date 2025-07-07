# clsUtil.h

## Overview
`clsUtil.h` is a C++ utility library that provides a collection of useful functions for random number generation, string manipulation, key generation, encryption, decryption, array operations, and swapping values. The library aims to simplify common programming tasks and enhance productivity.

## Features
- **Randomization:**
  - Generate random numbers within a specified range.
  - Generate random characters (small letters, capital letters, digits, special characters, or mixed).
  - Generate random words and keys.
  
- **Key Generation:**
  - Generate unique 16-character keys in the format `XXXX-XXXX-XXXX-XXXX`.
  
- **Array Operations:**
  - Fill arrays with random numbers, words, or keys.
  - Shuffle arrays of integers or strings.
  
- **Swapping Functions:**
  - Swap values of various data types (int, double, bool, char, string, clsDate).
  
- **Text Manipulation:**
  - Encrypt and decrypt text using a shift-based algorithm.
  - Generate a specified number of tab spaces.
  
## Usage
Include the header file in your project:

```cpp
#include "clsUtil.h"
```

### Example Usage

```cpp
#include <iostream>
#include "clsUtil.h"

int main() {
    clsUtil::Srand(); // Seed random generator
    
    // Generate a random number between 1 and 100
    int randomNum = clsUtil::RandomNumber(1, 100);
    std::cout << "Random Number: " << randomNum << std::endl;
    
    // Generate a random capital letter
    char randomChar = clsUtil::GetRandomCharacter(clsUtil::CapitalLetter);
    std::cout << "Random Character: " << randomChar << std::endl;
    
    // Generate a random key
    std::string key = clsUtil::GenerateKey();
    std::cout << "Generated Key: " << key << std::endl;
    
    // Encrypt and decrypt a message
    std::string message = "Hello";
    std::string encrypted = clsUtil::EncryptText(message, 3);
    std::string decrypted = clsUtil::DecryptText(encrypted, 3);
    
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    
    return 0;
}
```

## Installation
1. Download `clsUtil.h` from the project repository.
2. Place it in your project's include directory.
3. Include it in your source files as needed.

## Requirements
- C++11 or later.
- `clsDate.h` (for swapping date objects).

## Methods Highlights
### Randomization
- `Srand()`: Seeds the random number generator.
- `RandomNumber(int From, int To)`: Generates a random number within a given range.
- `GetRandomCharacter(enCharType CharType)`: Generates a random character based on the specified type.
- `GenerateWord(enCharType CharType, short Length)`: Creates a random word of specified length.
- `GenerateKey(enCharType CharType)`: Generates a random key in the format `XXXX-XXXX-XXXX-XXXX`.

### Array Operations
- `FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)`: Fills an array with random numbers.
- `FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short WordLength)`: Fills an array with random words.
- `ShuffleArray(int arr[100], int arrLength)`: Shuffles an array of integers.
- `ShuffleArray(string arr[100], int arrLength)`: Shuffles an array of strings.

### Swapping Functions
- `Swap(int& A, int& B)`, `Swap(double& A, double& B)`, `Swap(bool& A, bool& B)`, `Swap(char& A, char& B)`, `Swap(string& A, string& B)`, `Swap(clsDate& A, clsDate& B)`: Swaps values of different types.

### Encryption & Decryption
- `EncryptText(string Text, short EncryptionKey)`: Encrypts a text by shifting characters.
- `DecryptText(string Text, short EncryptionKey)`: Decrypts a text by reversing the shift.

## Author
Developed by Mohamed  Idrissi Alami.

