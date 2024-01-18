#ifndef InsertNodeManager_h
#define InsertNodeManager_h
#include "Node.h"
#include "LinkedListInfo.h"
#include "NodePositionInfo.h"

class InsertNodeManager {
  public:
    InsertNodeManager                 () = default;
    struct Node* InsertRootNode       (struct Node* ptr_node, NodePositionInfo& node);
    struct Node* InsertAtFirstNode    (struct Node* ptr_node, NodePositionInfo& node);
    struct Node* InsertBetweenNodes   (struct Node* ptr_node, NodePositionInfo& node);
    struct Node* InsertAtBackNode     (struct Node* ptr_node, NodePositionInfo& node);
    struct Node* InsertNode           (struct Node* ptr_node, NodePositionInfo& node);
  
  private:
    LinkedListInfo list_info;
};
#endif /* InsertNodeManager_h */
