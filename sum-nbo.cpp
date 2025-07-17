#include <stddef.h> 
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

int read_file(char* filename, uint32_t *buf, int size){
	FILE* fp;
	int read_len = 0;
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		printf("file open error(1)\n");
		return -1;
	}
	read_len = fread(buf, sizeof(uint32_t), size, fp);
	if (read_len<=0) {
		printf("file open error(2)\n");
		return -1;
	}
	fclose(fp);
	return 0;
}

int calc_files(int size, uint32_t *cal_buf){
	int calc = 0;
	for(int i=1; i<size; i++){
		calc += (int)cal_buf[i];
	}
	return calc;
}

int main(int argc, char** argv) {

	uint32_t read_data_set[argc];

	for(int i=1; i<argc; i++){
		uint32_t read_data;
		read_file(argv[i], &read_data, 1);
		read_data_set[i] = htonl(read_data);
		printf("%d(%08x) ",(int)read_data_set[i],read_data_set[i]);
		if(i!=0&&i!=argc-1)
			printf("+ ");

	}

	printf("= %d(%08x)\n",calc_files(argc,read_data_set),(uint32_t)calc_files(argc,read_data_set));	

	
	return 0;

}
