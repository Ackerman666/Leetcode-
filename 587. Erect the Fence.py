# use andrews_monotone_chain， let point = [x, y]
def convexhull(points):

    if len(points) < 3:
        return points
    
    upper = []
    lower = []

    points.sort(key = lambda point : (point[0], -point[1]))

    '''
    find upper convex
    '''
    upper.extend([points[-1], points[-2]])
    for point in points[-3::-1]:
        while len(upper) > 1 and crossPruduct(upper[-2], upper[-1], point) < 0:
            upper.pop()
        upper.append(point)

    '''
    find lower convex
    '''
    lower.extend([points[0], points[1]])
    for point in points[2:]:
        while len( lower) > 1 and crossPruduct( lower[-2],  lower[-1], point) < 0:
             lower.pop()
        lower.append(point)
    
    convexhull = []
    for point in set(map(tuple, lower+upper)):
        convexhull.append(list(point))

    return convexhull


def crossPruduct(pA, pB, pC):
    x1, y1 = pB[0]-pA[0], pB[1]-pA[1]
    x2, y2 = pC[0]-pB[0], pC[1]-pB[1]
    return x1*y2 - x2*y1







class Solution(object):
    def outerTrees(self, trees):
       return convexhull(trees)
        
