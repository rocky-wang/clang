/*
 *@Author	:Rocky
 *@Date		:2015-1-12
 *@Descr	:Run-Length-Decode
*/
#include <stdio.h>
#include <stdlib.h>

void *rlc_decode(void *data,int *num)
{
	unsigned char *cpdata = (unsigned char *)data;
	int cp_len = *num;
	int de_len;
	unsigned char *endata;
	unsigned char raw_data;
	int i,j,res;

	if(data == NULL){
		fprintf(stderr,"input data is empty...\n");
		return NULL;
	}
	if( cp_len % 2 ){
		fprintf(stderr,"input data num is odd.\n");
		return NULL;
	}

	de_len = 0;
	for(i = 1; i < cp_len; i+=2){
		de_len += cpdata[i];
	}
	printf("the decode len is %d\n",de_len);

	endata = (unsigned char *)malloc(de_len);
	if(endata == NULL){
		fprintf(stderr,"malloc encode data error!\n");
		return NULL;
	}
	*num = de_len;
	res = 0;
	for(i = 1; i < cp_len; i+=2){
		raw_data = cpdata[i-1];
		for(j = 0; j < cpdata[i]; j++){
			endata[res++] = raw_data;
		}
	}

	return endata;
}

int main()
{
	unsigned char encode_data[] = {0x11,0x3,0x22,0x2,0x33,0x5};
	int num = sizeof(encode_data)/sizeof(encode_data[0]);
	unsigned char *decode_data;
	int i;

	decode_data = rlc_decode(encode_data,&num);
	printf("the decode data is :\n");
	for(i = 0; i < num; i++){
		printf("0x%x ",decode_data[i]);
	}
	printf("\n");
	
	return 0;
}

