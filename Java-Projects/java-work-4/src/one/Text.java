package one;

public class Text
{
    public static void main(String[] args)
    {
        Account SYX=new Account(1122,20000,0.045);
        SYX.withDraw(2500);
        SYX.deposit(3000);
        SYX.visit();
        SYX.getMonthlyInterestRate();
        SYX.visitdataCreated();
    }

}
