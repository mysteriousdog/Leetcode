#include"class_1_10.h"

/************************************************************************************************************************/
/*39. 组合总和1
*递归回溯的方法
*/
/*
vector<vector<int> > Solution::combinationSum(vector<int>& candidates, int target){
    vector<vector<int> > vec;
    int n = candidates.size(),num;
    if(n<=0)return vec;
    for(int i = 0;i<n;i++){
        num = candidates[i];
        if(target - num >=0){
            vector<int> v;
            v.push_back(num);
            sol(vec,candidates,v,target-num,n,i);
        }
    }
    return vec;
}
void Solution::sol(vector<vector<int> >& vec ,vector<int>& candidates,vector<int>& v,int target,int n,int s){
    if(target == 0){
        vec.push_back(v);
        return;
    }
    if(target < 0)return;
    int num;
    for(int i =s;i<n;i++){
        num = candidates[i];
        if(target - num >=0){
            vector<int> vv(v);
            vv.push_back(num);
            sol(vec,candidates,vv,target-num,n,i);
        }
    }
}
*/
/************************************************************************************************************************/
/*82. 删除排序链表中的重复元素 II2
*设置一个头节点，每一次保留前节点进行遍历，删除重复节点
*遇到不重复的节点就双节点下移
*遇到重复的节点就后节点下移知道重复，进行删除操作
*循环往复
*/
/*
ListNode* Solution::deleteDuplicates(ListNode* head){
    if(head == NULL)return head;
    ListNode* pre = new ListNode(-1),*c = pre,*q;
    int flag = 0;
    pre->next = head;
    while(head){
        q = head->next;
        if(q == NULL || q->val != head->val){
            if(!flag){
                pre = head;
                head = q;
            }
            else{
                flag = 0;
                head = q;
                pre->next = head;
            }
            
        }
        else{
            head = q;
            flag = 1;
        }
    }
    return c->next;

}
*/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
