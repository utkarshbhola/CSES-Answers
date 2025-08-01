n = int(input())
A = list(map(int, input().split()))

cnt = 0
for i in range(1, n):
    if A[i] < A[i-1]:
        cnt += A[i-1] - A[i]  # add the difference
        A[i] = A[i-1]         # make it non-decreasing

print(cnt)
