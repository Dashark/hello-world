import java.util.ArrayList;

public class Transation extends Account
{
    String name;
    Transation(String newname,int newid,double newbalance,double newannuallnterestRate)
    {
        super(newid,newbalance,newannuallnterestRate);
        name=newname;
    }
    ArrayList<Transation>transations=new ArrayList<>();
    public void withDraw(double money)
    {
        transations.add(new Transation(name,id,(banlance-money),annuallnterestRate));
    }
    public void deposit(double money)
    {
        transations.add(new Transation(name,id,(banlance+money),annuallnterestRate));
    }
    public void visit()
    {
        System.out.print("The name is "+ name +",the id is " + id + ",the banlance is " + banlance + ",the annuallnterestRate is " + annuallnterestRate + ",the data is " + dateCreated.toString() + ".");
    }
}
