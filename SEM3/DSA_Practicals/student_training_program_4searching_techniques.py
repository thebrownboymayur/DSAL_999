"""
student who attended training program , searching student name using different search techniques
"""
def sentinel_search(student, key):
    student.append(key)  # Adding sentinel at the end
    i = 0
    while student[i] != key:
        i += 1
    student.pop()  # Removing sentinel
    if i < len(student) - 1 or student[-1] == key:
        return i
    else:
        return -1

def linear_search(student, key):
    for i in range(len(student)):
        if student[i] == key:
            return i
    return -1

def binary_search(student, key):
    low = 0
    high = len(student) - 1
    while low <= high:
        mid = (low + high) // 2
        if student[mid] == key:
            return mid
        elif student[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return -1

def fibonacci_search(student, key):
    def fibonacci(n):
        fib = [0, 1]
        while fib[-1] < n:
            fib.append(fib[-1] + fib[-2])
        return fib[:-1]

    fib = fibonacci(len(student))
    offset = -1
    k = len(student)
    while k > 0:
        i = min(offset + fib[k-2], len(student)-1)
        if student[i] < key:
            k -= 1
            offset = i
        elif student[i] > key:
            k -= 2
        else:
            return i
    return -1

# Input student roll numbers
student = []
num_students = int(input("Enter the total number of students: "))
for i in range(num_students):
    roll_number = int(input(f"Enter the roll number of student {i+1}: "))
    student.append(roll_number)
student.sort()  # Sorting the list for binary and fibonacci search

# Input roll number to search
key = int(input("Enter the roll number you want to search: "))

# Choose search technique
print("Choose search technique:")
print("1. Sentinel Search")
print("2. Linear Search")
print("3. Binary Search")
print("4. Fibonacci Search")
choice = int(input("Enter your choice (1-4): "))

# Perform chosen search
if choice == 1:
    index = sentinel_search(student[:], key)
elif choice == 2:
    index = linear_search(student, key)
elif choice == 3:
    index = binary_search(student, key)
elif choice == 4:
    index = fibonacci_search(student, key)
else:
    print("Invalid choice!")
    index = -1

# Display result
if index != -1:
    print(f"Roll number {key} found at index {index}.")
else:
    print(f"Roll number {key} not found.")

