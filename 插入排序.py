a=[]  # 插入排序
for i in range(5):
    b=int(input())
    a.append(b)
    for j in range(i+1):
        if a[i]<a[j]:
            temp = a[i]
            for k in range(i,j,-1):
                a[k]=a[k-1]
            a[j]=temp
            break
print(a)
