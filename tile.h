#include <ostream>
#pragma once
class Tile
{
  private:
    enum class State
    {
        empty,
        nought,
        cross,
    };

  public:
    State state{};
    Tile() = default;
    void setToNought() { state = State::nought; };
    void setToCross() { state = State::cross; };
    friend std::ostream& operator<<(std::ostream& out, const Tile& tile);
};
