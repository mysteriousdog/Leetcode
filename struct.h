
#ifndef _STRUCT_H
#define _STRUCT_H
#include"base.h"
typedef struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  }treenode;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x) {
        val =x;
        next = NULL;
    }
};
#endif


