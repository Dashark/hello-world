a=[]
for i in range(10):
    a.append(int(input()))
for i in range(8,-1,-1):
    for j in range(0,i+1):
        if a[j]>a[j+1]:
            temp=a[j]
            a[j]=a[j+1]
            a[j+1]=temp
for i in range(10):
    print(a[i],end='\n')
input("按任意键关闭")
