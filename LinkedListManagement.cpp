#include "LinkedListManagement.h"
#include <iostream>

LinkedListManagement::LinkedListManagement() {
  root_node = nullptr;
}

LinkedListManagement::~LinkedListManagement() {
  if (list_info.IsEmptyList(root_node)) {
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

void LinkedListManagement::DeleteNode() {
  root_node = remove.DeleteNode(root_node, node);
}

void LinkedListManagement::PrintList() {
  if (list_info.IsEmptyList(root_node)) {
    std::cout << "List is empty.";
    return;
  }
  struct Node* current_node = root_node;
  do {
    std::cout << current_node->data << "<-->";
    current_node = current_node->next_node;
  } while (current_node->next_node != root_node);
  std::cout << current_node->data << "<-->" << root_node->data << "\n";
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
    selection = request.GetValidatedUserInput(selection);
    switch (selection) {
      case 1: {
        node = request.InsertRequest(root_node);
        InsertNode();
        break;
      }
      case 2: {
        node = request.DeleteRequest(root_node);
        DeleteNode();
        break;
      }
      case 3: {
        std::cout << "\nLIST ALL NODES: \n----------------\n";
        PrintList();
        break;
      }
      case 4: {
        std::cout << "\nThank you... Goodbye!\n";
        break;
      }
      default: {
        std::cout << "Invalid selection. Try again\n";
        break;
      }
    }
  } while (selection != 4);
}
