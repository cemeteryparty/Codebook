#include <iostream>
#include <vector>

using namespace std;

void qsort(vector<int> &arr, short left, short right) {
    if (left > right) { return; }
    /* default the most right is pivot
    // sample of using middle as pivot
    short pi = (left + right) >> 1;
    swap(arr[pi], arr[right]);
    */
    short entry = left; // lt pivot
    for(short i = left; i < right; i++) {
        if (arr[i] < arr[right]) {
            swap(arr[i], arr[entry]);
            entry++;   
        }
    }
    swap(arr[entry], arr[right]);
    qsort(arr, left, entry - 1);
    qsort(arr, entry + 1, right);
}

int main() {
    int arr[] = {6,1,0,7,3,4,9,2,8,5}; 
    vector<int> nums(arr, arr + 10);
    qsort(nums, 0, nums.size() - 1);
    for(short i = 0; i < nums.size(); i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
