#ifndef LinkedListManagement_h
#define LinkedListManagement_h
#include "Node.h"
#include "LinkedListInfo.h"
#include "NodePositionInfo.h"

class LinkedListManagement {
  public:
    LinkedListManagement();
    void InsertRootNode();
    void InsertAtFirstNode(NodePositionInfo& node);
    void InsertNodeAtPosition(NodePositionInfo& node, int total_nodes);
    void InsertNode(NodePositionInfo& node);
    void PrintList(struct Node* ptr_node);
    void PrintMenu();
    void LaunchLinkedListManagement();

  private:
    Node* root_node;
    LinkedListInfo list_info;
    NodePositionInfo node;
};
