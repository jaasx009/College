#Factorial
def Factorial(n):
    f=1
    for i in range(1,n+1):
        f = f*i
    return f
def main():
    n=int(input("Enter n : "))
    f=Factorial(n)
    print(f"The factorial of {n} is {f}")
main()