import time
from random import randrange


def main():
    best = open("best.txt", "w")
    worst = open("worst.txt", "w")
    avg = open("avg.txt", "w")
    size = 8192
    for k in range(1, size, 64):
        b = bestCase(size)
        w = worstCase(size)

        best_start = time.time()
        mergeSort(b, k)
        best_end = time.time()
        best_time = best_end - best_start

        worst_start = time.time()
        mergeSort(w, k)
        worst_end = time.time()
        worst_time = worst_end - worst_start

        avg_time = 0
        for i in range(5):
            a = averageCase(size)
            avg_start = time.time()
            mergeSort(a, k)
            avg_end = time.time()
            avg_time += avg_end - avg_start
        avg_time = avg_time / 5

        best.write(str(k) + " " + str(best_time) + "\n")
        worst.write(str(k) + " " + str(worst_time) + "\n")
        avg.write(str(k) + " " + str(avg_time) + "\n")
    
    best.close()
    worst.close()
    avg.close()





        


def insertionSort(array):
    for i in range(1, len(array)):
        key = array[i]
        j = i-1
        while j >= 0 and key < array[j]:
                array[j + 1] = array[j]
                j -= 1
        array[j + 1] = key
    return array

def merge(left, right):
    i, j = 0, 0
    merged = []
    while True:
        if i == len(left):
            merged += right[j:]
            break
        if j == len(right):
            merged += left[i:]
            break

        if left[i] > right[j]:
            merged.append(right[j])
            j += 1
        else:
            merged.append(left[i])
            i += 1
    return merged


def mergeSort(array, k):
    if len(array) <= k:
        return insertionSort(array)
    mid = len(array)// 2
    left_half = mergeSort(array[0:mid], k)
    right_half = mergeSort(array[mid:], k)
    return merge(left_half, right_half)



def bestCase(size):
    return [x for x in range(size)]

def worstCase(size):
    return [x for x in range(size - 1, -1, -1)]

def averageCase(size):
    return [randrange(size) for x in range(size)]


main()
