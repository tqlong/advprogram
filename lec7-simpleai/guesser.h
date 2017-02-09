#pragma once

#include <string>
#include <set>

char getNextGuess(const std::set<char>& previousGuesses, const std::string& secretWord);
