#include <stdio.h>
#include <conio.h>

// Function to convert decimal to binary
int decimalToBinary(int decimal) {
    int binary = 0, base = 1;
    while (decimal!= 0) {
        int lastDigit = decimal % 2;
        binary += lastDigit * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
}

// Function to perform binary addition
int binaryAddition(int a, int b) {
    int carry = 0, result = 0, bit = 1;
    while (a!= 0 || b!= 0) {
        int bit_a = a % 10;
        int bit_b = b % 10;

        // Add the bits along with the carry
        int sum = bit_a + bit_b + carry;

        // Update the result
        result += (sum % 2) * bit;

        // Calculate the carry for the next bit
        carry = sum / 2;

        // Move to the next bit
        a /= 10;
        b /= 10;
        bit *= 10;
    }

    // Add the carry if exists
    result += carry * bit;
    return result;
}

// Function to perform logical shift left
int logicalShiftLeft(int num) {
    return num * 10; // Equivalent to shifting left by 1 position
}

// Function to perform logical shift right
int logicalShiftRight(int num) {
    return num / 10; // Equivalent to shifting right by 1 position
}

// Function to perform Booth's multiplication algorithm
int boothMultiply(int multiplicand, int multiplier) {
    int accumulator = 0;
    int bitMask = 1;

    // Iterate over each bit of the multiplier
    printf("\n\nThe shifting table in the Multiplicand and Mltiplier:");
    printf("\n|  %d |   %d |  %d   |",accumulator,multiplicand,multiplier);
    while (multiplier!= 0) {
        // Step 2: Test Y0; if it is 1, add content of X to the accumulator A
        if (multiplier % 10 == 1) {
            accumulator = binaryAddition(accumulator, multiplicand);
        }

        // Step 3: Logical Shift the content of X left one position and content of Y right one position
        multiplicand = logicalShiftLeft(multiplicand);
        multiplier = logicalShiftRight(multiplier);
        //printf("|  A  |   B  |   Q   |\n");
        printf("\n|  %d |   %d |  %d   |",accumulator,multiplicand,multiplier);

        // Move the bit mask to the next bit
        bitMask *= 10;
    }

    return accumulator;
}

// Function to convert binary number to decimal
int binaryToDecimal(int binary) {
    int decimal = 0, base = 1;
    while (binary!= 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

int main() {
    int multiplicand, multiplier;
    printf("Enter the multiplicand (decimal): ");
    scanf("%d", &multiplicand);
    printf("Enter the multiplier (decimal): ");
    scanf("%d", &multiplier);

    // Convert decimal to binary
    int binaryMultiplicand = decimalToBinary(multiplicand);
    int binaryMultiplier = decimalToBinary(multiplier);

    // Step 1: Clear the accumulator (sum)
    int product = boothMultiply(binaryMultiplicand, binaryMultiplier);

    // Convert binary product to decimal
    int decimalProduct = binaryToDecimal(product);

    // Display the output in a table format
    printf("\n\n\n\n");
    printf("+------------------+------------------+------------------+\n");
    printf("| Multiplicand     | Multiplier       | Product          |\n");
    printf("+------------------+------------------+------------------+\n");
    printf("| %d (decimal)     | %d (decimal)     | %d (decimal)     |\n", multiplicand, multiplier, decimalProduct);
    printf("| %d (binary)      | %d (binary)      | %d (binary)      |\n", binaryMultiplicand, binaryMultiplier,product);
    printf("+------------------+------------------+------------------+\n");

    getch();
    return 0;
}