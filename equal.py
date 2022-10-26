print(2 < 3 == 3 < 4)
# True
print(2 < 3 == 4 < 5)
# False

# < と == の優先順位は同じ
# 2 < 3 == 3 < 4 -> 2 < 3 and 3 < 4 -> True
# 2 < 3 == 4 < 5 -> 2 < 3 and 4 < 5 -> False
