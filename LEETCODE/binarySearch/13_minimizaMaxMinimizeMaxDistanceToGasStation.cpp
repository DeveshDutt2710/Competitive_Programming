/*
https://leetcode.com/problems/minimize-max-distance-to-gas-station/

minimizaMaxMinimizeMaxDistanceToGasStation

*/
#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<int>& stations, int K, double guess) {
        int sum = 0;
        for (int i = 0; i + 1 < stations.size(); ++i) {
            sum += int((stations[i + 1] - stations[i]) / guess);
        }
        return sum <= K;
    }

double minmaxGasDist(vector<int>& stations, int K) {
        double left = 0.0;
        double right = 1e8;
        while (right - left > 1e-6) {
            const auto mid = left + (right - left) / 2.0;
            if (possible(stations, K, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }


int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    int k=9;
    cout<<minmaxGasDist(vec,k);
    
    return 0;
}