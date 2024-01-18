#include "LinkedListInfo.h"
#include <iostream>

bool LinkedListInfo::IsAllocationError(struct Node* current_node) {
  return current_node == nullptr;
}

void LinkedListInfo::AllocationWarningMessage(struct Node* current_node) {
  if (IsAllocationError(current_node)) {
    std::cerr << "Allocation error\n";
  }
}

bool LinkedListInfo::IsEmptyList(struct Node* current_node) {
  return current_node == nullptr;
}

int LinkedListInfo::GetNumberOfNodes(struct Node* ptr_node) {
  if (IsEmptyList(ptr_node)) {
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
