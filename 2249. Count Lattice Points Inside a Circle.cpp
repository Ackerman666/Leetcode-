class Solution {
public:
   int countLatticePoints(vector<vector<int>>& circles) {
       int cnt = 0 , length = circles.size();
       for(int x=0 ; x<=200 ; x++){
           for(int y=0 ; y<=200 ; y++){
               for(int i=0 ; i<length ; i++){
                   int cx = circles[i][0], cy = circles[i][1], r = circles[i][2];
                   int x_diff = (x-cx) , y_diff = (y-cy) , r_pow = r*r;
                   if(x_diff*x_diff + y_diff*y_diff <= r_pow){
                       cnt++;
                       break;
                   }
               }
           }
       }
       return(cnt);
   }
};
