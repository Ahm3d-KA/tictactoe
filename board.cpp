#include "board.h"

std::ostream& operator<<(std::ostream& out, const Board& board)
{
    for (const std::array<Tile, gGridSize>& row : board.mGrid)
    {
        for (const Tile& tile : row)
        {
            out << " " << tile;
        }
        out << "\n";
    }
    return out;
}
