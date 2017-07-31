Print out maximum AP length: Micosoft  quetion
AP may not be contigous

*************************************************************

#include <iostream>
#include <vector>
using namespace std;

int maxAP(vector<int> &A){
    int maxc = 0;
   for(int i=0 ; i<A.size()-2 ; i++){
    for(int j=i+1 ; j<A.size()-1 ; j++){
        int c = 2;
        int d = A[j]-A[i];
        for(int k = j+1; k<A.size() ; k++){
            if(A[k] - A[j] == d) {c++; d += A[j]-A[i];}
                else if(A[k] - A[j] > d)break;
        }
   if(c > maxc)maxc = c;
    }
   }
    return maxc;
}

int main()
{
    vector<int> A = {2,5,10,12,15,17,19,20,25,30};
    cout<<maxAP(A);
    return 0;
}
