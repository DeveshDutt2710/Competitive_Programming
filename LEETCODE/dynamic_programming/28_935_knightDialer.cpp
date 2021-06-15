
/*

https://leetcode.com/problems/knight-dialer/

935. Knight Dialer
*/

#define MOD 1000000007
class Solution {
public:
    int knightDialer(int N) {
        long long int dp[N][10];
        memset(dp,0, sizeof(dp));
        for(int i = 0; i < 10; i ++){
            dp[0][i] = 1;
        }
        for(int i = 1; i < N; i++){
            for(int j = 0; j < 10; j++){
                switch(j){
                    case 1:
                        dp[i][j] = (dp[i - 1][6] + dp[i - 1][8]) % MOD;
                        break;
                    case 2:
                        dp[i][j] = (dp[i - 1][7] + dp[i - 1][9]) % MOD;
                        break;
                    case 3:
                        dp[i][j] = (dp[i - 1][4] + dp[i - 1][8]) % MOD;
                        break;
                    case 4:
                        dp[i][j] = (dp[i - 1][3] + dp[i - 1][9] + dp[i - 1][0]) % MOD;
                        break;
                    case 5:
                        dp[i][j] = 0;
                        break;
                    case 6:
                        dp[i][j] = (dp[i - 1][1] + dp[i - 1][7] + dp[i - 1][0]) % MOD;
                        break;
                    case 7:
                        dp[i][j] = (dp[i - 1][6] + dp[i - 1][2]) % MOD;
                        break;
                    case 8:
                        dp[i][j] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
                        break;
                    case 9:
                        dp[i][j] = (dp[i - 1][2] + dp[i - 1][4]) % MOD;
                        break;
                    case 0:
                        dp[i][j] = (dp[i - 1][6] + dp[i - 1][4]) % MOD;
                        break;
                }
            }
        }
        long long int sum = 0;
        for(int i = 0; i < 10; i++){
            sum += dp[N - 1][i];
            sum = sum % MOD;
        }
        return sum;
    }
};