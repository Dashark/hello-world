//��һԪ���η��̵ĸ�
// ���� ��y = x2 + 10x + 17
// �� x = 2, �� y = 41
// �� y = 2, �� x = ? 
/*#include <stdio.h>
#include <math.h>
int main() {
  float x1, x2;
  float y, a, b, c;
  printf("������ϵ����\n");
  scanf("%f, %f, %f, %f", &y, &a, &b, &c);
  c =  c - y;
  a = 2 * a;
  float temp = sqrt(b*b - 4* a*c);
  x1 = (-b + temp)/(a);
  x2 = (-b - temp)/(a);
  printf("һԪ���η��̸���\n");
  printf("%f\n", x1);  //������ʲô�� 
  printf("%f\n", x2);
  return 0;
}*/ 
//��13���н�a����Ϊ2������˵�14���е�4*a*c��Ϊ8*a*c����ʽ�������Գ�Ϊ��bug�� 


 //��һԪ���η��̵ĸ�
// ���� ��y = x2 + 10x + 17
// �� x = 2, �� y = 41
// �� y = 2, �� x = ? 
#include <stdio.h>
#include <math.h>
int main() {
  float x1, x2;
  float y, a, b, c;
  printf("������ϵ����\n");
  scanf("%f, %f, %f, %f", &y, &a, &b, &c);
  c =  c - y;
  float temp = sqrt(b*b - 4* a*c);
  a = 2 * a;
  x1 = (-b + temp)/(a);
  x2 = (-b - temp)/(a);
  printf("һԪ���η��̸���\n");
  printf("%f\n", x1);  //������ʲô�� 
  printf("%f\n", x2);
  return 0;
} //��˳������󼴿� 
