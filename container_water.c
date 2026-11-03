#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int max_water = 0;
    int left = 0;
    int right = heightSize - 1;
    
    while (left < right) {
        int width = right - left;
        int current_height = MIN(height[left], height[right]);
        int current_water = width * current_height;
        
        max_water = MAX(max_water, current_water);
        
        // Shift the shorter line inwards
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_water;
}
