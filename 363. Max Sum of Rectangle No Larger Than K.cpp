class Solution {
public:

    int find_max_subarray_sum(int array[] , int m , int k){
        int Max = -999999;
        for(int i=1 ; i<=m ; i++){
            for(int j=i ; j<=m ; j++){
                int sub_rec_sum = array[j]-array[i-1];
                if(sub_rec_sum <= k)
                    Max = max(Max , sub_rec_sum);
            }
        }
        return(Max);
    }


    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int prefix[101][101]={0} , m=matrix.size() , n=matrix[0].size() ;
        int MaxSum = -999999 , temp ;
        for(int i=1 ; i<=m ; i++){
            for(int j=1 ; j<=n ; j++){
                prefix[i][j] = prefix[i][j-1] + matrix[i-1][j-1];
            }
        }

        for(int i=1 ; i<=n ; i++){              //以第i行為開頭
            for(int j=i ; j<=n ; j++){         //以第j行為結尾
                int subarray[101]={0};
                for(int t=1 ; t<=m ; t++){
                    subarray[t] = subarray[t-1] + ( prefix[t][j] - prefix[t][i-1] );
                }
                temp = find_max_subarray_sum(subarray , m , k);
                if(temp <= k)
                    MaxSum = max(MaxSum , temp);
            }
        }



        return(MaxSum);

    }
};
