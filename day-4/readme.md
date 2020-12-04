Day 4.
I am not satisfied as to how jumbled up my code looks.

I commend the organizers for creating such correct input without any errors. I performed the first part lazily, and yet I did not encounter any hiccups. I 
did not check for any other cases. The only condition I checked was the presence of other strings. I did not check the name of the fields.

This hampered the second part as I hurriedly wrote multiple conditional statements.

I wrote whatever I thought in my head. But I see great room for improvement.

Areas to look at,

1. Proper implementation of the StringStream. And what to #include. 
  I loved the practicality of the StringStream and I struggled to implement it. I did not know the best way to use it. 
  Also, the other part was the getline, and how it assigns value if the line read only has \n. In this case the string received an empty string ,"" .
2. Using cctype, or avoid.
  Notice, that I did not use any cctypes. cctype functions would have decreased the code I would have to write down. However, in certain cases, I wanted
  to be certain that the character being processed was properly looked at. isdigit would have worked but isalphanum might not have.
  
  I should have used islower() and isdigit(). It would have cut down on code and made it more readable.
  
3. Using objects, and structures to store data so that I can review them easier later.

I thought about saving it in form of objects but, I do not know how big the data is and how taxing it'd be on my system. I also have to think about privacy. 
Even though a virtual problem, maybe it is not the best practices to store the info if the reason is to just check it.

Anyway, I'll work on it later.
