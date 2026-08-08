# RATIO2 - Rating 1035

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Ratio By 2

You have $2$ positive integers $X$ and $Y$.

In one operation, you can change the value of  **one**  of the integers by $1$ or $-1$.

Find the minimum number of operations needed to ensure that either $X \ge (2 \cdot Y)$ or $Y \ge (2 \cdot X)$, i.e. either $X$ is at least twice as large as $Y$, or $Y$ is at least twice as large as $X$.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first and only line of test case contains $2$ space-separated integers $X$ and $Y$.
### Output Format

For each test case, output on a new line the minimum number of operations.

### Constraints
- $1 \le T \le 81$
- $2 \le X, Y \le 10$
### Sample 1:
Input
Output

```
6
2 4
4 4
3 5
10 6
8 7
2 7

```

```
0
2
1
1
3
0
```

### Explanation:

 **Test case $1$:**  $Y \ge (2 \cdot X)$ already holds as $4 \ge (2 \cdot 2)$.

 **Test case $2$:**  Decrease $Y$ twice by $1$ to get $X = 4, Y = 2$. Then, $X \geq (2\cdot Y)$ holds.
This is the minimum possible number of operations.

 **Test case $3$:**  Increase $Y$ by $1$ to get $X = 3, Y = 6$. Then $Y \ge (2 \cdot X)$ holds.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-08T16:51:09.072Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >>y;
        if(x >= 2*y || y >= x*2)
        {
            cout << 0 <<endl;
            continue;
        }
        int a,b,c,d;
        a = x*2-y;
        b = y-x/2;
        c = y*2-x;
        d =x-y/2;
        int ans = min({a,b,c,d});
        cout << ans <<endl;
    }
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/RATIO2)