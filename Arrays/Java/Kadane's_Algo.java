//Kadane algo to return the largest the maximum sum of contiguous sub array
//For Ex -> arr[] = [-5, 4, 6, -3, 4, -1] Output -> 11

import java.util.Scanner;

public class Kadane_Algo {
    public static void main(String[] args){				// main function
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();						//taking inputs nno. of elements and array
        int arr[]= new int[n];
        for(int i = 0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        Algo obj = new Algo();						 //creating object
        System.out.println(obj.maxSumArray(arr, n));
    }
}
class Algo{
    int maxSumArray(int a[], int n){					//function that have logic of the algorithm
        int maxSum = 0;
        int currSum = 0;
        for(int i = 0; i<n;i++){
            currSum = currSum + a[i];
            if(currSum > maxSum){
                maxSum = currSum;
            }
            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
}