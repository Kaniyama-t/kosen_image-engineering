/* copyimage_s.c  ���̃v���O�����̖��O */
#include<stdio.h>
#include<stdlib.h>
#include"mypgm_s.h"

void copy_image( )
/* image1 �̃f�[�^�����̂܂� image2 �� */
{
    int x, y;    /* ����ϐ� */

    x_size2 = x_size1;  /* ����f�� */
    y_size2 = y_size1;  /* �c��f�� */
    for ( y = 0; y < y_size2; y ++ ){
        for ( x = 0; x < x_size2; x ++ ){
            image2[y][x] = image1[y][x] ;
        }
    }
}

void main(void)
{
    load_image_data( );	/* �摜�f�[�^�� image1 �ɓǂݍ��� */
    copy_image( ); 		/* image1 �̃f�[�^�����̂܂� image2 �� */
    save_image_data( );	/* image2 ��ۑ����� */
}
