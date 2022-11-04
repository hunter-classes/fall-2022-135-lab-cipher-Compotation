#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "funcs.h"

TEST_CASE("relative index of letter") {
  CHECK_EQ(getIndex('a'), 0);
  CHECK_EQ(getIndex('A'), 0);
  CHECK_EQ(getIndex('Z'), 25);
  CHECK_EQ(getIndex('z'), 25);
  CHECK_EQ(getIndex('l'), 11);
  CHECK_EQ(getIndex('L'), 11);
}

TEST_CASE("individual frequency of letter") {
  CHECK_EQ(getFrequency("helLo", 'l'), 0.4);
  CHECK_EQ(getFrequency("hi", 'z'), 0);
  CHECK_EQ(getFrequency("hello", 'l'), 0.4);
}

TEST_CASE("reverse index to lowercase letter") {
  CHECK_EQ(getLowerChar(0), 'a');
  CHECK_EQ(getLowerChar(25), 'z');
  CHECK_EQ(getLowerChar(3), 'd');
}

TEST_CASE("letter frequencies") {
  std::vector<double> test1 = {0, 0, 0, 0, 0.2, 0, 0, 0.2, 0, 0, 0, 0.4, 0, 0, 0.2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  CHECK_EQ(getFrequencies("hello"), test1);
  CHECK_EQ(getFrequencies("HEllO"), test1);
  CHECK_EQ(ENGLISH_FREQUENCY[9], 0.0015);
}