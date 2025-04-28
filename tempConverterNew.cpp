#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <chrono>
#include <thread>

int getValidMenuAndConversionSelection(const std::string &prompt, const std::string &errorMsg)
{
    int validConversionAndMenuSelection;
    std::cout << prompt;
    while(!(std::cin >> validConversionAndMenuSelection))
    {
        std::cout << errorMsg;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return validConversionAndMenuSelection;
}

double getValidTemperature(const std::string &prompt, const std::string &errorMsg)
{
    double validTemperature;
    std::cout << prompt;
    while(!(std::cin >> validTemperature))
    {
        std::cout << errorMsg;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    return validTemperature;
}

char getYesOrNo(const std::string &prompt)
{
    char yesOrNo;
    std::cout << prompt;
    while(true)
    {
        std::cin >> yesOrNo;
        yesOrNo = static_cast<char>(std::tolower(static_cast<unsigned char>(yesOrNo)));
        if (yesOrNo == 'y' || yesOrNo == 'n') break;
        std::cout << "\nYou've entered an invalid character! Please only enter either a 'y' or an 'n', capital or lowercase: "; 
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return yesOrNo;
}

std::string inputErrorHandling()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return "\nThe input you've entered is invalid! Please try again: ";
}

double fahrenheitToCelsius(double f)
{
    const double thirtyTwo = 32.0;
    const double fiveOverNine = 0.555555555555555; // Using the fraction caused issues
    return (f - thirtyTwo) * fiveOverNine;
} // If F = 32, 32 - 32 = 0 -> 0 * 5 / 9 = 0. So, 32F = 0C.

double fahrenheitToKelvin(double f)
{
    const double thirtyTwo = 32.0;
    const double fiveOverNine = 0.555555555555555;
    const double twoHundredSeventyThreePointOneFive = 273.15;
    return (f - thirtyTwo) * fiveOverNine + twoHundredSeventyThreePointOneFive;
} // If F = 32, 32 - 32 = 0 -> 0 * 5 / 9 = 0 -> 0 + 273.15 = 273.15. So, 32F = 273.15K.

double celsiusToFahrenheit(double c)
{
    const double thirtyTwo = 32.0;
    const double nineOverFive = 1.8;
    return (c * nineOverFive) + thirtyTwo;
} // If C = 32, 32 * 9/5 = 57.6 -> 57.6 + 32 = 89.6. So, 32C = 89.6F.

double celsiusToKelvin(double c)
{
    const double twoHundredSeventyThreePointOneFive = 273.15;
    return c + twoHundredSeventyThreePointOneFive;
} // If C = 32, 32 + 273.15 = 305.15. So, 32C = 305.15K.

double kelvinToFahrenheit(double k)
{
    const double twoHundredSeventyThreePointOneFive = 273.15;
    const double onePointEight = 1.8;
    const double thirtyTwo = 32.0;
    return (k - twoHundredSeventyThreePointOneFive) * onePointEight + thirtyTwo;
} // If K = 32, 32 - 273.15 = -241.15 -> -241.15 * 9 / 5 = -434.07 -> -434.07 + 32 = -402.07. So, 32K = -402.07F.

double kelvinToCelsius(double k)
{
    const double twoHundredSeventyThreePointOneFive = 273.15;
    return k - twoHundredSeventyThreePointOneFive;
} // If K = 32, 32 - 273.15 = -241.15. So, 32K = -241.15C.

int main()
{
    bool wantToDoMoreConversions = true;

    while(wantToDoMoreConversions)
    {
        int total = getValidMenuAndConversionSelection
        (
            "\nHow many conversions would you like to do? Make sure to enter a whole number: ",
            "\nYou've entered something that isn't a whole number! Please try again: "
        );

        if(total <= 0)
        {
            std::cout << "\nOh, haaa haaa.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "You're an actual riot.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            std::cout << "Actually, nah. Hold up. I got something for you.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            std::cout << "THINK FAST, CHUCKLENUTS!\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            
            for(int i = 0; i < INT16_MAX; i++)
            {
                std::cout << i;
            }

            return 1;
        }

        for(int i = 1; i <= total; ++i)
        {
            std::cout << "\n--- You're currently on conversion " << i << " out of " << total << " ---" << "\n\n";
            std::cout << "1. Fahrenheit -> Celsius\n"
                      << "2. Fahrenheit -> Kelvin\n"
                      << "3. Celsius -> Fahrenheit\n"
                      << "4. Celsius -> Kelvin\n"
                      << "5. Kelvin -> Fahrenheit\n"
                      << "6. Kelvin -> Celsius" << "\n\n";
                      
            int menuOption = getValidMenuAndConversionSelection
            (
                "Choose a conversion from the list above! (1-6): ",
                inputErrorHandling()
            );

            double inputTemp = 0.0;

            switch(menuOption)
            {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    inputTemp = getValidTemperature
                    (
                        "\nPlease enter the temperature you'd like to convert: ",
                        inputErrorHandling()
                    );
                    break;
                default:
                    if(menuOption < 1 || menuOption > 6)
                    {
                        std::cout << "\nYou're not funny.\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        std::cout << "I hope you know that.\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                        std::cout << "You know what. Press 'Enter' rn. See what happens.\n";

                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.get();

                        return 1;
                    }
            }

            double result = 0.0;

            switch(menuOption)
            {
                case 1:
                    result = fahrenheitToCelsius(inputTemp);
                    std::cout << "\nThe math for this conversion is as follows: (" << inputTemp << " - 32) * 5 / 9 => (" << (inputTemp - 32) << ") * 0.5555... = " << result << '\n';
                    break;
                case 2:
                    result = fahrenheitToKelvin(inputTemp);
                    std::cout << "\nThe math for this conversion is as follows:  (" << inputTemp << " - 32) * 5 / 9 + 273.15 => (" << (inputTemp - 32) << ") * 0.5555... + 273.15 => (" << (inputTemp - 32) * 5/9 << ") + 273.15 = " << result << "\n\n";
                    break;
                case 3:
                    result = celsiusToFahrenheit(inputTemp);
                    std::cout << "\nThe math for this conversion is as follows: (" << inputTemp << " * 9/5) + 32 => (" << (inputTemp * 9/5) << ") + 32 = " << result << '\n';
                    break;
                case 4:
                    result = celsiusToKelvin(inputTemp);
                    std::cout << "\nThe math for this conversion is as follows: (" << inputTemp << " + 273.15) = " << result << '\n';
                    break;
                case 5:
                    result = kelvinToFahrenheit(inputTemp);
                    std::cout << "\nThe math for this conversion is as follows: (" << inputTemp << " - 273.15) * 9 / 5 + 32 => (" << (inputTemp - 273.15) << ") * 1.8 + 32 => " << ((inputTemp - 273.15) * 1.8) << " + 32 = " << result << '\n';
                    break;
                case 6:
                    result = kelvinToCelsius(inputTemp);
                    std::cout << "\nThe math for this conversion is as follows: (" << inputTemp << " - 273.15) = " << result << '\n';
                    break;
            }

            std::cout << "\nAnd here's the final result: " << inputTemp << " --> " << result << '\n';
        }

        char again = getYesOrNo("\nDo you want to do another conversion? (y/n): ");
        wantToDoMoreConversions = (again == 'y');
    }
    std::cout << "\nThank you for using my Temperature Converter! Press press 'Enter' to end the program. :)\n";
    std::cin.get();

    return 0;
}
