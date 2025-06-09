/*
Recursion is a programming technique where a function calls itself to solve a smaller instance of the problem
*/

// Factorial 
int factorial(int n) {
    if (n == 0) return 1;         // base case
    return n * factorial(n - 1);  // recursive case
}

