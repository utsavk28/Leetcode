// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    stack<char> stk;
    int i,j,k,n=s.size();
    for(i=0;i<n;i++) {
        if(!stk.empty() && (stk.top() == '{' && s[i] == '}')) stk.pop(); 
        else stk.push(s[i]);
    }
    
    int count = 0;
    if(stk.size()%2 == 1) return -1;
    while(!stk.empty()) {
        char top = stk.top();
        stk.pop();
        if(stk.top() == top) count++;
        else count+=2;
        stk.pop();
    }
    
    return count;
}