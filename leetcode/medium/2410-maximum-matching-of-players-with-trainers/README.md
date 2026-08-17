# Maximum Matching of Players With Trainers

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a  **0-indexed**  integer array `players`, where `players[i]` represents the  **ability**  of the `ith` player. You are also given a  **0-indexed**  integer array `trainers`, where `trainers[j]` represents the  **training capacity** of the `jth` trainer.

The `ith` player can  **match**  with the `jth` trainer if the player's ability is  **less than or equal to**  the trainer's training capacity. Additionally, the `ith` player can be matched with at most one trainer, and the `jth` trainer can be matched with at most one player.

Return  *the  **maximum**  number of matchings between* `players` *and* `trainers` *that satisfy these conditions.* 

 

 **Example 1:** 

```
Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2
Explanation:
One of the ways we can form two matchings is as follows:
- players[0] can be matched with trainers[0] since 4 <= 8.
- players[1] can be matched with trainers[3] since 7 <= 8.
It can be proven that 2 is the maximum number of matchings that can be formed.

```

 **Example 2:** 

```
Input: players = [1,1,1], trainers = [10]
Output: 1
Explanation:
The trainer can be matched with any of the 3 players.
Each player can only be matched with one trainer, so the maximum answer is 1.

```

 

 **Constraints:** 

- 1 <= players.length, trainers.length <= 105
- 1 <= players[i], trainers[j] <= 109

 

 **Note:**  This question is the same as 445: Assign Cookies.

## Solution

**Language:** C++  
**Runtime:** 31 ms (beats 40.04%)  
**Memory:** 80.2 MB (beats 80.92%)  
**Submitted:** 2026-08-17T09:41:32.364Z  

```cpp
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i = 0;
        int j = 0;
        sort(trainers.begin(),trainers.end());
        sort(players.begin(),players.end());
        while(i < players.size() &&  j < trainers.size()){
            if(trainers[j] >= players[i]){
                i++;
            }
            j++;
        }
        return i;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/)