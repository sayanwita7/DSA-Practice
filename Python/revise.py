li=[]
n=int(input("Enter number of elements to add: "))
for i in range(n):
	li.append(int(input("Enter element: ")))
print(f"List: {li}")

print(f"Maximum Element: {max(li)}")

print(f"Alternate elements: ", end=" ")
for i in range(len(li),2):
	print(li[i], end= " ")

print("\nElements with single occurence : ", end = " ")
for i in range(len(li)):
	if li.count(li[i]) == 1:
		print(i, end= " ")

evens=[]
odds=[]
for i in li:
	if i%2 ==0:
		evens.append(i)
	else:
		odds.append(i)

print(f"\nEvens: {evens} \nOdds: {odds}")

a=int(input("Enter number a: "))
b=int(input("Enter number b: "))
def gcd (a,b):
	if b==0:
		return abs(a)
	else:
		return gcd (b, a%b)
print(f"GCD of {a} and {b} = {gcd(a,b)}")

n=int(input("Enter number of employees: "))
for i in range (n):
	name=input("Enter name: ")
	sal=float(input("Enter Salary: "))

