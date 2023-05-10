#include<iostream>
#include<vector>

using namespace::std;


void dfs(vector<string> &res, string str, int l, int r, int n){
    if(l>n || r>n || r>l) return;
    if(r==3) {res.push_back(str); return;}
    dfs(res, str+"(",l+1, r, n);
    dfs(res, str+")",l, r+1, n);
    return;
}

vector<string> generateParenthesis(int n){
    vector<string> res;
    dfs(res, "", 0, 0, 3);
    return res;
}


void printvector(vector<string> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
}


int main(){
    int n = 3;
    vector<string> res = generateParenthesis(n);
    printvector(res);
    return 0;
}