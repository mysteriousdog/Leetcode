#include"fun.h"




/*********************************************************************************************************************/

int findMaxInNums(int* nums,int numsSize){
    if(numsSize <= 0)return -1;
    int max = *nums,maxIndex = 0;
    for(int i =0;i < numsSize;i++){
        if(nums[i] > max){
            max = nums[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}
/*654. 最大二叉树*/
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    if(numsSize <= 0)return NULL;
    struct TreeNode* head = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int maxIndex = findMaxInNums(nums,numsSize);
    int *maxPointer = nums+maxIndex;
    head->val = *maxPointer;
    head->left = constructMaximumBinaryTree(nums,maxIndex);
    if (maxIndex >= numsSize-1)
    {
        head->right = NULL;
    }
    else{
        head->right = constructMaximumBinaryTree(maxPointer+1,numsSize-maxIndex-1);
    }
    return head;
}

void showTree(struct TreeNode* head){
    if (head->left != NULL)
    {
        showTree(head->left);
    }
    printf("%d  ",head->val);
    if(head->right != NULL){
        showTree(head->right);
    }
    
}

bool myCmp(vector<int> v1,vector<int> v2){
    if(v1[0] > v2[0])return true;
    if(v1[0] < v2[0])return false;
    return v1[1] >= v2[1];
}
/*********************************************************************************************************************/



/*********************************************************************************************************************/
