//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            
            String input[] = read.readLine().split(" ");
            String a = input[0];
            
            Solution ob = new Solution();
            if(ob.sameFreq(a)){
                System.out.println(1);
            }
            else{
                System.out.println(0);
            }
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    boolean sameFreq(String s) {
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char ch : s.toCharArray()) {
            frequencyMap.put(ch, frequencyMap.getOrDefault(ch, 0) + 1);
            
        }
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int frequency : frequencyMap.values()) {
            countMap.put(frequency, countMap.getOrDefault(frequency, 0) + 1);
            
        }
        if (countMap.size() == 1) {
            return true;
            
        }
        if (countMap.size() == 2) {
            int minFrequency = Collections.min(countMap.keySet());
            int maxFrequency = Collections.max(countMap.keySet());
            if ((minFrequency == 1 && countMap.get(minFrequency) == 1) ||
            (maxFrequency - minFrequency == 1 && countMap.get(maxFrequency) == 1)) {
                return true;
                
            }
            
        }
        return false;
        
    }
}