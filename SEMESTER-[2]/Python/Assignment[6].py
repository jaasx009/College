#String Palindrom
def pal(ch):
    ch=ch.lower()
    if ch==ch[::-1]:
        return True
    return False
def main():
    ch=input("Enter the letter : ")
    if pal(ch):
        print(f"{ch} is a palindrome.")
    else:
        print(f"{ch} is not a palindrome.")
main()