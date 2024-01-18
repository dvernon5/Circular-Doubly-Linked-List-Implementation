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

struct NodePositionInfo RequestManager::InsertRequest(struct Node* current_node) {
  std::cout << "\nADD NODE: \n---------\n";
  std::cout << "Enter a number: ";
  node.data = GetValidatedUserInput(node.data);
  if (current_node != nullptr) {
    int total_nodes = list_info.GetNumberOfNodes(current_node);
    std::cout << "Enter a position between 1 and " << total_nodes + 1 << " to insert node: ";
    node.position   = GetValidatedUserInput(node.position);
  }
  
  return node;
}

struct NodePositionInfo RequestManager::DeleteRequest(struct Node* current_node) {
  std::cout << "\nDELETE NODE: \n------------\n";
  int total_nodes = list_info.GetNumberOfNodes(current_node);
  switch (total_nodes) {
    case 0: {
      // List is empty.
      break;
    }
    case 1: {
      // Case: Only one node available. Prompt user to enter 1.
      std::cout << "Please enter the number 1: ";
      node.position = GetValidatedUserInput(node.position);
      break;
    }
    default: {
      std::cout << "Enter a position between 1 and " << total_nodes << " to delete node: ";
      node.position = GetValidatedUserInput(node.position);
      break;
    }
  }
  
  return node;
}
