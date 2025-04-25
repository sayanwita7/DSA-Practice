#Stack using lists
print("Stack Using Lists ... ")
st=[1,2,3,4,5,6]
print(f"Stack : {st}")
st.pop()
print(f"After pop() : {st}")
st.append(17)
print(f"After append(17): {st}")

#Stack using Collections
print("\nStack Using Collections ... ")
from collections import deque
q=deque([10,12,27,9,20])
print(f"Original: {q}")
q.pop()
print(f"After pop(): {q}")
q.append(17)
print(f"After append(17): {q} ")
q.clear()
print(f"After clear(): {q}")

#Stack using queue.LifoQueue
print("\nStack Using queue.LifoQueue ... ")
from queue import LifoQueue
q=LifoQueue(maxsize=3)
print(f"Initial stack size: {q.qsize()}")
q.put(1)
q.put(2)
q.put(3)
print(f"Elements added: 1,2,3")
print(f"Stack Full Now: {q.full()}")
print(f"Elements dequeued: {q.get()} {q.get()} {q.get()} ")

print(f"Stack Empty Now : {q.empty()}")
print(f"Stack Full Now: {q.full()}")
