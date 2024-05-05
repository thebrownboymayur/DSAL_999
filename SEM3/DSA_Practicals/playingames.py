"""
Assignment 01
In second year computer engineering class, group A student’s play cricket,
group B students play badminton and group C students play football.
Write a Python program using functions to compute following: -
a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not both
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not badminton.
(Note- While realizing the group, duplicate entries should be avoided, Do
not use SET built-in functions)"""

print(__doc__)

# Function to find the intersection of two lists
def inter(l1, l2):
    return [student for student in l1 if student in l2]

# Function to find the union of two lists
def uni(l1, l2):
    res = l1.copy()
    for student in l2:
        if student not in l1:
            res.append(student)
    return res

# Function to find the difference between two lists
def diff(l1, l2):
    return [student for student in l1 if student not in l2]

c = []
n = int(input("Enter the number of students who play cricket: "))
for i in range(n):
    cn = int(input("Enter their roll no: "))
    c.append(cn)
print("List of students who play cricket: ", c)

b = []
n = int(input("Enter the number of students who play badminton: "))
for i in range(n):
    bn = int(input("Enter their roll no: "))
    b.append(bn)
print("List of students who play badminton: ", b)

f = []
n = int(input("Enter the number of students who play football: "))
for i in range(n):
    fn = int(input("Enter their roll no: "))
    f.append(fn)
print("List of students who play football: ", f)

print("Students who play both cricket and badminton: ", inter(c, b))
print("Students who play either cricket or badminton but not both: ", uni(diff(c, b), diff(b, c)))
print("Students who play neither cricket nor badminton: ", diff(f, uni(c, b)))
print("Students who play cricket and football but not badminton: ", diff(inter(c, f), b))
print("End")
