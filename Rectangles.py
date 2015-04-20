__author__ = 'jjost'

squares = int(input())

rectangles = 0

sqr_root = int(squares ** 0.5)

for x in range(sqr_root):
    rectangles += int(squares / (x+1)) - x

print(rectangles)
