#include <QVector>

class Grid {
    public:
        Grid(const unsigned w = 8, const unsigned h = 8) : _w(w), _h(h) {
        grid.resize(w * h);

    }

    private:
        QVector<> grid;
        unsigned _w, _h;
}; 