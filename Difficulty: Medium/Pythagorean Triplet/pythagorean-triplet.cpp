class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
      	int n = arr.size();
        int maxEle = 0;
        for (int ele: arr) 
            maxEle = max(maxEle, ele);
    
        // Visited array to mark the elements
        vector<bool> vis(maxEle + 1, 0);
    
        // Marking each element of input array
        for (int ele: arr)
            vis[ele] = true;
    
        // Iterate for all possible a
        for (int a = 1; a < maxEle + 1; a++) {
    
            // If a is not there
            if (vis[a] == false)
                continue;
    
            // Iterate for all possible b
            for (int b = 1; b < maxEle + 1; b++) {
    
                // If b is not there
            	if (vis[b] == false)
                	continue;
    
                // calculate c value to form a pythagorean triplet
                int c = sqrt(a * a + b * b);
    
                // If c^2 is not a perfect square or c exceeds the
              	// maximum value
                if ((c * c) != (a * a + b * b) || c > maxEle)
                    continue;
    
                // If there exists c in the original array,
                // we have found the triplet
                if (vis[c] == true) {
                    return true;
                }
            }
        }
        return false;
    }
};