

#include"main.h"




int main(){

  Solution *s = new Solution();
  vector<int> nums = Tool::buildVec();
  sort(nums.begin(),nums.end());
  int target;
  cin>>target;
  cout<<s->threeSumClosest(nums,target)<<endl;

  return 0;
}
  

