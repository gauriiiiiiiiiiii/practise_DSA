void countFreq(int arr[], int n) {
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    int maxFreq = 0, minFreq = INT_MAX, maxEl = 0, minEl = 0;

    for (auto it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            maxEl = it.first;
        }
        if (it.second < minFreq) {
            minFreq = it.second;
            minEl = it.first;
        }
    }

    cout << "The highest frequency element is: " << maxEl << "\n";
    cout << "The lowest frequency element is: " << minEl << "\n";
}



