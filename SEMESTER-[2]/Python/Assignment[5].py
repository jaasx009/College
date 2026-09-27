#PrimeNUmber
def prime(n):
    for i in range(2,n):
        if n%i==0:
            return False
    return True
def main():
    n = int(input("Enter : "))
    if prime(n):
        print("This is a prime number.")
    else:
        print("This is not a prime number.")
main()