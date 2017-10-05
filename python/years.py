#!/usr/bin/env python3

print('lets go!')

year = int(input('press enter year:'))

if (year % 4 == 0) or (year % 400 == 0) and (year % 100 != 0):
    print('yes')

else:
    print('no')
