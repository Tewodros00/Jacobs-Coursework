import time
from random import randrange

def main():
    lomuto_time = hoare_time = median_time = 0
    iterations = 100000
    for i in range(iterations):
        array = randomArray()
        array_1 = array.copy()
        array_2 = array.copy()
        array_3 = array.copy()

        start = time.time()
        lomutoQuickSort(array_1, 0, 999)
        end = time.time()
        lomuto_time += end - start

        start = time.time()
        hoareQuickSort(array_2, 0, 999)
        end = time.time()
        hoare_time += end - start

        start = time.time()
        medianOf3QuickSort(array_3, 0, 999)
        end = time.time()
        median_time += end - start

    lomuto_time /= iterations
    hoare_time /= iterations
    median_time /= iterations

    print(f"lomuto: {lomuto_time}\nhoare: {hoare_time}\nmedian: {median_time}")
 
    

def lomutoQuickSort(array, p, r):
    if p < r:
        q = lomutoPartition(array, p, r)
        lomutoQuickSort(array, p, q)
        lomutoQuickSort(array, q + 1, r)
        
def lomutoPartition(array, p, r):
    pivot = array[p]
    i = p
    for j in range(p + 1, r + 1):
        if array[j] < pivot: 
            i += 1
            array[i], array[j] = array[j], array[i]
    array[p], array[i] = array[i], array[p]
    return i


def hoareQuickSort(array, p, r):
    if p < r:
        q = hoarePartition(array, p, r)
        hoareQuickSort(array, p, q)
        hoareQuickSort(array, q + 1, r)

def hoarePartition(array, p, r):
    pivot = array[(p + r) // 2]
    i = p - 1
    j = r + 1
    while True:
        i += 1
        while array[i] < pivot:
            i += 1
        j -= 1
        while array[j] > pivot:
            j -= 1
        if i >= j:
            return j
        array[i], array[j] = array[j], array[i]


def medianOf3QuickSort(array, p, r):
    if p < r:
        q = medianOf3Partition(array, p, r)
        medianOf3QuickSort(array, p, q)
        medianOf3QuickSort(array, q + 1, r)

def medianOf3Partition(array, p, r):
    mid = (p + r) // 2
    if array[p] > array[r]:
        array[p], array[r] = array[r], array[p]
    if array[p] > array[mid]:
        array[p], array[mid] = array[mid], array[p]
    if array[mid] > array[r]:
        array[mid], array[r] = array[r], array[mid]

    array[mid], array[r - 1] = array[r - 1], array[mid]

    pivot = array[r - 1]
    i = p - 1
    j = r + 1
    while True:
        i += 1
        while array[i] < pivot:
            i += 1
        j -= 1
        while array[j] > pivot:
            j -= 1
        if i >= j:
            return j
        array[i], array[j] = array[j], array[i]

def randomArray():
    return [randrange(100000) for x in range(1000)]

main()