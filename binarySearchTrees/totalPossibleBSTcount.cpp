/*

The problem is to calculate the number of unique BST.
To do so, we need to define two functions: 

1.G(n): the number of unique BST for a 
  sequence of length n.
2.F(i, n), 1 <= i <= n: The number of unique 
 BST, where the number i is the root of BST, 
 and the sequence ranges from 1 to n. As one can 
 see, G(n) is the actual function we need to calculate 
 in order to solve the problem. And G(n) can be derived
 from F(i, n), which at the end, would recursively refer 
 to G(n).
First of all, given the above definitions, we can see 
that the total number of unique BST G(n), is the sum of 
BST F(i) using each number i as a root. i.e.,
G(n) = F(1, n) + F(2, n) + ... + F(n, n).
Given a sequence 1…n, we pick a number i out of the 
sequence as the root, then the number of 
unique BST with the specified root F(i), is the 
cartesian product of the number of BST for 
its left and right subtrees.For example, F(2, 4): 
the number of unique BST tree with number 2 
as its root. To construct an unique BST out of the 
entire sequence [1, 2, 3, 4] with 2 as the 
root, which is to say, we need to construct an unique 
BST out of its left subsequence [1] and another BST out 
of the right subsequence [3,4], and then combine them 
together (i.e. cartesian 
product). F(i, n) = G(i-1) * G(n-i)    1 <= i <= n 
Combining the above two formulas, we obtain the 
recursive formula for G(n). i.e.

G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0) 




*/


#include <iostream>
using namespace std;

int uniqueBSTs(int n)
{
    int dparray[n+1]={0};
    dparray[0]=dparray[1]=1;
    
    for(int i=2;i<=n;++i)
    {
        for(int k=1;k<=i;++k)
        {
            dparray[i]+=dparray[k-1]*dparray[i-k];
        }
    }
    return dparray[n];
}

int main()
{
    int n=9;
    cout<<uniqueBSTs(n);
    return 0;
}




