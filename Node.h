#ifndef Node_h
#define Node_h
struct Node {
  struct Node* prev_node;
  int data;
  struct Node* next_node;
};
#endif /* Node_h */
