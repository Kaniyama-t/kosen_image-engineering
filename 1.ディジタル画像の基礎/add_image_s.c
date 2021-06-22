/* add_image.c  このプログラムの名前 */
#include<stdio.h>
#include<stdlib.h>
#include"mypgm_s.h"

void add_image( )
/* image1 のデータに画素値に任意の値を加算して image2 へ */
{
    int x, y, a ,wk;    /* 制御変数 */

    printf("画素値に任意の値を加算します．\n");
    printf("加算する値=");
    scanf_s("%d",&a);
    x_size2 = x_size1;  /* 横画素数 */
    y_size2 = y_size1;  /* 縦画素数 */
    for ( y = 0; y < y_size2; y ++ ){
        for ( x = 0; x < x_size2; x ++ ){
            wk = a + image1[y][x];
            if (wk > 255) wk = 255;
            if (wk <   0) wk = 0;
            image2[y][x] = (unsigned char)wk;
        }
    }
}

void main(void)
{
    load_image_data( );/* 画像データを image1 に読み込む */
    add_image( );      /* 画素値に任意の値を加算 */
    save_image_data( );/* image2 を保存する */
}
