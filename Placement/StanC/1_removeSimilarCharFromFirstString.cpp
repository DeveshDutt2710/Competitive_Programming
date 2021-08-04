/*



Coding round: 1 easy question
link : 
https://www.geeksforgeeks.org/remove-characters-from-the-first-string-which-are-present-in-the-second-string/ )

*/


#include <bits/stdc++.h>
#define NO_OF_CHAR 256

using namespace std;

vector<int> getcountarray(string str2)
{
    vector<int> count(NO_OF_CHAR,0);
    
    for(int i=0;i<str2.size();i++)
    {
        count[str2[i]]++;
    }
    
    return count;
}

void removeDirtyChars(string str1, string str2)
{
    vector<int> count = getcountarray(str2);
    
    vector<char> res;
    
    int ip_idx = 0;
    
    while(ip_idx<str1.size())
    {
        char temp = str1[ip_idx];
        if(count[temp] == 0)
        {
            res.push_back(temp);
        }
        ip_idx++;
    }
    
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i];
    }
}

int main()
{
    string str1 = "geeksforgeeks";
    string str2 = "mask";
 
    removeDirtyChars(str1, str2);
}