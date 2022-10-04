// Question :-
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s="";
    void generate(int& n,int open,int close,vector<string>& vec){
        if(n==close && n==open){
            vec.push_back(s);
            return;
        }
        if(open<n){
            s+="(";
            generate(n,open+1,close,vec);
            s.erase( s.end()-1 );
        }
        if(close<open && close<n){
            s+=")";
            generate(n,open,close+1,vec);
            s.erase( s.end()-1 );
        }   
        return;
    }
    vector<string> generateParenthesis(int n) {
       vector<string> vec;
       generate(n,0,0,vec); 
        return vec;
    }
};