__author__ = 'jjost'

length = float(input())

while length != 0:
    cards = 0
    total = 0
    for x in range (2,300):
        cards+=1
        total += float(1/x)
        if total > length:
            break

    print(cards," card(s)")
    length = float(input())


