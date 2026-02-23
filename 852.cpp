#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if (arr.size() == 3)
            return 1;

        int l = 0;
        int r = arr.size();
        while (l<r) {
            int mid = l + (r-l)/2;
            if (mid > 0 && arr[mid] < arr[mid-1])
                r = mid;
            else if (mid < arr.size() - 1 && arr[mid] < arr[mid+1])
                l = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};
