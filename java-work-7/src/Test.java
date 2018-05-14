public class Test
{
    public static void main(String[] args)
    {
        Transation testaccount=new Transation("George",1122,1000,0.015);
        testaccount.deposit(30);
        testaccount.deposit(40);
        testaccount.deposit(50);
        testaccount.withDraw(5);
        testaccount.withDraw(4);
        testaccount.withDraw(2);
        for(int i=0;i<6;i++)
        {
            testaccount.transations.get(i).visit();
            System.out.print("\n");
        }
    }
}
