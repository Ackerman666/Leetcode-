class Solution {
public:
    string addBinary(string a, string b) {
        int aindex=a.size()-1 , bindex=b.size()-1 , carry=0;
        string ans;
        while(aindex>=0 || bindex>=0 || carry){
            if(aindex>=0){
                carry += a[aindex]-'0';
                aindex--;
            }
            if(bindex>=0){
                carry += b[bindex]-'0';
                bindex--;
            }
            ans = char((carry%2)+'0') + ans;
            carry=carry/2;
        }
        return ans;
    }
};
