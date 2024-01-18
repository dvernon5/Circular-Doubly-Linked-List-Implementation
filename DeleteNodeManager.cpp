struct Node* DeleteNodeManager::DeleteFirstNode(struct Node* current_node, NodePositionInfo& node, int total_nodes) {
  const int A_SINGLE_NODE = 1;
  /* Case: There is only root node just delete it. */
  if (total_nodes == A_SINGLE_NODE) {
    delete current_node;
    current_node = nullptr;
  } else {
    /* Case: There is more than one node. Must move root node to next node and manipulate links. */
    struct Node* temp_ptr          = current_node;
    current_node                   = current_node->next_node;
    current_node->prev_node        = temp_ptr->prev_node;
    temp_ptr->prev_node->next_node = current_node;
    node.data                      = temp_ptr->data;
    delete temp_ptr;
    temp_ptr                       = nullptr;
  }
  std::cout << "Your data " << node.data << " was successfully deleted.\n";
  
  return current_node;
}

void DeleteNodeManager::DeleteBetweenNodes(struct Node* current_node, NodePositionInfo& node) {
  /* Case: Delete a Node at specific position. */
  for (int current_position = 0; current_position < node.position - 1; ++current_position) {
    current_node = current_node->next_node;
  }
  current_node->prev_node->next_node = current_node->next_node;
  current_node->next_node->prev_node = current_node->prev_node;
  node.data = current_node->data;
  delete current_node;
  current_node = nullptr;
  std::cout << "Your data " << node.data << " was successfully deleted.\n";
}

void DeleteNodeManager::DeleteBackNode(struct Node *current_node, NodePositionInfo &node) {
  // Case: Delete the last node.
  struct Node* temp_ptr = current_node->prev_node;
  temp_ptr->prev_node->next_node = current_node;
  current_node->prev_node = current_node->prev_node->prev_node;
  delete temp_ptr;
  temp_ptr = nullptr;
  std::cout << "Your data " << node.data << " was successfully deleted.\n";
}
