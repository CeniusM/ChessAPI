#pragma once

class Directions
{
public:
    const struct Index
    {
        static constexpr int North = 0;
        static constexpr int East = 2;
        static constexpr int South = 4;
        static constexpr int West = 6;
        static constexpr int NorthEast = 1;
        static constexpr int SouthEast = 3;
        static constexpr int SouthWest = 5;
        static constexpr int NorthWest = 7;
    };
    const struct Value
    {
        static constexpr int North = -8;
        static constexpr int East = 1;
        static constexpr int South = 8;
        static constexpr int West = -1;
        static constexpr int NorthEast = -7;
        static constexpr int SouthEast = 9;
        static constexpr int SouthWest = 7;
        static constexpr int NorthWest = -9;
        static constexpr int Indexed[] = { North, East, South, West, NorthEast, SouthEast, SouthWest, NorthWest };
    };
    static int LenghtToSide[64][8];
    static void Init()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                int North = j;
                int East = 7 - i;
                int South = 7 - j;
                int West = i;
                int NorthEast = North < East ? North : East;
                int SouthEast = South < East ? South : East;
                int SouthWest = South < West ? South : West;
                int NothWest = North < West ? North : West;

                LenghtToSide[i + (j << 3)][0] = North;
                LenghtToSide[i + (j << 3)][1] = East;
                LenghtToSide[i + (j << 3)][2] = South;
                LenghtToSide[i + (j << 3)][3] = West;
                LenghtToSide[i + (j << 3)][4] = NorthEast;
                LenghtToSide[i + (j << 3)][5] = SouthEast;
                LenghtToSide[i + (j << 3)][6] = SouthWest;
                LenghtToSide[i + (j << 3)][7] = NothWest;
            }
        }
    }
};