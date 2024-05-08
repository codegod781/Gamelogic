#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal character to its binary representation
char *hex_to_binary(char hex) {
    switch (hex) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
        default: return NULL;
    }
}

// Function to convert a hexadecimal string to its binary representation
char *hex_string_to_binary(const char *hex_string) {
    size_t length = strlen(hex_string);
    size_t binary_length = length * 4; // Each hexadecimal character represents 4 bits
    char *binary_string = (char *)malloc(binary_length + 1); // +1 for null terminator

    if (binary_string == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }

    binary_string[binary_length] = '\0'; // Null terminate the binary string

    for (size_t i = 0; i < length; i++) {
        char *binary_digit = hex_to_binary(hex_string[i]);
        if (binary_digit == NULL) {
            free(binary_string);
            return NULL;
        }
        strcat(binary_string, binary_digit);
    }

    return binary_string;
}







