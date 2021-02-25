#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==0){
        return 0;
    }
    int i,a,b,c;
    
    a=0;
    b=1;
    
    for(int i=2;i<=n;i++){
        
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main(){
    int n;
    cin>>n;
    cout<<endl;
    cout<<fib(n);
    
    return 0;
}

//time complexity : O(n)
//space complexity : O(1)