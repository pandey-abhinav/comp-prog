def comp(a, b):
    ia, ib = len(a[1]) - 1, len(b[1]) - 1
    while ia >= 0 and ib >= 0:
        if a[1][ia] < b[1][ib]:
            return 1
        if a[1][ia] > b[1][ib]:
            return -1
        ia -= 1
        ib -= 1

    while True:
        if ia >= 0 and a[1][ia] == 1:
            ia -= 1
        elif ib >= 0 and b[1][ib] == 1:
            ib -= 1
        else:
            break

    if ia >= 0:
        if a[1][ia] == 0: return 1
        if a[1][ia] == 2: return -1

    if ib >= 0:
        if b[1][ib] == 2: return 1
        if b[1][ib] == 0: return -1

    if a[0] < b[0]: return -1
    elif a[0] > b[0]: return 1

    return 0

def score(s):
    if s == "upper": return 2
    if s == "middle": return 1
    if s == "lower": return 0

t = input()

for _ in range(t):
    n = input()
    a = []
    for _ in range(n):
        line = raw_input()
        line = line.split()
        a.append([line[0][:-1], line[1].split("-")])

    a = map(lambda x: [x[0], map(score, x[1])], a)
    a = sorted(a, cmp=comp)

    for i in range(n):
        print a[i][0]
    print "=============================="
