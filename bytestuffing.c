#include <stdio.h>
#include <string.h>

// Define the control characters
#define FLAG 0x7E    // Delimiter character
#define ESC 0x7D     // Escape character
#define XOR 0x20     // XOR value for escaping

// Function to perform byte stuffing
void byteStuffing(char input[], char stuffed[]) {
    int input_len = strlen(input);
    int stuffed_len = 0;

    for (int i = 0; i < input_len; i++) {
        if (input[i] == FLAG || input[i] == ESC) {
            stuffed[stuffed_len++] = ESC;
            stuffed[stuffed_len++] = input[i] ^ XOR;
        } else {
            stuffed[stuffed_len++] = input[i];
        }
    }

    stuffed[stuffed_len] = '\0';
}

// Function to perform byte destuffing
void byteDestuffing(char stuffed[], char destuffed[]) {
    int stuffed_len = strlen(stuffed);
    int destuffed_len = 0;

    for (int i = 0; i < stuffed_len; i++) {
        if (stuffed[i] == ESC) {
            i++;
            destuffed[destuffed_len++] = stuffed[i] ^ XOR;
        } else {
            destuffed[destuffed_len++] = stuffed[i];
        }
    }

    destuffed[destuffed_len] = '\0';
}

int main() {
    char input[] = "Hello~W~orld"; // The ~ character is used as a delimiter here
    char stuffed[2 * strlen(input) + 1]; // The stuffed data may be longer
    char destuffed[strlen(input) + 1];

    byteStuffing(input, stuffed);
    byteDestuffing(stuffed, destuffed);

    printf("Original Data: %s\n", input);
    printf("Stuffed Data: %s\n", stuffed);
    printf("Destuffed Data: %s\n", destuffed);

    return 0;
}
