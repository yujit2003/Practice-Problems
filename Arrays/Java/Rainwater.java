// container with most water - leetcode problem 11 - Arrays
import java.util.Scanner;
public class Rainwater {
    public static void main(String[] args){                         //main function
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();                                       //taking inputs
        int arr[]= new int[n];
        for(int i = 0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        Solution obj = new Solution();                                      //creating object
        System.out.println(obj.maxArea(arr));
    }
}
class Solution {
    int maxArea(int[] height) {                                 //function that have the logic
    int left = 0;
    int right = height.length - 1;
    int max = 0;
    while (left < right) {
        int lh = height[left];
        int rh = height[right];
        int min = Math.min(lh, rh);
        int len = right - left;
        int area = min * len;
        max = Math.max(max, area);
        if (lh < rh)
            left++;
        else
            right--;
    }
    return max;
}
}
