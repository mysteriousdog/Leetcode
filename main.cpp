

#include"main.h"




int main(){
  int k[] = {3,2,1,5,6,4};
  vector<int> nums(k,k+6);
  Solution *s = new Solution();
  cout<<s->findKthLargest(nums,6)<<endl;

  return 0;
}
  

