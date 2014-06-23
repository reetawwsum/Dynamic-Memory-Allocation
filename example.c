#include <stdio.h>
#include <stdlib.h>

#define ESC 27 //It can be any number

int main(void){
	int bufferSize = 3;
	int *buffer, *temp;
	int currentInput = 1; //Make it anything expect 27
	int currentPosition = 0, i;
	buffer = (int *) malloc(bufferSize*sizeof(int));
	printf("Initial length of buffer is %d\n", bufferSize);
	while (currentInput != ESC){
		//Checking size of data inside buffer
		if (currentPosition > bufferSize-1){
			printf("Buffer finished!\n");
			bufferSize += 10;
			temp = (int *) realloc(buffer, bufferSize*sizeof(int));
			buffer = temp;
			printf("Buffer size increased!\n");
		}
		scanf("%d", &currentInput);
		buffer[currentPosition++] = currentInput;
	}
	printf("Length of buffer is %d\nElements in buffer :", bufferSize);
	for (i = 0; i < currentPosition; i++)
		printf("%d ", buffer[i]);
	return 0;
}