

#include"base.h"
#include"struct.h"
#include"class.h"
#include"fun.h"
#include"fun.cpp"




int main(){

  
  Solution *s = new Solution();
  int a[] = {3,1};
  vector<int> vec(a,a+2);
  int n = s->search(vec,1);
  cout<<n<<endl;

}

