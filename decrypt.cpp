#include <string>
#include "decrypt.h"
#include "caesar.h"

std::string decryptCaesar(std::string ciphertext, int rshift) {
  return encryptCaesar(ciphertext, -1 * rshift);
}

void negateArray(int shifts[], int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    shifts[i] = -1 * shifts[i];
  }
}
