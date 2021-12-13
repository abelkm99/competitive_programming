def taskOfPairing(freq):
    count = 0
    marker = False
    for i in freq:
        if i != 0:
          count += i // 2
        if i % 2 != 0 and marker:
            count += 1
            marker = False
        elif i % 2 != 0:
            marker = True
        else:
            marker = False
    return count

num = int(input())
arr = []
for i in range(num):
    arr.append(int(input()))
ans = taskOfPairing(arr)
print(ans)
