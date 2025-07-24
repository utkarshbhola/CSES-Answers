from collections import defaultdict
import sys
def solve(arr, X, N):
    # Dictionary to store the frequency of prefix sums
    pref_sums = {0: 1}
    pref = 0
    cnt = 0
    
    # Calculate the prefix sum at every index, and find the
    # count of subarrays with sum = pref - X
    for i in range(N):
        pref += arr[i]
        cnt += pref_sums.get(pref - X, 0)
        pref_sums[pref] = pref_sums.get(pref, 0) + 1
    
    return cnt

input = sys.stdin.read
data = input().split()
n = int(data[0])
x = int(data[1])
A = list(map(int, data[2:]))    # the array

result = solve(A, x, n)
print(result)
