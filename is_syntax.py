# Python3.8以降は再現しない？
a = 256
print(a is 256)
# True
b = 257
print(b is 257)
# False

A = [1,2,3]
B = [1,2,3]
print(A is B)
# False
print(id(A))
print(id(B))
A = B
print(A is B)
print(id(B))
# True
