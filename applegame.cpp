#include <iostream>

using namespace std;

int main() 
{  
    int s[10][17];
	int i,j;
    
	for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 17; j++)
        {
            s[i][j] = (rand() % 9) + 1;
        }
    }
	
	
	cout<<"Printing a 2D Array:\n";
	for (i = 0; i < 10; i++)
	{
		for(j = 0; j < 17; j++)
		{
			cout<<"\t"<< s[i][j];
		}
		cout<<endl;
	}
}

/*
class Grid {
    public:
        Grid(const unsigned w = 8, const unsigned h = 8) : _w(w), _h(h) {
        grid.resize(w * h);

    }

    private:
        QVector<> grid;
        unsigned _w, _h;
}; 
*/