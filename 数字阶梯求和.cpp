    #include <stdio.h>  
    #include <stdlib.h>  
      
    int main()  
    {  
        int a, n, plus, i, temp, count;  
        int number[1000];  
      
        while(scanf("%d %d", &a, &n) != EOF)  
        {   
            for(i = 0, temp = 0, count = 0; i <= n; i ++)  
            {  
                number[i] = ((n - i) * a + temp) % 10;  
                temp = ((n - i) * a + temp) / 10;  
                if(number[i] == 0)  
                {  
                    count ++;  
                }  
            }  
              
            if(count == n + 1)  
            {  
                printf("0\n");  
            }else  
            {  
                for(i = n; i >=0; i --)  
                {  
                    if(i == n && number[i] == 0)  
                    {  
                        continue;  
                    }else  
                    {  
                        printf("%d",number[i]);  
                    }  
                }  
                printf("\n");  
            }  
        }  
      
        return 0;  
    }  
