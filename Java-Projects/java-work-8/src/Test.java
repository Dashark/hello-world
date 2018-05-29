import java.util.*;
public class Test
{
    public static void main(String[] args)
    {
        Scanner input=new Scanner(System.in);
        System.out.print("请分别输入一个复数的实部和虚部：");
        Complex one=new Complex(input.nextDouble(),input.nextDouble());
        System.out.print("请分别输入另一个复数的实部和虚部:");
        Complex another=new Complex(input.nextDouble(),input.nextDouble());
        System.out.println("二者之和为："+one.add(another).toString());
        System.out.println("二者之差为："+one.substract(another).toString());
        System.out.println("二者之积为："+one.multiply(another).toString());
        System.out.println("二者之商为："+one.divide(another).toString());
    }
}
