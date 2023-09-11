/*
Readme File: 
Author: Hamza Malik
Student # 501112545
Submit Date: Mon July 17, 2023
Lab Due Date: Wed July 19, 2023

Question 1: 
Suppose you were given an object module (with no access to source code) that sorted an array of integers very efficiently. 
However, the sort function in the object module must be invoked with the following signature:
betterSort(int data[], first, last);
where the array to sort is data and the parameters first and last give the indices of the portion of the array that is to be sorted.
How could you write a mySort() function with the signature used in this lab that could exploit the better sorting function in the supplied object module?

Answer 1:
To leverage the efficient sorting algorithm in the given object module,
I would create a mySort() function with the signature void mySort(int d[], unsigned int n).

- This function takes in an array d of integers and the size of the array n. 

Inside mySort(), I would call the betterSort() function with the parameters betterSort(d, 0, n-1), 
- where d is the array to be sorted, 0 represents the first index of the array, and n-1 represents the index of the last element in the array. 

By providing the correct parameter mapping,
the entire array will be sorted effectively using the efficient sorting algorithm from the object module.
This allows me to have more control over the sorting process while still benefiting from the optimized sorting mechanism.




Side Note For my Self:
mysort() has 2 inputs (array and size of the array)
mySort(int d[], unsigned int n)

betterSort() has 2 inputs (d, 0, n-1)
- where d is the array to be sorted, 0 represents the first index of the array, and n-1 represents the index of the last element in the array. 









Code fully complies without any errors!

sortMain.o outputs:
10
20
30
40

sortMain2.o (You need to imput command line arguments)
ex. testSort 1 2 3 -5
Rearranges so would be 
-5
1
2
3

I was invoked with the command: ./cmdlineDemo
The command line arguments are:
   argv[1] (as string): hello
              (as int): 0
       (as int in hex): 0

   argv[2] (as string): 125
              (as int): 125
       (as int in hex): 7D

   argv[3] (as string): 22
              (as int): 22
       (as int in hex): 16

   argv[4] (as string): -6
              (as int): -6
       (as int in hex): FFFFFFFA

*/
