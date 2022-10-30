l = [x**2 for x in range(30)]
print(l)

ll = [x for x in range(30) if x % 2 == 0]
print(ll)

a = [[0, 1], [0, 1, 2, 3, 4], [0, 1, 2, 3], [1, 2, 3]]

lll = [z for y in a if y[0] == 1 for z in y if z > 0]
print(lll)
