#pragma once
#include <iostream>
#include <string>

std::string returnFileText(std::string filename);
std::string removeLeadingSpaces(std::string line);
int countChar(std::string line, char c);
std::string unindent(std::string filename);
std::string indent(std::string filename);
