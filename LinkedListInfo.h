#ifndef LinkedListInfo_h
#define LinkedListInfo_h
#include "Node.h"
class LinkedListInfo {
  public:
    void AllocationWarningMessage(struct Node* ptr_node);
    bool IsAllocationError(struct Node* ptr_node);
    bool IsEmpty(struct Node* ptr_node);
    int GetNumberOfNodes(struct Node* ptr_node);
  
  private:
    Node* ptr_node;
};
#endif /* LinkedListInfo_h */
