LCS

***********************************************************

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> A = {10 ,22, 9, 33 ,21, 50 ,41, 60, 80};
    vector<int> lcs(A.size(),1);
    int gmax = 0;
    for(int i=1 ; i<A.size() ; i++){
        for(int j=0 ; j<i ; j++){
            if(A[i]>A[j] ){
             lcs[i] = max(lcs[i],lcs[j]+1);
             gmax = max(lcs[i],gmax);
            }
        }
    }
cout<<gmax;
return 0;
}
