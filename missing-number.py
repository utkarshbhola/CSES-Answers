n = int(input())
arr = list(map(int, input().split()))
arr = sorted(arr)
missing_number = 1
for num in arr:
    if num == missing_number:
        missing_number += 1
print(missing_number)
