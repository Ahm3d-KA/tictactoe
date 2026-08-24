#include <ostream>
#pragma once
class Tile
{
  public:
    enum class State
    {
        empty,
        nought,
        cross,
    };

  private:
    State mState{};

  public:
    Tile() = default;
    void setToNought() { mState = State::nought; };
    void setToCross() { mState = State::cross; };
    State getState() { return mState; }
    void setState(State state) { mState = state; }
    friend std::ostream& operator<<(std::ostream& out, const Tile& tile);
};
