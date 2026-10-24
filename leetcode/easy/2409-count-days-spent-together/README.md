# Count Days Spent Together

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Alice and Bob are traveling to Rome for separate business meetings.

You are given 4 strings `arriveAlice`, `leaveAlice`, `arriveBob`, and `leaveBob`. Alice will be in the city from the dates `arriveAlice` to `leaveAlice` (**inclusive**), while Bob will be in the city from the dates `arriveBob` to `leaveBob` (**inclusive**). Each will be a 5-character string in the format `"MM-DD"`, corresponding to the month and day of the date.

Return *the total number of days that Alice and Bob are in Rome together.* 

You can assume that all dates occur in the  **same**  calendar year, which is  **not**  a leap year. Note that the number of days per month can be represented as: `[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]`.

 

 **Example 1:** 

```
Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
Output: 3
Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.

```

 **Example 2:** 

```
Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
Output: 0
Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.

```

 

 **Constraints:** 

- All dates are provided in the format "MM-DD".
- Alice and Bob's arrival dates are earlier than or equal to their leaving dates.
- The given dates are valid dates of a non-leap year.

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 12.12%)  
**Memory:** 7.7 MB (beats 97.58%)  
**Submitted:** 2026-10-24T14:36:07.039Z  

```cpp
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        map<int,int>Info1 = {{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
        pair<int,int> Alicestartmonth = {0,0};
        pair<int,int> Aliceendmonth ={0,0};
        pair<int,int> Bobstartmonth = {0,0};
        pair<int,int> Bobendmonth = {0,0};
        
        Alicestartmonth = {(arriveAlice[0]-'0')*10 + (arriveAlice[1]-'0'),(arriveAlice[3]-'0')*10 + (arriveAlice[4]-'0')};
        Bobstartmonth = {(arriveBob[0]-'0')*10 + (arriveBob[1]-'0'),(arriveBob[3]-'0')*10 + (arriveBob[4]-'0')};

        Aliceendmonth = {(leaveAlice[0]-'0')*10 + (leaveAlice[1]-'0'),(leaveAlice[3]-'0')*10 + (leaveAlice[4]-'0')};
        Bobendmonth = {(leaveBob[0]-'0')*10  + (leaveBob[1]-'0'),(leaveBob[3]-'0')*10  + (leaveBob[4]-'0')};
        
        if (Aliceendmonth < Bobstartmonth || Bobendmonth < Alicestartmonth)
            return 0;

        pair<int,int>start = {0,0};
        if(Alicestartmonth.first > Bobstartmonth.first || (Alicestartmonth.first == Bobstartmonth.first && Alicestartmonth.second > Bobstartmonth.second)){
            start = Alicestartmonth;
        }else{
            start = Bobstartmonth;
        }
        
        pair<int,int>end={0,0};
        if(Aliceendmonth.first < Bobendmonth.first || (Aliceendmonth.first == Bobendmonth.first && Aliceendmonth.second < Bobendmonth.second)){
            end = Aliceendmonth;
        }else{
            end = Bobendmonth;
        }
        
        if(start.first == end.first){
            return end.second - start.second + 1;
        }
        
        int days = 0;
        days = Info1[start.first] - start.second + 1;
        for(int i = start.first + 1; i < end.first; i++){
            days += Info1[i];
        }
        days += end.second;
        return days;
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/count-days-spent-together/)