#pragma once

#include <vector>
#include <string>

int generateRandomNumber(int min, int max);
bool isCharInWord(char ch, std::string word);
std::vector<std::string> readWordListFromFile(const std::string& filePath);
bool isAllDash(const std::string& s);
bool isAllNotDash(const std::string& s);
