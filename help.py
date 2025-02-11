# Get the list of all the prime numbers up to 1000

a = list(range(2, 500))
for i in range(2, 500):
    for j in range(2, i):
        if i % j == 0:
            a.remove(i)
            break
print(a)
print(len(a))