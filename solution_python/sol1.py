from math import sqrt

N_max = 3 * 10 ** 6 + 20
def check(n):
    total = 0
    for i in range(1,n):
        if (n % i == 0):
            total += i
    return total

def check2(n):
    total = 0
    for i in range(2,int(sqrt(n)) + 1):
        if (n % i == 0):
            total += i
            if (n // i != i):
                total += n // i
    total += 1
    return total

def subtask1(l, r):
    # Big o nation: O(n * n) n <= 10 ^ 3 -> 10 ^ 6
    cnt = 0
    for i in range(l, r + 1):
        if (check(i) > i):
            cnt += 1
    print(cnt)

def subtask2(l, r):
    # Big o nation: O(n * sqrt(n)) n <= 10 ^ 5 -> O(n * sqrt(10 ^ 5)) ~ 10 ^ 7
    cnt = 0
    for i in range(l, r + 1):
        if (check2(i) > i):
            cnt += 1
    print(cnt)

def subtask3(l, r):
    n = r
    i = 2
    dp = [1 for i in range(N_max)]
    dp[1] = 0

    while(2 * i <= n):
        j = 2 * i
        while(j <= n):
            dp[j] += i
            j += i
        i += 1
    
    cnt = 0
    for i in range(l, r + 1):
        if (dp[i] > i):
            cnt += 1
    print(cnt)

def main():
    l,r = map(int ,input().split())
    subtask3(l,r)

if __name__ == "__main__":
    main()