import java.util.*;
public class Text
{
    public static void main(String[] args)
    {
            Account[] textaccount = new Account[10];
            for (int i = 0; i < 10; i++)
                textaccount[i] = new Account((100 + i), 100);
            Scanner input = new Scanner(System.in);
            while(true) {
                System.out.print("Enter and id：");
                int id = input.nextInt();
                while (id < 100 || id > 109) {
                    System.out.print("Please enter id again: ");
                    id = input.nextInt();
                }
                menu(id, textaccount[id - 100]);
            }
    }
    public static void menu(int id,Account textaccount)
    {
        System.out.println("Main menu:");
        System.out.println("1:check balance");
        System.out.println("2:withdraw");
        System.out.println("3:deposit");
        System.out.println("4:exit");
        System.out.print("Enter a choice: ");
        Scanner input=new Scanner(System.in);
        int choice=input.nextInt();
        switch (choice)
        {
            case 1:textaccount.visit();menu(id, textaccount);
            case 2:{
                System.out.print("Enter the amount you want to withdraw: ");
                double money=input.nextDouble();
                textaccount.withDraw(money);
                textaccount.visit();
                menu(id, textaccount);
            }
            case 3:{
                System.out.print("Enter the amount you want to deposit: ");
                double money=input.nextDouble();
                textaccount.deposit(money);
                textaccount.visit();
                menu(id, textaccount);
            }
            default:break;
        }
    }
}
