


bool isExist(int i, int j, int index, vector<string> &A, string B) {
    if(index == B.length())
        return true;
        
    int n = A.size();
    int m = A[0].size();
    
    if(i < 0 || j < 0 || i >= n || j >= m || A[i][j] != B[index])
        return false;
    
    
    return isExist(i, j + 1, index+1, A, B) ||
           isExist(i, j - 1, index+1, A, B) ||
           isExist(i + 1, j, index+1, A, B) ||
           isExist(i - 1, j, index+1, A, B);
}

int Solution::exist(vector<string> &A, string B) {
    int b = B.length();
    if(b == 0) return 1;
        
    int n = A.size();
    if(n == 0) return 0;
    
    int m = A[0].size();
    if(m == 0) return 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == B[0]) {
                bool temp = isExist(i, j, 0, A, B);
                if(temp)
                    return 1;
            }
        }
    }
    
    return 0;
}