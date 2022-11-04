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
}

TEST_CASE("caesar") {
  CHECK_EQ(solve(
      "Qn pm pil ivgbpqvo kwvnqlmvbqit bw aig, pm ezwbm qb qv kqxpmz, bpib qa, jg aw kpivoqvo bpm wzlmz wn bpm tmbbmza wn bpm itxpijmb, bpib vwb i ewzl kwctl jm uilm wcb."),
           "If he had anything confidential to say, he wrote it in cipher, that is, by so changing the order of the letters of the alphabet, that not a word could be made out.");
  CHECK_EQ(solve("Cn cm hin xiqh ih uhs guj nloy jfuwym hypyl uly."),
           "It is not down on any map true places never are.");
  CHECK_EQ(solve(
      "Nfuipe jo xijdi fbdi mfuufs jo uif qmbjoufyu jt sfqmbdfe cz b mfuufs tpnf gjyfe ovncfs pg qptjujpot epxo uif bmqibcfu. Uif nfuipe jt obnfe bgufs Kvmjvt Dbftbs, xip vtfe ju jo ijt qsjwbuf dpssftqpoefodf."),
           "Method in which each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet. The method is named after Julius Caesar, who used it in his private correspondence.");
  CHECK_EQ(solve(
      "Lt iwt Etdeat du iwt Jcxits Hipith, xc Dgstg id udgb p bdgt etgutri Jcxdc, thipqaxhw Yjhixrt, xchjgt sdbthixr Igpcfjxaxin, egdkxst udg iwt rdbbdc stutcrt, egdbdit iwt vtctgpa Ltaupgt, pcs htrjgt iwt Qathhxcvh du Axqtgin id djghtakth pcs djg Edhitgxin, sd dgspxc pcs thipqaxhw iwxh Rdchixijixdc udg iwt Jcxits Hipith du Pbtgxrp."),
           "We the People of the United States, in Order to form a more perfect Union, establish Justice, insure domestic Tranquility, provide for the common defence, promote the general Welfare, and secure the Blessings of Liberty to ourselves and our Posterity, do ordain and establish this Constitution for the United States of America.");
}