m, n = map(int, input().split())

matrix = []

for _ in range(m):
    matrix.append(list(map(int, input().split())))

if m != n:
    print("Not a Symmetric Matrix")
else:
    symmetric = True

    for i in range(m):
        for j in range(i + 1, n):
            if matrix[i][j] != matrix[j][i]:
                symmetric = False
                break
        if not symmetric:
            break

    if symmetric:
        print("Symmetric Matrix")
    else:
        print("Not a Symmetric Matrix")