

#include"base.h"
#include"struct.h"
#include"class.h"
#include"fun.h"
#include"fun.cpp"




int main(){

  Solution *s = new Solution();
  vector<string> v = s->generateParenthesis(4);
  for (size_t i = 0; i < v.size(); i++)
  {
    cout<<v[i]<<endl;
  }
  
}
