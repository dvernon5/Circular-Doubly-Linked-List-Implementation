#ifndef DeleteNodeManager_h
#define DeleteNodeManager_h
#include "Node.h"
#include "LinkedListInfo.h"
#include "NodePositionInfo.h"

class DeleteNodeManager {
  public:
    DeleteNodeManager            () = default;
    struct Node* DeleteFirstNode (struct Node* current_node, NodePositionInfo& node, int total_nodes);
    void DeleteBetweenNodes      (struct Node* current_node, NodePositionInfo& node);
    void DeleteBackNode          (struct Node* current_node, NodePositionInfo& node);
    struct Node* DeleteNode      (struct Node* current_node, NodePositionInfo& node);
  
  private:
    LinkedListInfo list_info;
};
#endif /* DeleteNodeManager_h */
