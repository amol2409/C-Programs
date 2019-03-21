/*--------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*--------------------------------------------------------------------------------------*/

#define size 5

/*--------------------------------------------------------------------------------------*/

int nnz, nz; // nnz is no of non zero entry and nz is no of zero entry in matrix
int mat[size][size];
int nn[3];

void sparsity();
void initialization();
void display();
void write();

/*--------------------------------------------------------------------------------------*/

int main()
{
	int i;
	FILE *fp1;
	printf("\n");
	initialization();
	display();			// display matrix
	sparsity();	
	display(); 			// display Sparse matrix 
	write();			// write sparse matrix in file
	
	//printf("\nTotal no of entries in matrix:         %3d\n", (size*size) );
	//printf("Number of non-zero entries in matrix:  %3d\n", nnz);
	//printf("Number of zero entries in matrix:      %3d\n\n\n", nz);

	nn[0] = (size*size);
	nn[1] = nnz;
	nn[2] = nz;

	fp1 = fopen("nn.txt","w");
	for(i=0; i<3; i++)
	{
		fprintf(fp1,"%12d",nn[i]);
	}

	fclose(fp1);
	return 0;
}

/*--------------------------------------------------------------------------------------*/

void initialization()
{
	int i, j, x;	
	
	srand(time(0)); // seed for rand function

	for(i=0; i<size ; i++)
	{
		for(j=0; j<size ; j++)	
		{
			x = rand() % 10 ;
			//x = 1;
			if(x == 0)
			{
				x++;
			}

			mat[i][j] = x;
		}
	}
}

/*--------------------------------------------------------------------------------------*/

void display()
{
	int i, j, x; 
	
	for(i=0; i<size ; i++)
	{
		for(j=0; j<size ; j++)	
		{
			printf("%3d\t",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*--------------------------------------------------------------------------------------*/

void sparsity()
{
	int N, i, j, X, Y;   // X and Y are the cordinate which will become zero	

	N = (size * size) / 2; // N is number if ZEROs entry in matrix
	
	srand(time(0));

	for(i=0; i<N; i++ )
	{ 
		X = rand() % size;
		Y = rand() % size;
		mat[X][Y] = 0;			// set value zero
	}

	// counting no of non zero and zero entries in matrix
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
			if( mat[i][j] == 0)
			{
				nz++;
			}
		}
	}
	
	nnz = (size * size) - nz;
}

/*--------------------------------------------------------------------------------------*/

void write()
{
	int i, j;
	/*char C[] = "matrix_order .txt";
	C[12] = '179';
	*/
	FILE *fp;
	fp = fopen("matrix_order.txt", "w");
	
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
			fprintf(fp,"%3d",mat[i][j]);
		}
		fprintf(fp,"\n");
	}
	
	fclose(fp);

}

/*--------------------------------------------------------------------------------------*/
