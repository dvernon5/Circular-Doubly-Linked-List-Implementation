#include "RequestManager.h"
#include <iostream>
namespace ClearKeyboard {
  void ClearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}
using namespace ClearKeyboard;

int RequestManager::GetValidatedUserInput(int user_input) {
  while (!(std::cin >> user_input)) {
    std::cout << "Invalid type. Please enter a number.\n";
    ClearInputBuffer();
  }
  ClearInputBuffer();
  return user_input;
}
