

#include"main.h"




int main(){

  int target = 8;
  vector<int> v = Tool::buildVec();
  Solution *s = new Solution();
  vector<vector<int> >vec = s->combinationSum(v,target);
  cout<<"len "<<vec.size()<<endl;
  for(int i =0;i<vec.size();i++){
    Tool::showVec(vec[i]);
  }
  return 0;
}
  
