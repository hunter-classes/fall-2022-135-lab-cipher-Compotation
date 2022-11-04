#include <iostream>
#include <vector>
#include <map>
#include "funcs.h"


int getIndex(char c) {
  if (isupper(c)) {
    return c - 65;
  }
  return c - 97;
}

int getLowerChar(int index) {
  return 97 + index;
}

double getFrequency(std::string str, char letter) {
  int count = 0;
  for (auto c: str) {
    if (c == tolower(letter)) {
      count++;
    } else if (c == toupper(letter)) {
      count++;
    }
  }
  return ((double) count) / str.size();
}


std::vector<double> getFrequencies(std::string str) {
  std::vector<double> frequencies;
  for (int i = 0; i < 26; i++) {
    frequencies.push_back(getFrequency(str, getLowerChar(i)));
  }
  return frequencies;
}