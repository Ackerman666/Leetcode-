#include<stack>
#include<cstdlib>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stringstream ss;
        stack<int> st;
        int token_len = tokens.size() , ans;
        for(int i=0 ;i<token_len ;i++){
            string cur = tokens[i];
            if(cur=="+" || cur=="-" || cur=="*" || cur=="/"){
               int num1 , num2 , compute;
               num1 = st.top();
               st.pop();
               num2 = st.top();
               st.pop();
               if(cur=="+"){st.push(num2 + num1);}
               else if(cur=="-"){st.push(num2 - num1);}
               else if(cur=="*"){st.push(num2 * num1);}
               else if(cur=="/"){st.push(num2 / num1);}
            }
            else{
                st.push(atoi(cur.c_str()));
            }
        }
        return(st.top());
    }
};
