#include<iostream>
#include<vector>

using namespace::std;

string longestPalindrome(string s) {

    int maxLen = 0;
    int begin = 0;
    int len = s.size();

    //如果长度为1或者0直接输出
    if(len <= 1){
        return s;
    }

    //动态规划数组，并初始化
    vector<vector<int>> dp(len, vector<int>(len)); 
    for(int i = 0 ; i < len; i++){
        dp[i][i] = 1;
        maxLen = 1;
    }

    for(int L = 2 ; L <= len; L++){ //回文长度
        for(int i = 0; i < len; i++){   //左边开始位置
            int j = i + L - 1;    //计算得到的右边开始位置
            if(j>=len){     //超界限
                continue;
            }
            if(s[i] == s[j]){   //左右相同
                if(L<=3){   //两个三个直接就是
                    dp[i][j] = 1;
                }
                else{   //3以上就得看本身啦
                    dp[i][j] = dp[i+1][j-1];
                }
            }
            if(dp[i][j] && L>maxLen){   //如果本次是回文，且长度比之前的长
                begin = i;
                maxLen = L;
            }
        }
    }
    return s.substr(begin,maxLen);      //输出子串
}



int main(){
    string s = "123321";
    cout << longestPalindrome(s) << endl;
    return 0;
}
