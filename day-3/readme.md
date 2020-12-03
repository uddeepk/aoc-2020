Dec2, 2140 > Instead of using string vectors, i used vectors to store positions, and stars. Then ran trough the program with the same iteration.  Is this more optimized ? Is this code readable?

One problem I felt like is that using the position[0] as the counter for right 1 down 2 may seem confusing. I had to spend 20 minutes trying to debug it. However, I think it is more efficient than the initial code as I do not have to go through each every line times 5. I go through each line once using get line, and I just look at the strings 5 times.

Originl >
So I just basically built three functions. main and two functions to call with parameters to find the results.

I had to use long because int value was not big enough for the second part of the challenge.

I normally use console to input the file using <. However, I saved the fstream version so that I can remember what I did.

I saved the input in a string vector to use on subsequent runs. However, maybe I could have modified it by using multiple counters as it is going down ...
