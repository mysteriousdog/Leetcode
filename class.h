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
#include<queue>
#include<set>

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
/*
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length(),slen = numRows*2-2;
        char *cs = new char[len];
        //char *cs = (char*)malloc(sizeof(char)*len);
        for (size_t i = 0; i < len;)
        {
            cout<<"istart-->"<<i<<endl;
            cs[i] = s[i];
            cout<<"char-->"<<cs[i]<<endl;
            int j = i+1,send = i + slen-1,jlen = send+1;
            cout<<"send-->"<<send<<endl;
            
            i++;
            if (jlen > len)
            {
                jlen = len;
            }cout<<"jlen-->"<<jlen<<endl;
            
            for(;j<jlen;j++){
                cs[j] = s[i++];
                cout<<"char-->"<<cs[j]<<endl;
                if(send < jlen && j+1 < jlen){
                    cs[++j] = s[send--];
                    cout<<"char-->"<<cs[j]<<endl;
                }
            }
            cs[j] = s[i++];
            //i = j;
            i++;
            cout<<"iend--->"<<i<<endl;
        }
        int k = 0;
        for (size_t i = 0; i < slen; i++)
        {
            for(int j = i;j<len;j+=slen){
                s[k++] = cs[j];
            }
        }
        return s;
        
    }
        
};
*/

/*********************************************************************************************************************/
/*22. 括号生成*/
/*
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> s;
        set<string>::iterator it;
        vector<vector<string>> vec;
        vector<string> v;
        if(n<1){return v;}
        v.push_back("()");
        if(n == 1){return v;}
        vec.push_back(v);
        for(int i = 1;i<n;i++){
            s.clear();
            vector<string> vv;
           // cout<<vec.size()<<endl;
            s = genone(vec[i-1],s);
           // showSet(s);
            int b = 2,m = i-b + 1;
            while(m >= b){
                s = gentwo(vec[m-1],vec[b-1],s);
            //    showSet(s);
                b++;
                m--;
            }
            for(it = s.begin();it != s.end();it++){
                vv.push_back(*it);
            }
            vec.push_back(vv);
        }

        return vec[n-1];
        
    }
    set<string> gentwo(vector<string> v1 , vector<string> v2,set<string> s){
        for (size_t i = 0; i < v1.size(); i++)
        {
            for(int j = 0;j<v2.size();j++){
                string sv1 = v1[i],sv2 = v2[j];
                string sl = sv2 + sv1,sr = sv1 + sv2;
                s.insert(sl);
                s.insert(sr);

            }
        }
        return s;
        
        
    }
    set<string> genone(vector<string> v1,set<string> s){
       // cout<<"vone--->"<<v1.size()<<endl;
        for (size_t i = 0; i < v1.size(); i++)
        {
            string sv = v1[i];
            string sl = "()" + sv;
            string sr = sv + "()";
            string sw = "(" + sv + ")";
            s.insert(sw);
            s.insert(sl);
            if(sl != sr)s.insert(sr);
        }
       // cout<<"sone--->"<<s.size()<<endl;
        return s;
        
    }
    void showSet(set<string> s){
        set<string>::iterator it;
        int slen = s.size();
        cout<<"slen--->"<<slen<<endl;
        for(it = s.begin();it!=s.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
};
*/
/*********************************************************************************************************************/
/*24. 两两交换链表中的节点*/
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p1=head,*p2 = head,*p;
        ListNode* p0 = new ListNode(-1);
        p0->next = p1;
        if(head == NULL || head->next == NULL){return head;}
        p2 = head->next;
        head = p0;
        while(p2 != NULL){
            swapNode(p0,p1,p2);
            p = p1;
            p1 = p2;
            p2 = p;
            if(p2->next != NULL && p2->next->next != NULL){
                p2 = p2->next->next;
                p1 = p1->next->next;
                p0 = p0->next->next;
            }
            else{
                return head->next;
            }
        }
        return head->next;
    }
    void showList(ListNode* head){
        while(head!=NULL){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    void swapNode(ListNode* p0,ListNode* p1,ListNode *p2){
        p0->next = p2;
        p1->next = p2->next;
        p2->next = p1;
    }
};

*/
/*********************************************************************************************************************/
/*11. 盛最多水的容器
*时间复杂度太高，可以使用双指针法来进行优化
*/
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size(),max = height[1] < height[0] ? height[1]:height[0];
        for (size_t i = 0; i < len - 1; i++)
        {
            for(int j = i+1;j<len;j++){
                int real_hight,sum;
                real_hight = height[j] < height[i] ? height[j]:height[i];
                sum = real_hight * (j-i);
                if(sum > max){max = sum;}
            }
        }
        return max;
        
    }
};
*/
/*双指针法的优化，因为两边的高度只取决于最低的那个，设置双指针在头尾，所以在进行更新的时候只能够将短的那个指针向内推移
*这样才有可能得到更高的height，才嫩有可能突破原来的限制，质疑重复这个操作就可以计算max的值。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        
    }
};
/*********************************************************************************************************************/

/*********************************************************************************************************************/