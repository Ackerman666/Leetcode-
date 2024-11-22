class Solution {
public:

  
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        vector<vector<int>> area(m, vector<int> (n,0));
       
        int unoccupied = m*n - guards.size() - walls.size();

        // 0b1111 represents [left, right, up, down], where each bit set to 1 indicates a direction that doesn't require traversal.
        for(auto &wall : walls){
            area[wall[0]][wall[1]] = 0b1111;
        }
         for(auto &guard : guards){
            area[guard[0]][guard[1]] = 0b1111;
        }
    
        for(auto &guard : guards){

            // left scan
            for(int j=guard[1]-1 ; j>=0 ; --j){
                if(area[guard[0]][j] & 8)
                    break;
                unoccupied -= area[guard[0]][j] == 0;
                area[guard[0]][j] |= 8;     
            }

            // right scan
            for(int j=guard[1]+1 ; j<n ; ++j){
                if(area[guard[0]][j] & 4)
                    break;
                unoccupied -= area[guard[0]][j] == 0;
                area[guard[0]][j] |= 4;       
            }
           
            // up scan
            for(int i=guard[0]-1 ; i>=0 ; --i){
                if(area[i][guard[1]] & 2)
                    break;
                unoccupied -= area[i][guard[1]] == 0;
                area[i][guard[1]] |= 2;     
            }
           
            // down scan
            for(int i=guard[0]+1 ; i<m ; ++i){
                if(area[i][guard[1]] & 1)
                    break;
                unoccupied -= area[i][guard[1]] == 0;
                area[i][guard[1]] |= 1;
            }
         
        }
        return unoccupied;
    }
};
