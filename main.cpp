

#include"main.h"




int main(){

vector<int> nums = Tool::buildVec();
Tool::showVec(nums);
Solution *s = new Solution();
s->sortColors(nums);
Tool::showVec(nums);
}
  
