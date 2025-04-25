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
        std::cout << "\nYou've entered an invalid character! Please enter either a 'y' or an 'n': "; 
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return yesOrNo;
}

std::string menuErrorHandlingAndMessage()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return "\nThe menu option you've entered is invalid! Please try again: ";
}

std::string conversionErrorHandlingAndMessage()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return "\nThe value you've entered is invalid! Please try again: ";
}

double fahrenheitToCelsius(double f) { return (f - 32) * 5 / 9; }

double fahrenheitToKelvin(double f) { return (f - 32) * 5 / 9 + 273.15; }

double celsiusToFahrenheit(double c) { return (c * 9/5) + 32; }

double celsiusToKelvin(double c) { return c + 273.15; }

double kelvinToFahrenheit(double k) { return (k - 273.15) * 9 / 5 + 32; }

double kelvinToCelsius(double k) { return k - 273.15; }

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
                menuErrorHandlingAndMessage()
            );

            if(menuOption <= 0)
            {
                
            }

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
                        conversionErrorHandlingAndMessage()
                    );
                    break;
                default:
                    if(menuOption < 1 || menuOption > 6)
                    {
                        std::cout << "\nOh.\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        std::cout << "Look at this guy.\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                        std::cout << "We got a fuckin' goofster in here.\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                        std::cout << "WIP\n";
                        return 1;
                    }
            }

            double result = 0.0;

            switch(menuOption)
            {
                case 1:
                    result = fahrenheitToCelsius(inputTemp);
                    std::cout << "\nThe math for this conversion is as follows: (" << inputTemp << " - 32) * 5 / 9 => (" << (inputTemp - 32) << ") * 0.5555... = " << fahrenheitToCelsius(inputTemp) << '\n';
                    break;
                case 2:
                    result = fahrenheitToKelvin(inputTemp);
                    std::cout << "\nThe math for this conversion is as follows:  (" << inputTemp << " - 32) * 5 / 9 + 273.15 => (" << (inputTemp - 32) << ") * 0.5555... + 273.15 => (" << (inputTemp - 32) * 5/9 << ") + 273.15 = " << fahrenheitToKelvin(inputTemp) << "\n\n";
                    break;
                case 3:
                    result = celsiusToFahrenheit(inputTemp);
                    std::cout << "\nThe math for this conversion is as follows: (" << inputTemp << " * 9/5) + 32 => (" << (inputTemp * 9/5) << ") * + 32 = " << celsiusToFahrenheit(inputTemp) << '\n';
                    break;
                case 4:
                    result = celsiusToKelvin(inputTemp);
                    std::cout << "\nThe math for this conversion is as follows: (" << inputTemp << " + 273.15) = " << celsiusToKelvin(inputTemp) << '\n';
                    break;
                case 5:
                    result = kelvinToFahrenheit(inputTemp);
                    std::cout << "\nThe math for this conversion is as follows: (" << inputTemp << " - 273.15) * 9 / 5 + 32 => (" << (inputTemp - 273.15) << ") * 1.5 + 32 => " << ((inputTemp - 273.15) * 1.5) << " + 32 = " << kelvinToFahrenheit(inputTemp) << '\n';
                    break;
                case 6:
                    result = kelvinToCelsius(inputTemp);
                    std::cout << "\nThe math for this conversion is as follows: (" << inputTemp << " - 273.15) = " << kelvinToCelsius(inputTemp) << '\n';
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
