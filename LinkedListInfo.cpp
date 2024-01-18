#include "LinkedListInfo.h"
#include <iostream>

bool LinkedListInfo::IsAllocationError(struct Node* ptr_node) {
  return current_node == nullptr;
}

void LinkedListInfo::AllocationWarningMessage(struct Node* ptr_node) {
  if (IsAllocationError(ptr_node)) {
    std::cerr << "Allocation error\n";
  }
}

bool LinkedListInfo::IsEmpty(struct Node* ptr_node) {
  if (ptr_node == nullptr) {
    return true;
  }
  
  return false;
}

int LinkedListInfo::GetNumberOfNodes(struct Node* ptr_node) {
  if (ptr_node == nullptr) {
    return 0;
  }
  unsigned counter{0};
  struct Node* current_node = ptr_node;
  do {
    ++counter;
    current_node = current_node->next_node;
  } while (current_node != ptr_node);
  
  return counter;
}
