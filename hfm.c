#include"hfm.h"
#include<stdio.h>
#include<stdlib.h>
#define maxvalue 10000
#define maxleaf 30
#define maxnode 59
#define maxbit 10
void InitHuffman(hnodetype HuffNode[], hcodetype HuffCode[], int n) /*哈夫曼树结点初始化*/
{
	if (n <= 1)return;
	int i;
	for (i = 0; i < 2 * n - 1; i++) /*将指向父亲、左右孩子的指针置空*/
	{
		HuffNode[i].weight = 0;
		HuffNode[i].parent = 0;
		HuffNode[i].flag = 0;
		HuffNode[i].lchild = -1;
		HuffNode[i].rchild = -1;
	}
	for (i = 0; i < n; i++)
	{
		getchar();
		printf("输入第%d个叶结点的值：", i + 1);
		scanf("%c", &HuffNode[i].data);
		printf("输入对应结点权值：");
		scanf("%d", &HuffNode[i].weight);
	}
}

void OutputHuffman(hnodetype HuffNode[], hcodetype HuffCode[], int n) /*输出哈夫曼编码*/
{
	int i, j;
	printf("%d个叶结点对应编码为：\n", n);
	for (i = 0; i < n; i++)
	{
		printf("%c的编码为：", HuffNode[i].data);
		for (j = HuffCode[i].start + 1; j < n; j++)
		{
			printf("%d", HuffCode[i].bit[j]);
		}
		printf("\n");
	}
}

void Huffman(hnodetype HuffNode[], hcodetype HuffCode[], int n) /*构造哈夫曼树，生成哈夫曼编码*/
{
	int i, j;
	int m1, m2, x1, x2, c, p;
	hcodetype cd;
	for (i = 0; i < n - 1; i++)
	{
		m1 = m2 = maxvalue;
		x1 = x2 = 0;
		for (j = 0; j < n + i; j++)
		{
			if (HuffNode[j].weight < m1&&HuffNode[j].flag == 0)
			{
				m2 = m1;
				x2 = x1;
				m1 = HuffNode[j].weight;
				x1 = j;
			}
			else
			{
				if (HuffNode[j].weight < m2&&HuffNode[j].flag == 0)
				{
					m2 = HuffNode[j].weight;
					x2 = j;
				}
			}
		}
		HuffNode[x1].parent = n + i;
		HuffNode[x2].parent = n + i;
		HuffNode[x1].flag = 1;
		HuffNode[x2].flag = 1;
		HuffNode[n + i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
		HuffNode[n + i].lchild = x1;
		HuffNode[n + i].rchild = x2;
	}
	for (i = 0; i < n; i++)   /*生成哈夫曼编码*/
	{
		cd.start = n - 1;
		c = i;
		p = HuffNode[c].parent;
		while (p!=0)
		{
			if (HuffNode[p].lchild == c)
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
			cd.start--;
			c = p;
			p = HuffNode[c].parent;
		}
		for (j = cd.start + 1; j < n; j++)
		{
			HuffCode[i].bit[j] = cd.bit[j];
			HuffCode[i].start = cd.start;
		}
	}
}
