'''
Write a python program to store roll numbers of student array who attended training program in sorted
order. Write function for searching whether particular student attended training program or not, using
Fibonacci search
'''

def accept():
    num = int(input("Enter the number of students: "))
    student = []
    for i in range(num):
        roll_no = int(input("Enter the Roll No of the students in ascending order: "))
        student.append(roll_no)
    return student

def fibonaccianSearch(arr, x, n):
    # Initialize Fibonacci numbers
    fib_minus_2 = 0  # (m-2)'th Fibonacci No.
    fib_minus_1 = 1  # (m-1)'th Fibonacci No.
    fibonacci_number = fib_minus_1 + fib_minus_2  # m'th Fibonacci
    # fibonacci_number is going to store the smallest
    # Fibonacci Number greater than or equal to n
    while fibonacci_number < n:
        fib_minus_2 = fib_minus_1
        fib_minus_1 = fibonacci_number
        fibonacci_number = fib_minus_1 + fib_minus_2
    offset = -1  # Marks the eliminated range from front
    # while there are elements to be inspected.
    # Note that we compare arr[fib_minus_2] with x.
    # When fibonacci_number becomes 1, fib_minus_2 becomes 0
    while fibonacci_number > 1:
        # Check if fib_minus_2 is a valid location
        i = min(offset + fib_minus_2, n - 1)
        # If x is greater than the value at index fib_minus_2,
        # cut the subarray array from offset to i
        if arr[i] < x:
            fibonacci_number = fib_minus_1
            fib_minus_1 = fib_minus_2
            fib_minus_2 = fibonacci_number - fib_minus_1
            offset = i
        # If x is less than the value at index fib_minus_2,
        # cut the subarray after i+1
        elif arr[i] > x:
            fibonacci_number = fib_minus_2
            fib_minus_1 = fib_minus_1 - fib_minus_2
            fib_minus_2 = fibonacci_number - fib_minus_1
        # element found. return index
        else:
            return i
    # comparing the last element with x
    if fib_minus_1 and arr[n - 1] == x:
        return n - 1
    # element not found. return -1
    return -1

student = accept()
key = int(input("Enter the student Roll No you want to search: "))
student.sort()  # Ensure the list is sorted
num = len(student)
ind = fibonaccianSearch(student, key, num)
if ind >= 0:
    print(f"{key} is found at index {ind + 1} in the array {student}")
else:
    print(f"{key} isn't present in the array {student}")
