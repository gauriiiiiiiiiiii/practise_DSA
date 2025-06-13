/*
Recursion is a programming concept where a function calls itself to solve smaller subproblems of a larger task

Base Condition
This is the stopping point for recursion
Without a base condition, recursion continues infinitely, causing errors

Stack Overflow
Every recursive call is stored in a call stack
If there's no base condition, the function calls pile up endlessly, exhausting memory and causing a stack overflow (or Segmentation Fault)

Recursive Tree
A visual way to represent how recursive calls are made and returned
It helps understand the flow of execution
*/

// Print name N times
void printName(string name, int n, int i = 1) {
    if (i > n) return; // Base case
    cout << name << endl;
    printName(name, n, i + 1); // Recursive call with incremented counter
}

// Print 1 to N 
void printNum(int i = 1, int n) {
    if (i > n) return;           
    cout << i << endl;           
    printNum(i + 1, n);          
}

// Print 1 to N using Backtracking
void printNumBacktrack(int n) {
    if (n == 0) return;         
    printNumBacktrack(n - 1);           
    cout << n << endl;         
}

// Print N to 1 
void printNumReverse(int n) {
    if (n == 0) return;           
    cout << n << endl;           
    printNumReverse(n-1);         
}


// Print N to 1 using Backtracking
void printNumReverseBacktrack(int n) {
    if (n == 0) return;
    cout << n << endl;
    printNumReverseBacktrack(n - 1);
}

// Sum of first N numbers
int findSum(int n, int sum = 0) {
    if (n == 0) return sum;
    return findSum(n - 1, sum + n);
}

// Factorial of N numbers
int findFactorial(int n, int factorial = 1) {
    if (n == 1) return factorial;
    return findFactorial(n - 1, factorial * n);
}

// Reverse an array
vector<int> reverse(vector<int> &arr, int n){
    if (n == 0) return;
    cout << arr[n-1] << " ";
    reverse(arr, n-1);
}

