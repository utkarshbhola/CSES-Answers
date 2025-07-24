class NumMatrix:
    def __init__(self, matrix):
        self.m = len(matrix)
        self.n = len(matrix[0])
        self.prefix = [[0] * (self.n + 1) for _ in range(self.m + 1)]

        for i in range(1, self.m + 1):
            for j in range(1, self.n + 1):
                self.prefix[i][j] = (
                    matrix[i - 1][j - 1]
                    + self.prefix[i - 1][j]
                    + self.prefix[i][j - 1]
                    - self.prefix[i - 1][j - 1]
                )

    def find_trees(self, y1, y2, x1, x2):
        return (
            self.prefix[y2][x2]
            - self.prefix[y1 - 1][x2]
            - self.prefix[y2][x1 - 1]
            + self.prefix[y1 - 1][x1 - 1]
        )

# ------------------------
# Main Execution
# ------------------------
n, q = map(int, input().split())

# Convert '*' to 1 and '.' to 0
forest = []
for _ in range(n):
    line = input().strip()
    forest.append([1 if ch == '*' else 0 for ch in line])

obj = NumMatrix(forest)

for _ in range(q):
    y1, x1, y2, x2 = map(int, input().split())  # Use correct order
    if y1 < 1 or x1 < 1 or y2 > n or x2 > n or y1 > y2 or x1 > x2:
        print("Invalid query")
    else:
        print(obj.find_trees(y1, y2, x1, x2))
