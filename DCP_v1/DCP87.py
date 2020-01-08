"""
	author : Anand
    A rule looks like this:

    A NE B
    This means this means point A is located northeast of point B.
    A SW C
    means that point A is southwest of C.
    Given a list of rules, check if the sum of the rules validate
"""

def verify( src, path, dest, pos):
    isValid = True
    for p in path:
        if p == 'N':
            isValid = isValid and ( pos[src][1] > pos[dest][1])
        if p == 'S':
            isValid = isValid and ( pos[src][1] < pos[dest][1])
        if p == 'E':
            isValid = isValid and ( pos[src][0] > pos[dest][0])
        if p == 'W':
            isValid = isValid and ( pos[src][0] < pos[dest][0])
    return isValid

def addStraight( src, path, dest, pos):
    x = y = 0
    for p in path:
        if p == 'N':
            y = pos[dest][1] + 1
        elif p == 'S':
            y = pos[dest][1] - 1
        elif p == 'E':
            x = pos[dest][0] + 1
        elif p == 'W':
            x = pos[dest][0] - 1
    pos[src] = (x,y)

def addInverted( src, oppPath, dest, pos):
    x = y = 0
    for p in oppPath:
        if p == 'N':
            y = pos[dest][1] - 1
        elif p == 'S':
            y = pos[dest][1] + 1
        elif p == 'E':
            x = pos[dest][0] - 1
        elif p == 'W':
            x = pos[dest][0] + 1
    pos[src] = (x,y)



def validate( inputs):
    pos = {}
    pos['B'] = (0,0)
    for input in inputs:
        src, path, dest = input.split(' ')
        if src in pos and dest in pos:
            if verify( src, path, dest, pos) == False:
                return False
        elif src not in pos and dest in pos:
            addStraight( src, path, dest, pos)
        elif src in pos and dest not in pos:
            addInverted( dest, path, src, pos)
    return True




assert validate( ["A NW B", "A N B"])
assert not validate( ["A N B", "B NE C", "C N A"])