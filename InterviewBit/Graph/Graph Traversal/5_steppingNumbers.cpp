void dfs(vector<int>&res,vector<int>adj[],int i,int temp,int A,int B){
       temp=temp*10+i;
    if(temp>=A && temp<=B){
        res.push_back(temp);
    }

    if(temp>B)
    return;
    for(int x:adj[i]){
        dfs(res,adj,x,temp,A,B);
    }
    
}


vector<int> Solution::stepnum(int A, int B) {
    vector<int>adj[10];
    adj[0].push_back(1);
    adj[9].push_back(8);
    for(int i=1;i<9;++i){
        adj[i].push_back(i-1);
        adj[i].push_back(i+1);
    }
    vector<int> res;
    for(int i=0;i<10;++i){
        if(i==1)
        continue;
            dfs(res,adj,i,0,A,B);
    }
    sort(res.begin(),res.end());
    return res;
    
}




















void step(int A, int B, vector<int>& sol, long long int num){
    if(num > B){
        return;
    }
    
    int last = num%10;
    
    if(num >= A){
        sol.push_back(num);
    }
    
    if(last == 0){
        step(A, B, sol, num*10 + 1);
    }
    else if(last == 9){
        step(A, B, sol, num*10 + 8);
    }
    else{
        step(A, B, sol, num*10 + last - 1);
        step(A, B, sol, num*10 + last + 1);
    }
}

vector<int> Solution::stepnum(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> sol;
    vector<int> a;
    vector<int> b;
    
    if(A > B){
        return sol;
    }
    
    if(A == 0){
        sol.push_back(0);
    }
    
    for(int i = 1; i < 10; i++){
        step(A, B, sol, (long long int)i);
    }
    
    if(sol.size() != 0){
        sort(sol.begin(), sol.end());
    }
    
    return sol;
}