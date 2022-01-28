class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());            //長度小的放前面
        int len=strs[0].size();
        string ans="";
        for(int i=0;i<len;i++){
            bool common=true;
            int vclen=strs.size();
            for(int j=1;j<vclen;j++){
                if(strs[j-1][i]!=strs[j][i]){
                   return ans;
                }
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};
