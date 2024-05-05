marklist=[]
n=int(input("Enter no. of students :"))
for i in range(n):
    mark=int(input(f"Enter marks of {i+1} students : "))
    marklist.append(mark)
print("Marks of each students : ", marklist)

# Find Average
total = 0
count = 0
for mark in marklist:
    if mark != -1:
        total += mark
    else:
        count += 1
print("Total is :", total)
avg = total / (n - count)
print("Average is : ", avg)

# Maximum score
max_value = marklist[0]
min_value = marklist[0]
for mark in marklist:
    if mark != -1:
        if mark < min_value:
            min_value = mark
        if mark > max_value:
            max_value = mark
print("Highest Score is ", max_value)
print("Lowest Score is ", min_value)

# Count absent students
print("No of absent students are : ", count)

# Calculate frequency of each mark
freq = {}
for mark in marklist:
    if mark != -1:
        if freq.get(mark) == None:
            freq[mark] = 1
        else:
            freq[mark] += 1
print(freq)

# Find mark with the highest frequency
max_freq = 0
high_mark = 0
for mark in freq:
    if freq[mark] > max_freq:
        max_freq = freq[mark]
        high_mark = mark
print("Mark with highest freq is ", high_mark)
