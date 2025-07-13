def reverse(list):
    l = len(list)

    new_list = [None]*l

    for item in list:
        l = l - 1
        new_list[l] = item
    return new_list

list = [1, 2, 3, 4, 5, 6]

print(reverse(list))


def isSorted(list):
  flag = 0
  i = 1
  while i < len(list):
    if(list[i] < list[i - 1]):
        flag = 1
    i += 1
    if(not flag):
            return True
    else:
        return False
    


def hasDuplicates(list):
   for i in range(len(list)):
        for j in range(i + 1, len(list)):
            if(list[i] == list[j]):
                return True
   return False


def printEvenOdd(n):
    while(n > 0):
        if n % 2 == 0:
            print('Even number: ', n)
        else:
            print('Odd Number: ', n)
    n = n - 1



