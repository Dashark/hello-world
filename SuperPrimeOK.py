def isPrime(x):
    flag=1
    x=int(x)
    for i in range(2,x):
        if x % i == 0:
            flag=0
            break
    if flag:
        return 1
    else:
        return 0
def splitNum(x,num):
    n=0
    while 0 != x:
        num.append(x % 10)
        x=x // 10
    return num
def main():
    num=list()
    prime=list()
    z=0
    for x in range(100,10000):
        num.clear()
        num=splitNum(x,num)
        if isPrime(x):
            sum=0
            for i in num:
                sum += i
            if isPrime(sum):
                sqsum=0
                for i in num:
                    sqsum += (i * i)
                if isPrime(sqsum):
                    print(x)
                    prime.append(x)
                    z = z + 1
    sum=0
    for i in prime:
        sum += i
    av=sum / z
    print("平均数：{:.8f}".format(av))
main()
                    
    
        
        
    
