#ifndef _CLASS_H
#define _CLASS_H
#include"base.h"
#include"struct.h"
#include<string>
#include<stack>
#include<vector>
#include<string>
#include<map>


#endif
/*********************************************************************************************************************/
/*19. 删除链表的倒数第N个节点*/
/*
class Solution_19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0;
        ListNode* p1 = head,*p2 = head;
        while(p1->next != NULL){
            if(i++ >= n){
                p2 = p2->next;
            }
            p1 = p1->next;
        }
        if( i == n-1){
            p2 = head->next;
            free(head);
            return p2;
        }
        else if(i < n-1){return head;}
        else{
            p1 = p2->next;
            p2->next = p1->next;
            free(p1);
            return head;
        }
    }
    void showList(ListNode* head){
        while(head != NULL){
            printf("%d ",head->val);
            head = head->next;
        }
        printf("\n");
    }
    ListNode* initList(int* nums,int size){
        
        ListNode* head = (ListNode*)malloc(sizeof(ListNode)),*p,*c = head,*q;
        for (size_t i = 0; i < size; i++)
        {
            head->val = nums[i];
            p = (ListNode*)malloc(sizeof(ListNode));
            p->next = NULL;
            head->next = p;
            q = head;
            head = p; 
        }
        q->next = NULL;
        return c;
    }
};
*/
/*********************************************************************************************************************/
/*8. atoi*/
/*
class Solution_8 {
public:
    int myAtoi(std::string str) {
        int len = str.length();
        int i =0,flag = 1;
        long long sum = 0,numsize = 1;
        for (; i < len; i++)
        {
            // 遍历直到找到非空字符
            if(!isspace(str[i])){break;}
        }
        if (i == len)
        {
            // 字符串全为空白字符 
            return 0;
        }
        if(str[i] == '-'){flag = -1;i++;}
        else if(str[i] == '+'){i++;}
        while(str[i] == '0'){i++;}
        std::stack<int> s;
        while(str[i] >= '0' && str[i] <= '9'){
            s.push(str[i++] - '0');
        }
        i = 0;
        while(!s.empty()){
            if(i++ > 10){
                if(flag == 1)return INT_MAX;
                else{return INT_MIN;}
            }
            sum += numsize * s.top();
            s.pop();
            numsize *= 10;
        }
        sum = sum * flag;
        if(sum > INT_MAX){return INT_MAX;}
        if(sum < INT_MIN){return INT_MIN;}
        return (int)sum;
        
        
    }
};
*/
/*********************************************************************************************************************/
/*17. 电话号码的字母组合*/

class Solution {

private:
    string nmap[10];
    

public:
    Solution(){
        nmap[0] = "";
        nmap[1] = "";
        nmap[2] = "abc";
        nmap[3] = "def";
        nmap[4] = "ghi";
        nmap[5] = "jkl";
        nmap[6] = "mno";
        nmap[7] = "pqrs";
        nmap[8] = "tuv";
        nmap[9] = "wxyz";
    }
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        
        
        vector<string> newvec;
        if(len <= 0){return newvec;}
        string s = nmap[digits[0] - '0'];
        if(len == 1){
            //cout<<"s-len-->"<<s.length()<<endl;
            for (size_t i = 0; i < s.length(); i++)
            {
                //cout<<string(1,s[i])<<endl;
                newvec.push_back(string(1,s[i]));
                
            }
            return newvec;

        }
        // len > 1
        vector<string> oldvec =  letterCombinations(digits.substr(1));
        
        for (size_t i = 0; i < s.length(); i++)
        {
            string ss = string(1,s[i]);
           for(int j =0;j<oldvec.size();j++){
               newvec.push_back(ss + oldvec[j]);
           }
        }
        return newvec;
        
    }
    void showVec(vector<string> vec){
        for(int i =0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
};

/*********************************************************************************************************************/

/*********************************************************************************************************************/

/*********************************************************************************************************************/


