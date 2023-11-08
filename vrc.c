// VRC code in C

#include <stdio.h>

int main() {

  // Initialize the data
  int data[8] = {1, 0, 1, 0, 1, 0, 1, 0};
  int vrc = 0;

  // Calculate the VRC
  for (int i = 0; i < 8; i++) {
    vrc += data[i];
  }

  // Check the VRC
  if (vrc % 2 == 0) {
    printf("No error detected.\n");
  } else {
    printf("Error detected.\n");
  }

  return 0;
}

// LRC code in C

#include <stdio.h>

int main() {

  // Initialize the data
  int data[8] = {1, 0, 1, 0, 1, 0, 1, 0};
  int lrc = 0;

  // Calculate the LRC
  for (int i = 0; i < 8; i++) {
    lrc += data[i];
  }

  // Check the LRC
  if (lrc % 2 == 0) {
    printf("No error detected.\n");
  } else {
    printf("Error detected.\n");
  }

  return 0;
}