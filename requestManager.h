#ifndef RequestManager_h
#define RequestManager_h
#include "Node.h"
#include "NodePositionInfo.h"
#include "LinkedListInfo.h"

class RequestManager {
  public:
    int GetValidatedUserInput(int user_input);
    struct NodePositionInfo InsertRequest (struct Node* root_node);
    struct NodePositionInfo DeleteRequest (struct Node* root_node);
  
  private:
    NodePositionInfo node;
    LinkedListInfo list_info;
};
#endif /* RequestManager_h */
