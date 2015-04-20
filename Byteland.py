__author__ = 'jjost'
import sys
value_map = {}
value_map[0] = 0

def split(value):
    if (value in value_map.keys()):
        return value_map[value]

    val1 = split(int(value/2))
    val2 = split(int(value/3))
    val3 = split(int(value/4))

    if (value < (val1 + val2 + val3)):
        retval = val1 + val2 + val3
    else:
        retval = value

    value_map[value] = retval

    return retval

for value in sys.stdin:
    amount =  split(int(value))
    print(amount)







