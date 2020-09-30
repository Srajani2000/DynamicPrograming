
def xorAndSum(a, b):
    a, b = int(a, 2), int(b, 2)
    return sum(a^(b<<i) for i in range(314160)) % 1000000007



x= input()
y = input()
print(xorAndSum(x,y))