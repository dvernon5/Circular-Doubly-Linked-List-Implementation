#ifndef RequestManager_h
#define RequestManager_h
#include "Node.h"
#include "NodePositionInfo.h"
#include "LinkedListInfo.h"

class RequestManager {
  public:
    struct NodePositionInfo InsertRequest (struct Node* root_node);
    struct NodePositionInfo DeleteRequest (struct Node* root_node);
    int GetValidatedUserInput             (int user_input);
  
  private:
    NodePositionInfo node;
    LinkedListInfo list_info;
};
#endif /* RequestManager_h */
