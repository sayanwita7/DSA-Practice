from collections import defaultdict as d
#import collections.defaultdict as d

j1, j2, a1m = 4, 5, 2
visited = d(lambda: False)

def WJP(a1, a2):
    if (a1 == a1m and a2 == 0) or (a1 == 0 and a2 == a1m):
        print(f"Jug 1= {a1} Jug 2= {a2}")
        return True

    if visited[(a1, a2)] == False:
        print(f"Jug 1= {a1} Jug 2= {a2}")
        visited[(a1, a2)] = True

        return (WJP(0, a2) or
                WJP(a1, 0) or
                WJP(j1, a2) or
                WJP(a1, j2) or
                WJP(a1 + min(a2, j1 - a1), a2 - min(a2, j1 - a1)) or
                WJP(a1 - min(a1, j2 - a2), a1 + min(a1, j2 - a2)))

    else:
        return False
print(f"Capacity of Jug 1 = {j1} units and Jug 2 = {j2} units; Target = {a1m} units")
print("Steps: ")
WJP(0, 0)