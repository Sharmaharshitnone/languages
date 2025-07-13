# NOTE: This is module code, not a script.
def factorial(n):
    if(n <= 1):
        return 1
    else:
        return n * factorial(n - 1)

# NOTE: Compute the nth Fibonaaci number

def fibonacci(n):
    if n <= 0:
        return 0
    else:
        if n == 1 or n == 2:
            return 1
        else:
            return fibonacci(n - 1) + fibonacci(n - 2)
        
# NOTE: This is a recursive function to compute the sum of first 'n' Natural numbers

def sum_natural_numbers(n):
    if n <= 0:
        return 0
    else:
        return n + sum_natural_numbers(n - 1)

