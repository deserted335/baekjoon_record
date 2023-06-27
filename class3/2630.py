import sys

#incomplete

def pieces(ls):
    N = len(ls)
    if N == 1: return ls[0][0]
    a1 = [i[:N/2] for i in ls[:N/2]]
    a2 = [i[N/2:] for i in ls[:N/2]]
    a3 = [i[:N/2] for i in ls[N/2:]]
    a4 = [i[N/2:] for i in ls[N/2:]]
    a = [a1, a2, a3, a4]
    ones = [[1 for _ in range(N/2)] for _ in range(N/2)]
    zeros = [[0 for _ in range(N/2)] for _ in range(N/2)]

    white = 0
    blue = 0
    for i in a:
        if i == ones: blue += 1
        elif i == zeros: white += 1
        else:  




if __name__ == "__main__":
    N = int(input())
    paper = [[int(i) for i in sys.stdin.readline().rstrip().split()] for _ in range(N)]
