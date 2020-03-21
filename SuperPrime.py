# 超级素数：它本身，各位数字的和，各位数字的平方和，都是素数。
# 求 100~10000 内的所有超级素数，及它们的平均数。
# 要安装python运行环境，注意python2与python3的区别挺大的
def isPrime(n):
    if (n % 2 == 0 and n != 2) or (n % 3 == 0 and n != 3) or (n % 5 == 0 and n != 5) or (n % 7 == 0 and n != 7) or (
            n % 11 == 0 and n != 11):
        return 0
    k = 0
    for i in range(1, n + 1):
        if n % i == 0:
            k += 1
    if k == 2:
        return 1


def splitNum(n, anum_list):
    a = n
    b = 0
    c = 0
    num = n
    while num > 0:
        b += num % 10
        num = num // 10
    num = n
    while num > 0:
        c += (num % 10) ** 2
        num = num // 10
    if isPrime(a) and isPrime(b) and isPrime(c):
        anum_list.append(n)


num_list = list()
for i in range(100, 10001):
    splitNum(i, num_list)
print(num_list)
s = 0
for i in range(0, len(num_list)):
    s += num_list[i]
print("The average of the digit is", end=' ')
print(s / len(num_list))
input("按任意键结束")
