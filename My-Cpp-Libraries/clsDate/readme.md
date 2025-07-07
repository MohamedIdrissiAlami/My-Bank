# clsDate.h

## Overview
`clsDate.h` is a C++ library designed to simplify date manipulation and calculations. It provides a comprehensive set of methods to handle dates, including validation, arithmetic operations, calendar generation, and business-day calculations. The library allows easy initialization from system time, strings, or individual components (day, month, year).

## Features
- **Date Initialization:** Create dates from system time, strings (DD/MM/YYYY), or explicit values.
- **Validation:** Check if a date is valid.
- **Leap Year Detection:** Determine leap years and calculate days in months/years.
- **Date Arithmetic:** Add/subtract days, weeks, months, years, decades, centuries, and millennia.
- **Calendar Generation:** Print monthly/yearly calendars.
- **Date Comparison:** Compare dates (before/after/equal).
- **Day Calculations:** Find day of the week, days between dates, and business days.
- **Date Formatting:** Convert dates to strings.
- **Utility Functions:** Check weekends, business days, end-of-month/year, and more.

## Usage
Include the header in your project (ensure `clsString.h` is also included, as it's a dependency):

```cpp
#include "clsString.h"
#include "clsDate.h"
```

## Example

```cpp
#include <iostream>
#include "clsString.h"
#include "clsDate.h"

int main() {
    // Create a date object for today
    clsDate today;
    std::cout << "Today: ";
    today.Print(); // Output: DD/MM/YYYY

    // Add 1 week and print
    today.IncreaseDateByOneWeek();
    std::cout << "Next week: " << today.DateToString() << std::endl;

    // Calculate days between two dates
    clsDate deadline(25, 12, 2024);
    std::cout << "Days until deadline: "
              << today.GetDifferenceInDays(deadline) << std::endl;

    return 0;
}
```

## Installation
1. Download both `clsDate.h` and `clsString.h` from your project repository.
2. Place them in your project's include directory.
3. Include the headers in your source files as needed.

## Requirements
- C++11 or later.
- `clsString.h` (dependency for string splitting in constructors).

## Methods Highlights

### Key Methods
- **Constructors:** `clsDate()`, `clsDate(string)`, `clsDate(day, month, year)`.
- **Validation:** `IsValidDate()`, `IsLeapYear()`.
- **Arithmetic:** `AddDays()`, `IncreaseDateByXMonths()`, `DecreaseDateByOneDecade()`.
- **Comparison:** `CompareDates()`, `IsDateBeforeDate2()`.
- **Utilities:** `PrintMonthCalendar()`, `CalculateBusinessDays()`, `DaysUntilTheEndOfYear()`.

### Static Methods
- `GetSystemDate()`
- `IsValidDate()`
- `DateToString()`

## License
This project is licensed under the MIT License.

## Author
Developed by **Mohamed Idrissi Alami**.

