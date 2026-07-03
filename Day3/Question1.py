n = int(input())
arr = list(map(int, input().split()))
k = int(input())

comparisons = 0

for i in range(n):
    comparisons += 1
    if arr[i] == k:
        print("Found at index", i)
        print("Comparisons =", comparisons)
        break
else:
    print("Not Found")
    print("Comparisons =", comparisons)