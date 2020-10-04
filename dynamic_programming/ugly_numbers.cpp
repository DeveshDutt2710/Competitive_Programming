#include <iostream>
using namespace std;

int maxdivide(int a, int b){
    while(a%b==0){
        a=a/b;
    }
    return a;
}

int isUgly(int num){
    num=maxdivide(num,2);
    num=maxdivide(num,3);
    num=maxdivide(num,5);
    
    if(num==1){
        return 1;
    }
    else{
        return 0;
    }
}

int nthUglyNumber(int n){
    int i=1;
    int count=1;
    
    while(n>count){
        i++;
        if(isUgly(i)){
            count++;
        }
    }
    return i;
}

int main(){
    unsigned num=nthUglyNumber(150);
    cout<<"\n 150th ugly number is: "<<num;
    return 0;
}

//time complexity: O(n)
//space complexity: O(1)
