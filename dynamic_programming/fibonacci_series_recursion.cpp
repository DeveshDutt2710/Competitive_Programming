#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<endl;
    cout<<fib(n);
    
    return 0;
}

/*Time Complexity: T(n) = T(n-1) + T(n-2) 

which is exponential.
We can observe that this implementation does a lot of repeated work


Extra Space: O(n) 
if we consider the function call stack size, otherwise O(1)
*/
