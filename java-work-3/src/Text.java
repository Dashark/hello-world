import java.util.*;
public class Text {
    public static void main(String[] args) {
        System.out.println("请输入方阵的维度N");
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[][] matix = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                matix[i][j] = (int) Math.rint(Math.random());//产生0或1的随机数
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                System.out.print(matix[i][j]+" ");
            System.out.print("\n");
        }
        //输出全是0或1的行，如果没有，则输出“全是0或1的行有0行。”
        int count=0;
        System.out.print("全是1或0的行有");
        for(int i=0;i<N;i++)
        {
            int flag=1;
            for(int j=0;j<N-1;j++)
            {
                if(matix[i][j]!=matix[i][j+1])
                    flag=0;
            }
            if(flag==1)
            {
                System.out.print("第"+(i+1)+"行 ");
                count++;
            }
        }
        if(count==0)
            System.out.print("0行。");
        System.out.print("\n");
        //输出全是0或1的列，如果没有，则输出“全是0或1的列有0列。”
        count=0;
        System.out.print("全是1或0的列有");
        for(int j=0;j<N;j++)
        {
            int flag=1;
            for(int i=0;i<N-1;i++)
            {
                if(matix[i][j]!=matix[i+1][j])
                    flag=0;
            }
            if(flag==1)
            {
                System.out.print("第"+(j+1)+"列 ");
                count++;
            }
        }
        if(count==0)
            System.out.print("0列。");
        System.out.print("\n");
        //输出全是0或1的对角线是斜向右上还是斜向右下
        int flag1=0,flag2=0;
        for(int i=0;i<N-1;i++)//判断是否为斜向右上对角方阵
            if(matix[i][i]!=matix[i+1][i+1])
                flag1=1;
        for(int i=0;i<N-1;i++)//判断是否为斜向右下对角方阵
            if(matix[N-i-1][i]!=matix[N-i-2][i+1])
                flag2=1;
        if(flag1==0)
        {
            if(flag2==0)
                System.out.println("该方阵既是斜向右上对角方阵，也是斜向右下对角方阵。");
            else
                System.out.println("该方阵是斜向右下对角方阵。");
        }
        else
        {
            if(flag2==0)
                System.out.println("该方阵是斜向右上对角方阵。");
            else
                System.out.println("该方阵既不是斜向右上对角方阵，也不是斜向右下对角方阵。");

        }

    }
}


