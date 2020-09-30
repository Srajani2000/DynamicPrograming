def Sumpieces(arr):
    n = len(arr)
    mod = 10**9+7
    multi  = [0 for _ in range(n)]
    start = pow(2,n,mod)-1
    j = n-2
    multi[0] = start
    multi[n-1] = start
    for i in range(1,n//2+1):
        start = start+pow(2,j,mod)-pow(2,i-1,mod)
        multi[i] = start
        multi[n-i-1] = multi[i]
        j -= 1
    x = [arr[i] * multi[i] for i in range(n)]
    print(multi)
    print(sum(x)%mod)


Sumpieces([4 ,2, 9, 10, 1])