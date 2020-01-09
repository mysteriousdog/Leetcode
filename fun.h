
#ifndef _FUN_H
#define _FUN_H
#include"base.h"
#include"struct.h"
void p();
/*654. 最大二叉树*/
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize);
/*19. 删除链表的倒数第N个节点*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

/*比较函数*/
 bool myCmp(vector<int> v1,vector<int> v2);
#endif




