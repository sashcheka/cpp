#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <cctype>
#include <iomanip>
#include <algorithm>

std::string ToHex(int value) {
  std::stringstream ss;
  ss << std::hex << value;
  std::string hexStr = ss.str();

  if (hexStr.length() < 3) {
    hexStr = std::string(3 - hexStr.length(), '0') + hexStr;
  } else if (hexStr.length() > 3) {
    hexStr = hexStr.substr(hexStr.length() - 3);
  }

  std::transform(hexStr.begin(), hexStr.end(), hexStr.begin(), 
                 [](unsigned char c) { return std::toupper(c); });

  return hexStr;
}

std::string Encrypt(const std::string& candidate) {
  std::vector<std::string> tokens;
  std::string token;
  std::stringstream ss(candidate);

  while (std::getline(ss, token, ',')) {
    tokens.push_back(token);
  }

  std::string full_name = tokens[0] + tokens[1] + tokens[2];
  std::string date = tokens[3] + tokens[4] + tokens[5];

  std::set<char> uniqueChars;
  for (char& ch : full_name) {
    uniqueChars.insert(ch);
  }

  int uniqueCharsCount = uniqueChars.size();
  
  int dateDigitsSum = 0;
  for (int i = 0; i < date.size() - 4; ++i) {
    dateDigitsSum += date[i] - '0';
  }
  dateDigitsSum *= 64;
  
  int firstCharPosition = (std::tolower(full_name[0]) - 'a' + 1) * 256;
  
  int sum = uniqueCharsCount + dateDigitsSum + firstCharPosition;

  std::string encryption = ToHex(sum);

  return encryption;
}

int main() {
  int n;
  std::vector<std::string> encryptions;
  
  std::cin >> n;
  std::string candidate;
  
  for (int i = 0; i < n; i++) {
    std::cin >> candidate;
    encryptions.push_back(Encrypt(candidate));
  }
  
  for (std::string& encryption : encryptions) {
    std::cout << encryption << " ";
  }
}