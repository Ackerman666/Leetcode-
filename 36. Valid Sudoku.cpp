class Solution {
public:

    int matrix_num(int i , int j){
         if(i<3){
            if(j<3)      return(0);
            else if(j<6) return(1);
            else         return(2);
        }
        else if(i<6){
            if(j<3)      return(3);
            else if(j<6) return(4);
            else         return(5);
        }
        else{
            if(j<3)      return(6);
            else if(j<6) return(7);
            else         return(8);
        }
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool row_info[9][9]={0} , col_info[9][9]={0} , matrix_info[9][9]={0};
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                int matrix_label = matrix_num(i, j);
                int cur = board[i][j]-'0';
                if(cur>=0 && cur<=9){
                    cur-=1;
                    //相同的列或行有出現同個數字就不合法
                    if(row_info[i][cur] || col_info[j][cur] || matrix_info[matrix_label][cur]){
                        return(false);
                    }
                    else{
                        row_info[i][cur]=1;
                        col_info[j][cur]=1;
                        matrix_info[matrix_label][cur]=1;
                    }
                }
            }
        }
        return(true);
    }
};
