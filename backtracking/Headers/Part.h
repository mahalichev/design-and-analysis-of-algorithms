#ifndef PART_H
#define PART_H

#include "Coordinate.h"

class Part{
    public:
        Part(int x_, int y_, int size_);
        Coordinate coord;
        int size;
};

#endif