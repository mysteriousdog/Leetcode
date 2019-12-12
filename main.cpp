

#include"base.h"
#include"struct.h"
#include"class.h"
#include"fun.h"
#include"fun.cpp"




int main(){


  
  Solution *s = new Solution();
  int a[] = {1,2,3,4};
  int b[] = {5,6,7,8};
  int c[] = {9,10,11,12};
  vector<int> vec1(a,a+4);
  vector<int> vec2(b,b+4);
  vector<int> vec3(c,c+4);
  vector<vector<int> > matrix;
  matrix.push_back(vec1);
  matrix.push_back(vec2);
  matrix.push_back(vec3);
  vector<int> vec = s->spiralOrder(matrix);

  for(int i =0;i<vec.size();i++){
    cout<<vec[i]<<endl;
  }
  
}
  

