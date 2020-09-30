
def GetHut(field,m,n):
    hut = [ [0 for col in range(n)] for col in range(n)] 
    best = 0
    for i in range(1,m):
        for j in range(n):
            pointer = j
            for k in range(j,n):
                
                if(field[i][0][k]=='.' and field[i][0][j]!='x' and field[i-1][0][j]!='x' and j!=k and field[i-1][0][k]!='x'):
                    hut[j][k] = hut[j][k]+1
                    now = (k-pointer)*2+(hut[j][k])*2
                    best = max(best,now)
                    # print(i,j,k,"hut value ",(k-pointer)*2+(hut[j][k])*2)

                else:
                    pointer = k
                    hut[j][k] = 0
    if best==0:
        print("impossible")
    else:
        print(best)




m ,n= input().split()
m = int(m)
n  = int(n)
mat = [input().split() for i in range(m)]
GetHut(mat,m,n)



