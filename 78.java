import java.util.ArrayList;
import java.util.List;

class solution{
    public static List<List<Integer>> subsets(int[] nums){
        //create a list containing the only empty subset
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<>()); // add the empty subset

        for (int num : nums){
            int size = ans.size();  // current number of subsets in the ans list
            
            // iterate over all the subsets that EXISTED BEFORE we processed the current 'num'
            for (int i=0; i<size; i++){
                // // get the subset from the existing list
                // List<Integer> existingSubset = ans.get(i);
                // // create a new list (inclusion path)
                // List<Integer> newSubset = new ArrayList<>(existingSubset);
                
                // combining the above 2 steps
                List<Integer> subset = new ArrayList<>(ans.get(i));

                // add the current 'num' to the subset
                subset.add(num);

                // add the subset to 'ans' list
                ans.add(subset);
            }
        }

        return ans;
    }
}
