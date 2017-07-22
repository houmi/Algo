#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

void printArray(vector<int> arr, bool print = true) {
    if (print) {
        cout << "Print vector" << endl;
    }
    string delim = "";
    for (auto num : arr) {
        cout << delim << num;
        delim = ",";
    }
    cout << endl;

}

void findPairSum(vector<int> arr, int k) {
    unordered_set<int> set;

    cout << "Find Pair Sum" << endl;

    for (auto num : arr) {
        int target = k - num;
        if (set.find(target) != set.end()) {
            cout << num << "+" << target << "=" << k << endl;
        } else {
            set.insert(num);
        }
    }
}

void removeDuplicates(vector<int> arr) {
    cout << "Remove Dups" << endl;
    vector<int> arr2(arr);
    sort(arr2.begin(), arr2.end());

    int idx = 0;
    for (int i=1; i<arr2.size();i++) {
        if (arr2[i] != arr2[idx]) {
            arr2[++idx] = arr2[i];
        }
    }
    
    arr2.resize(idx);
    printArray(arr2, false);
}

void maximumSubarray(vector<int> arr) {
    cout << "Maximum Sub-array: ";
    int curSum = 0;
    int maxSum = 0;
    curSum = maxSum = INT_MIN;
    for ( auto num : arr) {
        curSum = max(curSum+num, num);
        maxSum = max(curSum, maxSum);
    }

    cout << maxSum << endl;

}

void merge(vector<int> &arr, int low, int middle, int high) {
    vector<int> aux(arr);
    int i=low, j = middle+1;

    for (int k=low; k<=high;k++) {
        if (i>middle) {  
            arr[k] = aux[j++];
        } else if (j>high) {
            arr[k] = aux[i++];
        }   
        else if (aux[i] < aux[j]) {
            arr[k] = aux[i++];
        } else {
            arr[k] = aux[j++];
        }
    }
}

void mergesorthelper(vector<int> &arr, int low, int high) {
    if (low<high) {
        int mid = low + (high-low)/2;
        mergesorthelper(arr, low, mid);
        mergesorthelper(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void mergesort(vector<int> arr) {
    cout << "Merge Sort" << endl;
    vector<int> arr2(arr);
    mergesorthelper(arr2, 0, arr2.size()-1);
    printArray(arr2, false);
}

int qs_partition(vector<int> &arr, int low, int high) {
    
    int pivot = high;
    int firsthigh = low;
    for (int i=low; i<high; i++) {
        if (arr[i] < arr[pivot]) {
            swap(arr[i], arr[firsthigh]);
            firsthigh++;
        }
    }
    swap(arr[firsthigh], arr[pivot]);

    return firsthigh;
}

void quicksorthelper(vector<int> & arr, int low, int high) {
    if (low < high) {
        int p = qs_partition(arr, low, high);
        quicksorthelper(arr, low, p-1);
        quicksorthelper(arr, p+1, high);
    }
}

void quicksort(vector<int> arr) {
    cout << "Quick Sort" << endl;
    vector<int> arr2(arr);
    quicksorthelper(arr2, 0, arr2.size()-1);
    printArray(arr2, false);
}


void frequency(vector<int> arr) {
    cout << "Number:Frequency" << endl;
    map<int,int> freq;
    for (auto num : arr) {
        freq[num]++;
    }

    priority_queue<pair<int, int>> pq;
    for (auto it : freq) {
        pq.push(make_pair(it.second, it.first));
    }

    while (!pq.empty()) {
        cout << pq.top().second << ":" << pq.top().first << endl;
        pq.pop();
       
    }
}


int main() {

    vector<int> arr = {50,3,2,-9, 10,9,45,-40, 123,2,3,1,2,5,9,8,-11,25,30,10,19,3};

    printArray(arr);
    findPairSum(arr, 13);
    removeDuplicates(arr);
    maximumSubarray(arr);
    mergesort(arr);
    quicksort(arr);
    frequency(arr);


    
    return 0;

}