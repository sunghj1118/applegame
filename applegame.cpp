#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Grid {
    public:
        Grid(int length, int width) : m_length(length), m_width(width), m_data(length * width) {}

        int getLength() const { return m_length; }
        int getWidth() const { return m_width; }

        int& operator()(int i, int j) { return m_data[i * m_width + j]; }
        const int& operator()(int i, int j) const { return m_data[i * m_width + j]; }

        void fillRandom() {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(1, 9);
            
            for (int i = 0; i < m_length; ++i) {
                for (int j = 0; j < m_width; ++j) {
                    (*this)(i, j) = dis(gen);
                }
            }
        }

        void solve() {
        // This function solves the grid and outputs the score.
            int counter = 0;
            for (int i = 0; i < m_length; ++i) {
                for (int j = 0; j < m_width; ++j) {
                    int current = (*this)(i, j);
                    if (current == 0) {
                        continue;
                    }
                    int right = j + 1;
                    int sum = current;
                    while (right < m_width) {
                        int next = (*this)(i, right);
                        if (sum + next < 10) {
                            sum += next;
                            right++;
                        } else if (sum + next == 10) {
                            counter += right - j;
                            for (int k = j; k <= right; ++k) {
                                (*this)(i, k) = 0;
                            }
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        void printGrid() const {
            for (int i = 0; i < m_length; ++i) {
                for (int j = 0; j < m_width; ++j) {
                    cout << (*this)(i, j) << " ";
                }
                cout << endl;
            }
        }
    
    
    private:
        int m_length;
        int m_width;
        vector<int> m_data;
};


int main() 
{  
    Grid grid(10, 17);
    grid.fillRandom();
    grid.printGrid();
    grid.solve();
    cout << "\nThis\n" << endl;
    grid.printGrid();
    return 0;
}