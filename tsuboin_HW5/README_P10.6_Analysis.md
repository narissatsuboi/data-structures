// Narissa Tsuboi

// README_P10.6_Analysis.md

// Paragraph explaining the Big-O time requirements 
// for the HYDRA algorithm in terms of Big-O notation

**Big-O Time Requirements for the Hydra Algorithm**

A summary of the Hydra operations is as follows: Seed a LinkedList ADT with a 
single string of arbitrary length, traverse to the end of the list, and if the 
string contained in the end node contains one character,remove it from 
the LinkedList. Else, remove it and replace it with two copies with the first 
letter removed. In the conceptual time complexity analysis of the worse case 
scenario, we assume the latter operation, replacing a head with two heads. In
this case, the size of the work doubles at each remove operation, which is an
exponential relationship. As the string length grows, the remove operation
increases, so the doubling increases exponentially. The graph of string length
(n) versus function runtime in milliseconds (see Hydra Big-O Graph.png) confirms
the conceptual analysis. The data exhibits an exponential curve, with the 
runtimes (roughly) doubling at each increment of n. 


_The Hydra problem referenced here is from PP10.6 Data Abstraction and Problem
Solving by Carrano._ 