# My-Bank: C++ Banking System

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![OOP](https://img.shields.io/badge/Object_Oriented-Yes-green.svg)

A complete console-based banking management system built with C++ and OOP principles.

## 📋 Table of Contents
- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [Project Structure](#-project-structure)
- [Code Examples](#-code-examples)
- [Acknowledgments](#-acknowledgments)

## ✨ Features
- **User Authentication System**
  - Secure login with 3-attempt limit
  - Password encryption
- **Client Management**
  - Add/Delete/Update clients
  - Search functionality
- **Banking Operations**
  - Deposit/Withdraw/Transfer funds
  - Balance inquiries
- **Admin Controls**
  - Role-based permissions
  - User management
- **Data Persistence**
  - All data saved to text files
  - Login activity logging

## 💻 Installation
1. Clone the repository:
```bash
git clone https://github.com/mohamedidrissialami/My-Bank.git  
```
2. Compile with g++:  
g++ Bank.cpp -o MyBank  
3. Run the program:  
1. Login with admin credentials (admin/123)
2. Navigate menus using number keys
3. Follow on-screen instructions  

🗂 Project Structure :  


plaintext
My-Bank/
├── Bank.cpp               # Main application entry
├── Config.h               # Configuration constants
├── Global.h               # Global variables
├── clsClient.h            # Client class
├── clsUser.h              # User class
├── clsScreen.h            # Base screen class
├── Screens/               # All UI screens
│   ├── clsDepositScreen.h
│   ├── clsWithdrawScreen.h
│   └── ... 
└── Data/                  # Data storage
    ├── Clients.txt
    ├── Users.txt
    └── LoginRegister.txt
💡 Code Examples
Secure Password Handling:

cpp
string encrypted = clsUtil::EncryptText(password, EncryptionKey);
Transaction Validation:

cpp
bool Withdraw(float amount) {
    return (amount <= AccountBalance) && Deposit(-amount);
}
Permission Checking:

cpp
if(user.HasAccessTo(clsUser::pManageUsers)) {
    // Admin-only functionality
}
🙏 Acknowledgments
Special Thanks to Dr. Mohammed Abu-Hadhoud
This project stands on the shoulders of my esteemed mentor, Dr. Mohammed Abu-Hadhoud, whose guidance in software design principles and object-oriented programming has been invaluable to my development as a programmer. 


Developed with passion by Mohamed Idrissi Alami
📧 mohamedidrissialami3@gmail.com
🔗 https://github.com/MohamedIdrissiAlami
