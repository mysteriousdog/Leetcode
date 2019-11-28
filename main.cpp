

#include"base.h"
#include"struct.h"
#include"class.h"
#include"fun.h"
#include"fun.cpp"




int main(){

  Solution *s = new Solution();
  int nums[9] = {1,8,6,2,5,4,8,3,7};
  vector<int> vec(nums,nums+9);

  int max = s->maxArea(vec);
  cout<<max<<endl;
  

  
}
