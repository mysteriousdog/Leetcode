#include"class_0_10.h"

/************************************************************************************************************************/
/*61. 旋转链表*/
/*
ListNode* Solution::rotateRight(ListNode* head, int k) {
    if(k == 0)return head;
    ListNode *p = head,*q = head,*c = head,*preq;
    preq = new ListNode(-1);
    preq->next = q;
    int i =1,l=1;
    while(p){
        l++;
        if(i>=k){
            q = q->next;
            preq = preq->next;
        }
        if(p->next == NULL)break;
         p = p->next;
         i++;
    }
    if(l == k)return c;
    if(l > k){
        p->next = c;
        preq->next = NULL;
        return q;
    }
    else{
        k = k%l;
        k = l - k;
        for(int i = 0;i<k;i++){
            q = q->next;
            preq = preq->next;
        }
        p->next = c;
        preq->next = NULL;
        return q;
    }
    
}
*/
/************************************************************************************************************************/
/*215. 数组中的第K个最大元素*/
/*
int Solution::findKthLargest(vector<int>& nums, int k){
    buildHeap(nums);
    return getTopK(nums,k);
}
void Solution::buildHeap(vector<int>& nums){
    int n = nums.size();
    for(int i = 0;i<n;i++){
        sortHeap(nums,i,n);
        showVec(nums);
    }
}
int Solution::getTopK(vector<int>& nums,int k){
    int num;
    for(int i =1;i<k;i++){
        showVec(nums);
        getchar();
        nums[0] = nums.back();
        nums.pop_back();
        mySort(nums,nums.size());
    }
    return nums[0];
}
void Solution::mySort(vector<int>& nums,int n){
    if(n <=1)return;
    int left,right,bigger,temp;
    for(int i = 0;i<n;){
        left = (i+1)*2-1;
        if(left >= n)return;
        right = (i+1)*2;
        if(right <n){
            bigger = nums[left] >= nums[right] ? left:right;
        }
        else{bigger = left;}
        if(nums[bigger] > nums[i]){
            temp = nums[bigger];
            nums[bigger] = nums[i];
            nums[i] = temp;
            i = bigger;
        }
        else{return;}
        
    }
}
void Solution::sortHeap(vector<int>& nums,int i,int n){
    if(i<=0 || nums.empty())return;
    int temp,par;
    if((i+1)%2 == 0){
        par = (i+1)/2-1;
        if(nums[i] > nums[par]){
            temp = nums[par];
            nums[par] = nums[i];
            nums[i] = temp;
            sortHeap(nums,par,n);
        }
    }
    else{
        par = i/2-1;
        if(nums[i] > nums[par]){
            temp = nums[par];
            nums[par] = nums[i];
            nums[i] = temp;
            sortHeap(nums,par,n);
        }
    }

}
void Solution::showVec(vector<int>& nums){
    for(int i = 0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}
*/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
