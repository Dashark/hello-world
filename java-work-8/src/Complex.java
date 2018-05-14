import java.lang.*;
public class Complex
{
    double a,b;
    Complex()
    {
        a=0;
        b=0;
    }
    Complex(double newa)
    {
        a=newa;
        b=0;
    }
    Complex(double newa,double newb)
    {
        a=newa;
        b=newb;
    }
    public double getRealPart()
    {
        return a;
    }
    public double getImaginaryPart()
    {
        return b;
    }
    public Complex add(Complex another)
    {
        Complex add=new Complex((a+another.a),(b+another.b));
        return add;
    }
    public Complex substract(Complex another)
    {
        Complex substract=new Complex((a-another.a),(b-another.b));
        return substract;
    }
    public Complex multiply(Complex another)
    {
        Complex multiply=new Complex((a*another.a-b*another.b),(a*another.b+another.a*b));
        return multiply;
    }
    public Complex divide(Complex another)
    {
        Complex divide=new Complex(((a*another.a+b*another.b)/(another.a*another.a+another.b*another.b)),((another.a*b-a*another.b)/(another.a*another.a+another.b*another.b)));
        return divide;
    }
    @Override
    public String toString()
    {
        if(b==0)
            return String.valueOf(a) ;
        else
            return String.valueOf(a+"+"+b+"i");
    }
    @Override
    public Object clone() throws CloneNotSupportedException
    {
        return super.clone();
    }
}



