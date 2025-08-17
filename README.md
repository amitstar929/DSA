# DSC Competitive Programming Recruitment Tasks (25-26)

This repository contains my solutions for the **DSC Competitive Programming Recruitment Tasks (25-26)**.  
All 5 tasks are solved in a **single C++ file** (`main.cpp`) with proper function separation and inline comments for clarity.

---

## 🚀 Contents
The repository includes solutions to the following problems:

1. **Parentheses Checker**  
   Check if a given string of brackets is balanced.  
   - Input Example: `()[]{}`  
   - Output Example: `Valid`  
   - Approach: Use a **stack** to track opening and closing brackets.  

2. **Longest Consecutive Subsequence**  
   Find the length of the longest subsequence with consecutive numbers, order doesn’t matter.  
   - Input Example: `[100,4,200,1,3,2]`  
   - Output Example: `4`  
   - Approach: Store numbers in a **hash set** and expand consecutive sequences.  

3. **Subarray Sum Equals K**  
   Count the number of continuous subarrays that sum up exactly to `k`.  
   - Input Example: `[1,2,3], k=3`  
   - Output Example: `2`  
   - Approach: Use **prefix sum + hashmap** to track previous sums.  

4. **Trapping Rain Water**  
   Calculate total water trapped between bars after rain.  
   - Input Example: `[0,1,0,2,1,0,1,3,2,1,2,1]`  
   - Output Example: `6`  
   - Approach: Precompute **leftMax[] and rightMax[]** for each bar, then sum trapped water.  

5. **Alien Dictionary (Topological Sort)**  
   Determine a valid order of characters from a sorted dictionary in an alien language.  
   - Input Example: `["baa","abcd","abca","cab","cad"]`  
   - Output Example: `bdac`  
   - Approach: Build a **graph of dependencies** and apply **Kahn’s algorithm (Topological Sort)**.  

---

## 🛠️ Implementation Details
- All 5 problems are solved in **one C++ file (`main.cpp`)**.  
- Each problem is implemented in a **separate function**:
  - `isBalanced()` → Parentheses Checker  
  - `longestConsecutive()` → Longest Consecutive Subsequence  
  - `subarraySum()` → Subarray Sum Equals K  
  - `trap()` → Trapping Rain Water  
  - `alienOrder()` → Alien Dictionary  

- The `main()` function demonstrates example input/output for each task.

---

## ▶️ How to Run

### Compile
```bash
g++ main.cpp -o dsc_tasks

// Example Output

Enter a string of brackets to check if it is balanced: ()[]{}
Valid
Length of the longest consecutive subsequence: 4
Count of valid subarrays: 2
Units of trapped water: 6
A valid order of characters: bdac

