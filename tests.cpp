#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

#include <iostream>
#include <string>
#include <fstream>

std::string f1a = "\t \t   std::string removeLeadingSpaces() {";
std::string f1b = "std::string removeLeadingSpaces() {";
std::string f1c = "\n Hello, World!~ \t \n";
std::string f1d = "Hello, World!~ \t \n";

std::string f2a = "the quick brown fox jumped over the lazy dog";
std::string f2b = "{\n\t function { \t if { \t code; } \n\t { code; } \n }";

std::string f3a = "TestStrings/f3a.txt";
std::string f3b = returnFileText("TestStrings/f3b.txt");

std::string f4a = returnFileText("TestStrings/f4a.txt");

TEST_CASE("removeLeadingSpaces(std::string line)") {
  CHECK(removeLeadingSpaces(f1a) == f1b);
  CHECK(removeLeadingSpaces(f1c) == f1d);
}

TEST_CASE("countChar(std::string line, char c)") {
  CHECK(countChar(f2a, 'e') == 4);
  CHECK(countChar(f2b, '{') == 4);
  CHECK(countChar(f2b, '}') == 3);
  CHECK(countChar(f2b, ' ') == 14);
  CHECK(countChar(f2b, '\t') == 4);
  CHECK(countChar(f2b, '\n') == 3);
}

TEST_CASE("unindent(std::string filename)") {
  CHECK(unindent(f3a) == f3b);
}

TEST_CASE("indent(std::string filename)") {
  CHECK(indent(f3a) == f4a);
}
