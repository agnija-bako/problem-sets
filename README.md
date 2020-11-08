# problem-sets
This a repository with solutions to the exercises in the [Harvard computer science course I've taken](https://www.edx.org/course/cs50s-introduction-to-computer-science). Languages used in the solutions are C and Python.


## 01 - C
### coins:
In coins a user provides an amount of money that is owed and the solutions finds a way to give back change with a minimum number of coins used. Coins available are 25¢, 10¢, 5¢ and 1¢.

### validate credit card:
Using Luhns alogorithm provided in the problem and a specification how to identify whether the card is a VISA card, Mastercard or AMEX, the solutions checks if the card number provided by the user is valid and identifies which card it is.

## 02 - C

### reading-level
Using the The Coleman-Liau index, after taking an input of a text the program outputs the reading level of a given text. 

Examples:
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3

Text: Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.
Grade 5

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

Examples:
./sub YTNSHKVEFXRBAUQZCLWDMIPGJO
plaintext:  HELLO
ciphertext: EHBBQ

./sub VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  hello, world
ciphertext: jrssb, ybwsp

## 03 - C
### majority-voting
Using the plurality method, determine who is the winner of the election. The winner is determined by a majority vote - every voter gets one vote, and the candidate with the most votes wins. 
Note: the solution in the code starts under //SOLUTION.

Example
./majority Alice Bob Charlie
Number of voters: 4
Vote: Alice
Vote: Bob
Vote: Charlie
Vote: Alice
Alice

### ranked-choice voting
Unlike majority-voting in a ranked-choice system, voters can vote for more than one candidate. Instead of just voting for their top choice, they can rank the candidates in order of preference. If any candidate has a majority (more than 50%) of the first preference votes, that candidate is declared the winner of the election. 

If no candidate has a majority of the votes, the last place candidate is eliminated, and anyone who voted for them will instead vote for their next preference (who hasn’t themselves already been eliminated). Once a candidate has a majority, that candidate is declared the winner.

The solution accepts user input of voter number, candidates in their ranked preferences and in the end outputs the winner of the election.

Example:
./ranked Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice

### ranked-pairs - voting
In this problem the task is to use the Tideman alternative method of voting. The Tideman voting method (also known as “ranked pairs”) is a ranked-choice voting method that’s guaranteed to produce the Condorcet winner of the election if one exists. 
#### How does it work:
Generally speaking, the Tideman method works by constructing a “graph” of candidates, where an arrow (i.e. edge) from candidate A to candidate B indicates that candidate A wins against candidate B in a head-to-head matchup. [See this graph as an example](https://cs50.harvard.edu/x/2020/psets/3/condorcet_graph_1.png). 
The arrow from Alice to Bob means that more voters prefer Alice to Bob (5 prefer Alice, 4 prefer Bob). Likewise, the other arrows mean that more voters prefer Alice to Charlie, and more voters prefer Charlie to Bob.
Looking at this graph, the Tideman method says the winner of the election should be the “source” of the graph (i.e. the candidate that has no arrow pointing at them). In this case, the source is Alice — Alice is the only one who has no arrow pointing at her, which means nobody is preferred head-to-head over Alice. Alice is thus declared the winner of the election.
#### Input and output of the solution:
The solution accepts user input of voter number, candidates in their ranked preferences and in the end outputs the winner of the election.

Example:
./pairs Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Charlie
