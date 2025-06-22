class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {


        //DP[i] : 表示在第i題到最後一題之間的範圍答題時，所能得到的最大points
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
