// Problem Description
 
 

// Determine whether an integer is a palindrome. Do this without extra space.

// A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed. Negative numbers are not palindromic.

// Example :

// Input : 12121
// Output : 1


// Input : 123
// Output : 0



int Solution::isPalindrome(int A) {
    
    int rev,sum=0;
    int temp = A;
    
    while(A>0){
       rev=A%10;
        A=A/10;
       sum=sum*10+rev;
     
       
    }
    
    return temp==sum;
    
     
}
