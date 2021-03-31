from random import randrange
def main():
    array = [randrange(100000) for x in range(1000)]
    quickSortDualPivot(array, 0, len(array) - 1)
    print("Dual pivot Quicksort:")
    print("sorted" if array == sorted(array) else "not sorted")

    print()

    array2 = [randrange(100000) for x in range(1000)]
    quickSortRandomized(array2, 0, len(array2) - 1)
    print("Randomized dual pivot Quicksort:")
    print("sorted" if array2 == sorted(array2) else "not sorted")



def quickSortDualPivot(array, p, r):
    if p < r:
        a, b = dualPartition(array, p, r)
        quickSortDualPivot(array, p, a)
        quickSortDualPivot(array, a + 1, b - 1)
        quickSortDualPivot(array, b + 1, r)

def dualPartition(array, p, r):
    if array[p] > array[p + 1]:
        array[p], array[p + 1] = array[p + 1], array[p]
    array[p + 1], array[r] = array[r], array[p + 1]

    leftPivot = array[p]
    rightPivot = array[r]

    i = p + 1
    j = r - 1
    k = i

    while k <= j:
        if array[k] <= leftPivot:
            array[k], array[i] = array[i], array[k]
            i += 1
        elif array[k] >= rightPivot:
            while array[j] > rightPivot and k < j:
                j -= 1
            array[k], array[j] = array[j], array[k]
            j -= 1
            if array[k] < leftPivot:
                array[k], array[i] = array[i], array[k]
                i += 1
        k += 1
    i -= 1
    j += 1
    
    array[p], array[i] = array[i], array[p]
    array[r], array[j] = array[j], array[r]
    return i, j


def quickSortRandomized(array, p, r):
    if p < r:
        a, b = randomDualPartition(array, p, r)
        quickSortRandomized(array, p, a)
        quickSortRandomized(array, a + 1, b - 1)
        quickSortRandomized(array, b + 1, r)

def randomDualPartition(array, p, r):
    left = randrange(r - p) + p
    right = randrange(r - p) + p
    array[p], array[left] = array[left], array[p]
    array[r], array[right] = array[right], array[r]

    if array[p] > array[r]:
        array[p], array[r] = array[r], array[p]

    leftPivot = array[p]
    rightPivot = array[r]

    i = p + 1
    j = r - 1
    k = i

    while k <= j:
        if array[k] <= leftPivot:
            array[k], array[i] = array[i], array[k]
            i += 1
        elif array[k] >= rightPivot:
            while array[j] > rightPivot and k < j:
                j -= 1
            array[k], array[j] = array[j], array[k]
            j -= 1
            if array[k] < leftPivot:
                array[k], array[i] = array[i], array[k]
                i += 1
        k += 1
    i -= 1
    j += 1
    
    array[p], array[i] = array[i], array[p]
    array[r], array[j] = array[j], array[r]
    return i, j

main()