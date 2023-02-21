from math import floor

t = int(input())
for _ in range(t):
  n = int(input())
  arr = [int(i) for i in input().split(" ")]
  mn = min(arr)
  cnt = 0
  mx = floor(n/2)
  for el in arr:
    if(el != mn and cnt < mx):
      print(f'{el} {mn}')
      cnt += 1

    if(cnt == mx):
      break
    