#include<stdio.h>
#include<stdlib.h>

int min(int x, int y) {
	return x < y ? x : y;
}

int max(int x, int y) {
	return x > y ? x : y;
}

void convolution(int* input1, int* input2, int* output, int mm, int nn)
{
	//�洢��ַ
	int* xx = (int*)malloc(sizeof(int) * (mm + nn - 1));
	//��ʼ���
	for (int i = 0; i < mm + nn - 1; i++)
	{
		xx[i] = 0;
		//��λ�����ٵľ����Ϊ�������
		for (int j = 0; j < min(mm,nn) ; j++) {
			//��һ������ȵڶ�����������ִ��
			if (mm <= nn) {
				if (i - j >= 0 && i - j < max(mm, nn)) {
					printf("%d ", input1[j]);
					printf("%d ", input2[i-j]);
					xx[i] += input1[j] * input2[i - j];
				}
			}
			//��һ������ȵڶ����������ִ��
			else {
				if (i - j >= 0 && i - j < max(mm, nn)) {
					printf("%d ", input1[i-j]);
					printf("%d ", input2[j]);
					xx[i] += input2[j] * input1[i - j];
				}
			}
			printf("\n");
		}
	}
	printf("\n");
	for (int i = 0; i < mm+nn-1; i++) {
		output[i] = xx[i];
	}
	delete[] xx;
}

int main() {
	int mm, nn;
	printf("�������һ�������Ŀ\n");
	scanf_s("%d", &mm);

	//malloc����ռ�
	int* input1 = (int*)malloc(sizeof(int) * mm);
	printf("�������һ�������ֵ\n");
	for (int i = 0; i < mm; i++) {
		scanf_s("%d", &input1[i]);
	}
	printf("������ڶ��������Ŀ\n");
	scanf_s("%d", &nn);
	int* input2 = (int*)malloc(sizeof(int) * nn);
	printf("������ڶ��������ֵ\n");
	for (int j = 0; j < nn; j++) {
		scanf_s("%d", &input2[j]);
	}

	//������ռ�
	int* output = (int*)malloc(sizeof(int) * (mm+nn-1));
	convolution(input1, input2, output, mm, nn);

	printf("������\n");
	for (int i = 0; i < mm + nn - 1; i++)
	{
		printf("%d ", output[i]);
	}
	printf("\n");

	return 0;
}	

