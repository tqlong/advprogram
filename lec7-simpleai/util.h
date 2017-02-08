#pragma once

#include <vector>
#include <string>

int generateRandomNumber(int min, int max);
bool isCharInWord(char ch, std::string word);
std::vector<std::string> readWordListFromFile(const std::string& filePath);
