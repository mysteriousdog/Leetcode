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
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        auto its = height.begin(),ite = height.end();
        int max = (ite-its)*(*its > *ite ? *ite : *its),sum;
        while(ite > its){
            if( *ite < *its){
                ite--;
            }
            else{
                its++;
            }
            sum = (ite-its)*(*its > *ite ? *ite : *its);
            if(sum >max)max = sum;
        }
        return max;
    }
};
*/
/*********************************************************************************************************************/
/*34. 在排序数组中查找元素的第一个和最后一个位置
*线城市简单的二分查找加上遍历，理论上是log(n) + n
* 并非严格的log(n)
*/
/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1,mid = (low+high)/2;
        while(high >= low){
            mid = (low+high)/2;
            if(nums[mid] == target){return getRange(mid,nums,target);}
            if(nums[mid] > target){high = mid-1;continue;}
            if(nums[mid] < target){low = mid +1;continue;}
        }
        vector<int> vec;
        vec.push_back(-1);
        vec.push_back(-1);
        return vec;

    }
    vector<int> getRange(int index,vector<int> nums,int target){
        int len = nums.size(),low = index-1,high = index +1;
        while(low >=0){
            if(nums[low--] != target){low += 2;break;}
        }
        if(low<0)low = 0;
        while(high < len){
            if(nums[high++] != target){high -= 2;break;}
        }
        if(high >= len)high = len-1;
        vector<int> vec;
        vec.push_back(low);
        vec.push_back(high);
        return vec;

    }
};
*/

/*使用了二分查找来查找左右的边界，优化了时间复杂度，虽然在提交中没有呈现，但是在大数据的情况下效率会有所提升*/

/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>vec;
        int len = nums.size();
        int mid = binarySearch(nums,target,0,len-1),low,high,lmid,hmid,slow,shigh;
        if(mid == -1){
            vec.push_back(-1);
            vec.push_back(-1);
            return vec;
        }
        low = 0;
        high = mid-1;
        while(high >= low){
            lmid = binarySearch(nums,target,low,high);
            if(lmid == -1){slow = high+1;break;}
            high = lmid - 1;
        }
        if(high < low){slow = high +1;}
        vec.push_back(slow);
        //cout<<vec[0]<<endl;
        low = mid +1;
        high = len-1;
        //cout<<"low->"<<low<<"high->"<<high<<endl;
        while(high >= low){
            hmid = binarySearch(nums,target,low,high);
            if(hmid == -1){shigh= low-1;break;}
            low = hmid + 1;
        }
        if(high < low){shigh = low -1;}
        vec.push_back(shigh);
        //cout<<vec[1]<<endl;
        return vec;

    }
    int binarySearch(vector<int> nums,int target,int low,int high){
        int mid,mid_val;
        while(high >= low){
            mid = (low + high)/2;
            mid_val = nums[mid];
            if(mid_val == target){return mid;}
            if(mid_val > target){
                high = mid-1;
                continue;
            }
            low = mid + 1;
            continue;
        }
        return -1;
    }
};
*/

/*********************************************************************************************************************/
/*12. 整数转罗马数字*/
/*
class Solution {
public:
    string intToRoman(int num) {
        int thousand,hundred,ten,dan;
        string str = "";
        thousand = num/1000;
        num = num%1000;
        cout<<thousand<<" "<<num<<endl;
        for(int i =0;i<thousand;i++){
            str += "M";
        }
        hundred = num/100;
        num %= 100;
        if(hundred == 9){str += "CM";}
        else if(hundred >= 5){
            str += "D";
            hundred -= 5;
            for(int j = 0;j<hundred;j++){
                str += "C";
            }
        }
        else if(hundred == 4){str += "CD";}
        else{
            for(int j = 0;j<hundred;j++){
                str += "C";
            }
        }
        ten = num / 10;
        num %= 10;
        if(ten == 9){str += "XC";}
        else if(ten == 4){str += "XL";}
        else if(ten >= 5){
            str += "L";
            ten -= 5;
            for(int j = 0;j<ten;j++){
                str += "X";
            }
        }
        else if(ten <4){
            for(int j = 0;j<ten;j++){
                str += "X";
            }
        }

        if(num < 4){
           for(int j = 0;j<num;j++){
                str += "I";
            } 
        }
        else if(num == 4){str += "IV";}
        else if(num >=5 && num <9){
            str += "V";
            num -= 5;
            for(int j = 0;j<num;j++){
                str += "I";
            } 
        }
        else if(num == 9){
            str += "IX";
        }

        return str;
    }
};

*/

/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*43. 字符串相乘*/
/*

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")return "0";
        int zeros_num = 0;
        vector<string> q;
        string m1,m2,m3;
        for (int i = num1.length()-1; i >=0; i--)
        {
           // cout<<"i--"<<i<<endl;
            q.push_back(mulTow(num2,char(num1[i]),zeros_num++));
        }
        while(!q.empty()){
            if(q.size() == 1){return q.front();}
            m1 = q.back();
            q.pop_back();
            m2 = q.back();
            q.pop_back();
            m3 = addTow(m1,m2);
            //cout<<"m1  "<<m1<<"  m2  "<<m2<<"  m3  "<<m3<<endl;
            q.push_back(m3);
        }
        
    }
    string mulTow(string num1,char num2,int zeros_num){
        if(num1 == "0" || num2 == '0')return "0";
        int rank = 0,m1,m2 = num2 - '0',sum,k;
        string final_num = "";
        for (int i = num1.length()-1; i >=0; i--)
        {
            m1 = num1[i] - '0';
            sum = m1*m2 + rank;
            rank = sum /10;
            sum = sum%10;
            final_num += to_string(sum);
        }
        if(rank != 0){final_num += to_string(rank);}
        final_num = myReverse(final_num);
        for (size_t i = 0; i < zeros_num; i++)
        {
            final_num += "0";
        }
        return final_num;
        

    }
    string addTow(string num1,string num2){
        num1 = myReverse(num1);
        num2 = myReverse(num2);
        string final_num = "";
        int len1 = num1.length(),len2 = num2.length(),len3;
        len3 = len1 > len2? len2:len1;
        int rank = 0,sum,m1,m2,i=0;
        for (; i < len3; i++)
        {
            m1 = num1[i] - '0';
            m2 = num2[i] - '0';
            sum = m1 +m2 +rank;
            rank = sum /10;
            sum = sum %10;
            final_num += to_string(sum);
        }
        if(len1 == len2){
            if (rank == 1)
            {
                final_num += "1";
            }
            
        }

        if(len1 > len2){
            for ( ; i < len1; i++)
            {
                m1 = num1[i] - '0' + rank;
                rank = m1/10;
                m1 %= 10;
                final_num += to_string(m1);
            }
            
        }
        else if(len1 < len2){
            for ( ; i < len2; i++)
            {
                m2 = num2[i] - '0' + rank;
                rank = m2/10;
                m2 %= 10;
                final_num += to_string(m2);
            }
            
        }
        final_num = myReverse(final_num);
        return final_num;
        
        
    }
    string myReverse(string str)
{
	string res("");
	for (int i = str.size() - 1; i >= 0; i--)
	{
		res += str[i];
	}
	return res;
}

};
*/
/*********************************************************************************************************************/
/*33. 搜索旋转排序数组*/
/*
*1：完成基础二分查找代码
*2:如果未翻转直接进行二分查找,判断是否反转需要对首位数字进行比较，首大于尾反转，否则未反转
*3：如果进行了反转，需要根据target所属首尾来进行原数组中最小或者最大值的定位，方便得到两个点
*3.1：利用二分地方法来进行定位查找点
*4：在两个点中规定一个数组进行二分查找找到target
*/
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(),low = 0,high = len-1,mid_point;
        if(len <=0){return -1;}
        if(nums[high] >= nums[low]){return binarySearch(nums,low,high,target);}
        mid_point = searchPoint(nums,low,high);
        if(target >= nums[low]){
            return binarySearch(nums,low,mid_point,target);
        }
        return binarySearch(nums,mid_point+1,high,target);
    }

    int binarySearch(vector<int> nums,int start,int end,int target){
        //基础测试完毕
            int mid,mid_val;
            
            while(end >= start){
                mid = (start + end) / 2;
                mid_val = nums[mid];
                if(mid_val == target){return mid;}
                if(mid_val >target ){
                    end = mid-1;
                    continue;
                }
                start  = mid +1;
            }
            return -1;
}
    int searchPoint(vector<int> nums,int low,int high){
        //基础测试完毕
        int mid,mid_val,min = nums[low];
        while(high>=low){
            mid = (low + high) /2;
            mid_val = nums[mid];
            if(mid_val >= min){low = mid+1;
            if(nums[low] < min){return low-1;}
            continue;}
            if(mid_val < min){high = mid-1;
            if(nums[high] > min){return high;}
            continue;}
        }
        return -1;
    }
};
*/

/*********************************************************************************************************************/
/*46. 全排列
*首先想到的是使用递归来进行全排列，时间复杂度和空间复杂度都比较高
*/
/*
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        auto it = nums.end();
        vector<vector<int> > vec; 
        int m;
        while(!nums.empty()){
            m = nums.back();
            nums.pop_back();
            vector<vector<int> >vv = permute(nums);
            for(int i =0;i<vv.size();i++){
                vv[i].push_back(m);
                vec.push_back(vv[i]);
            }
        }
        return vec;
    }
};
*/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/