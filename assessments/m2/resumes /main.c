#include <stdio.h>
#define SQUARE(X) (X*X)

void main(){
 	int y  = 9 ;	
	int result = 0 ;
	printf("hello universe %d ", SQUARE(y++)) ;

	printf("hello universe %d ",y) ;
}
