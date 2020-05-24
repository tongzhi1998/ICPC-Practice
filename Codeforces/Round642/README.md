########## Personal Submission For Codeforces Round 642 ########

Problem A&B are trivial, so we omit the explanation for them. \

C. This problem is not hard, but can you really solve it by just using one line of code?\
My Solution: Let dp[i] represents the # of moves needed for a board of length i,
We can easily derive that dp[i] = dp[i-2] + (pow(i,2)-pow(i-2,2))**(i/2). We can then pre-compute all the results and answer each query \

D. Although it looks like a pattern-finding problem, it can actually be solved just using brute-force. However, how should we maintain all the segments in a sorted order? The answer is either using set with specified comparator or using a priority queue of specified comparator. But we still need some careful implememtation. \

E. This is a standard DP problem. \