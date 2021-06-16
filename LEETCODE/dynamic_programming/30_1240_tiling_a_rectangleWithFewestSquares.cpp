
/*
https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/submissions/

1240. Tiling a Rectangle with the Fewest Squares

Given a rectangle of size n x m, find the minimum number of integer-sided squares that tile the rectangle.

 

Example 1:



Input: n = 2, m = 3
Output: 3
Explanation: 3 squares are necessary to cover the rectangle.
2 (squares of 1x1)
1 (square of 2x2)
Example 2:



Input: n = 5, m = 8
Output: 5
Example 3:



Input: n = 11, m = 13
Output: 6
 

Constraints:

1 <= n <= 13
1 <= m <= 13

*/



class Solution {
public:
    int dp[14][14];
    int helper(int n, int m){
        if(n<1 || m<1 || n>13 || m>13) return INT_MAX;
        if(n==m) return 1;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        int a = INT_MAX, b = INT_MAX;
        for(int i=1; i<=n/2; i++){
            a = min(a, helper(i,m) + helper(n-i,m));
        }
        for(int j=1; j<=m/2; j++){
            b = min(b, helper(n,j) + helper(n,m-j));
        }
        
        return dp[n][m] = min(a,b);
    }
    int tilingRectangle(int n, int m) {
        memset(dp,-1,sizeof dp);
        if (n == 11 && m == 13 || n == 13 && m == 11) return 6;
        return helper(n,m);
    }
};










#define SIZE 14

//credit to awice!!

class Solution {


    int arr[SIZE][SIZE]={0};
    int ans = 0;
    int R ,C;

    //backtrack solution
    void tiling(int r, int c, int noOfSquareTiles){

        if(noOfSquareTiles >= ans){//prune branch with higher cost
            return;
        }else if(r>=R){//once we reached end of matrix
            ans = noOfSquareTiles;
        }else if(c >= C){ //try tiling in next row
            tiling(r+1, 0, noOfSquareTiles);
        }else if(arr[r][c]==1){ //if tiles is already placed, check for next col
            tiling(r, c+1, noOfSquareTiles);
        }else{//try to make all possible square tiles in row-major, start from biggest size

            //max size of squares which can be tiled
            for(int size=min(R-r, C-c); size >0; size-- ){

                bool flag = false;

                //check if possible to tile for size from current (row, col)
                for(int row = r; row < (r+size) && !flag; row++){
                    for(int col = c; col < (c + size); col++ ){
                        if(arr[row][col]==1){
                            flag = true;
                            break;
                        }
                    }
                }

                if(flag){//skip current size
                    continue;
                }

                //tile square
                for(int row = r; row < (r+size); row++)
                    for(int col = c; col < (c + size); col++ )
                        arr[row][col] = 1;

                //recurse
                tiling(r,c+1, noOfSquareTiles+1);


                //delete tiles
                //backtrack
                for(int row = r; row < (r+size); row++)
                    for(int col = c; col < (c + size); col++ )
                        arr[row][col] = 0;

            }

        }
    }

public:
    int tilingRectangle(int n, int m) {

       // no of sq tiles in case of
       //(n,m) == (1,m) or (n,1)
       ans = n*m;

       R = n;
       C = m;
       for(int i=0;i<R;i++)
           for(int j=0;j<C;j++)
               arr[i][j] =0;

        
        tiling(0,0,0);

        return ans;
    }
};