'''
Write a pythonprogram to store roll numbers of student in array who attended
training program in random order. Write function for searching whether particular
student attended training program or not, using Sentinel search.
'''

student = []
num = int(input("Enter the total number of students: "))
for i in range(num):
    stu = int(input(f"Enter the roll number {i+1}: "))
    student.append(stu)
print(student)

last = student[num - 1]
print(f"last = {last}")

key2 = int(input("Enter the roll number you want to search using Sentinel Search: "))
student[num - 1] = key2

i = 0
while student[i] != key2:
    i = i + 1

if i < num - 1 or last == key2:
    print("Element is found.")
else:
    print("Element not found.")
