# Temperature Converter

A simple C++ console application that converts between Fahrenheit, Celsius, and Kelvin.
Perform one or more conversions in a single run, with validated input, progress indicators, and step-by-step math explanations.

---

## Features

- Six conversion types:
  1. Fahrenheit → Celsius
  2. Fahrenheit → Kelvin
  3. Celsius → Fahrenheit
  4. Celsius → Kelvin
  5. Kelvin → Fahrenheit
  6. Kelvin → Celsius
- Specify how many conversions to perform in a batch
- “Conversion 2 of 5” style progress display
- Robust input validation for both menu selections and numeric values
- “Do you want to do another conversion?” loop at the end
- Clear, step-by-step math breakdown of each conversion

---

## Prerequisites

- A C++ compiler with C++11 support or newer (e.g. GCC, Clang, etc...)
- (Optional) CMake if you prefer a build system
- A terminal or command prompt

---

## Building

### Using a single compile command

```bash
g++ -std=c++11 -o temp_converter main.cpp
```

## Using CMake

```cmake
mkdir build
cd build
cmake ..
make
```

---

## Usage

Run the compiled executable from your terminal:

```bash
./temp_converter
```

1. How many conversions? Enter a whole number.
2. For each conversion:
  - Pick a menu option (1–6).
  - Enter the temperature value to convert.
  - View the math steps and the final result.
3. Repeat? After the batch completes, type 'y' to start another batch or 'n' to exit.
4. Exit: Press Enter when prompted.

### Example
```
$ ./temp_converter

How many conversions would you like to do? 2

--- You're currently on conversion 1 of 2 ---
1. Fahrenheit -> Celsius
2. Fahrenheit -> Kelvin
3. Celsius -> Fahrenheit
4. Celsius -> Kelvin
5. Kelvin -> Fahrenheit
6. Kelvin -> Celsius

Choose a conversion from the list above! (1-6): 1

Please enter the temperature you'd like to convert: 212

The math for this conversion is as follows:
(212 - 32) * 5 / 9 => (180) * 0.5555... = 100
And here's the final result: 212 --> 100

--- You're currently on conversion 2 of 2 ---
Choose a conversion from the list above! (1-6): 2

Please enter the temperature you'd like to convert: 32

The math for this conversion is as follows:
(32 - 32) * 5 / 9 + 273.15 => (0) * 0.5555... + 273.15 = 273.15
And here's the final result: 32 --> 273.15

Do you want to do another conversion? (y/n): n

Thank you for using my Temperature Converter! Press Enter to end the program.
```

---

## Error Handling

- Menu input: Only accepts integers 1–6, re-prompts on invalid entry.
- “How many” input: Only accepts positive whole numbers, re-prompts on invalid entry.
- Temperature input: Only accepts real numbers, re-prompts on invalid entry.
- Continue prompt: Only accepts y or n, re-prompts on invalid entry.

---

## Contact

- Discord: savxl
- Twitter: rsavxl
- Instagram: @20sav.xl02
