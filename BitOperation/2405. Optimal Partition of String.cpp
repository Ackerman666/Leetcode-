class Solution {
public:
    int partitionString(string s) {

        //用26位元紀錄字元有無出現，第1位元紀錄A、第2紀錄B...
        int ans = 0, len = s.size(), record = 0;

        for(auto i=0 ; i<len ; i++){
            if(1<<(s[i]-'a') & record){
                ans++;
                record = 0;
            }
            record |= 1<<(s[i]-'a');
        }
        ans++;
        return(ans);

    }
};
