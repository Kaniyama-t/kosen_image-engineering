/* add_image.c  ���̃v���O�����̖��O */
#include<stdio.h>
#include<stdlib.h>
#include"mypgm_s.h"

void add_image( )
/* image1 �̃f�[�^�ɉ�f�l�ɔC�ӂ̒l�����Z���� image2 �� */
{
    int x, y, a ,wk;    /* ����ϐ� */

    printf("��f�l�ɔC�ӂ̒l�����Z���܂��D\n");
    printf("���Z����l=");
    scanf_s("%d",&a);
    x_size2 = x_size1;  /* ����f�� */
    y_size2 = y_size1;  /* �c��f�� */
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
    load_image_data( );/* �摜�f�[�^�� image1 �ɓǂݍ��� */
    add_image( );      /* ��f�l�ɔC�ӂ̒l�����Z */
    save_image_data( );/* image2 ��ۑ����� */
}
