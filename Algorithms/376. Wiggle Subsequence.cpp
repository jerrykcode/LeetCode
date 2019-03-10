class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int *up = new int[size];       
        int *down = new int[size];      
        fill(up, up + size, 0);
        fill(down, down + size, 0);
        up[0] = down[0] = 1;        
        for (int i = 1; i < size; i++) 
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    up[i] = max(up[i], down[j] + 1);
                    down[i] = max(down[i], down[j]);   
                }
                else if (nums[j] > nums[i]) {
                    down[i] = max(down[i], up[j] + 1);
                    up[i] = max(up[i], up[j]);
                }
                else {
                    up[i] = max(up[i], up[j]);
                    down[i] = max(down[i], down[j]);
                }
            }
        int result = max(up[size - 1], down[size - 1]);
        //free(up);
        //free(down);
        return result;
    }
};