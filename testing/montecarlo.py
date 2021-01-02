import random


def f(x):
    return 3*x*x*x+2*x+1


def montecarlo():
    inside_area = 0.0
    total_points = 10000000

    Q = 0.0


    xmin = -1
    xmax = 1

    y1 = f(xmin)
    y2 = f(xmax)

    if (y1 != 0 and y2 != 0 and (y1 > 0 and y2 > 0) or (y1 < 0 and y2 < 0)):

        if (y1 > 0 and y2 > 0 and y1 > y2 or y1 < 0 and y2 < 0 and y2 > y1):
            y2 = 0
        else:
            y1 = 0

    for i in range(total_points):
        x = random.uniform(-1, 1)
        if y1 > y2:
            y = random.uniform(y2, y1)
        else:
            y = random.uniform(y1, y2)

        if (f(x) >= y >= 0):
            inside_area += 1.0
        elif (f(x) <= y < 0):
            inside_area -= 1.0

    Q = 2.0 * abs(y1 - y2) * (inside_area / total_points)
    print(inside_area)
    print(Q)
montecarlo()
