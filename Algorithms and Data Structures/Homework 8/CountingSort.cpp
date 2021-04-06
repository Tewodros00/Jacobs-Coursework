int* countingSort(int arr[], int dim, int range) {
    int* c = new int[range];
    for (int i = 0; i < range; i++)
        c[i] = 0;
    
    for (int i = 0; i < dim; i++) 
        c[arr[i]] += 1;
    
    for (int i = 1; i < range; i++) 
        c[i] += c[i - 1];
        
    int* b = new int[dim];

    for (int i = dim - 1; i >= 0; i--) {
        b[c[arr[i]] - 1] = arr[i];
        c[arr[i]] -= 1;
    }

    delete [] c;
    
    return b;
}