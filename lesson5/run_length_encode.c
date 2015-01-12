/*
 *@Author	:Rocky
 *@Date		:2015-1-12
 *@Descr	:Run-Length-Coding,Compression Data Way.
*/
#include <stdio.h>
#include <stdlib.h>
/*
 *@Fun		:Run-Length-Coding Process
 *=======================================
 *rdata	------	the point to raw data
 *cdata	------	the point to encoded data
 *num	------	the raw data len and encoded data len
 *count ------	the count of encoding
*/
void *rlc_encode(void *data,int *num)
{
	unsigned char *rdata = (unsigned char *)data;
	unsigned char *cdata;
	int raw_len = *num;
	int count = 1;
	int res_len = 0;
	unsigned char tmpdata;
	int i;
	if(data == NULL)
		return NULL;

	tmpdata = rdata[0];
	for(i = 1; i < raw_len; i++){
		if(tmpdata != rdata[i]){
			count++;
			tmpdata = rdata[i];
		}
	}
	printf("the differnet num is %d\n",count);
	cdata = (unsigned char *)malloc(count*2);
	if(cdata == NULL){
		fprintf(stderr,"malloc space error!\n");
		return NULL;
	}
	
	*num = count*2;
	res_len = 0;
	cdata[res_len++] = rdata[0];
	tmpdata = rdata[0];
	count = 1;
	for(i = 1; i < raw_len; i++){
		if(tmpdata != rdata[i]){
			cdata[res_len++] = count;
			cdata[res_len++] = rdata[i];
			tmpdata = rdata[i];
			count = 1;
			continue;
		}
		count++;
	}
	cdata[res_len] = count;

	return cdata;
}

int main(int argc,char *argv[])
{
	unsigned char raw_data[] = {0x11,0x11,0x11,0x22,0x22,0x33,0x33,0x33,0x33,0x33};
	unsigned char *coded_data;
	int num,i;

	num = sizeof(raw_data)/sizeof(raw_data[0]);
	coded_data = rlc_encode(raw_data,&num);

	printf("the encode result is :\n");
	for(i = 0; i < num; i++){
		printf("0x%x ",coded_data[i]);
	}
	printf("\n");

	free(coded_data);	

	return 0;
}
