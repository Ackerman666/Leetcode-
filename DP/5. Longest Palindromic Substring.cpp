class Solution {

private:
    string str;

public:

    void ini(int str_len , bool isPalindromic[][1001]){                      //DP建迴文表
        for(int i=0 ;i<str_len ;i++){
            isPalindromic[i][i]=true;
        }

        for(int i=str_len-2 ; i>=0 ;i--){
            for(int j=str_len-1 ; j>i ;j--){
                if(str[i]==str[j]){
                    int left=i+1 , right=j-1;
                    if( isPalindromic[left][right] || (left > right) ){
                        isPalindromic[i][j]=true;
                    }
                }
            }
        }
    }

    string longestPalindrome(string s) {
        int str_len = s.size();
        int CurPalLen=0;                              //目前找到最迴文的長度
        int opi_len = str_len;
        int ans_left , ans_right;
        bool isPalindromic[1001][1001]={0};
        string ans="";
        str=s;
        ini(str_len , isPalindromic);
        for(int i=0 ; i<str_len ; i++){
            for(int j=str_len-1 ; j>=i ;j--){
                int sub_str_len = (j-i+1);
                if(sub_str_len <= CurPalLen)
                    break;
                if(isPalindromic[i][j]){
                    ans_left=i;
                    ans_right=j;
                    CurPalLen=sub_str_len;
                    break;
                }
            }
            if(CurPalLen==opi_len)            //optimal condiction
                break;
            opi_len--;
        }
        for(int i=ans_left ;i<=ans_right ;i++)
            ans+=s[i];
        return(ans);
    }
};
