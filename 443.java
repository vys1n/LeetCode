class Solution {
    public int compress(char[] chars) {
        StringBuilder s = new StringBuilder();
        for (int i=0; i<chars.length; i++) {
            int count = 1;
            while (i+1 < chars.length && chars[i] == chars[i+1]) {
                count++;
                i++;
            }
            s.append(chars[i]);
            if (count > 1)
                s.append(count);
        }
        for (int i=0; i<s.length(); i++) {
            chars[i] = s.charAt(i);
        }
        return s.length();
    }
}

/*
public int compress(char[] chars) {
    int len = chars.length;
    int i = 0, k = 0;   // i is read pointer, k is write pointer
    
    while (i < len) {
        chars[k++] = chars[i];
        int j = i + 1;
        
        while (j < len && chars[i] == chars[j])
            j++;

        if (j-i > 1) {
            String current = String.valueOf(j-i);
            for (char c : current.toCharArray())
                chars[k++] = c;
        }

        i = j;
    }

    return k;
}

TC - O(n)
SC - O(1)

*/

/*
        int j = 0;
        int i = 0;
        int len = chars.length;
        while(i<len){
            char first_ch = chars[i];
            int count = 0;
            while(i<len && chars[i] == first_ch){
                count++;
                i++;
            }
            chars[j] = first_ch;
            j++;
            if(count>1){
                String temp = Integer.toString(count);
                for(char c : temp.toCharArray()){
                    chars[j] = c;
                    j++;
                }
            }
        }
        return j;
*/
