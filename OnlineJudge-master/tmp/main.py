class L(object):
    def __init__(self, v1, v2):
        self.v1 = v1
        self.v2 = v2

def compare(a, b):
    if a.v1 < b.v1:
        return True
    if a.v1 > b.v1:
        return False
    if a.v2 < b.v2:
        return True
    return False
def k(v):
    return v.v1
V = [L(1, 2), L(3, 1), L(3, 3), L(2, 3)]

V = sorted( V, key=lambda x:(x.v1, x.v2))
for x in V:
    print(x.v1, x.v2)

