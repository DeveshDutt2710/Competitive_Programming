//Time Complexity: O(mn)

#include <bits/stdc++.h>

using namespace std;

int count(int S[], int m, int n)
{
    int i,j,x,y;
    
    int table[n+1][m];
    
    for(i=0;i<m;i++){
        table[0][i]=1;
    }
    
    for(i=1;i<n+1;i++){
        for(j=0;j<m;j++){
            x=(i-S[j]>=0)?table[i-S[j]][j]:0;
            y=(j>=1)?table[i][j-1]:0;
            
            table[i][j]=x+y;
        }
    }
    return table[n][m-1];
}

int main() 
{ 
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 4; 
    cout << count(arr, m, n); 
    return 0; 
}

/*
//space optimized method : O(n)


int count( int S[], int m, int n ) 
{ 
 
    int table[n+1]; 

    memset(table, 0, sizeof(table)); 

    table[0] = 1; 
  
    for(int i=0; i<m; i++) 
        for(int j=S[i]; j<=n; j++) 
            table[j] += table[j-S[i]]; 
  
    return table[n]; 
}
*/