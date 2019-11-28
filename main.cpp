

#include"base.h"
#include"struct.h"
#include"class.h"
#include"fun.h"
#include"fun.cpp"




int main(){

  Solution *s = new Solution();
  int nums[9] = {5,7,7,8,8,10};
  vector<int> vec(nums,nums+6);
  int len  = vec.size();
  vec = s->searchRange(vec,10);
  cout<<vec[0]<<vec[1]<<endl;
  

  
}

