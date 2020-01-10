#ifndef _CLASS_0_10_H
#define _CLASS_0_10_H
#include"../base.h"
#include"../struct.h"
#include"../fun.h"
#include<string>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include"../toolclass.h"




/************************************************************************************************************************/
/*61. 旋转链表1*/
/*
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k);
};
*/
/************************************************************************************************************************/
/*215. 数组中的第K个最大元素2
*写一下c++版本的堆排序，找第k个最大的元素，大根对，重复k次，返回即可
*/
/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k);
    void buildHeap(vector<int>& nums);
    int getTopK(vector<int>& nums, int k);
    void sortHeap(vector<int>& nums,int i,int n);
    void mySort(vector<int>& nums,int n);
    void showVec(vector<int>& nums);
};
*/
/************************************************************************************************************************/
/*92. 反转链表 II3
*在一次遍历需要完成反转，首先记录反转的开始节点，使用两个基点存储前后节点，一边遍历一边直接反转
最后改变前后介入的节点，时间复杂度O(n)
*/
/*
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n);
};
*/
/************************************************************************************************************************/
/*64. 最小路径和4
*DP
*/
/*
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid);
};
*/
/************************************************************************************************************************/
/*31. 下一个排列5
*执行一遍遍历，找出违反升序的最后一个index，将其与前者交换
若无违反升序，反转即可
*/
/*
class Solution {
public:
    void nextPermutation(vector<int>& nums);
};
*/
/************************************************************************************************************************/
/*16. 最接近的三数之和6
*使用双指针法，同时遍历数组，时间复杂度为O(n2)
*/
/*
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target);
    int twoPoint(vector<int>& nums,int target,int low, int high);
};
*/
/************************************************************************************************************************/
/*98. 验证二叉搜索树7
使用递归的逻辑，首先判断下一层是否符合
若不符合直接返回失败
若是符合递归判断下层节点是否符合
*/
/*
class Solution {
public:
    bool isValidBST(TreeNode* root);
    bool judge(TreeNode* root, int &min,int &max);
};
*/

/*尝试使用中序遍历*/
/*
class Solution {
public:
    bool isValidBST(TreeNode* root);
    int midBl(TreeNode* root,bool &flag,int &max);
};
*/

/************************************************************************************************************************/
/*78. 子集8
*DP的思想
*/
/*
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums);
    vector<vector<int> > com(vector<int>& nums,int index,int n);
};
*/
/************************************************************************************************************************/
/*94. 二叉树的中序遍历9
*递归
*/
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root);
    void dg(vector<int>& nums,TreeNode* root);
};
*/
/************************************************************************************************************************/
/*56. 合并区间 10
*首先实现vector<vector<int> > 中的排序，重写sort算法
*排序完成以后进行遍历合并
*/
/*
class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals);
};
*/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/




#endif


