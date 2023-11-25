# design-and-analysis-of-algorithms
A collection of practical works completed in the process of studying the subject "Design and Analysis of Algorithms"

## 🔙 Backtracking
In this work, a backtracking algorithm was used to construct a square with a minimum number of smaller squares. For example, a square with side 7 can be constructed as follows:

![image](https://github.com/mahalichev/design-and-analysis-of-algorithms/assets/54910038/5ccd36cf-226b-4293-95a8-0f6b60ba9056)

Modification: Recursive backtracking. Ability to specify a list of squares (from 0 to $N^2$ squares in the list), which must be used to cover a square with side N.

Input data:
- Side length
- Number of required squares
- List of lengths of required squares

Output data:
- Number of squares
- Coordinates of the upper left corners and lengths of the squares

To run the program, enter the following commands:
```
make
./a.out
```
```
// Run example
./a.out
7
3
3 3 3
```

Directory: `./backtracking`

## 🌊 Maximum flow
Implementation of the Ford-Fulkerson algorithm for finding the maximum flow in the network.

#### Individualization
Search according to the rule: each time a transition is performed along the edge that has the maximum residual capacity. If there are several such edges, then select the one that was discovered earlier in the current path search.

Input data:
- Mode (1 - Standart; 2 - Individualization)
- Number of directed edges of the graph
- Source
- Sink
- Graph edge
- Graph edge
- ...

Output data:
- Maximum flow value
- Edge of the graph with the actual value of the flowing flow
- Edge of the graph with the actual value of the flowing flow
- ...

To run the program, enter the following commands:
```
make
./a.out
```
```
// Run example
./a.out
1
5
a
d
a b 1000
a c 1000
b d 1
b c 1000
c d 1000
```

Directory: `./ford-fulkerson`

## 🟰 Knuth–Morris–Pratt algorithm
Knuth–Morris–Pratt algorithm is implemented for searching the number of occurrences of a substring in a string.

Input data:
- First string P
- Second string T

Output data:
- Indices of the beginning of occurrences of P in T, separated by a comma (if P is not included in T, then output -1).

To run the program, enter the following commands:
```
make
./a.out
```
```
// Run example
./a.out
ab
ababba
```

Directory: `./knuth-morris-pratt`
