Map = {}
List = tuple(raw_input())
for x in List:
    if x in Map:
        Map[x] = Map[x] + 1
    else:
        Map[x] = 1
Map[' '] = 'f'
for x in Map:
    print x, Map[x]
print List
