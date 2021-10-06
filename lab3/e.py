b = input()
a = map(int, input().split())
x = sorted(set(a))
print(x[-2])