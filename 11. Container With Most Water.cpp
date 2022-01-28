class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,ans=0;
        while(i!=j){
            int left=height[i] , right=height[j];
            if(left<=right){            //以height[i]為高
                ans=max(ans,(j-i)*left);
                i++;
            }
            else{                               //以height[j]為高
                ans=max(ans,(j-i)*right);
                j--;
            }
        }
        return(ans);
    }
};
