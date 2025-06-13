// Use of two loops : Time Complexity: O(N*N) & Space Complexity: O(N)
void countFrequency(vector<int>& nums) {
    int n = nums.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << nums[i] << " " << count << endl;
    }
}

// Using Map : Time Complexity: O(N) & Space Complexity: O(N)
void Frequency(int arr[], int n) {
    unordered_map<int, int> map;
   
    for (int i = 0; i < n; i++) {
        map[arr[i]]++;       
    }
   
    for (auto x : map) {
        cout << x.first << " " << x.second << endl;      
    }
}

