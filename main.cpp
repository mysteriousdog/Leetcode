

#include"base.h"
#include"struct.h"
#include"class.h"
#include"fun.h"
#include"fun.cpp"




int main(){

    Solution *s = new Solution();
    vector<int> vec;
    vec.push_back(-1);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(-1);
    vec.push_back(-4);
    vec.push_back(5);
    vec.push_back(-2);
    vec.push_back(1);
    //-4 -2 -1 -1 0 1 1 2 5 
    vector<vector<int> >  v= s->threeSum(vec);
    cout<<v.size()<<endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        vec = v[i];
        
        for (size_t j = 0; j < vec.size(); j++)
        {
            
            cout<<vec[j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
