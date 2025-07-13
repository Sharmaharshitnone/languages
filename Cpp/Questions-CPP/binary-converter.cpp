#include <iostream>
#include <string>
#include <vector>

void printBinary(int num)
{
    std::cout << "Converting " << num << " to binary:" << std::endl;
    std::cout << std::endl;

    // Method 1: Show the division process
    std::cout << "=== METHOD 1: Division by 2 ===" << std::endl;
    std::vector<int> remainders;
    int temp = num;

    if (temp == 0)
    {
        std::cout << "0 ÷ 2 = 0 remainder 0" << std::endl;
        remainders.push_back(0);
    }
    else
    {
        while (temp > 0)
        {
            int remainder = temp % 2;
            remainders.push_back(remainder);
            std::cout << temp << " ÷ 2 = " << (temp / 2) << " remainder " << remainder << std::endl;
            temp = temp / 2;
        }
    }

    std::cout << std::endl;
    std::cout << "Reading remainders from bottom to top: ";
    for (int i = remainders.size() - 1; i >= 0; --i)
    {
        std::cout << remainders[i];
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Method 2: Show the powers of 2
    std::cout << "=== METHOD 2: Powers of 2 ===" << std::endl;
    std::cout << "Powers of 2: ";
    for (int i = 7; i >= 0; --i)
    {
        std::cout << (1 << i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Bit positions: ";
    for (int i = 7; i >= 0; --i)
    {
        std::cout << i << "   ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "For " << num << ":" << std::endl;

    // Show which powers of 2 make up the number
    std::vector<int> powers;
    temp = num;
    for (int i = 7; i >= 0; --i)
    {
        int power_of_2 = 1 << i;
        if (temp >= power_of_2)
        {
            powers.push_back(power_of_2);
            temp -= power_of_2;
        }
    }

    if (powers.empty())
    {
        std::cout << "0 = 0" << std::endl;
    }
    else
    {
        std::cout << num << " = ";
        for (int i = 0; i < powers.size(); ++i)
        {
            std::cout << powers[i];
            if (i < powers.size() - 1)
                std::cout << " + ";
        }
        std::cout << " = ";
        for (int i = 0; i < powers.size(); ++i)
        {
            // Find which power this is
            int power = 0;
            int val = powers[i];
            while (val > 1)
            {
                val >>= 1;
                power++;
            }
            std::cout << "2^" << power;
            if (i < powers.size() - 1)
                std::cout << " + ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Binary representation (8 bits):" << std::endl;
    std::cout << "Position: ";
    for (int i = 7; i >= 0; --i)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Binary:   ";
    for (int i = 7; i >= 0; --i)
    {
        if (num & (1 << i))
        {
            std::cout << "1 ";
        }
        else
        {
            std::cout << "0 ";
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void demonstrateStringToBitmask()
{
    std::cout << "=== STRING TO BITMASK CONVERSION ===" << std::endl;
    std::cout << std::endl;

    std::string examples[] = {"abc", "def", "un", "iq", "ue"};

    for (const std::string &s : examples)
    {
        std::cout << "String: \"" << s << "\"" << std::endl;

        int mask = 0;
        std::cout << "Characters: ";
        for (char c : s)
        {
            int bit_position = c - 'a';
            std::cout << c << "(bit " << bit_position << ") ";
            mask |= (1 << bit_position);
        }
        std::cout << std::endl;

        std::cout << "Bitmask value: " << mask << std::endl;
        std::cout << "Binary: ";
        for (int i = 25; i >= 0; --i)
        {
            if (mask & (1 << i))
            {
                std::cout << "1";
            }
            else
            {
                std::cout << "0";
            }
            if (i % 4 == 0)
                std::cout << " "; // Space every 4 bits for readability
        }
        std::cout << std::endl;

        std::cout << "Set bits represent: ";
        for (int i = 0; i < 26; ++i)
        {
            if (mask & (1 << i))
            {
                std::cout << (char)('a' + i) << " ";
            }
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

int main()
{
    std::cout << "=== BINARY CONVERSION TUTORIAL ===" << std::endl;
    std::cout << std::endl;

    // Demo with specific examples
    int examples[] = {56, 7, 0, 1, 15, 255};

    for (int num : examples)
    {
        printBinary(num);
        std::cout << "----------------------------------------" << std::endl;
    }

    demonstrateStringToBitmask();

    // Interactive part
    std::cout << "=== INTERACTIVE CONVERTER ===" << std::endl;
    std::cout << "Enter a number to convert to binary (or -1 to exit): ";

    int input;
    while (std::cin >> input && input != -1)
    {
        printBinary(input);
        std::cout << "Enter another number (or -1 to exit): ";
    }

    return 0;
}

/*
This program helps you understand:

1. How to convert decimal numbers to binary manually
2. How powers of 2 work in binary representation
3. How strings are converted to bitmasks in our algorithm
4. Visual representation of binary numbers

Key concepts:
- Each bit position represents a power of 2
- Bit 0 = 2^0 = 1, Bit 1 = 2^1 = 2, Bit 2 = 2^2 = 4, etc.
- For strings, bit position = character - 'a'
- So 'a' = bit 0, 'b' = bit 1, 'c' = bit 2, etc.
*/
