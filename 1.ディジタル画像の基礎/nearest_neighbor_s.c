/* �ŋߖT�@�i�摜�T�C�Y�ϊ��j�v���O���� nearest_neighbor_s.c */
#include<stdio.h>
#include<stdlib.h>
#include"mypgm_s.h"

void nearest_neighbor( )
/* ���摜 image1 ���g�債�� image2 �ɑ������ */
{
	int x, y;    /* ����ϐ� */
	int x1, y1;    /* ����ϐ� */
	double ratio;
	printf("�g��摜���쐬���܂��D\n");
	printf("�g�傷��{������͂��ĉ������B\nratio = ");
	scanf_s("%lf", &ratio);
	x_size2 = (int)(ratio * x_size1);  /* ����f�� */
	y_size2 = (int)(ratio * y_size1);  /* �c��f�� */
	if (x_size2 > MAX_IMAGESIZE || y_size2 > MAX_IMAGESIZE) {
		printf("�z��l %d x %d �𒴂��Ă��܂��D\n",
			MAX_IMAGESIZE, MAX_IMAGESIZE);
		printf("�������������ȉ摜���g���ĉ������D\n");
		exit(1);
	}

	for (y = 0; y < y_size2; y++) {
		for (x = 0; x < x_size2; x++) {
			x1 = (int)(1.0/ratio * x + 0.5);
			y1 = (int)(1.0/ratio * y + 0.5);
			image2[y][x] = image1[y1][x1];
		}
	}
}
void main( )
{
	load_image_data( );    /* �摜�f�[�^�� image1 �ɓǂݍ��� */
	nearest_neighbor( );    /* �ŋߖT�@ */
	save_image_data( );    /* image2 ��ۑ����� */
}
