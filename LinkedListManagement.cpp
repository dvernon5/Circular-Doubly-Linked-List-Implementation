#include "LinkedListManagement.h"
#include <iostream>

namespace InputValidation {
  void ClearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  int GetValidatedInput(int user_input) {
    while (!(std::cin >> user_input)) {
      std::cout << "Invalid type. Please enter a number.\n";
      ClearInputBuffer();
    }
    ClearInputBuffer();
    return user_input;
  }
} using namespace InputValidation;

LinkedListManagement::LinkedListManagement() {
  root_node = nullptr;
}

LinkedListManagement::~LinkedListManagement() {
  if (list_info.IsEmpty(root_node)) {
    std::cout << "List is empty.";
    return;
  }
  struct Node* current_node = root_node->prev_node;
  while (current_node != root_node) {
    struct Node* temp_ptr = current_node;
    current_node = current_node->prev_node;
    delete temp_ptr;
  }
  delete root_node;
  root_node = nullptr;
}

void LinkedListManagement::InsertNode() {
  root_node = insert.InsertNode(root_node, node);
}

void LinkedListManagement::DeleteFirstNode(NodePositionInfo& node, int total_nodes) {
  const int A_SINGLE_NODE = 1;
  /* Case: There is only root node just delete it. */
  if (total_nodes == A_SINGLE_NODE) {
    delete root_node;
    root_node = nullptr;
  } else {
    /* Case: There is more than one node. Must move root node to next node and manipulate links. */
    struct Node* temp_ptr          = root_node;
    root_node                      = root_node->next_node;
    root_node->prev_node           = temp_ptr->prev_node;
    temp_ptr->prev_node->next_node = root_node;
    node.data                      = temp_ptr->data;
    delete temp_ptr;
    temp_ptr = nullptr;
  }
  std::cout << "Your data " << node.data << " was successfully deleted.\n";
}

void LinkedListManagement::DeleteNodeAtPosition(NodePositionInfo& node, int total_nodes) {
  /* Case: Delete a Node at specific position. */
  struct Node* ptr_node = root_node;
  for (int current_node = 0; current_node < node.position - 1; ++current_node) {
    ptr_node = ptr_node->next_node;
  }
  ptr_node->prev_node->next_node = ptr_node->next_node;
  ptr_node->next_node->prev_node = ptr_node->prev_node;
  node.data                      = ptr_node->data;
  delete ptr_node;
  ptr_node = nullptr;
  std::cout << "Your data " << node.data << " was successfully deleted.\n";
}

void LinkedListManagement::DeleteNode(NodePositionInfo& node) {
  if (list_info.IsEmpty(root_node)) {
    std::cout << "List is empty\n";
    return;
  }
  const int BEGINNING_POSITION = 1;
  int total_nodes = list_info.GetNumberOfNodes(root_node);
  if (node.position == BEGINNING_POSITION) {
    DeleteFirstNode(node, total_nodes);
  } else if (node.position > 1 && node.position <= total_nodes) {
    DeleteNodeAtPosition(node, total_nodes);
  } else {
    std::cout << "Invalid position! Please enter a number between " << BEGINNING_POSITION
              << " and " << total_nodes << "\n";
  }
}

void LinkedListManagement::PrintList(struct Node* ptr_node) {
  if (list_info.IsEmpty(ptr_node)) {
    std::cout << "List is empty.";
    return;
  }
  do {
    std::cout << ptr_node->data << "<-->";
    ptr_node = ptr_node->next_node;
  } while (ptr_node->next_node != root_node);
  std::cout << ptr_node->data << "<-->" << root_node->data << "\n";
}

void LinkedListManagement::PrintMenu() {
  std::cout << "\nWelcome to Linked List Management System.\n";
  std::cout << "1. Insert\n";
  std::cout << "2. Delete\n";
  std::cout << "3. List Nodes\n";
  std::cout << "4. Exit\n";
  std::cout << "Selection >> ";
}

void LinkedListManagement::LaunchLinkedListManagement() {
  int selection{0};
  do {
    PrintMenu();
    selection = GetValidatedInput(selection);
    switch (selection) {
      case 1: {
        std::cout << "\nADD NODE: \n---------\n";
        std::cout << "Enter a number: ";
        node.data = GetValidatedInput(node.data);
        if (root_node != nullptr) {
          int total_nodes = list_info.GetNumberOfNodes(root_node);
          std::cout << "Enter a position between 1 and " << total_nodes + 1 << " to insert node: ";
          node.position   = GetValidatedInput(node.position);
        }
        InsertANode(node);
        break;
      }
      case 2: {
        std::cout << "\nDELETE NODE: \n------------\n";
        int total_nodes = list_info.GetNumberOfNodes(root_node);
        if (total_nodes == 1) {
          // Case: Only one node available. Prompt user to enter 1.
          std::cout << "Please enter the number 1: ";
        } else {
          // Case: Multiple nodes available. Prompt user to enter a number between 1 and total nodes.
          std::cout << "Enter a position between 1 and " << total_nodes << " to delete node: ";
        }
        node.position = GetValidatedInput(node.position);
        DeleteNode(node);
        break;
      }
      case 3:
        std::cout << "\nLIST ALL NODES: \n----------------\n";
        PrintList(root_node);
        break;
      case 4:
        std::cout << "\nThank you... Goodbye!\n";
        break;
      default:
        std::cout << "Invalid selection. Try again\n";
        break;
    }
  } while (selection != 4);
}
