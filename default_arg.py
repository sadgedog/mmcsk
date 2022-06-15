import time
import datetime

# pythonはデフォルト引数を最初しか評価しない
def arg(i, A = []):
    A.append(i)
    return A

print(arg(12))
print(arg(12))
# [12]
# [12, 12]

def dt(t = datetime.datetime.now()):
    print(t)

dt()
time.sleep(1)
dt()
# 2022-06-16 07:02:57.004877
# 2022-06-16 07:02:57.004877


# デフォルト引数はイミュータブルな型にする
def arg2(i: int, A = ()):
    A = list(A)
    A.append(i)
    return A

print(arg2(12))
print(arg2(11))
# [12]
# [11]
