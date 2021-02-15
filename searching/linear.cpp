#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int search(int arr[], int n, int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            return i;
        }
    }
    return -1;
}

int searchOptimised(vector<int> arr, int search_Element)
{
    int left = 0;
    int length =arr.size();
    int position = -1;
    int right = length -1;
    
    while(left<right)
    {
        if(arr[left]== search_Element)
        {
            position=left;
            cout<<search_Element<<"  found at : "<<position+1<<" in "<<left+1<<" Attempt"<<endl;
        }
        if(arr[right]==search_Element)
        {
            position=right;
            cout<<search_Element<<"  found at position : "<<position+1<<" in "<<length-right<<" Attempt"<<endl;
        }
        left++;
        right--;
        
    }
    if(position==-1)
    {
        cout<<search_Element<<" not found in the array"<<endl;
    }
}

int main()
{
    vector<int> arr{ 1, 2, 3, 4, 5 };
    int arr1[] = { 1, 2, 3, 4, 5 };
    int search_element = 5;
    int n = sizeof(arr1) / sizeof(arr1[0]);
    
    int result = search(arr1, n, search_element);
    (result == -1)
        ? cout << "Element is not present in array"<<endl
        : cout << "Element is found at position " << result+1<<" in "<<result+1<<"th Attempt"<<endl;
     
    searchOptimised(arr, search_element);
    return 0;
}