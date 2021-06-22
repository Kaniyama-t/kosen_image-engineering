/* 最近傍法（画像サイズ変換）プログラム nearest_neighbor_s.c */
#include<stdio.h>
#include<stdlib.h>
#include"mypgm_s.h"

void nearest_neighbor( )
/* 原画像 image1 を拡大して image2 に代入する */
{
	int x, y;    /* 制御変数 */
	int x1, y1;    /* 制御変数 */
	double ratio;
	printf("拡大画像を作成します．\n");
	printf("拡大する倍率を入力して下さい。\nratio = ");
	scanf_s("%lf", &ratio);
	x_size2 = (int)(ratio * x_size1);  /* 横画素数 */
	y_size2 = (int)(ratio * y_size1);  /* 縦画素数 */
	if (x_size2 > MAX_IMAGESIZE || y_size2 > MAX_IMAGESIZE) {
		printf("想定値 %d x %d を超えています．\n",
			MAX_IMAGESIZE, MAX_IMAGESIZE);
		printf("もう少し小さな画像を使って下さい．\n");
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
	load_image_data( );    /* 画像データを image1 に読み込む */
	nearest_neighbor( );    /* 最近傍法 */
	save_image_data( );    /* image2 を保存する */
}
