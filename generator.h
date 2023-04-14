#pragma once
#include <string>
#include <ctime>

class PassConfig {
public:
    int length;
    bool includeNumbers;
    bool includeSymbols;
    bool includeUppercase;
    bool includeLowercase;

public:
    PassConfig(int len = 15, bool inclNum = true, bool inclSymb = true, bool inclUpper = true, bool inclLower = true);

    friend class PasswordGenerator;
};

class PasswordGenerator {
private:
    char randomUpper();
    char randomLower();
    char randomDigit();
    char randomSpecial();
public:
    PasswordGenerator() { std::srand(std::time(0)); }
    std::string generate(const PassConfig& config);
};