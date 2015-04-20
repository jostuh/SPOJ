__author__ = 'jjost'

tests = int(input())

for x in range(tests):
    blank = input()
    kids = int(input())
    total_pieces = 0
    for y in range(kids):
        pieces = int(input())
        total_pieces += pieces

    if (total_pieces % kids == 0):
        print("YES")
    else:
        print("NO")
