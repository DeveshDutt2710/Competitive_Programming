int Solution::minDistance(string A, string B) {

    int row = A.size();
    int col = B.size();
    
    vector<vector<int> > temp(row+1, vector<int>(col+1));
    
    for(int i = 0; i < temp.size(); i++){
        for(int j = 0; j < temp[0].size(); j++){
            if(j == 0){
                temp[i][j] = i;
            }
            else if(i == 0){
                temp[i][j] = j;
            }
            else if(A[i-1] == B[j-1]){
                temp[i][j] = temp[i-1][j-1];
            }
            else{
                temp[i][j] = min(temp[i-1][j-1], temp[i-1][j]);
                temp[i][j] = min(temp[i][j-1], temp[i][j]);
                temp[i][j] = temp[i][j]+1;
            }
        }
    }
    
    return temp[row][col];
}