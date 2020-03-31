#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



long int recursiveFibonacci(long int n);
unsigned long * fibonacci_array(unsigned int n);
void * make_copy_of_array(void * src_array, unsigned long int array_size);
void swap(unsigned long *x, unsigned long *y);
unsigned long * reverse(unsigned long * array, unsigned long i, unsigned long j);
void bubble_sort(unsigned long * array, unsigned long array_dimension);


int main(int argc, char **argv) {

    long int n = 0;
    long int result = 0;

    //------------------Esercizio A------------------
    if(0){
      printf("Inserire un valore intero per Fibonacci: ");
      scanf("%ld", &n);
      result = recursiveFibonacci(n);
      printf("Fibonacci di (%ld) e' pari a: %ld", n, result);
    }
    //------------------Esercizio B------------------
     if(0){
     long int num = 6;
     unsigned long  *fibonacci_result ;
      fibonacci_result = calloc(num,sizeof(long));

      for(int i=0;i<=num;i++){
        fibonacci_result[i]=recursiveFibonacci(i);
        printf("%ld ",fibonacci_result[i]);
      }
     }
    //------------------Esercizio C------------------
    if(1){
      unsigned long  *fibonacci_result ;
      unsigned long  *fibonacci_result_copy ;
      long int num = 39;
      long result = 0;

      fibonacci_result = calloc(num,sizeof(long));
      fibonacci_result_copy = make_copy_of_array(fibonacci_result,num);
        if (fibonacci_result_copy == NULL) {
		      perror("ERROR in make_copy_of_array() ");
          exit(EXIT_FAILURE);
        }
      bubble_sort(fibonacci_result_copy , num);

      result = memcmp(fibonacci_result, fibonacci_result_copy,num*sizeof(long));
      if(result==0){
        printf("Gli array sono UGUALI!");
      }else{
        printf("Gli array sono DIVERSI!");
      }

    }

    return EXIT_SUCCESS;
}

//----------------------Funzioni-------------------------------//
//--------------Fibonacci
long int recursiveFibonacci(long int n) {
    long int result;
    if (n < 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
    }
}
//--------------Fibo Array
unsigned long * fibonacci_array(unsigned int n){
    unsigned long  *array ;
    array = malloc(n* sizeof(long));
    for(int i=0;i<n;i++){
      array[i]=recursiveFibonacci(i);
    }
    return array;
}
//-------------- Array copy
void * make_copy_of_array(void * src_array, unsigned long array_size) {
	if (src_array == NULL)
		return NULL;
	void * result;
	result = malloc(array_size*sizeof(long));
	memcpy(result, src_array, array_size);
	return result;
}
//--------------Swap
void swap(unsigned long *x, unsigned long *y) {
	unsigned long t = *x;
	*x = *y;
	*y = t;
}
//-------------- Reverse
unsigned long * reverse(unsigned long * array, unsigned long i, unsigned long j)
{
	while (i < j)
		swap(&array[i++], &array[--j]);
	return array;
}
//--------------Bubble Sort
void bubble_sort(unsigned long * array, unsigned long array_dimension) {
	int n, newn;
	n = array_dimension;
	while (n > 1) {
		newn = 0;
		for (int i = 1; i < n; i++) {
			if (array[i-1] > array[i]) {
				swap(&array[i-1], &array[i]);
				newn = i;
			}
		}
		n = newn;
	}
}
