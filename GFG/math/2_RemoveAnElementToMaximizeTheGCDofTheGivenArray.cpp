/*
https://www.geeksforgeeks.org/remove-an-element-to-maximize-the-gcd-of-the-given-array/

RemoveAnElementToMaximizeTheGCDofTheGivenArray
*/


int maxGCD(int a[], int n)
{
    int prefix[n+2];
    int suffix[n+2];
    
    
    prefix[1] = a[0];
    
    for(int i=2;i<=n;i++)
    {
        prefix[i] = gcd(prefix[i-1],a[i-1]);
    }
    
    suffix[n]=a[n-1];
    
    for(int i=n-1;i>=0;i--)
    {
        suffix[i] = gcd(suffix[i+1],a[i-1]);
    }
    
    int ans = max(suffix[2],prefix[n-1]);
    
    for(int i=2;i<n;i++)
    {
        ans = max(ans, gcd(prefix[i-1],suffix[i+1]));
    }
    
    return ans;
}

