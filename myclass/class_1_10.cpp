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
/*120. 三角形最小路径和3
*DP的思想，遍历一遍
*事件O(n),空间0
*/
/*
int Solution::minimumTotal(vector<vector<int> >& triangle){
    int n = triangle.size(),sum = 0,m,min;
    if(n<1)return 0;
    sum += triangle[0][0];
    for(int i =1;i<n;i++){
        triangle[i][0] += triangle[i-1][0];
        for(int j =1;j<i;j++){
            min = triangle[i-1][j-1] <= triangle[i-1][j] ? triangle[i-1][j-1]:triangle[i-1][j];
            triangle[i][j] += min;
        }
        triangle[i][i] += triangle[i-1][i-1];
    }
    min = triangle[n-1][0];
    for(int i =0;i<n;i++){
        if(triangle[n-1][i] < min)min = triangle[n-1][i];
    }
    return min;

}
*/
/************************************************************************************************************************/
/*200. 岛屿数量4
*遍历，主要思想为对于陆地需要判断上左的相连性
*项链的话改为相同的类型，不项链的话新建类型，
*最后倒出新建的类型数量
*/
/*
int Solution::numIslands(vector<vector<char> >& grid){
    int res = 100;
    int m = grid.size(),n = grid[0].size();
    for(int i =0;i<grid.size();i++){
        for(int j =0;j<grid[i].size();j++){
            char cc = grid[i][j];
            if(grid[i][j] == '1'){
                extend(grid,i,j,n,m,res++);
            }
        }
    }
    return res-100;
}

void Solution::extend(vector<vector<char> >& grid,int x,int y,int n,int m,int res){
    grid[x][y] = res;
    if(x-1>=0 && grid[x-1][y]== '1'){extend(grid,x-1,y,n,m,res);}
    if(y+1<n && grid[x][y+1] == '1'){extend(grid,x,y+1,n,m,res);}
    if(x+1 < m && grid[x+1][y] == '1'){extend(grid,x+1,y,n,m,res);}
    if(y-1 >=0 && grid[x][y-1] == '1'){extend(grid,x,y-1,n,m,res);}
}
*/
/************************************************************************************************************************/
/*75. 颜色分类5
*双指针法，酱0，2分别置于两边
*排序的结果效率不高，主要体现在对于1的处理不高效，需要进行优化
*/
/*
void Solution::sortColors(vector<int>& nums){
    int n = nums.size(),low = 0,high = n-1;
    while(high > low){
        int lnum,hnum,k;
        lnum = nums[low];
        hnum = nums[high];
        if(lnum == hnum){
            switch(lnum){
                case 0:
                low++;
                break;
                case 1:
                    k = low;
                    while(high > low){
                    low++;
                    if(nums[low]==1)continue;
                    int p = nums[low];
                    nums[low] = 1;
                    nums[k] = p;
                    low = k;
                    break;
                    }
                break;
                case 2:
                high--;
                break;
                default:
                break;
            }
        }
        else if(hnum > lnum){
            if(hnum == 2){high--;}
            else{low++;}
        }
        else{
            int p = hnum;
            nums[high] = nums[low];
            nums[low] = p;
        }
    }

}
*/

/************************************************************************************************************************/
/************************************************************************************************************************/
