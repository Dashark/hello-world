package one;

import java.util.*;

public class Account
{

    private int id;
    private double banlance;
    private double annuallnterestRate;
    private Date dateCreated= new Date();
    public Account()
    {
        id=0;
        banlance=0;
        annuallnterestRate=0;
    }
    public Account(int newid,double newbanlance,double newannuallnterestRate)
    {
        id=newid;
        banlance=newbanlance;
        annuallnterestRate=newannuallnterestRate;
    }
    public void visit()
    {
        System.out.print("The id is " + id + ",the banlance is " + banlance + ",the annuallnterestRate is " + annuallnterestRate + ",");

    }
    public void change()
    {
        Scanner input=new Scanner(System.in);
        id=input.nextInt();
        banlance=input.nextDouble();
        annuallnterestRate=input.nextDouble();
    }
    public void visitdataCreated()
    {
        System.out.println(dateCreated.toString());
    }
    public void getMonthlyInterestRate()
    {
        System.out.println("the MonthlyInterestRate is "+(annuallnterestRate/12.0)+".");
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
