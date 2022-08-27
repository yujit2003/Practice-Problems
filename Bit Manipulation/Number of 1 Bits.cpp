// Write a function that takes an integer and returns the number of 1 bits it has.

// Example Input
// Input1:
//     11 
  
// Example Output
// Output1:
// 3

// Explaination1:
// 11 is represented as 1101 in binary 



int Solution::numSetBits(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

unsigned int count=0;
    while(A){
        A=A&(A-1);
        count++;
    }
    
    return count;
    
    
}

