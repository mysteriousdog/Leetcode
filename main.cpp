

#include"main.h"




int main(){

  vector<int> vec = Tool::buildVec();
  Solution *s = new Solution();
  s->nextPermutation(vec);
  Tool::showVec(vec);
  return 0;
}
  

