#include <bits/stdc++.h>
using namespace std;

// Function Declaration
bool isBalanced(string s);
int longestConsecutive(vector<int>& nums);
int subarraySum(vector<int>& nums, int k);
int trap(vector<int>& height);
string alienOrder(vector<string>& words);


// Function to check if the brackets in the string are balanced
bool isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        // If opening bracket, push into stack
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } 
        else {
            // If stack is empty -> no opening bracket
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            // Check correct matching
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty(); // If empty -> all matched
}

// Function to find the length of the longest consecutive sequence in an array
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;

    for (int num : nums) {
        // Start of a sequence (previous number not present)
        if (!s.count(num - 1)) {
            int currentNum = num;
            int streak = 1;

            // Count consecutive numbers
            while (s.count(currentNum + 1)) {
                currentNum++;
                streak++;
            }
            longest = max(longest, streak);
        }
    }
    return longest;
}

// Function to count the number of subarrays with a sum equal to k
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp; // prefixSum -> frequency
    mp[0] = 1; // base case (empty subarray)
    
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        if (mp.find(sum - k) != mp.end()) {
            count += mp[sum - k];
        }
        mp[sum]++;
    }
    return count;
}

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i-1], height[i]);

    rightMax[n-1] = height[n-1];
    for (int i = n-2; i >= 0; i--)
        rightMax[i] = max(rightMax[i+1], height[i]);

    int water = 0;
    for (int i = 0; i < n; i++)
        water += min(leftMax[i], rightMax[i]) - height[i];

    return water;
}

string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> indegree;

    // Initialize indegree for all characters
    for (auto &word : words) {
        for (char c : word) {
            indegree[c] = 0;
        }
    }

    // Build graph from adjacent words
    for (int i = 0; i < words.size()-1; i++) {
        string w1 = words[i], w2 = words[i+1];
        int len = min(w1.size(), w2.size());
        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                if (!adj[w1[j]].count(w2[j])) {
                    adj[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                break;
            }
        }
    }

    // BFS (Kahn’s algorithm)
    queue<char> q;
    for (auto &p : indegree) {
        if (p.second == 0) q.push(p.first);
    }

    string order = "";
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        order += c;

        for (char nei : adj[c]) {
            indegree[nei]--;
            if (indegree[nei] == 0) q.push(nei);
        }
    }

    return order;
}

// Function Calling and Input/Output

int main() {
    
    cout << "Enter a string of brackets to check if it is balanced: ";
    string s;
    cin >> s;
    if (isBalanced(s)) cout << "Valid\n";
    else cout << "Invalid\n";

    vector<int> arr1 = {100, 4, 200, 1, 3, 2};
    cout << "Length of the longest consecutive subsequence: " << longestConsecutive(arr1) << endl;

    vector<int> arr2 = {1, 2, 3};
    int k = 3;
    cout << "Count of valid subarrays: " << subarraySum(arr2, k) << endl;

    vector<int> arr3 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Units of trapped water: " << trap(arr3) << endl;

    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    cout << "A valid order of characters: " << alienOrder(words) << endl;
    return 0;
}

