#ifndef LinkedListManagement_h
#define LinkedListManagement_h
#include "Node.h"
#include "LinkedListInfo.h"
#include "NodePositionInfo.h"

class LinkedListManagement {
  public:
    LinkedListManagement();
    void InsertNode();
    void DeleteNode();
    void PrintList(struct Node* ptr_node);
    void PrintMenu();
    void LaunchLinkedListManagement();
    ~LinkedListManagement();

  private:
    Node* root_node;
    LinkedListInfo list_info;
    NodePositionInfo node;
};
