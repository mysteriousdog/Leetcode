#include"class_0_10.h"
/************************************************************************************************************************/
/*61. 旋转链表*1/
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
/*215. 数组中的第K个最大元素*2/
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
/*92. 反转链表 II*3/
/*
ListNode* Solution::reverseBetween(ListNode* head, int m, int n){
    if(m == n)return head;
    ListNode *c = head,*p = head,*q = NULL,*pre,*preq = new ListNode(-1);
    preq->next =c;
    for(int i =1;i<n;i++){
        if(i == m-1){preq = p;}
        if(i == m){pre = p;q = p;q->next = p->next;}
        if(q){p = q->next;}
        else{
            p = p->next;
        }
        if(i >= m){
            q->next = p->next;
            p->next = pre;
            pre = p;
        }
        
    }
    if(preq->next == c){
        preq->next = p;
        return preq->next;
    }
    preq->next = p;
    return c;
}
*/
/************************************************************************************************************************/
/*64. 最小路径和*4/
/*
int Solution::minPathSum(vector<vector<int> >& grid){
    int pathtop,pathleft,len;
    for(int i=0;i<grid.size();i++){
        pathtop = INT_MAX;
        pathleft = INT_MAX;
        for(int j =0;j<grid[i].size();j++){
            if(i == 0 && j == 0)continue;
            if(i > 0){pathtop = grid[i][j] + grid[i-1][j];}
            if(j >0){pathleft = grid[i][j] + grid[i][j-1];}
            grid[i][j] = pathtop>pathleft?pathleft:pathtop;
            pathtop = INT_MAX;
            pathleft = INT_MAX;
        }
    }
    return grid.back().back();
}
*/
/************************************************************************************************************************/
/*31. 下一个排列*5/
/*
void Solution::nextPermutation(vector<int>& nums){
    int n = nums.size(),temp;
    if(n<=1)return;
    int index = -1,index2 = -1;
    for(int i =1;i<n;i++){
        if(nums[i] > nums[i-1]){index = i-1;index2 = i;}
        else if(nums[i] >nums[index] && nums[i] < nums[index2]){index2 = i;}
    }
    if(index !=-1){
        temp = nums[index];
        nums[index] = nums[index2];
        nums[index2] = temp;
        if(nums.end() > nums.begin()+1+index){
            sort(nums.begin()+1+index,nums.end());
        }
    }
    else{
        int i =0;
        n--;
        while(n>i){
            temp = nums[n];
            nums[n] = nums[i];
            nums[i] = temp;
            i++;
            n--;
        }
    }

}
*/
/************************************************************************************************************************/
/*16. 最接近的三数之和6
*进行了在双指针指上的一些优化
双指针的low和high选择可以保证是在index之后的
应为在之前的话会有结果重复
*/
/*
int Solution::threeSumClosest(vector<int>& nums, int target){
    sort(nums.begin(),nums.end());
    int tar2,n = nums.size(),temp,tempsum,sum,max=INT_MAX;
    for(int i =0;i<n-2;i++){
        tar2 = target - nums[i];
            temp = nums[i];
            tempsum = twoPoint(nums,tar2,i+1,n-1);
            cout<<"tempsum"<<tempsum<<endl;
            if(abs(temp + tempsum - target) < max){
                max = abs(temp + tempsum - target);
                sum = temp + tempsum; 
                cout<<"sum"<<sum<<endl;
            }
        }
        return sum;
    }
int Solution::twoPoint(vector<int>& nums,int target,int low, int high){
    int n = nums.size(),max = INT_MAX;
    int sum,result = nums[high] + nums[low];
    while(high > low){
        sum = nums[low] + nums[high];
        if(sum == target){return sum;}
        if(sum >target){
            if(sum -target < max){
                max = sum-target;
                result = sum;
            }
            while((high-1 > low && nums[high] == nums[high-1])){high--;}
            high--;
        }
        else{
            if(target - sum < max){
                max = target - sum;
                result = sum;
            }
            while((low + 1 < high && nums[low] == nums[low + 1])){low++;};
            low++;
        }
    }
    return result;
}
*/
/************************************************************************************************************************/

/************************************************************************************************************************/

/************************************************************************************************************************/

/************************************************************************************************************************/
