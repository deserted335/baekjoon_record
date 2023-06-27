import sys
from collections import defaultdict 
if __name__=="__main__":
    N = int(input())
    cnt = defaultdict(int)
    for _ in range(N):
        tmp = int(sys.stdin.readline().rstrip())
        cnt[tmp] += 1
        
    for item in sorted(cnt): 
        for _ in range(cnt[item]):
            print(item)