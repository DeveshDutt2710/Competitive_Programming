int countSwap(string s)
{
    int n = s.length()
    
    int count=0;
    
    for(int i=0;i<n/2;i++)
    {
        int left = i;
        
        int right = n-left-1;
        
        while(left<right)
        {
            if(s[left]==s[right])
            {
                break;
            }
            else
            {
                right--;
            }
        }
        
        if(left==right)
        {
            return -1;
        }
        
        for(int j=right;j<n-left-1;j++)
        {
            swap(s[j],s[j+1]);
            count++;
        }
    }
}