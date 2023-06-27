from collections import defaultdict
import sys
# incomplete

if __name__=="__main__":
  N, M, B = (int(i) for i in input().split())
  height = [[int(i) for i in sys.stdin.readline().rstrip().split()] for _ in range(N)]
  height_cnt = defaultdict(int)
  for ls in height:
    for item in ls:
      height_cnt[item] += 1  
  
  tar = max(height_cnt)
  dumm = min(height_cnt)
  while tar >= dumm:
    time = 0
    shortest = float("inf")
    hightest = 0
    nB = 0
    for h in height_cnt: nB += (h - tar) * height_cnt[h]
    if nB > B:
      tar -= 1
      continue
    else:
      for h in height_cnt:
        diff = h - tar
        if diff > 0: time += 2 * diff * height_cnt[h]
        elif diff == 0: continue
        else: time -= diff * height_cnt[h]
      if shortest > time: 
        highest = tar 
        shortest = time
      elif shortest == time: highest = max(highest, tar) 
      tar -= 1
  print("%d %d" %(shortest, highest))
      



  




  # min_ls = []
  # for key in height_cnt:
  #   time = 0
  #   block_insuff = 0
  #   cur_B = B
  #   for other_key in height_cnt:
  #     diff = key - other_key
  #     if diff > 0:
  #       cur_B -= diff * height_cnt[other_key]
  #       time += diff * height_cnt[other_key]
  #     elif diff == 0:
  #       continue
  #     else:
  #       time -= 2 * diff * height_cnt[other_key]
  #       cur_B += diff * height_cnt[other_key] 
  #   if cur_B < 0: continue
  #   min_ls.append((time, key))
  # min_ls.sort(key=lambda x: x[0])
  # print(*min_ls)
  # max_value = 0
  # for tup in min_ls:
  #   if tup[0] == min_ls[0][0]: max_value = max(tup[1], max_value)
  # print("%d %d" % (min_ls[0][0], max_value))