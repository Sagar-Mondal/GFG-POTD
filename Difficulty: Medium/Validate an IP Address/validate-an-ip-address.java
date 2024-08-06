//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

import java.io.*;
import java.util.*;

public class validip {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            String s = sc.next();
            Solution obj = new Solution();

            if (obj.isValid(s))
                System.out.println("true");
            else
                System.out.println("false");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {

    public boolean isValid(String s) {
        int n = s.length();
         
        // for test cases like 1...1 or something lesser than 7
        if (n < 7)
            return false;
 
        // Using StringTokenizer to separate all the strings from
        // '.' and push back into vector like for example -
        // 222.111.111.111 vector is v = ["222", "111", "111", "111"]
        StringTokenizer st = new StringTokenizer(s, ".");
        int count = 0;
        while (st.hasMoreTokens()) {
            String substr = st.nextToken();
            count++;
 
            // If the substring size is greater than 1 and the first character is '0', return false
            if (substr.length() > 1 && substr.charAt(0) == '0')
                return false;
 
            // For substrings like a.b.c.d, checking if any character is non-numeric
            for (int j = 0; j < substr.length(); j++) {
                if (!Character.isDigit(substr.charAt(j)))
                    return false;
            }
 
            // Check if the number is greater than 255
            if (Integer.parseInt(substr) > 255)
                return false;
        }
        // If the count of substrings is not 4, return false
        if (count != 4)
            return false;
 
        return true;
    }
}