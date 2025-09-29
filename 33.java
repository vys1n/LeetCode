// Search in Rotated Sorted Array
class leetcode33 {
    public static void main(String[] args){

    }

    public int BruteForceSearch(int[] nums, int target){
        for (int i=0; i<nums.length; i++) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }

    public int TwoPassSearch(int[] nums, int target){
        int l=0, r = nums.length-1;
        while(l<r){
            int m = (l+r)/2;
            if (nums[m] > nums[r]) {
                l = m+1;
            } else {
                r = m;
            }
        }
        int pivot = l;
        int res = binarySearch(nums, target, 0, pivot-1);
        if (res != -1)
            return res;
        return binarySearch(nums, target, pivot, nums.length-1);
    }
    
    public int OnePassSearch(int[] nums, int target){
        int l=0, r = nums.length-1;
        
        while(l<=r){
            int m = (l+r)/2;
            
            if(nums[m] == target)
                return m;
            
            if(nums[l] <= nums[m])
                if(target > nums[m] || target < nums[l])
                    l = m+1;
                else
                    r = m-1;
                
            else
                if (target < nums[m] || target > nums[r])
                    r = m-1;
                else
                    l = m+1;
        }

        return -1;
    }

    public static int binarySearch(int[] arr, int key, int low, int high){
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == key)
                return mid;
            if (arr[mid] < key)
                low = mid + 1;
            if (arr[mid] > key)
                high = mid - 1;
        }
        return -1;
    }
}
