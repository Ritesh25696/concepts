You are at the side of a river. You are given a m litre jug and a n litre jug where 0 < m < n. Both the jugs are initially empty. The jugs don’t have markings to allow measuring smaller quantities. You have to use the jugs to measure d litres of water where d < n. Determine the minimum no of operations to be performed to obtain d litres of water in one of jug.
The operations you can perform are:

Empty a Jug
Fill a Jug
Pour water from one jug to the other until one of the jugs is either empty or full.
Input:
First line consists of T test cases. Only line of every test case consists of 3 spaced integers denoting m , n, and d respectively. 

Output:
Single line output, print the minimum number of operations.

Constraints:
1<=T<=100
1<=N,D<=100
1<=M<=N

Example:
Input:
2
8 56 46
3 5 4
Output:
-1
6

************************************************************************************************************************************

#include<iostream>
using namespace std;

int gcd(int a , int b){
    if(b == 0)return a;
    gcd(b , a%b);
}

int pour(int fromcap , int tocap , int d){
    int from = fromcap;
    int to = 0;
    int step = 1;
    while(from != d && to != d){
        int temp = min(from , tocap-to);
        to += temp;
        from -= temp;
        step++;
        if(from == d || to == d)return step;
        if(from == 0){
            from = fromcap;
            step++;
        }
        if(to == tocap){
            step++;
            to = 0;
        }
    }
    return step;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int m , n , d;
	    cin>>m>>n>>d;
	    if(m>n)swap(m,n);
	    if(d>n){
	        cout<<-1<<endl;
	        continue;
	    }
	    if(d%(gcd(n,m)) != 0){
	        cout<<-1<<endl;
	        continue;
	    }
	    cout<<min(pour(n,m,d),pour(m,n,d))<<endl;
	}
	return 0;
}
