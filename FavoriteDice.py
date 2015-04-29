__author__ = 'jjost'

tests = int(input())

for x in range(tests):
    sides = int(input())
    expected = float(0)
    for y in range(sides):
        expected += sides/(sides - y)

    print("%.2f" % round(expected,2))
