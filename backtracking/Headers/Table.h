#ifndef TABLE_H
#define TABLE_H

#include "Part.h"
#include <vector>
#include <iostream>

class Table{
    public:
        Table(int n);
        void RequiredSquaresRead();
        void Optimization();
        void Fill();
        void Recursion();
        void FindCoordOfEmptySpace(Coordinate &coord);
        bool IsEmpty(Coordinate &coord, int size);
        bool IsFit(Coordinate &coord, int size);
        void AddSquare(Coordinate &coord, int size);
        void RemoveSquare(Coordinate &coord, int size);
        void ClearField();
        void DisplayResult();
    private:
        std::vector<std::vector<int>> Field;
        std::vector<Part> BestSolution;
        std::vector<Part> Solution;
        std::vector<int> RequiredSquares;
        int BestSolutionPartsAmount;
        int SolutionPartsAmount = 0;
        int FieldSize;
};

#endif
