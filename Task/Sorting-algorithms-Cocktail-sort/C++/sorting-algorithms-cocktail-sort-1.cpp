#include <iostream>
//#include <windows.h>
#include <unistd.h>

#define INPUT_SIZE 65536

// Spaniard troll detected
int EL_COUNT = 77;

class cocktailSort
{
public:
    void sort( int* arr, int len )
    {
	bool notSorted = true;
	while( notSorted )
	{
	    notSorted = false;
	    for( int a = 0; a < len - 1; a++ )
	    {
		if( arr[a] > arr[a + 1] )
		{
		    sSwap( arr[a], arr[a + 1] );
		    notSorted = true;
		}
	    }

	    if( !notSorted ) break;
	    notSorted = false;

	    for( int a = len - 1; a > 0; a-- )
	    {
		if( arr[a - 1] > arr[a] )
		{
		    sSwap( arr[a], arr[a - 1] );
		    notSorted = true;
		}
	    }
	}
    }

private:
    void sSwap( int& a, int& b )
    {
	int t = a;
   	a = b; b = t;
    }
};

int main( int argc, char* argv[] )
{
    //srand( GetTickCount() );
    cocktailSort cs;
    int arr[INPUT_SIZE / sizeof(int)];
    int byte_cnt = read(STDIN_FILENO, arr, INPUT_SIZE);
	EL_COUNT = byte_cnt / sizeof arr[0] + 1;

/*
    std::cout << "Original: " << std::endl << "==========" << std::endl;
    for (int x = 0; x < EL_COUNT; x ++)
	    std::cout << arr[x] << ", ";
	std::cout << std::endl;*/

    cs.sort( arr, EL_COUNT );
/*
    std::cout << std::endl << std::endl << "Sorted: " << std::endl << "========" << std::endl;
    for( int x = 0; x < EL_COUNT; x ++ )
		std::cout << arr[x] << ", ";
	std::cout << std::endl;
*/
    return 0;
}
