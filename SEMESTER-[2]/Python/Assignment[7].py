#SUM = 1/1+1/2+1/3+1/4.....1/n
sum=0
n=int(input("Enter : "))
for i in range(1,n+1):
    sum=sum+1/i
print(f"Sum is : {sum:.2f}")