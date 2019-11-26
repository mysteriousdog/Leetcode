#ifndef _CLASS_H
#define _CLASS_H
#include"base.h"
#include"struct.h"
#include<string>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
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
/*
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
*/


/*********************************************************************************************************************/

/*15. 三数之和
*时间复杂度是n3，太慢了，考虑双指针法
*/
/*
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        
        vector<vector<int> > vec;
        if(nums.size() <3){return vec;}
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for (size_t i = 0; i < len-2; i++)
        {
            int numi = nums[i];
            if(i !=0 && numi == nums[i-1])continue;
            //如果当前的num与前一个num相同，则直接跳过
            for (size_t j = i+1; j < len-1; j++)
            {
                if(j != i+1 && nums[j] == nums[j-1]){continue;}
                for (size_t k = j+1; k < len; k++)
                {
                    if(nums[j] + nums[k] == -numi)
                    {
                        vector<int> v;
                        v.push_back(numi);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        vec.push_back(v);
                        break;
                    }
                    if(nums[j] + nums[i] > -numi){break;}
                }
                
            }
            
        }
        return vec;
        
    }
};
*/
/*********************************************************************************************************************/



/*********************************************************************************************************************/

/*15. 三数之和
*双指针法,时间复杂度n2
*/
/*
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > vec;
        if(nums.size() <3){return vec;}
        sort(nums.begin(),nums.end());
        int len = nums.size(),low,high=len-1;
        for (size_t i = 0; i < len-2; i++)
        {
            int numi = nums[i];
            if(i !=0 && numi == nums[i-1])continue;
            //如果当前的num与前一个num相同，则直接跳过
            low = i+1;
            high = len-1;
            while(low<high){
                if(nums[low] + nums[high] == -numi){
                    vector<int> v;
                    v.push_back(numi);
                    v.push_back(nums[low]);
                    v.push_back(nums[high]);

                    //vec.push_back({numi,nums[low],nums[high]});
                    vec.push_back(v);
                    while(nums[high] == nums[--high] && high > low){}
                }
                else if(nums[low] + nums[high] > -numi){
                    while(nums[high] == nums[--high] && high > low){}
                }
                else{
                    while(nums[low] == nums[++low] && high > low){}
                }

            }
            
        }
        return vec;

    }
};
*/
/*********************************************************************************************************************/

/*6. Z 字形变换*/

class Solution {
public:
    string convert(string s, int numRows) {
        
    }
};

/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/


