import java.util.ArrayList;
import java.util.List;

class solution{
    public List<List<Integer>> permute(int[] nums){
        List<List<Integer>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), nums);
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> tempList, int[] nums){
        // BASE CASE
        // if the curr perm is the same len as the original arr, it is complete
        if (tempList.size() == nums.length){
            // add a new ArrayList copy of tempList
            result.add(new ArrayList<>(tempList));
            return;
        }
        
        // recursion
        for (int i=0; i<nums.length; i++){
            // 1. check if element already present in the curr perm (tempList)
            if (tempList.contains(nums[i])) continue;   // skip if already chosen

            // 2. choose
            tempList.add(nums[i]);

            // 3. recurse
            // move to the next level of the tree
            backtrack(result, tempList, nums);

            // 4. un-choose
            // remove the last added element to reset the state
            // and try a diff no. in the curr position
            tempList.remove(tempList.size() - 1);
        }
    }
}
