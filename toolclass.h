#ifndef toolclass_H
#define toolclass_H

#include"base.h"
#include"struct.h"

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
};

#endif