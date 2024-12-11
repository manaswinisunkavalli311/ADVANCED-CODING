#include <stdio.h>
int trap(int* height, int heightSize) {
    int left[heightSize], right[heightSize];
    int max = 0;
    for (int i = 0; i< heightSize; i++) {
        if (height[i] > max) {
            max = height[i];
        }
        left[i] = max;
    }
    max = 0;
    for (int i = heightSize - 1; i >= 0; i--) {
        if (height[i] > max) {
            max = height[i];
        }
        right[i] = max;
    }
    int water = 0;
    for (int i = 0; i < heightSize; i++) {
        int min_height = (left[i] < right[i]) ? left[i] : right[i];
        if (min_height > height[i]) {
            water += min_height - height[i];
        }
    }   
    return water;
}
