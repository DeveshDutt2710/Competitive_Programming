#include <bits/stdc++.h>
using namespace std;

stack<int> st;

string ns;

int insert_at_bottom(int x)
{
    if(st.size() == 0)
    {
        st.push(x);
    }
    else
    {
        int a =st.top();
        st.pop();
        insert_at_bottom(x);
        
        st.push(a);
    }
}

int reverse()
{
    if(st.size()>0)
    {
        int x = st.top();
        st.pop();
        reverse();
        
        insert_at_bottom(x);
    }
}

int main()
{
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    
    reverse();
    
    cout<<"REVERSED STACK\n"<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<"\n";
        st.pop();
    }
}