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
