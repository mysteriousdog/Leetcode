

#include"base.h"
#include"struct.h"
#include"class.h"
#include"fun.h"
#include"fun.cpp"




int main(){

  Solution *s = new Solution();
  string str = "LEETCODEISHIRING";
  string ss = s->convert(str,4);
  cout<<ss<<endl;
}
