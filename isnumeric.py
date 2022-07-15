# isnumeric see Numerals in Unicode
def main():
    print("123".isnumeric())
    print("一十百千万億兆", "一十百千万億兆".isnumeric())
    print("京", "京".isnumeric())
    print("⑨", "⑨".isnumeric())
    print("全角", "１２３４５６７８９０".isnumeric())
    print("壱弐参", "壱弐参".isnumeric())
    print("¾", "¾".isnumeric())
    print("೬", "೬".isnumeric())
    
main()
