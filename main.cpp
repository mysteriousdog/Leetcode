

#include"main.h"




int main(){

  Solution *s = new Solution();
  vector<int> nums = Tool::buildVec();
  vector<vector<int> > vec = s->subsets(nums);
  for(int i = 0;i<vec.size();i++){
    Tool::showVec(vec[i]);
  }
  return 0;
}
  
