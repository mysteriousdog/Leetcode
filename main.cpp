

#include"base.h"
#include"struct.h"
#include"class.h"
#include"fun.h"
#include"fun.cpp"




int main(){


  
  Solution *s = new Solution();
  TreeNode*root = new TreeNode(3);
  TreeNode*root2 = new TreeNode(9);
  TreeNode*root3 = new TreeNode(20);
  root->left = root2;
  root->right = root3;
  TreeNode*root4 = new TreeNode(15);
  TreeNode*root5 = new TreeNode(7);
  root3->left = root4;
  root3->right = root5;
  vector<vector<int> > vec = s->levelOrder(root);
  cout<<vec.size()<<endl;
  for(int i =0;i<vec.size();i++){
    for(int j = 0;i<vec[i].size();j++){
      cout<<vec[i][j]<<" ";
      getchar();
    }
    cout<<endl;
  }
  
}
  

