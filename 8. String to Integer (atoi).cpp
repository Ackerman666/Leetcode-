class Solution {
public:
    int myAtoi(string s) {
        bool IsNegative=false;
        bool interrupt=false;
        long long int ans=0,len=s.size(),ascii;
        for(int i=0;i<len;i++){
            ascii=int(s[i]);
            if(ascii>='0' && ascii<='9'){
                ans=ans*10+(ascii-'0');
                if(ans>INT_MAX)
                    break;
                interrupt=true;
            }
            else{
                if(!interrupt && ( ascii==' ' || ascii=='-' || ascii=='+')){
                    if(ascii==' ')
                        continue;
                    else if(ascii=='-' || ascii=='+'){
                        if(ascii=='-'){
                            IsNegative=true;
                            interrupt=true;
                        }
                        else{
                            IsNegative=false;
                            interrupt=true;
                        }
                    }
                }
                else
                    break;
            }
        }
        if(IsNegative)
            ans=-ans;
        if(ans<INT_MIN)
            ans=INT_MIN;
        if(ans>INT_MAX)
            ans=INT_MAX;
        return ans;
    }
};
