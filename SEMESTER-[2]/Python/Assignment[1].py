'''Write a menu driven program to convert temperature in celsius to fahrenheit
    and vice versa.'''
def Temperature():
    while True:
        print("1.Fahrenheit to Celsius.")
        print("2. Celcius to Fahrenheit.")
        print("3. EXIT.")
        c = int(input("Enter your choice : "))
        match c:
            case 1:
                F = float(input("Enter the temperature in Fahrenheit : "))
                C = (F-32)*5/9
                print(f"{F}°F is equal to {C:.2f}°C")
            case 2:
                C = float(input("Enter the temperature in Celcius : "))
                F = (C*9/5)+32
                print(f"{C}°C is equal to {F:.2f}°F")
            case 3:
                print("You have exited the program.")
                return False
            case _:
                print("Invalid input.")
Temperature()