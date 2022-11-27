import sys
# default 4300
sys.set_int_max_str_digits(4500)
# 桁数の多いint <-> strの変換が遅い
# python 3.10.7~はintが無制限で無い

A = 100 ** 100000

B = str(A)
