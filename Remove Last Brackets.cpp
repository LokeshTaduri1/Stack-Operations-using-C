/* Remove last Brackets */


#include<iostream>
#include<string.h>
using namespace std;
string removebrackets(string exp)
{
    int count=0;
    string ans="";
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]=='(')  count++;
        if(exp[i]==')')  count--;
        if(exp[i]=='('&&count!=1)  ans+=exp[i];
        if(exp[i]==')'&&count!=0)  ans+=exp[i];
    }
    return ans;
}
int main()
{
    string exp="(()())(())";
    cout<<removebrackets(exp);
}
