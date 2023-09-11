/*
Readme File For the Tower Of Hanoi
: 
Author: Hamza Malik
Student # 501112545
Submit Date: Mon July 17, 2023
Lab Due Date: Wed July 19, 2023


Question1:

Suppose that towers(5, 2, 3) is invoked.                                                                                            

1.      How will the first recursive call to towers() be invoked? Answer this question in the form: towers(x, y, z) where you give the actual values to the three parameters.

2.      How many recursive calls to towers() will be made before this first recursive call actually returns to the initial invocation?

3.      Once towers(5, 2, 3) has invoked its first recursive call to towers() and this invocation has returned, what will be printed to stdout? (i.e. What actual move will be made by towers(5, 2, 3) ?)

4.      How will the second recursive call to towers() be invoked? Answer this question in the form: towers(x, y, z) where you give the actual values to the three parameters.


Answer1:
1. Towers (5,2,3)  recursive call to towers (4,2,1) 
2. towers () called 5 times before initial invocation returned 
3. first disk move from tower 2 to 3 to stdout
4. the second recursive call to towers() will be towers (4, 1 , 3)


Question2:

Suppose that towers(8, 1, 2) is invoked. How many lines will be printed to stdout?

Note

·         You should note (or try to convince yourself) that the number of lines printed to stdout is precisely equal to the number of moves required to solve the problem.

·         You can use the theoretical analysis of the problem to determine the number of moves.

·         The towers command behaves somewhat differently than what has been described so far. In particular, if it is invoked with an argument, it will move the specified number of disks from Tower 1 to Tower 2. For example,

*/

Answer2:
255 lines will be printed to stdout. 
