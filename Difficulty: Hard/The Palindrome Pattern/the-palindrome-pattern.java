//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        Solution ob = new Solution();
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String input_line[] = read.readLine().trim().split("\\s+");
            int n = Integer.parseInt(input_line[0]);
            String input_line1[] = read.readLine().trim().split("\\s+");
            int[][] a = new int[n][n];
            int c = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = Integer.parseInt(input_line1[c]);
                    c++;
                }
            }
            String ans = ob.pattern(a);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public String pattern(int[][] arr) {
        int n = arr.length;
        
        for(int i=0;i<n;i++){
            //check if ith row is Palindrome 
            if(Row_Palindrome(i,n,arr))   return i+" R";
        }
        
        for(int i=0;i<n;i++){
            //check if ith row is Palindrome 
            if(Column_Palindrome(i,n,arr))   return i+" C";
        }
        
        return "-1";
    }
    boolean Row_Palindrome(int row,int n,int a[][]){
        int l=0, r=n-1;
        while(l<r){
            if(a[row][l]==a[row][r]){
                l++;
                r--;
            }else{
                return false;
            }
        }
        return true;
    }
    boolean Column_Palindrome(int col,int n,int a[][]){
        int l=0, r=n-1;
        while(l<r){
            if(a[l][col]==a[r][col]){
                l++;
                r--;
            }else{
                return false;
            }
        }
        return true;
    }
}
