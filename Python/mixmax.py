import math 
def minmax (currDepth, nodeIndex, maxTurn, scores, targetDepth):
	if (currDepth == targetDepth):
		return scores[nodeIndex]
	if (maxTurn):
		return max(minmax(currDepth+1, nodeIndex*2, False, scores, targetDepth), minmax(currDepth+1, nodeIndex*2+1, False, scores, targetDepth))
	else:
		return min(minmax(currDepth+1, nodeIndex*2, True, scores, targetDepth), minmax(currDepth+1, nodeIndex*2+1, True, scores, targetDepth))

scores = [3,5,2,9,12,5,23,25]
treeDepth = math.log(len(scores),2)
print("Optimal value: ", end = " ")
print(minmax(0,0,True, scores, treeDepth))
