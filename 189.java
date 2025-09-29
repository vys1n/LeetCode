public class rotateArray {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        int k = 3;
        PrintArray(arr);
        ReverseRotateArray(arr, k);
        PrintArray(arr);
    }

    public static void PrintArray(int[] arr) {
        for (int val : arr)
            System.out.print(val + " ");
        System.out.println();
    }

    public static void BruteForceRotateArray(int[] nums, int k) {
        int n = nums.length;
        k %= n;
        for (int i=0; i<k; i++) {
            int lastElement = nums[n-1];
            for (int j=n-1; j>0; j--) {
                nums[j] = nums[j-1];
            }
            nums[0] = lastElement;
        }
    }

    public static void ReverseRotateArray(int[] nums, int k) {
        int n = nums.length;
        k %= n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }

    public static void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}
