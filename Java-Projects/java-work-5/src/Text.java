public class Text
{
    public static void main(String[] args) {

        Queue newqueue =new Queue(20);
        for(int i=0;i<20;i++)
            newqueue.enqueue((i+1));
        for(int i=newqueue.size-1;i>=0;i--)
            System.out.print(newqueue.element[i]+" ");
        System.out.println("\n");
        for(int i=0;i<20;i++)
            newqueue.dequeue((i+1));
        for(int i=newqueue.maxsize-1;i>=0;i--)
            System.out.print(newqueue.element[i]+" ");
    }

}
