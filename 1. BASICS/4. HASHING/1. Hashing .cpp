Hashing is a technique to store and fetch data efficiently
Pre-store information (like frequency of elements) & Quickly retrieve the answer (without looping every time)

// Brute Force Approach:
For every query: Loop over the array & Count how many times the number appears

Time Complexity: O(Q * N) If Q = 10^5 and N = 10^5, → 10^10 operations = slow

// Optimized Approach: Hashing
Precompute Frequencies Use a hash array to store how many times each number appears
This runs once in O(N)

Limitation: If array has very large elements like 10^9, you can not create hash[10^9 + 1]  it is too big!

int hash[13] = {0}; // Assuming max number is 12
for (int i = 0; i < n; i++) {
    hash[arr[i]] += 1;
}
cout << hash[number] << endl;

// Hash Map instead of an array allows dynamic memory and works for large numbers
unordered_map<int, int> hash;
for (int i = 0; i < n; i++) {
    hash[arr[i]]++;
}

// Character Hashing:
Given a string like "abcdabefc" and queries like ['a', 'c', 'z'], return the number of times each character appears

// Brute Force Approach
Loop over the entire string for each query and count the matches
Time Complexity: O(Q * N) (Q = number of queries, N = string length), Not efficient if Q or N is large.

// Optimized Approach – Character Hashing
Use frequency array or hash table to store frequency of characters
Mapping Characters to Array Index: 'a' - 'a' = 0, 'b' - 'a' = 1, ..., 'z' - 'a' = 25

// LowerCase Letters
int hash[26] = {0};
for (int i = 0; i < s.size(); i++) {
    hash[s[i] - 'a']++;
}
cout << hash[query_char - 'a'];

// For Mixed Case: Use a hash array of size 256 (for all ASCII characters)
int hash[256] = {0};
for (char c : s) hash[c]++;
cout << hash[query_char];

// map or unordered_map : Handling Large Numbers or Arbitrary Keys
map<int, int> freq;
for (int i = 0; i < n; i++) {
    freq[arr[i]]++;
}
cout << freq[x] << endl; // returns 0 if x not present

// map 
Internal DS	: Balanced BST
Order :	Sorted by keys
Time (Insert/Find) : O(log N)
Use When : Sorted traversal

// unordered_map
Internal DS	: Hash Table
Order :	No order
Time (Insert/Find) : O(1) average, O(N) worst
Use When : Fast lookups required

// Hash Function: Division Method (Modulo)
index = value % mod

Collision
Occurs when multiple different values map to the same hash index

How to Handle Collisions: Linear Chaining
Instead of storing just frequency, you store a list (or a linked list)
When searching, you: Go to the correct index,  Linearly scan the list at that index

This avoids overwriting data
But increases time when too many land in the same spot
Scan the entire chain → O(N) - worst-case time complexity




