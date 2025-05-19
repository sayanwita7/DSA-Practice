def move(ar, p, st):
	rh = 9999
	store_st = st.copy()
	for i in range(len(ar)):
		d_st = st.copy()
		t = d_st[p]
		d_st[p] = d_st[ar[i]]
		d_st[ar[i]] = t
		t_rh = count(d_st)
		if t_rh<rh:
			rh = t_rh
			store_st= d_st.copy()
	return store_st, rh

def count(s):
	c = 0
	ideal = [1, 2, 3, 4, 5, 6, 7, 8, 0]
	for i in range(9):
		if s[i]!=0 and s[i]!=ideal[i]:
			c+=1
	return c

def printFormatted(matrix):
	for i in range(9):
		if i % 3 == 0 and i>0:
			print()
		print(matrix[i], " ", end= " ")
				
state = [1,2,3,0,5,6,4,7,8]
h=count(state)
level=1
print(f"\n Level: {level}")
printFormatted(state)
print(f"\n Heuristic value : {h}")
arr={0:[1,3], 1:[0,2,4], 2:[1,5], 3:[0,4,6], 4:[1,3,5,7], 5:[2,4,8], 6:[3,7], 7:[4,6,8], 8:[5,7]}
while h>0:
	pos = int(state.index(0))
	level += 1
	state,h = move(arr[pos], pos, state)
	print(f"\n Level: {level}")
	printFormatted(state)
	print(f"\n Heuristic value : {h}")
