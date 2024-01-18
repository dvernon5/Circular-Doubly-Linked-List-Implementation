#include "InsertNodeManager.h"
#include <iostream>

struct Node* InsertNodeManager::InsertRootNode(struct Node* ptr_node, NodePositionInfo& node) {
  struct Node* root_node       = new Node;
  list_info.AllocationWarningMessage(root_node);
  root_node->prev_node         = root_node;
  root_node->data              = node.data;
  root_node->next_node         = root_node;
  ptr_node                     = root_node;
  const int POSITION_INCREMENT = 1;
  std::cout << "Your data " << node.data << " was successfully added at "
            << "Position "  << node.position + POSITION_INCREMENT << ".\n";
  
  return ptr_node;
}

struct Node* InsertNodeManager::InsertAtFirstNode(struct Node* ptr_node, NodePositionInfo& node) {
  struct Node* new_node = new Node;
  list_info.AllocationWarningMessage(new_node);
  new_node->prev_node             = ptr_node->prev_node;
  new_node->data                  = node.data;
  new_node->next_node             = ptr_node;
  new_node->prev_node->next_node  = new_node;
  ptr_node->prev_node             = new_node;
  ptr_node                        = new_node;
  std::cout << "Your data " << node.data << " was successfully added at "
            << "Position "  << node.position << ".\n";
  
  return ptr_node;
}

struct Node* InsertNodeManager::InsertNodeAtPosition(struct Node* ptr_node, NodePositionInfo& node) {
  const int POSITION_DECREMENT = 1;
  struct Node* current_node    = ptr_node;
  for (size_t current_position = 0;
        current_position < node.position - POSITION_DECREMENT && current_node->next_node != ptr_node;
       ++current_position)
  {
    current_node = current_node->next_node;
  }
  struct Node* new_node              = new Node;
  list_info.AllocationWarningMessage(new_node);
  new_node->prev_node                = current_node->prev_node;
  new_node->data                     = node.data;
  new_node->next_node                = current_node;
  current_node->prev_node->next_node = new_node;
  current_node->prev_node            = new_node;
  std::cout << "Your data " << node.data  << " was successfully added at "
            << "Position "  << node.position << ".\n";
  
  return ptr_node;
}

struct Node* InsertNodeManager::InsertAtBackNode(struct Node* ptr_node, NodePositionInfo &node) {
  struct Node* new_node          = new Node;
  list_info.AllocationWarningMessage(new_node);
  new_node->prev_node            = ptr_node->prev_node;
  new_node->data                 = node.data;
  new_node->next_node            = ptr_node->prev_node->next_node;
  ptr_node->prev_node->next_node = new_node;
  ptr_node->prev_node            = new_node;
  
  return ptr_node;
}
