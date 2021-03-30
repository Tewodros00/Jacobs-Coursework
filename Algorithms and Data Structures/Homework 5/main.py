from math import pow, ceil, sqrt
from decimal import Decimal
import time

def main():
    print(matrixFibonacci(1))
    # size = [0, 1, 2, 3, 4, 5, 6, 8, 10, 13, 16, 20, 25, 32, 40, 50, 63, 83, \
    #     130, 200, 500, 1000, 5000, 15000, 50000, 500000, 1000000, 10000000, \
    #     50000000, 100000000] 

    # naive_time = open("naive.txt", "w")
    # for i in size:
    #     if i > 41:
    #         break
    #     begin = time.time()
    #     naiveFibonacci(i)
    #     end = time.time()
    #     naive_time.write(str(i) + " " + str(end - begin) + "\n")   
    # naive_time.close()

    
    # bottom_up_time = open("bottom_up.txt", "w")
    # for i in size:
    #     if i > 1000001:
    #         break
    #     begin = time.time()
    #     bottomUpFibonacci(i)
    #     end = time.time()
    #     bottom_up_time.write(str(i) + " " + str(end - begin) + "\n")
    # bottom_up_time.close()


    # closed_form_time = open("closed_form_time.txt", "w")
    # for i in size:
    #     begin = time.time()
    #     closedFormFibonacci(i)
    #     end = time.time()
    #     closed_form_time.write(str(i) + " " + str(end - begin) + "\n")
    # closed_form_time.close()


    # matrix_time = open("matrix_time.txt", "w")
    # for i in size:
    #     if i > 10000000:
    #         break
    #     begin = time.time()
    #     matrixFibonacci(i)
    #     end = time.time()
    #     matrix_time.write(str(i) + " " + str(end - begin) + "\n")
    # matrix_time.close()

    return 0


# naive recursive implementation of a Fibonacci number.
def naiveFibonacci(n):
    if n < 2:
        return n
    else:
        return naiveFibonacci(n - 1) + naiveFibonacci(n - 2)


# bottom up implementation which is an iterative way of generating a Fibonacci
# number.
def bottomUpFibonacci(n):
    if n == 0:
        return 0
    num1 = 0
    num2 = 1
    for i in range(1, n):
        new_num = num1 + num2
        num1 = num2
        num2 = new_num
    return num2


# recursive implementation of power function
def power(a, n):
    if n == 0:
        return 1 
    if n % 2 == 0:
        return power(a, n//2) * power(a, n//2)  
    else:    
        return power(a, n//2) * power(a, n//2) * a

# Closed form implementation: Not always accurate due to floating point 
# arithmetic imprecision and should be used with caution. 
def closedFormFibonacci(n):
    a = (1 + sqrt(5)) / 2
    f = power(a, n) / sqrt(5)
    return f


def multiplyMatrix(a, b):
    c00 = a[0][0]*b[0][0] + a[0][1]*b[1][0]
    c01 = a[0][0]*b[0][1] + a[0][1]*b[1][1]
    c10 = a[1][0]*b[0][0] + a[1][1]*b[1][0]
    c11 = a[1][0]*b[0][1] + a[1][1]*b[1][1]
    
    a[0][0] = c00
    a[0][1] = c01
    a[1][0] = c10
    a[1][1] = c11

def powerMatrix(a, n):
    if n < 2:
        return
    b = [[1, 1], [1, 0]]
    powerMatrix(a, n // 2)
    multiplyMatrix(a, a)
    if (n % 2 != 0):
        multiplyMatrix(a, b)

# Generates Fibonacci number using the Matrix representaion.
def matrixFibonacci(n):
    a = [[1, 1], [1, 0]]
    if n == 0:
        return 0
    powerMatrix(a, n)
    return a[0][1]

main()