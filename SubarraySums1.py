n, x = map(int, input().split())
A = list(map(int, input().split()))
l = 0
r = 0
ans = 0
curr_sum = 0
while r < n:
    curr_sum += A[r]
    
    while curr_sum > x and l <= r:
        curr_sum -= A[l]
        l += 1

    if curr_sum == x:
        ans += 1  # Found one valid subarray

    r += 1

print(ans)
