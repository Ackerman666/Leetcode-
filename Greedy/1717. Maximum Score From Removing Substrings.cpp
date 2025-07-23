class Solution {
public:

    int remove(string &s, string pattern, int val){
        int idx = 0; // the length of the removed string
        int point = 0;
        for(auto &c : s){
            s[idx++] = c;
            if(idx>=2 && s[idx-2] == pattern[0] && s[idx-1] == pattern[1]){
                idx-=2;
                point += val;
            }
        }
        s.resize(idx);
        return point;
    }

    int maximumGain(string s, int x, int y) {
        if(x >= y)
            return remove(s, "ab", x) + remove(s, "ba", y);
        return remove(s, "ba", y) + remove(s, "ab", x);
    }
};