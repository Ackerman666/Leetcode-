class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int lball = 0, rball = 0, moves = 0;

        if(boxes[0] == '1')
            ++lball;

        // Calculate steps for the ball to reach the leftmost position.
        for(int i=1 ; i<boxes.size() ; i++){
            if(boxes[i] == '1'){
                moves += i;
                ++rball;
            }
        }
        ans.push_back(moves);

        // Current box's total moves = Previous box's total moves 
        // + Number of balls on the left (all left balls move right)
        // - Number of balls on the right (all right balls move left)
        for(int i=1 ; i<boxes.size() ; i++){
            moves = moves - rball + lball; 
            ans.push_back(moves);
            rball -= (boxes[i] - '0');
            lball += (boxes[i] - '0');
        }
        return ans;
    }
};
