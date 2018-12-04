struct BitArray{
	unsigned char* array;
	unsigned int size;
};
typedef struct BitArray* Array;

Array createBitArray(int);
int set(Array, int, int);
int get(Array, int);
