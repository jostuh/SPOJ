__author__ = 'jjost'

import sys

num_tests = int(input())

for x in range(num_tests):
    num_contestants = int(input())
    males = []
    females = []

    males = [int(x) for x in input().split()]
    females = [int(x) for x in input().split()]

    males = sorted(males)
    females = sorted(females)

    hotness_total = 0
    for i in range(num_contestants):
        hotness_total += males[i]*females[i]

    print(hotness_total)








