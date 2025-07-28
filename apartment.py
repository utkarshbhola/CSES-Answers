n, m, k = map(int, input().split())
applicants = sorted(map(int, input().split()))
apartments = sorted(map(int, input().split()))

i = j = cnt = 0

while i < n and j < m:
    if abs(applicants[i] - apartments[j]) <= k:
        cnt += 1
        i += 1
        j += 1
    elif apartments[j] < applicants[i] - k:
        j += 1
    else:
        i += 1

print(cnt)
