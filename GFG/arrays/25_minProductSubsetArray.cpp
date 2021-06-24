/*

https://www.geeksforgeeks.org/minimum-product-subset-array/

Given an array a, we have to find the minimum product 
possible with the subset of elements present in the array. 
The minimum product can be a single element also.
*/

#include <iostream>
using namespace std;

int minProduct(int arr[], int n)
{
    int negativeCount = 0, zeroCount = 0;
    int minNegative=0, maxNegative = 0, minPositive = 0, maxPositive = 0, product = 1;
    
    for(int i=0;i<n;i++)
    {
        
        if(arr[i] < 0)
        {
            if(arr[i] < minNegative)
            {
                minNegative = arr[i];
            }
            if(arr[i] > maxNegative)
            {
                maxNegative = arr[i];
            }
            negativeCount++;
            product *= arr[i];
        }
        else if(arr[i] == 0)
        {
            zeroCount++;
        }
        else
        {
            product *= arr[i];
            if(arr[i] < minPositive)
            {
                minPositive = arr[i];
            }
            if(arr[i] > maxPositive)
            {
                maxPositive = arr[i];
            }
        }
    }
    if(negativeCount%2 != 0)
    {
        return product;
    }
    if(negativeCount%2 == 0 && negativeCount != 0)
    {
        return product/maxNegative;
    }
    else
    {
        if(zeroCount == 0)
        {
            return minPositive;
        }
        else
        {
            return 0;
        }
    }
}

int main() {
    int a[] = { -1, -1, -2, 4, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << minProduct(a, n);
    return 0;
}
