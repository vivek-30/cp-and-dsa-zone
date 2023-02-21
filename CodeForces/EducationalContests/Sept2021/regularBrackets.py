t = int(input())
for i in range(t):
  n = int(input())
  for j in range(n):
    print("()" * j + "(" * (n-j) + ")" * (n-j))