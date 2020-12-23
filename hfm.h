#ifndef HFM_H
#define HFM_H
#include<stdio.h>
#include<stdlib.h>
#define maxvalue 10000
#define maxleaf 30
#define maxnode 59
#define maxbit 10
typedef struct
{
	char data;
	int weight, flag;
	int parent, lchild, rchild;
}hnodetype;
typedef struct
{
	int bit[maxbit];
	int start;
}hcodetype;
void InitHuffman(hnodetype HuffNode[], hcodetype HuffCode[], int n); /*哈夫曼树结点初始化*/
void OutputHuffman(hnodetype HuffNode[], hcodetype HuffCode[], int n); /*输出哈夫曼编码*/
void Huffman(hnodetype HuffNode[], hcodetype HuffCode[], int n) ;/*构造哈夫曼树，生成哈夫曼编码*/



#endif
