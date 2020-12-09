Day-9 AoC 2020
Update 2349 : I found a more efficient way of performing part 2. look at the method star2. I used iterators to traverse through the vector of input. The iterators itStart, and itEnd start equal. THen we go in loop until we find sum == star1 or we hit end. 
We check if itStart == itEnd then itEnd = itStart +1; sum = itStart + itEnd then we conntinue;
if sum < star1 , then itEnd++; sum+=itEnd;
if sum > star1, then sum -=itStart; itStart++;
Shaved 2 minutes off my initial program.

Difficulty feels like it is ramping up. If the algorithm isn't difficult to think, then the implementation is. Atleast for me. 

Anyways, the first part felt really easy. It took me quite a long time, as I wanted to use deque, and set. I implemented both for the first time. Also, the flow
of the program may look awkward as I am just trying to get an effective answer rather than an efficient one.

Runtime took approx 2 mins.

I need to revisit this with more efficient algorithms, and better implementations of data structures. My computer is starting to feel the burden of all the bruteforcing.
