import random

def random_sol(tsp):
	cities = list(range(len(tsp)))
	solution=[]
	for i in range (len(tsp)):
		randcity = cities[random.randint(0, len(cities)-1)]
		solution.append(randcity)
		cities.remove(randcity)
	return (solution)

def routelength (tsp, solution):
	routelength=0
	for i in range(len(solution)):
		routelength+= tsp[solution[i-1]][solution[i]]
	return routelength

def getNeighbour(solution):
	neighbours=[]
	for i in range (len(solution)):
		for j in range (i+1, len(solution)):
			neighbour = solution.copy()
			neighbour[i]=solution[j]
			neighbour[j]= solution[i]
			neighbours.append(neighbour)
	return neighbours

def getBestNeighbour(tsp, neighbours):
	bestRoutelength= routelength(tsp, neighbours[0])
	bestNeighbour = neighbours[0]
	
	for neighbour in neighbours:
		curRoutelength = routelength(tsp, neighbour)
		if curRoutelength< bestRoutelength:
			bestRoutelength = curRoutelength 
			bestNeighbour = neighbour
	return bestNeighbour, bestRoutelength


def hillClimbing(tsp):
	currentSol= random_sol(tsp)
	#print(currentSol)
	currentroutelength= routelength(tsp, currentSol)
	#print(currentroutelength)
	neighbours= getNeighbour(currentSol)
	#print(neighbours)
	bestNeighbour, bestNeighbourRoute = getBestNeighbour(tsp, neighbours)
	#print (bestNeighbour, bestNeighbourRoute)
	while bestNeighbourRoute< currentroutelength:
		currentSol = bestNeighbour
		currentroutelength= bestNeighbourRoute
		neighbours= getNeighbour(currentSol)
		bestNeighbour, bestNeighbourRoute = getBestNeighbour(tsp, neighbours)
	return currentSol, currentroutelength

cities = ["0", "1", "2", "3"]
tsp =[[0,400,500,300],
			[400,0,300,500],
			[500,300,0,400],
			[30,500,400,0]]
print("Given the distance matrix for the Travelling Salesman Problem: ")
print("   ", end=" ")
for i in range(len(cities)):
	print(cities[i].center(3, " "), end=" ")
print()
for i in range (len(tsp)):
	print(cities[i].center(3, " "), end=" ")
	for j in range (len(tsp)):
		x=str(tsp[i][j])
		print(x.rjust(3, " "), end=" ")
	print()
print("\nSolution: ", hillClimbing(tsp))
