from os.path import split
#python默认输入为字符串
#读取一个整数
n=int(input())
print(n)

#读取一行用空格分开的整数
a=0
b=0
a,b=map(int,input().split())
print(a,b)

#读取一整行数组
#将map结果强制映射到list(相当于c++的vector)

arr=list(map(int,input().split()))
for i in arr:
    print(i,end=" ")
print()
for i,x in enumerate(arr):
    print(f"下标是{i},值是{x}")
for i in range(len(arr)):
    arr[i]*=2
for i in arr:
    print(i,end=" ")
