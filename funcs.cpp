#include <iostream>
#include <vector>
#include <map>
#include "funcs.h"
#include <cmath>
#include <algorithm>
#include "decrypt.h"


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

double getDistance(std::vector<double> vec) {
  double radicand = 0;
  for (int i = 0; i < 26; i++) {
    radicand += pow(vec[i] - ENGLISH_FREQUENCY[i], 2);
  }
  return sqrt(radicand);
}

std::string solve(std::string encrypted_string) {
  std::vector<std::string> possibleDecryptions;
  for (int i = 0; i < 26; i++) {
    possibleDecryptions.push_back(decryptCaesar(encrypted_string, i));
  }
  std::vector<double> distances;
  for (int i = 0; i < 26; i++) {
    distances.push_back(getDistance(getFrequencies(possibleDecryptions[i])));
  }
  auto it = std::min_element(std::begin(distances), std::end(distances));
  return possibleDecryptions[std::distance(std::begin(distances), it)];
}