'''Write a program to calculate students grade.'''
name = input("Enter the students name : ")
print("Enter the marks of the subjects : ")
sub1 = float(input("Subject 1 : "))
sub2 = float(input("Subject 2 : "))
sub3 = float(input("Subject 3 : "))
sub4 = float(input("Subject 4 : "))
sub5 = float(input("Subject 5 : "))
total = sub1+sub2+sub3+sub4+sub5
per = (total/500)*100
if per>=90:
    Grade = 'A+'
elif per>=70:
    Grade = 'B+'
elif per>=50:
    Grade = 'C+'
else:
    Grade = 'F'
print(f"Student's name   - {name}")
print(f"Total marks      - {total}")
print(f"Total Percantage - {per}")
print(f"Grade            - {Grade}")
