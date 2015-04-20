__author__ = 'jjost'

max_num = 2**63
cube_map = {}
cube_map[1] = 192

def validate8(value):
    if (value % 1000 == 888):
        return 1
    else:
        return 0


tests = int(input())

for x in range(tests):
    value = int(input())
    number = 0
    if (value % 4 == 1):
        number = 192
    elif (value%4 == 2):
        number = 442
    elif(value%4==3):
        number = 692
    elif(value%4==0):
        number = 942-1000
    number += 1000*int(value/4)
    print(number)
    #if (value not in cube_map.keys()):
     #   for x in range(cube_map[len(cube_map)] + 1, max_num):
      #      if (validate8(x**3)):
       #         cube_map[len(cube_map)+1] = x
        #        if (len(cube_map)==value):
         #           break

    #print(cube_map[value])
    #print( cube_map[value]**3)




