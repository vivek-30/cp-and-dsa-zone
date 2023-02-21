t = int(input())
for _ in range(t):
  s = input()
  t = input()
  if(t == "a"):
    print("1")
  elif(t.find("a") != -1):
    print("-1")
  else:
    print(2**len(s))
