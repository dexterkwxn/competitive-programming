import math

def main():
    tc = int(input())
    for i in range(tc):
        n = int(input())
        print(math.ceil(pow(n, 0.5))-1)
        print(pow(n, 0.5))


main()
