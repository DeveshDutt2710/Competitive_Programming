
/*


https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
1320_MinimumDistancetoTypeaWordUsingTwoFingers



You have a keyboard layout as shown above in the XY plane, where each English uppercase letter is located at some coordinate, for example, the letter A is located at coordinate (0,0), the letter B is located at coordinate (0,1), the letter P is located at coordinate (2,3) and the letter Z is located at coordinate (4,1).

Given the string word, return the minimum total distance to type such string using only two fingers. The distance between coordinates (x1,y1) and (x2,y2) is |x1 - x2| + |y1 - y2|. 

Note that the initial positions of your two fingers are considered free so don't count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.

 

Example 1:

Input: word = "CAKE"
Output: 3
Explanation: 
Using two fingers, one optimal way to type "CAKE" is: 
Finger 1 on letter 'C' -> cost = 0 
Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
Finger 2 on letter 'K' -> cost = 0 
Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
Total distance = 3
Example 2:

Input: word = "HAPPY"
Output: 6
Explanation: 
Using two fingers, one optimal way to type "HAPPY" is:
Finger 1 on letter 'H' -> cost = 0
Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
Finger 2 on letter 'P' -> cost = 0
Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
Total distance = 6
Example 3:

Input: word = "NEW"
Output: 3
Example 4:

Input: word = "YEAR"
Output: 7
 

Constraints:

2 <= word.length <= 300
Each word[i] is an English uppercase letter.
*/



class Solution {
public:
    int dp[27][27][301] = {[0 ... 26][0 ... 26][0 ... 300] = -1};
    
    int cost(char from, char to) 
    {
        return from == 26 ? 0 : abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
    }
    int minimumDistance(string &word, int pos = 0, char left = 26, char right = 26) 
    {
        if (pos >= word.size()) 
            return 0;
        if (dp[left][right][pos] == -1) 
        {
            auto to = word[pos] - 'A';
            
            dp[left][right][pos] = min(cost(left, to) + minimumDistance(word, pos + 1, to, right),
                                        cost(right, to) + minimumDistance(word, pos + 1, left, to));
        }
        
        return dp[left][right][pos];
    }
};





class Solution {
public:
    int cost(char from, char to) 
    {
        if (from == 26) return 0;
        return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
    }
    
    int minimumDistance(string word) 
    {
        int dp[301][27][27] = {};    
        for (int pos = word.size() - 1; pos >= 0; --pos) 
        {
            auto to = word[pos] - 'A';
            for (int i = 0; i < 27; ++i) 
            {
                for (int j = 0; j < 27; ++j) 
                {
                    dp[pos][i][j] = min(dp[pos + 1][to][i] + cost(j, to), dp[pos + 1][to][j] + cost(i, to));
                }
            }
        }
        return dp[0][26][26];
    }
};





class Solution {
public:
    int cost(char from, char to) {
        if (from == 26) return 0;
        return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
    }
    int minimumDistance(string word) {
        int dp[2][27][27] = {};    
        for (int pos = word.size() - 1; pos >= 0; --pos) {
            auto to = word[pos] - 'A';
            for (int i = 0; i < 27; ++i) {
                for (int j = 0; j < 27; ++j) {
                    dp[pos % 2][i][j] = min(dp[(pos + 1) % 2][to][i] + 
                        cost(j, to), dp[(pos + 1) % 2][to][j] + cost(i, to));
                }
            }
        }
        return dp[0][26][26];
    }
};