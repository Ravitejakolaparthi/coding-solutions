# TRTR3 - Rating 1479

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Triple Threat

For a  **binary**  string $A$ of length $3N$, we define a new binary string $f(A)$ of length $N$ via the following rule:

- For each index $i$ ($1 \le i \le N$), the $i$-th character of $f(A)$ is the most frequent element among the three values $(A_i, A_{i+N}, A_{i+2N})$.

For example, if $N=3$ and $A = \texttt{010100110}$ then $f(A) = \texttt{110}$ because:

- The first character is the most frequent element among $(A_1, A_4, A_7) = (0, 1, 1)$, which is $1$.
- The second character is the most frequent element among $(A_2, A_5, A_8\} = (1, 0, 1)$, which is $1$.
- The third character is the most frequent element among $(A_3, A_6, A_9) = (0, 0, 0)$, which is $0$.

You're given two integers $N$ and $X$. Find  *any*  binary string $A$ of length $3N$ satisfying the following conditions:

- $A$ contains exactly $X$ ones and $3N-X$ zeros, and
- $f(A)$ is lexicographically minimum$^\dagger$ across all strings satisfying the first condition.

If there are multiple valid strings, you may find any of them.
Note that you do not need to lexicographically minimize $A$, but rather find $A$ that minimizes $f(A)$ lexicographically.

$^\dagger$We say a binary string $P$ is lexicographically smaller than a binary string $Q$ of the same length if and only if there exists an index $i$ such that:

- $P_j = Q_j$ for each $1 \le j \lt i$, and
- $P_i = 0$ but $Q_i = 1$
### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of a single line of input, containing $2$ space-separated integers $N$ and $X$.
### Output Format

For each test case, output on a new line the binary string $A$ of length $3N$ you found that contains exactly $X$ ones and lexicographically minimizes $f(A)$.

If there are multiple valid solutions, any of them will be accepted.

### Constraints
- $1 \leq T \leq 15250$
- $1 \leq N \leq 100$
- $0 \leq X \leq 3N$
### Sample 1:
Input
Output

```
3
1 0
2 2
3 5

```

```
000
100001
011101001
```

### Explanation:

 **Test case $1$:**  We need a string of length $3$ with $0$ ones. The only choice is $\texttt{000}$ so that's the answer.

 **Test case $2$:**  We need a string of length $6$ with $2$ ones. For $A = \texttt{100001}$ we have $f(A) = \texttt{00}$ which is clearly lexicographically minimum.
So, this $A$ is a valid answer.

 **Test case $3$:**  We need a string of length $9$ with $5$ ones. For $A = \texttt{011101001}$ we have $f(A) = \texttt{001}$. It can be proved that we cannot obtain a lexicogaphically smaller value of $f(A)$ under the given constraints.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-09T10:23:50.041Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/TRTR3)