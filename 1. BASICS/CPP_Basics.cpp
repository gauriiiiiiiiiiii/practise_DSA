//General Skelton

#include<bits/stdc++.h> 
using namespace std;

int main () 
{
    // Input and Output
    cout << "Hello World!" << endl;
    cout << "Hello World!" << endl; 

    int x;
    cin >> x;
    cout << "Number is:" << x <<endl;

    // Data Types 
    int a = 10; // Integer
    
    long x = 1000000; // Long Integer
    long long y = 10000000000; // Long Long Integer

    float b = 10.5; // Float
    double c = 20.5; // Double
    long double e = 30.5; // Long Double
    short s = 5; // Short Integer

    char d = 'A'; // Character 
    string str = "Hello"; // String

    string str2; // Empty string   
    getline(cin, str2); // Read a string with spaces
    cout << "String is: " << str2 << endl;

    bool isTrue = true; // Boolean

    vector<int> vec = {1, 2, 3, 4, 5}; // Vector

    // If-Else
    int age;
    cin >> age;
    if (age >= 18) { cout << "You are an adult!" ;}
    else if (age < 18) { cout << "You are not an adult!" ; }
    else { cout << "Invalid age!" ; }

    int marks;
    cin >> marks;
    if (80 <= marks < 101) { cout << "Grade A"; }
    else if (60 <= marks < 80) { cout << "Grade B"; }
    else if (50 <= marks < 60) { cout << "Grade C"; }
    else if (45 <=marks < 50) { cout << "Grade D"; }
    else if (25 <=marks < 45) { cout << "Grade E"; }
    else if (marks < 25) { cout << "Grade F";}
    else { cout << "Invalid Marks"; }

    int marks;
    cin >> marks;
    if (marks < 25) { cout << "Grade F";}
    else if (marks < 45) { cout << "Grade E"; }
    else if (marks < 50) { cout << "Grade D"; }
    else if (marks < 60) { cout << "Grade C"; }
    else if (marks < 80) { cout << "Grade B"; }
    else if (marks < 101) { cout << "Grade A"; }
    else { cout << "Invalid Marks"; }

    // Nested If-Else

    int age;
    if (age < 18) { cout << "Not Eligible for Job"; }
    else if (age <= 57) {
        cout << "Eligible for Job" << endl;
        if (age >= 55) {cout << "Eligible for Job but Retirement Soon";}
        else if (age > 57) { cout << "Retirement Time"; }
    }

    // Switch Case
    
    

    return 0;
}




