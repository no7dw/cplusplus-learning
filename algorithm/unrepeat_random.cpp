#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int aTest[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int nPos, nTemp;

    srand((unsigned)time(NULL));

    for(int nCount = 0; nCount < 10; nCount ++)
    {
        nPos = rand()%10;
        nTemp = aTest[nPos];
        aTest[nPos] = aTest[nCount];
        aTest[nCount] = nTemp;

        cout << aTest[nCount]<< endl;
    }
    return 0;
}  //基于交换位置,所以不可能重复
