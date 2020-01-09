

#include"main.h"




int main(){

  Solution *s = new Solution();
  vector<int> nums1 = Tool::buildVec();
  vector<int> nums2 = Tool::buildVec();
  vector<int> nums3 = Tool::buildVec();
  vector<vector<int> > vec;
  vec.push_back(nums1);
  vec.push_back(nums2);
  vec.push_back(nums3);
  vec = s->merge(vec);
  for(int i = 0;i<vec.size();i++){
    Tool::showVec(vec[i]);
  }
  return 0;
}
  
