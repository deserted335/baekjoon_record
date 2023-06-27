import sys

# sequential search

# if __name__=="__main__":
#     K, N = (int(i) for i in input().split())
#     ls = [int(sys.stdin.readline().rstrip()) for _ in range(K)]
#     lth = int(sum(ls) / N)
#     for i in range(lth, 0, -1):
#       num = 0
#       for cable in ls:
#         num += cable // i
#       if num >= N:
#          tar = i
#          break
#     print(tar)

# binary search
# find largest num s.t. num >= N 

if __name__=="__main__":
    K, N = (int(i) for i in input().split())
    ls = [int(sys.stdin.readline().rstrip()) for _ in range(K)]
    start = 1
    end = int(sum(ls) / N) + 1
    while end - start != 1 and start != end:
      num = 0
      mid = (start + end) // 2
      for cable in ls: num += cable // mid 

      if num >= N: start = mid 
      else: end = mid 
    print(start)