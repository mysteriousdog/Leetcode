

#include"base.h"
#include"struct.h"
#include"class.h"
#include"fun.h"
#include"fun.cpp"




int main(){


  
  Solution *s = new Solution();
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  vector<vector<int> > vec = s->permute(nums);
  for (int i = 0; i < vec.size(); i++)
  {
    vector<int> vv = vec[i];
    for(int j=0;j<vv.size();j++){
      cout<<vv[j]<<"  ";
    }
    cout<<endl;
  }
}
  

