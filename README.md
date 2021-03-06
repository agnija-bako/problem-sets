# problem-sets
This a repository with solutions to the exercises in the [Harvard computer science course I've taken](https://www.edx.org/course/cs50s-introduction-to-computer-science). Languages used in the solutions are C and Python.


## 01 - C
### coins:
In coins a user provides an amount of money that is owed and the solutions finds a way to give back change with a minimum number of coins used. Coins available are 25¢, 10¢, 5¢ and 1¢.

### validate credit card:
Using Luhns alogorithm provided in the problem and a specification how to identify whether the card is a VISA card, Mastercard or AMEX, the solutions checks if the card number provided by the user is valid and identifies which card it is.

## 02 Arrays - C

### reading-level
Using the The Coleman-Liau index, after taking an input of a text the program outputs the reading level of a given text. 

Examples:<br/>
`Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!`<br/>
`Grade 3` <br/>
`Text: Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.`<br/>
`Grade 5`

### shift-cipher
Using a shift-cipher or (Caesar cipher), after taking an input of a text and a key, the program outputs and encrypted version of that text.

Examples:<br/>
`./shift 1`<br/>
`plaintext:  HELLO`<br/>
`ciphertext: IFMMP`

`./shift 13`<br/>
`plaintext:  hello, world`<br/>
`ciphertext: uryyb, jbeyq`

### substitution-cipher
Using a substitution-cipher, after taking an input of a text and a key, the program outputs and encrypted version of that text.

Examples:<br/>
`./sub YTNSHKVEFXRBAUQZCLWDMIPGJO`<br/>
`plaintext:  HELLO`<br/>
`ciphertext: EHBBQ`

`./sub VCHPRZGJNTLSKFBDQWAXEUYMOI`<br/>
`plaintext:  hello, world`<br/>
`ciphertext: jrssb, ybwsp`

## 03 Algorithms - C
### majority-voting
Using the plurality method, determine who is the winner of the election. The winner is determined by a majority vote - every voter gets one vote, and the candidate with the most votes wins. 


Examples:<br/>
`./majority Alice Bob Charlie`<br/>
`Number of voters: 4`<br/>
`Vote: Alice`<br/>
`Vote: Bob`<br/>
`Vote: Charlie`<br/>
`Vote: Alice`<br/>
`Alice`

### ranked-choice voting
Unlike majority-voting in a ranked-choice system, voters can vote for more than one candidate. Instead of just voting for their top choice, they can rank the candidates in order of preference. If any candidate has a majority (more than 50%) of the first preference votes, that candidate is declared the winner of the election. 

If no candidate has a majority of the votes, the last place candidate is eliminated, and anyone who voted for them will instead vote for their next preference (who hasn’t themselves already been eliminated). Once a candidate has a majority, that candidate is declared the winner.

The solution accepts user input of voter number, candidates in their ranked preferences and in the end outputs the winner of the election.

Examples:<br/>
`./ranked Alice Bob Charlie`<br/>
`Number of voters: 5`<br/>
`Rank 1: Alice`<br/>
`Rank 2: Bob`<br/>
`Rank 3: Charlie`<br/>
<br/>
`Rank 1: Alice`<br/>
`Rank 2: Charlie`<br/>
`Rank 3: Bob`<br/>
<br/>
`Rank 1: Bob`<br/>
`Rank 2: Charlie`<br/>
`Rank 3: Alice`<br/>
<br/>
`Rank 1: Bob`<br/>
`Rank 2: Alice`<br/>
`Rank 3: Charlie`<br/>
<br/>
`Rank 1: Charlie`<br/>
`Rank 2: Alice`<br/>
`Rank 3: Bob`<br/>
`Alice`

### ranked-pairs - voting
In this problem the task is to use the Tideman alternative method of voting. The Tideman voting method (also known as “ranked pairs”) is a ranked-choice voting method that’s guaranteed to produce the Condorcet winner of the election if one exists. 
#### How does it work:
Generally speaking, the Tideman method works by constructing a “graph” of candidates, where an arrow (i.e. edge) from candidate A to candidate B indicates that candidate A wins against candidate B in a head-to-head matchup. [See this graph as an example](https://cs50.harvard.edu/x/2020/psets/3/condorcet_graph_1.png). 
The arrow from Alice to Bob means that more voters prefer Alice to Bob (5 prefer Alice, 4 prefer Bob). Likewise, the other arrows mean that more voters prefer Alice to Charlie, and more voters prefer Charlie to Bob.
Looking at this graph, the Tideman method says the winner of the election should be the “source” of the graph (i.e. the candidate that has no arrow pointing at them). In this case, the source is Alice — Alice is the only one who has no arrow pointing at her, which means nobody is preferred head-to-head over Alice. Alice is thus declared the winner of the election.
#### Input and output of the solution:
The solution accepts user input of voter number, candidates in their ranked preferences and in the end outputs the winner of the election.

Examples:<br/>
`./ranked Alice Bob Charlie`<br/>
`Number of voters: 5`<br/>
`Rank 1: Alice`<br/>
`Rank 2: Charlie`<br/>
`Rank 3: Bob`<br/>
<br/>
`Rank 1: Alice`<br/>
`Rank 2: Charlie`<br/>
`Rank 3: Bob`<br/>
<br/>
`Rank 1: Bob`<br/>
`Rank 2: Charlie`<br/>
`Rank 3: Alice`<br/>
<br/>
`Rank 1: Bob`<br/>
`Rank 2: Charlie`<br/>
`Rank 3: Alice`<br/>
<br/>
`Rank 1: Charlie`<br/>
`Rank 2: Alice`<br/>
`Rank 3: Bob`<br/>
`Charlie`
## 04 Memory - C
### Photo filters
The task is to implement a program that applies the following filters to BMPs:
- Grayscale
- Reflection
- Blur - using the “box blur” method
- Edges - detect edges of the image by applying the Sobel operator.
Find the solution in - helpers.c
### Restore
The task is to implement a program that recovers JPEGs from a forensic image. A card.raw is provided.
## 05 Data structures - C
### spell-check
The task is to implement a program that spell-checks a file using a hash table. The solution takes a text as an input and after checking it against the dictionary outputs any misspellings found in that text.

## 06 - Python
Tasks - **coins**, **reading-level** and **validate credit card** are exactly the same as in C above, but written in Python. 

### DNA-sequences
The task is to implement a program that identifies a person based on their DNA.
Provided in the task we have a DNA database, that looks something like this:<br/>
`name,AGAT,AATG,TATC`<br/>
`Alice,28,42,14`<br/>
`Bob,17,22,19`<br/>
`Charlie,36,18,25`<br/>
#### How does it work:
"AGAT" "AATG" and "TATC" are Short Tandem Repeats of the DNA or STRs. An STR is a short sequence of DNA bases(adenine (A), cytosine (C), guanine (G), or thymine (T)) that tends to repeat consecutively numerous times at specific locations inside of a person’s DNA. The number of times any particular STR repeats varies a lot among individuals. The solution uses all the provided STRs in the DNA database and looks for an exact person match of all combinations.
#### Input and output
The program accepts 2 files as an input - the dna database, and the sequence of DNA of a particular person. The output is the person match in the database. 

Example:<br/>
`python seq.py databases/large.csv sequences/5.txt`<br/>
`Lavender`<br/>

## 07 SQL - Python
The task is to implement a program to import student data into a database, and then produce class rosters.
The program accepts csv as an input and imports the student list from a csv file into SQLite database. After the data is imported, the program queries and prints all students in the database alphabetically based on their house.

Example<br/>
`$ python import.py characters.csv`<br/>
`$ python roster.py Gryffindor`<br/>
`Lavender Brown, born 1979`<br/>
`Colin Creevey, born 1981`<br/>
`Seamus Finnigan, born 1979`<br/>
`Hermione Jean Granger, born 1979`<br/>
`Neville Longbottom, born 1980`<br/>
`Parvati Patil, born 1979`<br/>
`Harry James Potter, born 1980`<br/>
`Dean Thomas, born 1980`<br/>
`Romilda Vane, born 1981`<br/>
`Ginevra Molly Weasley, born 1981`<br/>
`Ronald Bilius Weasley, born 1980`<br/>



