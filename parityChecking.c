#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to calculate and check even parity
bool checkEvenParity(const char* binaryData) {
    int count = 0;
    int len = strlen(binaryData);

    // Count the number of '1' bits in the binary data
    for (int i = 0; i < len; i++) {
        if (binaryData[i] == '1') {
            count++;
        }
    }

    // Check if the count of '1' bits is even
    return count % 2 == 0;
}

int main() {
    char binaryData[64];  // Assuming a maximum binary data length of 64 bits.

    printf("Enter binary data: ");
    scanf("%s", binaryData);

    bool isCorrect = checkEvenParity(binaryData);

    if (isCorrect) {
        printf("Parity check: Passed (even parity)\n");
    } else {
        printf("Parity check: Failed (even parity)\n");
    }

    return 0;
}
