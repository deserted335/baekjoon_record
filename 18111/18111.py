# 마인크래프트
from collections import defaultdict

if __name__=="__main__":
  N, M, B = (int(i) for i in input().split())
  height = [[int(i) for i in input().split()] for _ in range(N)]
  height_cnt = defaultdict(int)
  for ls in height:
    for item in ls:
      height_cnt[item] += 1
  min_ls = []
  for key in height_cnt:
    need_B = 0
    time = 0
    for other_key in height_cnt:
      diff = key - other_key
      if diff > 0:
        need_B += diff * height_cnt[other_key]
        time += diff * height_cnt[other_key]
      elif diff == 0:
        continue
      else:
        time += -2 * diff * height_cnt[other_key]
    if need_B > B: continue
    else: min_ls.append((time, key))
  min_ls.sort(key=lambda x: x[0])
  max_value = 0
  for tup in min_ls:
    if tup[0] == min_ls[0][0]: max_value = max(tup[1], max_value)
  print("%d %d" % (min_ls[0][0], max_value))