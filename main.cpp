
#include"base.h"
#include"struct.h"
#include"class.h"
#include"fun.h"
#include"fun.cpp"




int main(){

    Solution *s = new Solution();
    vector<string> vec = s->letterCombinations("234"); 
    s->showVec(vec);
    return 0;
}