#ifndef LinkedListManagement_h
#define LinkedListManagement_h
#include "InsertNodeManager.h"
#include "DeleteNodeManager.h"
#include "RequestManager.h"

class LinkedListManagement {
  public:
    LinkedListManagement();
    void InsertNode();
    void DeleteNode();
    void PrintList();
    void PrintMenu();
    void LaunchLinkedListManagement();
    ~LinkedListManagement();
  
  private:
    Node* root_node;
    InsertNodeManager insert;
    DeleteNodeManager remove;
    RequestManager request; 
    LinkedListInfo list_info;
    NodePositionInfo node;
};
#endif /* LinkedListManagement_h */
