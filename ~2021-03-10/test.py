DP = [0 for i in range(0,260)]
DP[0] = 1
DP[1] = 1
DP[2] = 3
idx = 2
while 1 :
    try : 
        n = int(input())
        if idx >= n :
            print(DP[n])
            continue
        for i in range(idx+1,n+1) :
            DP[i] = DP[i-1] + DP[i-2]*2
        if idx < n :
            idx = n
        print(DP[n])
    except EOFError:
        break
