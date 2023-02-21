s = input()
seq = ["oo", "xxx", "oxo"]

for _ in seq:
  if(s.find(_) != -1):
    print("No")
    break
else:
  print("Yes")