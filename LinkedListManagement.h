#ifndef LinkedListManagement_h
#define LinkedListManagement_h
#include "Node.h"
#include "LinkedListInfo.h"
#include "NodePositionInfo.h"

class LinkedListManagement {
  public:
    LinkedListManagement();
    void InsertNode();
    void DeleteFirstNode(NodePositionInfo& node, int total_nodes);
    void DeleteNodeAtPosition(NodePositionInfo& node, int total_nodes);
    void DeleteNode(NodePositionInfo& node);
    void PrintList(struct Node* ptr_node);
    void PrintMenu();
    void LaunchLinkedListManagement();
    ~LinkedListManagement();

  private:
    Node* root_node;
    LinkedListInfo list_info;
    NodePositionInfo node;
};
