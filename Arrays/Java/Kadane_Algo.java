import java.util.Scanner;

public class Kadane_Algo {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[]= new int[n];
        for(int i = 0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        Algo obj = new Algo();
        System.out.println(obj.maxSumArray(arr, n));
    }
}
class Algo{
    int maxSumArray(int a[], int n){
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