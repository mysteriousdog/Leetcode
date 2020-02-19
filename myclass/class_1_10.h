#ifndef _CLASS_1_10_H
#define _CLASS_1_10_H
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
/*39. 组合总和1
*递归回溯的方法
*/
/*
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target);
    void sol(vector<vector<int> >& vec ,vector<int>& candidates,vector<int>& v,int target,int n,int s);
};
*/
/************************************************************************************************************************/
/*82. 删除排序链表中的重复元素 II2
*设置一个头节点，每一次保留前节点进行遍历，删除重复节点
*遇到不重复的节点就双节点下移
*遇到重复的节点就后节点下移知道重复，进行删除操作
*循环往复,事件O(n),空间O(1)
*/
/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head);
};
*/
/************************************************************************************************************************/
/*120. 三角形最小路径和3
*DP的思想，遍历一遍
*事件O(n),空间0
*/
/*
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle);
};
*/
/************************************************************************************************************************/
/*200. 岛屿数量4
*遍历，主要思想为对于陆地需要判断上左的相连性
*项链的话改为相同的类型，不项链的话新建类型，
*最后倒出新建的类型数量
*/
/*
class Solution {
public:
    int numIslands(vector<vector<char> >& grid);
    void extend(vector<vector<char> >& grid,int x,int y,int n,int m,int res);
};
*/
/************************************************************************************************************************/
/*75. 颜色分类5
*初始化一个常数的为1的数组，
*遍历原数组，统计其中0，2的个数，统计的同时在新建的数组中进行修改
*空间O(1),事件O(1)
*/
/*
class Solution {
public:
    void sortColors(vector<int>& nums);
};
*/
/************************************************************************************************************************/
/*63. 不同路径 II6
*dp
*/
/*
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid);
};
*/
/************************************************************************************************************************/
/*29. 两数相除7
*使用位运算得到一个临界点，取余迭代操作，知道余数小于除数
*将各个结果相加返回
*/
/*
class Solution {
public:
    int divide(int dividend, int divisor);
};
*/
/************************************************************************************************************************/
/*103. 二叉树的锯齿形层次遍历8
*/
/*
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root);
};
*/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/




#endif