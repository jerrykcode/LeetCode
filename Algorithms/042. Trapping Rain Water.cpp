/*
Using two arrays, maxFromLeft and maxFromRight, meaning the max height form height[0] to height[i] 
and from height[i] to the last element. For every bar i in the map, the water surface is the minimum 
value of maxFromLeft[i] and maxFromRight[i]. If the water surface is higher than the bar, then water 
can be collected.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size == 0) return 0;
        int * maxFromLeft = new int[size]; //maxFromLeft[i] = the max height from 0 to i
        int * maxFromRight = new int[size]; //maxFromRight[i] = the max height from i to size - 1
        maxFromLeft[0] = height[0];
        for (int i = 1; i < size; i ++) {
            maxFromLeft[i] = max(maxFromLeft[i - 1], height[i]);
        }
        maxFromRight[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i --) {
            maxFromRight[i] = max(maxFromRight[i + 1], height[i]);
        }
        int water = 0;
        for (int i = 0; i < size; i ++) 
            if (min(maxFromLeft[i], maxFromRight[i]) - height[i] > 0)
                water += min(maxFromLeft[i], maxFromRight[i]) - height[i];
        return water;
    }
};
