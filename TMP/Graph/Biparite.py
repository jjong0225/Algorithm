import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline
def dfs(v):
  for i in table[v]:   
    if color[i] == 0: # 0 인 상태는 방문 안한 상태
      color[i] = 2 if color[v] == 1 else 1 # 여기서 색깔 칠해 줌
      dfs(i)
    elif color[i] == color[v]:
       color[0] += 1 # color[0]은 변수 넣기 귀찮아서 쩃든 False일때(NO)

T = int(input())

for _ in range(T):
  V,N = map(int,input().split())
  color = [0]*(V+1)
  table = [[] for _ in range(V+1)]

  for i in range(N):
    A,B = map(int,input().split())
    table[A].append(B)
    table[B].append(A)
  for i in range(1,V+1):
    if color[i] == 0:
      color[i] = 1
      dfs(i)
  if color[0] != 0:
    print('NO')
  else:
    print('YES')