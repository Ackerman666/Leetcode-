class Solution {
public:

    int mod = 1e9 + 7;

    long long mod_pow(long long base, long long k, long long mod){
        int result = 1;
        while(k){
            if(k & 1)
                result = (result * base)%mod;
            base = (base * base)%mod;
            k>>=1;
        }
        return result;
    }

    string_view Rabin_Karp(string &s, int k){
        unordered_map<int, vector<int>> hash_table;
        int hash = 0, power = 1;
        for(int i=0 ; i<k ; ++i){
            hash = ((hash<<1)%mod + s[i]) % mod;
        }
        power = mod_pow(2, k - 1, mod);
            
        hash_table[hash].push_back(0);

        for(int i=k ; i<s.size() ; ++i){
            hash -= (1LL* s[i-k] * power) % mod;
            hash = (hash + mod) % mod; // Prevent negative values
            hash = ((hash<<1)% mod + s[i]) % mod;

            if(hash_table.count(hash)){
                for(auto &start : hash_table[hash]){
                    if(s.compare(start, k, s, (i-k+1), k)==0){
                        string_view sv(s);
                        return sv.substr(start, k);
                    }
                }
            }
            hash_table[hash].push_back(i-k+1);
        }
        return "";
    }

    string longestDupSubstring(string s) {
        int l = 1 , r = s.size(), len;
        string_view pattern="";

        // Binary search to find the maximum length of a duplicated substring.
        // For each length, use the Rabin-Karp algorithm to check whether any substring of that length appears more than once in s
        while(l<=r){
            len = (l+r) >> 1;
            string_view tmp = Rabin_Karp(s, len);
            if(tmp!=""){
                pattern = tmp;
                l = len+1;
            }
            else
                r = len-1;
        }
        return string(pattern);
    }
};