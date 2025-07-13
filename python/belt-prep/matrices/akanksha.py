# arr = list(map(int, input().split()))
# arr.reverse()
# print(*arr)
#

#reverse an array 
#arr=list(map(int,input().split()))
#arr.reverse()
#print( *arr) 
#reversing an array
#arr=list(map(int,input().split()))
#print(*arr[::-1])




#frequnecy highest lowest

#s=input()
#freq={}
#for char in s:
 #   if char in freq:
  #      freq[char]+=1
   # else:
    #    freq[char]=1
#max_char=max(freq,key=freq.get)
#min_char=min(freq,key=freq.get)
#print(max_char, freq[max_char])
#print(min_char,freq[min_char])





#add two array
#arr1=list(map(int,input().split()))
#arr2=list(map(int,input().split()))
#merged=arr1+arr2
#merged.sort()
#print(merged)





#arr=list(map(int,input().split()))
#x=int(input())
#n=len(arr)
#for i in range(n//2):
 #   arr[i],arr[n-1-i]=arr[n-1-i],arr[i]
#for val in arr:
#     if val>x:
#        print(val,end="  ")
#print()
#for val in arr:
#     if val<=x:
 #          print(val,end=" ")







#remove last occurence 


# There's a syntax error in the code - a missing colon after the `for` loop definition. Here's the corrected version and the corresponding question:

# # Question

# Write a program that removes the last occurrence of a given substring from a string. 

# Your program should:
# 1. Take two strings as input - the main string `s` and the substring `w` to be removed
# 2. Find the last occurrence of `w` in `s`
# 3. If `w` is found, remove it from `s` and print the resulting string
# 4. If `w` is not found in `s`, print "not found"

# ## Example:

# **Input:**
# ```
# abcdabcdabcd
# abcd
# ```

# **Output:**
# ```
# abcdabcd
# ```

# **Explanation:** The substring "abcd" occurs three times in "abcdabcdabcd". The program removes the last occurrence, resulting in "abcdabcd".

# **Input:**
# ```
# hello world
# xyz
# ```

# **Output:**
# ```
# not found
# ```

# **Explanation:** The substring "xyz" does not exist in "hello world", so the program outputs "not found".



# s=input()  
# w=input()
# s_len=len(s)
# w_len=len(w)
# last_index=-1
# for i in range(s_len-w_len+1):
#    if(s[i:i+w_len]==w):
#        last_index=i
#    if last_index!=-1:
#            result=s[:last_index]+s[last_index+w_len:]
#            print(result)
#    else:
#            print("not found")


#copy
#n=int(input())
#arr=list(map(int,input().split()))

#copy_arr=[]
#for i in range(n):
#    copy_arr.append(arr[i])
#print(copy_arr)


# # Question

# Write a program that performs a left rotation on an array. A left rotation operation on an array of size `n` shifts each element of the array 1 unit to the left. Given an array of integers and a rotation count `d`, rotate the array left `d` times.

# Your program should:
# 1. Take an integer `d` representing the number of rotations
# 2. Take an array of integers
# 3. Perform `d` left rotations on the array
# 4. Print the rotated array

# ## Example:

# **Input:**
# ```
# 2
# 1 2 3 4 5
# ```

# **Output:**
# ```
# 3 4 5 1 2
# ```

# **Explanation:** The array is rotated left by `d=2` positions. After first rotation it becomes `2 3 4 5 1`, and after second rotation it becomes `3 4 5 1 2`.

# This solution uses an efficient approach known as the "reversal algorithm" that performs the rotation in O(n) time complexity with O(1) extra space by:
# 1. Reversing the first `d` elements
# 2. Reversing the remaining elements
# 3. Reversing the entire array




# def reverse(arr,start,end):
#    while start<end:
#        arr[start],arr[end]=arr[end],arr[start]
#        start+=1
#        end-=1
# d=int(input())
# arr=list(map(int,input().split()))
# n=len(arr)
# d=d%n
# reverse(arr,0,d-1)
# reverse(arr,d,n-1)
# reverse(arr,0,n-1)
# print(*arr)


# def reverse(arr, start, end):
#     while start < end:
#         arr[start], arr[end] = arr[end], arr[start]
#         start += 1
#         end -= 1
#
# d = int(input())
# arr = list(map(int, input().split()))
# n = len(arr)
# d = d % n
# reverse(arr, 0, d - 1)
# reverse(arr, d, n - 1)
# reverse(arr, 0, n - 1)
# print(*arr)


'''

# Valid Parentheses

Write a program that determines if a given string of parentheses, brackets, and braces is valid or balanced.

A string is considered valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

## Input
A string consisting of parentheses, brackets and braces: '(', ')', '{', '}', '[', ']'

## Output
Print "true" if the string is valid, otherwise print "false"

## Examples
- Input: "()"
  Output: true

- Input: "()[]{}"
  Output: true

- Input: "(]"
  Output: false

- Input: "([)]"
  Output: false

- Input: "{[]}"
  Output: true

'''




# s=input()
# stack=[]
# mapping={')':'(','}':'{',']':'['}
# valid=True
# for char in s:
#     if char in '({[':
#        stack.append(char)
#     elif char in ')}]':
#        if not stack or stack[-1]!=mapping[char]:
#            valid=False
#            break
#        stack.pop()
# if stack:
#    valid=False
# if valid:
#    print('true')
# else: 
#    print('false')

'''

In the function:
```python
if not stack or stack[-1] != mapping[char]:
```

This line is checking two conditions:

1. `not stack` - Checks if the stack is empty. If we encounter a closing bracket (like `)`, `}`, or `]`) but have no corresponding opening brackets on the stack, then the expression is invalid.

2. `stack[-1] != mapping[char]` - Checks if the current closing bracket doesn't match the expected type based on the most recent opening bracket. The `mapping` dictionary maps each closing bracket to its corresponding opening bracket:
   ```python
   mapping = {")": "(", "}": "{", "]": "["}
   ```

For example, if we have `[{` on our stack and encounter a `)`, this condition will be true because we expected a `}` to match the most recent opening bracket `{`.

If either condition is true, the function returns `False` because the string isn't valid. This is a key validation step in the algorithm for checking balanced brackets.

'''


# s = input()
# stack = []
# mapping = {')': '(', '}': '{', ']': '['}
# valid = True
#
# for char in s:
#     if char in '({[':
#         stack.append(char)
#     elif char in ')}]':
#         if not stack or stack[-1] != mapping[char]:
#             valid = False
#             break
#         stack.pop()

'''
# Character Frequency Analysis

Write a program that analyzes the frequency of characters in a given string.

## Problem Description
Given a string, find the character that appears most frequently and the character that appears least frequently. Print both characters along with their frequencies.

## Input Format
A single line containing a string.

## Output Format
Two lines:
- First line: The most frequent character followed by its frequency count
- Second line: The least frequent character followed by its frequency count

## Notes
- If multiple characters have the same highest frequency, report the first one found.
- If multiple characters have the same lowest frequency, report the first one found.

## Example
Input:
```
abcdaabcc
```

Output:
```
a 3
d 1
```

Explanation:
In the string "abcdaabcc":
- 'a' appears 3 times (most frequent)
- 'b' appears 2 times
- 'c' appears 3 times (appears after 'a')
- 'd' appears 1 time (least frequent)

Since 'a' is the first character with the highest frequency, it's printed first.
Since 'd' is the only character with the lowest frequency, it's printed second.

'''

# s=input()
# freq={}
# for char in s:
#     if char in freq:
#         freq[char]+=1
#     else:
#         freq[char]=1
# max_char=max(freq.keys(), key=freq.get)
# min_char=min(freq.keys(), key=freq.get)
# print(max_char,freq[max_char])
# print(min_char,freq[min_char])

'''
# Recursive Power Function

Write a program that calculates x raised to the power of n (x^n) using recursion.

## Problem Description
Implement a recursive function that computes x^n for any real number x and integer n.

## Requirements
1. Your function should handle:
   - Positive exponents (n > 0)
   - Negative exponents (n < 0)
   - Zero exponent (n = 0)
2. Use a recursive approach (not built-in operators or functions like **)

## Input Format
- First line: A real number x (the base)
- Second line: An integer n (the exponent)

## Output Format
The result of x^n

## Example 1
Input:
```
2.0
3
```
Output:
```
8.0
```

## Example 2
Input:
```
2.0
-2
```
Output:
```
0.25
```

## Example 3
Input:
```
5.0
0
```
Output:
```
1.0

'''

# def power(x,n):
#     if n==0:
#         return 1
#     elif n<0:
#         return 1/power(x,-n)
#     else:
#         return x*power(x,n-1)
# x=float(input())
# n=int(input())
# result=power(x,n)
# print(result)

'''


# Array Reversal

Write a program that reverses an array of integers in-place.

## Problem Description
Given an array of integers, reverse the array in-place (without using extra space) and print the reversed array.

## Input Format
- First line: An integer n (the size of the array)
- Second line: n space-separated integers representing the array elements

## Output Format
The reversed array printed as space-separated integers on a single line.

## Constraints
- 1 ≤ n ≤ 10^5
- -10^9 ≤ array elements ≤ 10^9

## Example
Input:
```
5
1 2 3 4 5
```

Output:
```
5 4 3 2 1 
```

## Notes
- You must reverse the array in-place, meaning you should modify the original array without creating a new one.
- Your solution should have O(n) time complexity and O(1) space complexity.
'''

# n=int(input())
# arr=list(map(int,input().split()))
# start=0
# end=n-1
# while start<end:
#    arr[start],arr[end]=arr[end],arr[start]
#    start+=1
#    end-=1
# for num in arr:
#   print(num,end=" ")



s=input()
word=input()
n=len(s)
word_len=len(word)
i=n-1
index=-1
while i>=0:
   if s[i:i+word_len]==word:
       index=i
       break
   i-=1
if index !=-1:
   s=s[:index]+s[index+word_len:]
   print(s)


#def power(x,n):
 # if n==0
  #  return 1
  #elif n<0:
  #  return 1/power(x,-n)
  #else:
 #   return x*power(x,n-1)
#x=float(input())
#n=int(input())
#result=power(x,n)
#print(f"{result:.2f}")



#n=int(input())
#arr1=list(map(int,input().split()))
#m=int(input())
#arr2=list(map(int,input().split()))
#i=j=0
#merged=[]
#while i<n and j<m:
#  if arr1[i]<arr2[j]:
 #   merged.append(arr1[i])
  #  i+=1
  #else:
   # merged.append(arr2[j])
    #j+=1
    #while i<n:
    #  merged.append(arr1[i])
     # i+=1
     # while j<m:
      # j+=1
#print(" ".join(map(str,merged)))






#n=int(input())
#arr=list(map(int,input().split()))
#even=[]
#odd=[]
#for i in range(n):
  #if arr[i]%2==0:
   # even.append(arr[i])
  #else:
    #odd.append(arr[i])

#for i in range(len(even)):
 # print(even[i],end="")
#print()


#for i in range(len(odd)):
#  print(odd[i],end="")





#n,k=map(int,input().split())
#arr=list(map(int,input().split()))
#i=0
#while i<n:
 # left=i
  #right=min(i+k-1,n-1)
  #while left<right:
   # temp=arr[left]
    #arr[left]=arr[right]
    #arr[right]=temp
   # left+=1
   # right-=1

  #i+=k
#for i in range(n):
 # print(arr[i],end=" "
