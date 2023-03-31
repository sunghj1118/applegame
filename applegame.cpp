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
                    // Compares with the values on the right
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

                    // Compares with values below
                    int down = i + 1;
                    sum = current;
                    while (down < m_length) {
                        int next = (*this)(down, j);
                        if (sum + next < 10) {
                            sum += next;
                            down++;
                        } else if (sum + next == 10) {
                            counter += down - i;
                            for (int k = i; k < down; ++k) {
                                (*this)(k, j) = 0;
                            }
                            break;
                        } else {
                            break;
                        }                    
                    }
                }
            }
        }

        int score() {
            // This function solves the grid and outputs the score.
            int counter = 0;
            for (int i = 0; i < m_length; ++i) {
                for (int j = 0; j < m_width; ++j) {
                    int current = (*this)(i, j);
                    if (current == 0) {
                        counter++;
                    }
                    else{
                        continue;
                    }
                }
            }
            return counter;
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
    int current_score, new_score, runs = 0;
    Grid grid(10, 17);
    grid.fillRandom();
    grid.printGrid();
    grid.solve();
    current_score << grid.score();
    cout << "Run " << 1 << ": " << current_score << endl;
    cout << "\n--------\n" << endl;
    runs = 2;

    do{
        grid.solve();
        current_score = new_score;
        new_score = grid.score();
        cout << "Run " << runs << ": " << new_score << endl;
        cout << "\n--------\n" << endl;
        runs++;
    } while (current_score != new_score);
    
    grid.printGrid();
    return 0;
}