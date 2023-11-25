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
