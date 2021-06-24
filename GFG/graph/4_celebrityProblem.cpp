/*
https://www.geeksforgeeks.org/the-celebrity-problem/

In a party of N people, only one person is known to everyone.
Such a person may be present in the party, 
if yes, (s)he doesn’t know anyone in the party. 
We can only ask questions like “does A know B? “. 
Find the stranger (celebrity) in the minimum number of questions.
We can describe the problem input as an array of numbers/characters 
representing persons in the party. 
We also have a hypothetical function HaveAcquaintance(A, B) 
which returns true if A knows B, false otherwise. How can we solve the problem. 

Examples:  

Input:
MATRIX = { {0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 0, 0, 0},
           {0, 0, 1, 0} }
Output:id = 2
Explanation: The person with ID 2 does not 
know anyone but everyone knows him

Input:
MATRIX = { {0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 1, 0, 0},
           {0, 0, 1, 0} }
Output: No celebrity
Explanation: There is no celebrity.

*/

#include <bits/stdc++.h>
#include <list>

using namespace std;

bool MATRIX[4][4] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};
                    
bool knows(int a, int b)
{
    return MATRIX[a][b];
}

int findCelibrity(int n)
{
    int indegree[n] = {0}, outdegree[n] = {0};
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x = knows(i,j);
            outdegree[i] += x;
            indegree[j] += x;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(indegree[i] == n-1 && outdegree[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" : cout << "Celebrity ID " << id;
    return 0;
}