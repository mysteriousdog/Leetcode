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

/*63. 不同路径 II6
*dp
*/
/*
int Solution::uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid){
    int n = obstacleGrid.size(),m = obstacleGrid[0].size();
    if(n<=0 || m<= 0)return 0;
    if(obstacleGrid[0][0] == 1)return 0;
    obstacleGrid[0][0] = 2;
    for(int i = 0;i<n;i++){
        for(int j = 0; j<m;j++){
            long val = obstacleGrid[i][j];
            if(val == 0){
                if(i-1 >=0 && obstacleGrid[i-1][j] != 1){
                    val += obstacleGrid[i-1][j]-1;
                }
                if(j-1 >=0 && obstacleGrid[i][j-1] != 1){
                    val += obstacleGrid[i][j-1]-1;
                }
                if(val == 0){obstacleGrid[i][j] = 1;}
                else{obstacleGrid[i][j] = val+1;}
            }
        }
    }
    return obstacleGrid[n-1][m-1]-1;
}
*/
/************************************************************************************************************************/
/*29. 两数相除7
*使用位运算得到一个临界点，取余迭代操作，知道余数小于除数
*将各个结果相加返回
*/
/*
int Solution::divide(int dividend, int divisor){
    int i,sum = 0,pre,qes,c;
    if(dividend == 0 || divisor ==0)return 0;
    bool flag = (dividend ^ divisor) >= 0;
    if(dividend >0)dividend = -dividend;
    if(divisor>0)divisor = -divisor;
    while(dividend <= divisor){
        i= 1;
        c = dividend;
        while(1){
            cout<<"i--"<<i<<endl;
            pre = dividend,qes = dividend>>1;
            if(pre<=divisor && qes >= divisor){
                i--;
                sum -= 1<<i;
                break;
            }
            i++;
            dividend = qes;
        }
        dividend = c - (divisor<<i);
        cout<<"--"<<i<<"--"<<c<<"--"<<dividend<<"--"<<sum<<endl;

    }
    if(flag){
        cout<<"zheng"<<endl;
        if(sum == INT_MIN)sum = INT_MAX;
        else{
            sum = -sum;
        }
    }
    return sum;
    
}
*/
/************************************************************************************************************************/
/*103. 二叉树的锯齿形层次遍历8
交替使用队列与栈的思想进行数据罗列
*/
/*
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root){
    vector<vector<int> > vec;
    if(!root)return vec;
    queue<TreeNode*> q;
    stack<TreeNode*> s;
    q.push(root);
    while(!q.empty() || !s.empty()){
        vector<int> v;
        if(!q.empty()){
            while(!q.empty()){
                v.push_back(q.front()->val);
                if(q.front()->left)
                s.push(q.front()->left);
                if(q.front()->right)
                s.push(q.front()->right);
                q.pop();
            }
            vec.push_back(v);
        }
        else{
            while(!s.empty()){
                v.push_back(s.top()->val);
                if(s.top()->left)
                q.push(s.top()->left);
                if(s.top()->right)
                q.push(s.top()->right);
                s.pop();
            }
        }
    }
}
*/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
