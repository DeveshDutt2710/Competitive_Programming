#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void NSL(int arr[], int n)
{
    vector<int> V;
    stack<int> s;
    
    for(int i=0;i<=n-1;i++)
    {
        if(s.empty())
        {
            V.push_back(-1);
        }
        else
        {
            if(s.top()<arr[i])
            {
                V.push_back(s.top());
            }
            else
            {
                while(!s.empty() && s.top()>arr[i])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    V.push_back(-1);
                }
                else
                {
                    V.push_back(s.top());
                }
            }
        }
        s.push(arr[i]);
    }
    
    // reverse(V.begin(), V.end());
    
    for(int i=0;i<n;i++)
    {
        cout<<V[i]<<" ";
    }
}

int main() {
	int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    NSL(arr,n);
	return 0;
}
