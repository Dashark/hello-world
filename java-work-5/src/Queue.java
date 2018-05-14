public class Queue {
    int size=0;
    int [] element;
    int maxsize;
    Queue(int newsize) {
        maxsize = newsize;
        element = new int[maxsize];
    }
    Queue()
    {
        this(8);
    }
    public void enqueue(int v)
    {
        if(size<maxsize)
        {
            for(int i=size-1;i>=0;i--)
                element[i+1]=element[i];
            element[0]=v;
            size++;
        }
     }
    public void dequeue(int v)
    {
        for(int i=0;i<maxsize;i++)
        {
            if(v==element[i])
            {
                int j=i;
                for(;j>0;j--)
                {
                    element[j]=element[j-1];
                }
                element[j]=0;
                size--;
            }
        }
    }
    public boolean empty()
    {
        if(size==0)
            return true;
        else
            return false;
    }
    public int getSize()
    {
        return size;
    }
}
