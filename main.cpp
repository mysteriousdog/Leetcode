

#include"base.h"
#include"struct.h"
#include"class.h"
#include"fun.h"
#include"fun.cpp"




int main(){


  
  Solution *s = new Solution();
  int n[] = {5,5,3,5,1,-5,1,2};
  vector<int> nums(n,n+8);
  int target = 4;
  vector<vector<int> > vec =  s->fourSum(nums,target);
  for(int i = 0;i<vec.size();i++){
    for(int j = 0;j<vec[i].size();j++){
      cout<<vec[i][j]<<"  ";
    }
    cout<<endl;
  }
  
}
  

