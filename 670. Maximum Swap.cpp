class Solution {
public:
    int maximumSwap(int num) {
        string digits = to_string(num);
        int right_max = -1, right_max_idx = 0, idx = 0, idy = 0;

        for (int i = digits.size(); i >= 0; --i) {
            // Update the rightmost maximum digit and its index
            if (digits[i] > right_max) {
                right_max = digits[i];
                right_max_idx = i;
            }
            // If a smaller digit is found before the max, swapping these digits can make "num" greater.
            // => record the swap positions
            else if (digits[i] < right_max) {
                idx = i;
                idy = right_max_idx;
            }
        }

        swap(digits[idx], digits[idy]);
        return stoi(digits);
    }
};
