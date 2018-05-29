import java.util.*;
public class Account {
    int id;
    double banlance;
    public Account()
    {
        id=0;
        banlance=0;
    }
    public Account(int newid,double newbanlance)
    {
        id=newid;
        banlance=newbanlance;
    }
    public void visit()
    {
        System.out.println("The id is " + id + ",the banlance is " + banlance + ".");

    }
    public void change()
    {
        Scanner input=new Scanner(System.in);
        id=input.nextInt();
        banlance=input.nextDouble();
    }
    public void withDraw(double money)
    {
        banlance=banlance-money;
    }
    public void deposit(double money)
    {
        banlance=banlance+money;
    }
}

