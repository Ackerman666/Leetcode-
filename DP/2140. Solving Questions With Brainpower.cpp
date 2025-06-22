class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {


        //DP[i] : ��ܦb��i�D��̫�@�D�������d���D�ɡA�ү�o�쪺�̤jpoints
        long long int ans = 0, DP[200001] = {0}, len = questions.size();

        for(int i=len-1 ; i>=0 ; i--){
            long long int points = questions[i][0], skip = questions[i][1] + 1;
            //DP[i] = points;

            DP[i] = max(DP[i+1], DP[i+skip] + points);


            ans = max(ans, DP[i]);

        }

        return(ans);


    }
};
