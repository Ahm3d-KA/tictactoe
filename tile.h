#include <ostream>
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
    State state{};
    Tile() = default;
    void setToNought() { state = State::nought; };
    void setToCross() { state = State::cross; };
    friend std::ostream& operator<<(std::ostream& out, const Tile& tile);
};
