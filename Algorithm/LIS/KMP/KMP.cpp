vector<int> buildFail(string pattern){
    int pattern_len = pattern.size();
    vector<int> fail(pattern_len, -1);
    
    for(int i=1 ; i<pattern_len ; i++){
        int match_point = fail[i-1] + 1;

        while(match_point != 0){
            if(pattern[match_point] == pattern[i]){
                fail[i] = match_point;
                break;
            }
            match_point = fail[match_point-1] + 1;
        }
        if(fail[i] == -1 && pattern[i] == pattern[0] )
            fail[i] = 0;
    }
    return(fail);
}

// KMP algorithm for finding the first occurrence index of a pattern in a string.
// Returns the index where the pattern is found or -1 if not found. 
int KMP(string s, string pattern, vector<int> &fail){
    
    int slen = s.size();
    int plen = pattern.size();
    int p_index = 0;

    for(int i=0 ; i<slen ; i++){
        if(s[i] == pattern[p_index]){
            p_index++;
        }
        else{
            if(p_index != 0){
                p_index = fail[p_index-1] + 1;
                i--;
                continue;
            }
        }
        if(p_index == plen){
            return(i-plen+1);
        }
    }
    return(-1);
}