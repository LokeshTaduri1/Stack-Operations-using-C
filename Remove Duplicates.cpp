/* Remove Duplicates */



#include<bits/stdc++.h>
#include<stack>
using namespace std;
void removeDuplicates(string s)
{
    stack<char> S;
    int i;
    string result;
    for(i=0;i<s.length();i++)
    {
        
        if(S.empty()==false && S.top()==s[i])
        {
            while(S.empty()==false && S.top()==s[i])
            {
                S.pop();
            }
            continue;
        }
        S.push(s[i]);
    }
    while(S.empty()==false)
    {
        result.push_back(S.top());
        S.pop();
    }
    
    for(i=0;i<(result.length()/2);i++)
    {
        char store=result[i];
        result[i]=result[result.length()-i-1];
        result[result.length()-i-1]=store;
    }
    cout<<result;
}
int main()
{
    string exp="bacffccdyu";
    removeDuplicates(exp);
}
