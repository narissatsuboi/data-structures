# HW5

# Carrano Programming Problem 10.6 (Hydra)
Do this exercise from the book. Where it says "Bag", you should use the ```LinkedList``` class from previous homeworks/lecture notes (included in the starter code).

Your program must:
* Prompt the user to enter a starting string (as in the instructions in the book).
* Count the number of "heads" that the hero ends up cutting off to defeat the hydra.

Your submission must include:
* The source code for a functional solution.
  * Complete this in ```Hydra.cpp```.
* A *complete paragraph* (**not** just source code comments) explaining the time requirements for the algorithm in terms of Big-O notation.
* An image of a plot of timings for various sizes of the start string.
  * For timings, use the ```Timer``` class we built in Week 5 class (available in the Lecture code in github)
  * You will have to experiment to see how large the string needs to be to make this "interesting".
  * To collect the timings, you will probably want to modify your program to auto-generate start strings (but your final submission must prompt the user for a string and execute once).
    * You can include both modes in the same program, selecting one or the other based on user input.
  * The plot image should be in a stadard format (PNG, JPG, etc.)
  * You need to have a scale so that we can clearly read the times in ms.

## Submission
* Create a SINGLE folder *named with your SU email name* containing ONLY source code for this problem plus the plot of timings image.
  * ```.h``` files
  * ```.cpp``` files
  * ```CMakeLists.txt```
  * A single PNG/JPG named (for example) ```plot.jpg```.
* Zip this folder.
* Double-check that it only contains files of the type listed just above ^^.
* And submit it to HW5 in Canvas.

If you submit any additional files, including:
  * Executable, binary, and output files, including everything in ```cmake-build-debug```
  * CLion files (i.e. ```.idea```)
  * Mac .DS_Store folders

  you *will* lose points.

If your code does not compile using the following command line:

```$ g++ Hydra.cpp ListInterface.h LinkedList.h Timer.h -o HW5 -pedantic -Wall -Werror -std=c++11```

you *will* lose points, up to and including receiving a 0 on the assignment.

Upload the zip file to the HW5 assignment in Canvas.
