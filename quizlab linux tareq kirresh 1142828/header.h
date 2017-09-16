

struct imaginary_t{

int i;
int r;

};

typedef struct imaginary_t imaginary;

imaginary addi(imaginary, imaginary);
imaginary subi(imaginary, imaginary);
imaginary muli(imaginary, imaginary);
imaginary create_imaginary(int, int);
void print_imaginary(imaginary);
