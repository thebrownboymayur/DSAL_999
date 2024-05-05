'''
Write a pythonprogram to store roll numbers of student in array who attended training
program in random order. Write function for searching whether particular student attended
training program or not, using Linear search
'''

student = []
num = int(input("Enter the total number of students: "))
for i in range(num):
    stu = int(input(f"Enter the roll number {i+1}: "))
    student.append(stu)
print("List of student roll numbers:", student)

key = int(input("Enter the roll number you want to search using Linear Search: "))

position = -1  # Initialize position variable outside the loop
for i in range(num):
    if student[i] == key:
        position = i
        break  # Exit the loop once the element is found

if position != -1:
    print(f"{key} is found at position {position+1} using Linear Search")
else:
    print(f"{key} not found in the list {student} using Linear Search")
