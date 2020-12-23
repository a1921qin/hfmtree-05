#include"hfm.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	hnodetype HuffNode[maxnode];
	hcodetype HuffCode[maxleaf];
	int n;
	printf("输入数据个数：");
	scanf("%d", &n);
	InitHuffman(HuffNode, HuffCode, n);  /*结点初始化*/
	Huffman(HuffNode, HuffCode, n);      /*构造哈夫曼树*/
	OutputHuffman(HuffNode, HuffCode, n);/*输出哈夫曼编码*/
	return 0;
}

