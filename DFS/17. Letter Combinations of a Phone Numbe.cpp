#include<map>
#include<vector>
class Solution {
public:
    map<char , string> mp;
    vector<string> ans;
    int digits_len;
    Solution(){
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
    }
    void dfs(int loc , string &digits , string temp){
        if(loc==digits_len){
            ans.push_back(temp);
            return;
        }
        int hash_len=mp[digits[loc]].size();               //the string length of mp[i]
        for(int j=0;j<hash_len;j++){
            dfs(loc+1 , digits , temp+mp[digits[loc]][j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return ans;
        digits_len=digits.size();
        dfs(0,digits,"");
        return ans;
    }
};
