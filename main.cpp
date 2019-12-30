

#include"main.h"




int main(){

  Solution *s = new Solution();
  TreeNode *root = Tool::buildTree();
  cout<<s->isValidBST(root)<<endl;
  return 0;
}
  

