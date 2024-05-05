'''
Write a python program to store roll numbers of student array who attended training program in sorted
order. Write function for searching whether particular student attended training program or not, using
Binary search
'''

def accept():
    num = int(input("Enter the number of students: "))
    student = []
    for i in range(num):
        roll_no = int(input("Enter the Roll No of students in ascending order please: "))
        student.append(roll_no)
    return student

student = accept()
key = int(input("\nEnter the student Roll No you want to search: "))

def binary_search(arr, a, low, high):
    # Repeat until low and high meet each other
    while low <= high:
        mid = low + (high - low)//2
        if arr[mid] == a:
            return mid
        elif arr[mid] < a:
            low = mid + 1
        else:
            high = mid - 1
    return -1

student.sort()  # Ensure the list is sorted
index = binary_search(student, key, 0, len(student)-1)

if index != -1:
    print(f"The Element {key} is found at position: {index+1}")
else:
    print(f"Element {key} not found")
