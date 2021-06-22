/* copyimage_s.c  このプログラムの名前 */
#include<stdio.h>
#include<stdlib.h>
#include"mypgm_s.h"

void copy_image( )
/* image1 のデータをそのまま image2 へ */
{
    int x, y;    /* 制御変数 */

    x_size2 = x_size1;  /* 横画素数 */
    y_size2 = y_size1;  /* 縦画素数 */
    for ( y = 0; y < y_size2; y ++ ){
        for ( x = 0; x < x_size2; x ++ ){
            image2[y][x] = image1[y][x] ;
        }
    }
}

void main(void)
{
    load_image_data( );	/* 画像データを image1 に読み込む */
    copy_image( ); 		/* image1 のデータをそのまま image2 へ */
    save_image_data( );	/* image2 を保存する */
}
