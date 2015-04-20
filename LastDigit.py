__author__ = 'jjost'

num_tests = int(input())

for i in range(num_tests):
    line = [int(x) for x in input().split()]
    base = line[0]
    digit = base % 10
    base = base % 10
    exponent = line[1]
    num_list = []

    if (exponent == 0):
        base = 1
        num_list.append(base)

    while base not in num_list:
        num_list.append(base)
        base = digit * base
        base = base % 10

    remainder = exponent % len(num_list)
    print(num_list[remainder-1])
