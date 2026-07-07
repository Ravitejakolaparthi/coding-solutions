# EQEXCH - Rating 1019

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Equivalent Exchange

A certain shop sells two colors of stones: red stones and blue stones.

Today, $N$ customers, numbered $1, 2, \ldots, N$, will visit the shop  **in order**.
The $i$-th customer will request a trade with parameter $A_i$, where:

- If $A_i \gt 0$, then the $i$-th customer will give $A_i$ red stones to the shop, and wants $A_i$ blue stones in return.
- If $A_i \lt 0$, then the $i$-th customer will give $-A_i$ blue stones to the shop, and wants $-A_i$ red stones in return.

It is guaranteed that $A_i \ne 0$ for all $1 \le i \le N$.

The shop can only hold a total of $K$ stones.
At the start of the day, before any customers enter, the shopkeeper will choose an integer $X$ ($0 \le X \le K$), and stock the shop with $X$ red stones and $K-X$ blue stones.

Determine if it is possible for the shopkeeper process all $N$ trades without ever running out of stones of either color.
More formally, determine if it is possible to choose $X$ in such a way that the following condition holds:

- The number of red stones and the number of blue stones in the shop both remain non-negative at all points of time.
### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains two space-separated integers $N$ and $K$ — the number of trades and the total number of stones in the shop. The second line contains $N$ space-separated integers $A_1, \ldots, A_N$.
### Output Format

For each test case, output on a new line the answer: `Yes` if it's possible to always have a non-negative number of both colors of stones, and `No` otherwise.

Each letter of the output may be printed in either uppercase or lowercase, i.e. the strings `NO`, `No`, `nO`, and `no` will be treated as equivalent.

### Constraints
- $1 \leq T \leq 100$
- $1 \leq N \leq 100$
- $1 \le K \le 1000$
- $-100 \le A_i \le 100$
- $A_i \ne 0$
### Sample 1:
Input
Output

```
4
3 10
5 2 -9
2 3
2 2
4 12
-4 -7 8 -10
4 8
8 -8 8 -8

```

```
Yes
No
No
Yes

```

### Explanation:

 **Test case $1$:**  One possibility is for the shopkeeper to choose $X = 2$, starting with $2$ red stones and $8$ blue stones. Then,

- $A_1 = 5$, so the first customer will give $5$ red stones and wants $5$ blue stones. After this transaction, the shop has $7$ red stones and $3$ blue stones.
- $A_2 = 2$, so the second customer will give $2$ red stones and wants $2$ blue stones. After this transaction, the shop has $9$ red stones and $1$ blue stone.
- $A_3 = -9$, so the third customer will give $9$ blue stones and wants $9$ red stones. After this transaction, the shop has $0$ red stones and $10$ blue stones.

The number of stones of both types were always $\ge 0$, so this is a success and the answer is `Yes`.

 **Test case $2$:**  We have $K = 3$. Note that:

- If $X = 2$ or $X = 3$ is chosen, then we start with $\le 1$ blue stone. However, the first transaction asks for $2$ blue stones so we'll end up negative. Thus, these are not valid.
- If $X = 0$ or $X = 1$ are chosen, after the first transaction we give away two blue stones; so we again have $\le 1$ blue stone remaining. The second transaction also asks for $2$ blue stones and we're thus unable to complete it.

Since no starting value of $X$ is valid, the answer is `No`.

 **Test case $3$:**  It can be verified that no matter the choice of $X$ in $[0, 12]$ will allow us to keep a non-negative number of red and blue stones at all times; so the answer is `No`.

 **Test case $4$:**  We can choose $X = 0$ and then all transactions are valid.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-07T16:50:56.066Z  

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int>v(n);
        for(int i =0;i<n;i++)
        cin >> v[i];
        vector<int>prefix(n+1);
        prefix[0]=0;
        // prefix[1]=v[0];
        for(int i=1;i<n+1;i++)
        {
            prefix[i] = v[i-1] + prefix[i-1];
        }
        int m = 99999;
        int b = -1;
        for(int i = 0;i<n+1;i++)
        {
            m = min(m,prefix[i]);
            b = max(b,prefix[i]);
        }
        if(b - m >k)
        cout << "No\n";
        else
        cout << "Yes\n";
        
    }
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/EQEXCH)