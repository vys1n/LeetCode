public class maxSubArray {
    public static void main(String[] args) {
        int[] arr = {2,-3,4,-2,2,1,-1,4};
        // BruteForceMaxSubArray(arr);
        // PrefixSumMaxSubArray(arr);
        KadaneMaxSubArray(arr);
    }

    public static void BruteForceMaxSubArray(int[] arr) {
        int maxSum = Integer.MIN_VALUE;
        int currSum = 0;
        for (int i=0; i<arr.length; i++) {
            int start = i;
            for (int j=i; j<arr.length; j++) {
                int end = j;
                currSum = 0;
                for (int k=start; k<=end; k++) {
                    currSum += arr[k];
                }
                if (maxSum < currSum)
                    maxSum = currSum;
            }
        }
        System.out.println(maxSum);
    }

    public static void PrefixSumMaxSubArray(int[] arr) {
        int n = arr.length;
        int[] prefixSum = new int[n+1];

        prefixSum[0] = 0;

        for (int i=0; i<n; i++)
            prefixSum[i+1] = prefixSum[i] + arr[i];

        int maxSum = Integer.MIN_VALUE;

        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                int currSum = prefixSum[j+1] - prefixSum[i];
                if (maxSum < currSum)
                    maxSum = currSum;
            }
        }

        System.out.println(maxSum);
    }

    public static void KadaneMaxSubArray(int[] arr) {
        /* int maxSum = Integer.MIN_VALUE;
        int curSum = 0;
        for (int i=0; i<arr.length; i++) {
            curSum += arr[i];
            if (curSum < arr[i])
                curSum = arr[i];
            if (maxSum < curSum)
                maxSum = curSum;
        }
        System.out.println(maxSum); */

        int maxSum = arr[0], curSum = 0;
        for (int num : arr) {
            if (curSum < 0)
                curSum = 0;
            curSum += num;
            maxSum = Math.max(maxSum, curSum);
        }
        System.out.println(maxSum);
    }
}
