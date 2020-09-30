for _ in range(int(input())):
    n = int(input())
    b = list(map(int, input().split(' ')))
    
    l, h = 0, 0
    for i in range(1, n):
        l, h = (max(l, h + b[i - 1] - 1),
                max(l + b[i] - 1, h + abs(b[i] - b[i - 1])))
        print(l," ",h)
    print(max(l, h))