'''Write a Python program to store first year percentage of students in array. Write
function for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.''' 

print(__doc__)

def accept():
    n = int(input("Enter Total number of students: "))
    L = []
    print("Enter first year percentage of students: ")
    for i in range(n):
        L.append(float(input()))
    return L, n

def bubbleSort(arr, n):
    for i in range(n-1):  # 0 to n-1
        f = 0
        for j in range(0, n-i-1):  # 0 to n-i-1
            if arr[j] > arr[j + 1]:
                f = 1
                arr[j], arr[j+1] = arr[j+1], arr[j]
        if f == 0:
            break
        print(f"After pass {i+1}", arr)
    return arr

def selectionSort(arr, n):
    for i in range(n):  # 0 to n-1
        min_index = i
        for j in range(i+1, n):  # i+1 to n-1
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
        print(f"After pass {i+1}", arr)
    return arr

L, n = accept()
print("Entered list is:", L)

a = bubbleSort(L[:], n)  # Passing a copy of list to maintain original list for selection sort
print("Sorted list after Bubble Sort:")
print(a)

b = selectionSort(L[:], n)  # Passing a copy of list to maintain original list for selection sort
print("Sorted list after Selection Sort:")
print(b)

print("Top 5 scores are:")
print(b[-1:-6:-1])
