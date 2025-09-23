i=1
while i<=3:
    print('hello:',i)
    i=i+1
print('end')i=1
dan=7
while i<=9:
    print(dan,"x",i,"=",dan*i)
    i=i+1dan = input("단입력:")
dan = int(dan)
i=1
while i<=9:
    print(dan,"x",i,"=",dan*i)
    i=i+1dan = input("단입력:")
dan = int(dan)

for i in range(1,10):
  print(dan,"x",i,"=",dan*i)
i=1
dan=2

while dan<=9:
    i=1
    while i<=9:
        print(dan, "x", i, "=", dan * i)
        i=i+1
    dan=dan+1
    print("")dan=2

for dan in range(2,10,1):
    for i in range(1,10,1):
       print(dan, "x", i, "=", dan * i)
    print("")