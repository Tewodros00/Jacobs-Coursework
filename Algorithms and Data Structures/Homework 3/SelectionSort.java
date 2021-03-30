package com.company;

import java.io.*;
import java.util.Random;

public class SelectionSort {
    public static void main(String[] args) {
        // used to keep record of execution times
        double[][] executionTimes = new double[3][63];
        int count = 0;

        // for choosing length of array
        for (int i = 100; i < 50000; i+=800) {
            // for choosing the type of input(best, average, worst)
            for (int j = 0; j < 3; j++) {
                executionTimes[j][count] = 0;
                // running the same sized arrays 5 times
                for (int k = 0; k < 5; k++) {
                    int[] array;
                    if (j == 0)
                        array = randomCase(i);
                    else if (j == 1)
                        array = bestCase(i);
                    else
                        array = worstCase(i);

                    long start = System.nanoTime();
                    selectionSort(array);
                    long end = System.nanoTime();

                    executionTimes[j][count] += (end - start) / 1000000000F;
                }
                // average times of the 5 arrays
                executionTimes[j][count] = executionTimes[j][count] / 5;
            }
            count++;
        }

        try {
            for (int i = 0; i < 3; i++) {
                // writing the execution times to a file for use in gunplot
                String[] filename = {"Average.txt", "Best.txt", "Worst.txt"};
                File outfile = new File(filename[i]);
                FileOutputStream os = new FileOutputStream(outfile);
                OutputStreamWriter osw = new OutputStreamWriter(os);
                Writer writer = new BufferedWriter(osw);

                for (int j = 0; j < 63; j++)
                    writer.write((100 + j * 800) + " " + Double.toString(executionTimes[i][j]) + "\n");
                writer.close();
            }
        } catch (IOException ioe) {
            System.out.println(ioe.getMessage());
        }
    }

    static void selectionSort(int[] array) { // described in the pdf
        for (int i = 0; i < array.length - 1; i++) {
            int currentMinInd = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[j] < array[currentMinInd]) {
                    currentMinInd = j;
                }
            }
            if (currentMinInd != i) {
                int temp = array[i];
                array[i] = array[currentMinInd];
                array[currentMinInd] = temp;
            }
        }
    }

    static int[] randomCase(int size) { // described in the pdf
        Random random = new Random();
        int[] randomArray = new int[size];
        for (int i = 0; i < size; i++)
            randomArray[i] = random.nextInt(size);
        return randomArray;
    }

    static int[] worstCase(int size) { // described in the pdf
        int[] worstCaseArray = new int[size];
        worstCaseArray[0] = size;
        for (int i = 1; i < size; i++)
            worstCaseArray[i] = i;
        return worstCaseArray;
    }

    static int[] bestCase(int size) { // described in the pdf
        int[] bestCaseArray = new int[size];
        for (int i = 1; i < size; i++)
            bestCaseArray[i] = i + 1;
        return bestCaseArray;
    }
}
