class Solution {
public:
    int partitionString(string s) {

        //��26�줸�����r�����L�X�{�A��1�줸����A�B��2����B...
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
