board = [" " for x in range(9)]

def printBoard():
  r1="|{}|{}|{}|".format(board[0], board[1], board[2])
  r2="|{}|{}|{}|".format(board[3], board[4], board[5])
  r3="|{}|{}|{}|".format(board[6], board[7], board[8])
  print(r1,r2,r3, sep="\n")
  
def playerMove(icon):
  number=0
  if icon=="X":
    number =1
  print(f"Your turn Player {number} :")
  choice=int(input("Enter move (0-8): "))
  if board[choice]==" ":
    board[choice]=icon
  else:
    print("Space occupied!")

def isVictory (icon):
  if (board[0]==icon and board[1]==icon and board[2]==icon):  
    return True
  elif (board[3]==icon and board[4]==icon and board[5]==icon):  
    return True
  elif (board[6]==icon and board[7]==icon and board[8]==icon):  
    return True
  elif (board[0]==icon and board[3]==icon and board[6]==icon):  
    return True
  elif (board[1]==icon and board[4]==icon and board[7]==icon):  
    return True
  elif (board[2]==icon and board[5]==icon and board[8]==icon):  
    return True
  elif (board[0]==icon and board[4]==icon and board[8]==icon):  
    return True
  elif (board[2]==icon and board[4]==icon and board[6]==icon):  
    return True
  else:
    return False
def isDraw():
  if " " not in board:
    print("Game is a Draw")

print("Game Start!")
for i in range (9):
  c=""
  if i%2==0:
    c="O"
  else:
    c="X"
  playerMove(c)
  printBoard()
  if i>=4:
    if isVictory(c):
      print (f"Player {c} Wins!")
      break
isDraw()
