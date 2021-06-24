// Narissa Tsuboi
// README_HW6
// 5/12/21

**HW 2 Corrections Narrative**

All problems - Updated documentation to C++ style per Programming Process & 
Documentation file on Canvas. Added main documentation, prototype descriptions
(pre, process, post) and function descriptions (in, out) where appropriate. 

All problems - Resolved stack dump upon compilation. For fib specifically, I 
had to change n from 45 to 40 to avoid a stack dump on my machine.

All problems - Ensured all files compiled with flags. I am copying the files
directly out of the read me, compiling, and running in windows command prompt.

Palindrome - Implemented helper function to trim line separators from the end of
each line read from file to allow program to read CRLF and LF line separators. 
Previously words.txt was set up in CRLF and the program only addressed LF.

Fibonnaci - Printed the first 45 fib. numbers for iterative, recursive, and 
recursiveBetter methods. Added print statements to separate each time trial.
Added brief description of the program to display to screen. 

Coin Change - In the first submission, I did not complete this problem at all.
Now I have completed it. This time around I decided to find what the 292
combinations were recursively and calculate the weight separately with a 
helper function that is called when the base case is reached. Separating the 
two problems simplified the problem into a understandable parts for me. 3
When trying to do it iteratively I could not find how to address taking as 
many coins of the larger denomination as possible and then switching to the next
lowest denomination. Please reference the approach section at the top of 
coinchange.cpp file for more info. 




