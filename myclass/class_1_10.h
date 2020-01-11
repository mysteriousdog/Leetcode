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
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/




#endif