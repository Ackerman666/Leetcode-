class Solution {
public:
    bool isValid(string s) {
        stack<char> ch;
        int strlen = s.size();
        for(int i=0 ; i<strlen ; i++){
            char cur = s[i];
            if(cur=='(' || cur=='[' || cur=='{')
                 ch.push(cur);
            else{
                if(ch.empty()){
                    ch.push('#');
                    break;
                }
                if(cur==')'){
                    if(ch.top() != '(')
                        break;
                    ch.pop();
                }
                else if(cur==']'){
                    if(ch.top() != '[')
                       break;
                    ch.pop();
                }
                else if(cur=='}'){
                    if(ch.top() != '{')
                        break;
                    ch.pop();
                }
            }
        }
        return(ch.empty());
    }
};
