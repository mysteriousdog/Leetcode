#ifndef toolclass_H
#define toolclass_H

#include"base.h"
#include"struct.h"
#include<queue>

class Tool{
    public:
    static void showList(ListNode* head){
        cout<<"now output the val of list: "<<endl;
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    static ListNode* buildList(){
        cout<<"input the length of the list: "<<endl;
        int n;
        cin>>n;
        ListNode *head = new ListNode(-1),*c = head,*p;
        int val;
        cout<<"input the value of list: "<<endl;
        for(int i = 0;i<n;i++){
            cin>>val;
            p = new ListNode(val);
            head->next = p;
            head = p;
        }
        return c->next;
    }
    static vector<int> buildVec(){
        cout<<"input the len of the vec: "<<endl;
        int n,val;
        cin>>n;
        vector<int> vec;
        cout<<"now input the value of the vec: "<<endl;
        for(int i =0;i<n;i++){
            cin>>val;
            vec.push_back(val);
        }
        return vec;
    }
    static void showVec(vector<int> vec){
        for(int i = 0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    static TreeNode* buildTree(){
        int num;
        cout<<"input 233 means null node."<<endl;
        cin>>num;
        if(num == 233){
            return NULL;
        }
        TreeNode *root = new TreeNode(num);
        root->left = buildTree();
        root->right = buildTree();
        return root;

    }
};

#endif