#include <iostream>
#include <string>
#include <fstream>

// special function, not gonna test
std::string returnFileText(std::string filename) {
  std::ifstream infile { filename };
  std::string raw { std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>() };
  return raw;
}

// F1
std::string removeLeadingSpaces(std::string line) {
  for (char c : line) {
    if (!isspace(c))
      return line.substr(line.find(c));
  }
}

// F2
int countChar(std::string line, char c) {
  int ctr = 0;
  for (char x : line)
    if (x == c) ctr++;
  return ctr;
}

// F3
std::string unindent(std::string filename) {
  std::string line, unindented;
  std::ifstream file;
  file.open(filename);
  while (std::getline(file, line))
    unindented += removeLeadingSpaces(line) + "\n";
  file.close();
  return unindented;
}

//F4
std::string indent(std::string filename) {
  int indents = 0;
  std::string line, tabs, indented;

  std::ifstream file;
  file.open(filename);
  while (std::getline(file, line)) {

    if (countChar(line, '}') > 0) {
      indents--;
      tabs = "";
      for (int i = 0; i < indents; i++)
	tabs += '\t';
    }

    indented += tabs + removeLeadingSpaces(line) + '\n';

    if (countChar(line, '{') > 0) {
      indents++;
      tabs = "";
      for (int i = 0; i < indents; i++)
	tabs += '\t';
    }
  }

  file.close();
  return indented;
}
