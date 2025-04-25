print("Queue Using Lists ... ")
que=[1,2,3,4,5,6]
print(f"Queue : {que}")
que.pop(0)
print(f"After pop() : {que}")
que.append(17)
print(f"After append(17): {que}")


print("\nQueue using queue.Queue ... ")
from queue import Queue
q=Queue(maxsize=3)
print(f"Initial queue size: {q.qsize()}")
q.put(1)
q.put(2)
q.put(3)
print(f"Elements added: 1,2,3")
print(f"Queue Full Now: {q.full()}")
print(f"Elements dequeued: {q.get()} {q.get()} {q.get()} ")
print(f"Queue Empty Now : {q.empty()}")
print(f"Queue Full Now: {q.full()}")

print("\nQueue Using Collections ... ")
from collections import deque
q=deque([10,12,27,9,20])
print(f"Original: {q}")
q.popleft()
print(f"After popleft(): {q}")
q.pop()
print(f"After pop(): {q}")

q.append(17)
print(f"After append(17): {q} ")
q.appendleft(27)
print(f"After appendleft(27): {q} ")
q.clear()
print(f"After clear(): {q}")
