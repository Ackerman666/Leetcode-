class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,ans=0;
        while(i!=j){
            int left=height[i] , right=height[j];
            if(left<=right){            //�Hheight[i]����
                ans=max(ans,(j-i)*left);
                i++;
            }
            else{                               //�Hheight[j]����
                ans=max(ans,(j-i)*right);
                j--;
            }
        }
        return(ans);
    }
};
