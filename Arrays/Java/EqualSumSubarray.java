// link for problem :-https://leetcode.com/contest/biweekly-contest-86/problems/find-subarrays-with-equal-sum/

class Solution {
    public boolean findSubarrays(int[] nums) {
        int n=nums.length;
        boolean res=false;
        int i=0;
        while(i<n-2)
        {
            int sum=nums[i]+nums[i+1];
            int j=i+1;
            while(j<n-1)
            {
                if(nums[j]+nums[j+1]==sum)
                {
                    res=true;
                    return res;
                }
                else
                {
                    j+=1;
                }
            }
            i+=1;
        }
        
        return res;
        
    }
}
