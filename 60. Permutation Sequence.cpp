class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> v;
        int f = 1;
        for(int i=1 ; i<=n ; ++i){
            v.push_back('0'+i);
            f *= i;
        }

        string result = "";
        k -= 1;     // base to 0
        for(int i=n ; i>=1 ; --i){
            f = f/i;
            int idx = k/f;
            result += v[idx];
            k -= f * idx;
            v.erase(v.begin()+idx);  // O(n)
        }

        return result;
            
    }
};
