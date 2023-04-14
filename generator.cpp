#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "generator.h"

std::string PasswordGenerator::generate(const PassConfig& config) {
    std::string password;

    if (!config.includeLowercase && !config.includeNumbers && !config.includeSymbols && !config.includeUppercase) {
        throw std::out_of_range("No char available");
    }

    for (int i = 0; i < config.length; i++) {
        char randChar;
        int j = i;

        int choice = std::rand() % 4;
        if (choice == 0) {
            if (config.includeUppercase)
                randChar = randomUpper();
            else
                i--;
        }
        else if (choice == 1) {
            if (config.includeLowercase)
                randChar = randomLower();
            else
                i--;
        }
        else if (choice == 2) {
            if (config.includeNumbers)
                randChar = randomDigit();
            else
                i--;
        }
        else if (choice == 3) {
            if (config.includeSymbols)
                randChar = randomSpecial();
            else
                i--;
        }
        if (i == j)
            password += randChar;
    }

    return password;
}

char PasswordGenerator::randomUpper() {
    char randChar = std::rand() % 26 + 'A';
    return randChar;
}

char PasswordGenerator::randomLower() {
    char randChar = std::rand() % 26 + 'a';
    return randChar;
}

char PasswordGenerator::randomDigit() {
    char randChar = std::rand() % 10 + '0';
    return randChar;
}

char PasswordGenerator::randomSpecial() {
    char randChar;
    int choice = std::rand() % 3;
    if (choice == 0)
        randChar = std::rand() % 15 + '!';
    else if (choice == 1)
        randChar = std::rand() % 7 + ':';
    else if (choice == 2)
        randChar = std::rand() % 7 + '[';
    else
        randChar = std::rand() % 5 + '{';

    return randChar;
}

PassConfig::PassConfig(int len, bool inclNum, bool inclSymb, bool inclUpper, bool inclLower) {
    length = len;
    includeNumbers = inclNum;
    includeSymbols = inclSymb;
    includeUppercase = inclUpper;
    includeLowercase = inclLower;
}