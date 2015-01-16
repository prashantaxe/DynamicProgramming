

#include <cstring>
#include <cassert>

void compute_even_equal_substr(char* array)
{
	assert(array);
	assert(array);

	size_t size = strlen(array);
	
	/*
	Compute the sum of all sub-strings and store them in a 2-D matrix, diagonally.
	*/

	int* matrix = new int[size*size]; //Row Major Matrix

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i*size + j] = -100;
		}
	}

	for (int i = 0; i < size; i++)
	{
		matrix[i*size + i] = array[i] - '0';
	}
	
	/*
	Filling the upper half matrix
	*/
	int max_len = 0;
	for (int len = 2; len <= size; len++)
	{
		for (int i = 0; i < size-len+1; i++)
		{
			int j = i + len - 1;
			int k = len / 2;
	
			//    sum from i-j         sum from i to j-k        sum from j-k+1 to j
			matrix[(i)*size + j] = matrix[(i)*size + j - k] + matrix[(j-k+1)*size + j];
			std::cout << i  << " "<<j << "\n";
			if (matrix[(i )*size + j] < 0)
			{
				std::cout << "failed\n";
			}
			//check.
			if (len % 2 == 0 && matrix[i*size+j-k] == matrix[(j-k+1)*size+j])
			{
				if (max_len < len)
					max_len = len;
			}
		}

		
	}

	std::cout << max_len << "\n";

}

int main(int argc, _TCHAR* argv[])
{
	char* a = "12312346";
	compute_even_equal_substr(a);
}