#pragma once

#include <vector>

const std::vector<double> ENGLISH_FREQUENCY = {0.082, 0.015, 0.028, 0.043, 0.13, 0.022, 0.02, 0.061, 0.07, 0.0015,
                                               0.0077, 0.04, 0.024, 0.067, 0.075, 0.019, 0.00095, 0.00095, 0.06, 0.063,
                                               0.091, 0.028, 0.0098, 0.024, 0.0015, 0.02, 0.00074
};

int getIndex(char c);

double getFrequency(std::string str, char letter);

std::vector<double> getFrequencies(std::string str);

int getLowerChar(int index);
