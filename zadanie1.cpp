#include <include>
using namespace std;
int Mysqrt(int x)
{
    int y;
    for (int i = 2; i < x; i++)
    {
        if (i * i <= x)
            y = i;
        else
            break;
    }
    return y;
}
