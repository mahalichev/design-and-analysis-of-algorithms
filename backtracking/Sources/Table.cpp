#include "../Headers/Table.h"

Table::Table(int n): FieldSize(n), BestSolutionPartsAmount(n*n+1){
    std::vector<int> length(FieldSize);
    for(int i = 0; i < FieldSize; i++){
        Field.push_back(length);
    }
}

void Table::RequiredSquaresRead(){
    int n, SquareSize;
    std::cout << "Required squares amount - ";
    std::cin >> n;
    std::cout << "Squares sizes - ";
    for(int i = 0; i < n; i++){
        std::cin >> SquareSize;
        RequiredSquares.push_back(SquareSize);
    }
}

void Table::Optimization(){
    Coordinate coord(0,0);
    if(!(FieldSize % 2)){
        AddSquare(coord, FieldSize/2);
        coord = Coordinate(FieldSize/2, 0);
        AddSquare(coord, FieldSize/2);
        coord = Coordinate(0, FieldSize/2);
        AddSquare(coord, FieldSize/2);
    } else if (!(FieldSize % 3)){
        AddSquare(coord, FieldSize*2/3);
        coord = Coordinate((FieldSize*2)/3, 0);
        AddSquare(coord, FieldSize/3);
        coord = Coordinate(0, (FieldSize*2)/3);
        AddSquare(coord, FieldSize/3);
    }
    else if (!(FieldSize % 5)){
        AddSquare(coord, (FieldSize*3)/5);
        coord = Coordinate((FieldSize*3)/5, 0);
        AddSquare(coord, (FieldSize*2)/5);
        coord = Coordinate(0, (FieldSize*3)/5);
        AddSquare(coord, (FieldSize*2)/5);
    }
    else{
        AddSquare(coord, (FieldSize+1)/2);
        coord = Coordinate((FieldSize+1)/2, 0);
        AddSquare(coord, (FieldSize-1)/2);
        coord = Coordinate(0, (FieldSize+1)/2);
        AddSquare(coord, (FieldSize-1)/2);
    }
};

void Table::FindCoordOfEmptySpace(Coordinate &coord){
    for (int i = 0; i < FieldSize; i++){
        for (int j = 0; j < FieldSize; j++){
            if (!Field[i][j]){
                coord.x = j;
                coord.y = i;
                return;
            }
        }
    }
}

void Table::Recursion(){
    if (SolutionPartsAmount >= BestSolutionPartsAmount){
        return;
    }
    Coordinate CoordOfEmptySpace(-1,-1);
    FindCoordOfEmptySpace(CoordOfEmptySpace);
    if (CoordOfEmptySpace.x == -1){
        if(!RequiredSquares.size()){
            BestSolution = Solution;
            BestSolutionPartsAmount = SolutionPartsAmount;
        }
        return;
    }
    for (int SizeIterator = FieldSize - 1; SizeIterator > 0; SizeIterator--){
        if (!(IsFit(CoordOfEmptySpace, SizeIterator) && IsEmpty(CoordOfEmptySpace, SizeIterator))){
            continue;
        }
        int BackupSquareSize = 0;
        for(int i = 0; i < RequiredSquares.size(); i++){
            if(SizeIterator == RequiredSquares[i]){
                BackupSquareSize = SizeIterator;
                RequiredSquares.erase(RequiredSquares.begin() + i);
                break;
            }
        }
        AddSquare(CoordOfEmptySpace, SizeIterator);
        Recursion();
        if(BackupSquareSize){
            RequiredSquares.push_back(BackupSquareSize);
        }
        RemoveSquare(CoordOfEmptySpace, SizeIterator);
    }
}

void Table::Fill(){ 
    if (!RequiredSquares.size()){
        Optimization();
    }
    Recursion();
    ClearField();
}

bool Table::IsEmpty(Coordinate &coord, int size){
    for (int i = coord.y; i < coord.y + size; i++){
        for(int j = coord.x; j < coord.x + size; j++){
            if (Field[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}

bool Table::IsFit(Coordinate &coord, int size){
    if ((coord.x + size > FieldSize) || (coord.y + size > FieldSize)){
        return false;
    }
    return true;
}

void Table::AddSquare(Coordinate &coord, int size){
    if(IsEmpty(coord, size)){
        SolutionPartsAmount++;
        Solution.push_back(Part(coord.x, coord.y, size));
        for (int i = coord.y; i < coord.y + size; i++){
            for(int j = coord.x; j < coord.x + size; j++){
                Field[i][j] = SolutionPartsAmount;
            }
        }
    }
}

void Table::RemoveSquare(Coordinate &coord, int size){
    for (int i = coord.y; i < coord.y + size; i++){
        for (int j = coord.x; j < coord.x + size; j++){
            Field[i][j] = 0;
        }
    }
    Solution.pop_back();
    SolutionPartsAmount--;
}

void Table::ClearField(){
    for(int i = 0; i < FieldSize; i++){
        Field[i].resize(0);
        Field[i].resize(FieldSize);
    }
    SolutionPartsAmount = 0;
    Solution.clear();
}

void Table::DisplayResult(){
    if (!BestSolution.size()){
        std::cout << "Can't create table with this parts\n";
        return;
    }
    std::cout << BestSolutionPartsAmount << '\n';
    for(auto &Part: BestSolution){
        std::cout << Part.coord.x + 1 << ' ' << Part.coord.y + 1 << ' ' << Part.size << '\n';
        AddSquare(Part.coord, Part.size);
    }
    for(int i = 0; i < FieldSize; i++){
        for(int j = 0; j < FieldSize; j++){
            std::cout << (char)('A' + Field[i][j] - 1) << ' ';
        }
        std::cout << '\n';
    }
}
