#ifndef LinkedListInfo_h
#define LinkedListInfo_h
#include "Node.h"

class LinkedListInfo {
  public:
    LinkedListInfo                () = default;
    void AllocationWarningMessage (struct Node* current_node);
    bool IsAllocationError        (struct Node* current_node);
    bool IsEmptyList              (struct Node* current_node);
    int GetNumberOfNodes          (struct Node* ptr_node);
};
#endif /* LinkedListInfo_h */
