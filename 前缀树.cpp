
#include <iostream>
#include <string>
using namespace std;
typedef struct character
{
    char ch;                    //字符
    bool flag;                  //判断是不是最后一个
    struct character *nextNode; //向右走（平级）
    struct character *goRight;  //向下走（走向子节点）
} character;

int insert(character *head, string s, int x)
{
    character *p = head;
    int length = s.length();
    if (p->ch == 0 && p->nextNode == NULL && p->goRight == NULL) //插入第一个
    {
        for (int j = x; j < length; j++) //向下移动
        {
            character *temp = new character;
            p->nextNode = temp;
            temp->goRight = NULL;
            temp->nextNode = NULL;
            temp->ch = s[j];
            if (j == length - 1) //最后一个
            {
                temp->flag = true;
            }
            else //不是最后一个
            {
                temp->flag = false;
            }
            p = p->nextNode;
        }
        return 0;
    }
    else if (p->ch == 0) //后面插入，但现在在head，要向下走
    {
        p = p->nextNode;
    }
    {
        if (x == length - 1) //最后一个字符
        {
            while (p->goRight != NULL)
            {
                if (p->ch == s[x]) //找到了
                {
                    p->flag = true;
                    return 0;
                }
                p = p->goRight;
            }
            if (p->goRight == NULL) //没找到，这个其实不需要
            {
                character *temp = new character;
                p->goRight = temp;
                temp->goRight = NULL;
                temp->nextNode = NULL;
                temp->ch = s[x];
                temp->flag = true;
                return 0;
            }
        }
        for (int i = x; i < length; i++)
        {
            while (p->goRight != NULL)
            {
                if (p->ch == s[i])
                {
                    return insert(p->nextNode, s, x + 1); //递归
                }
                p = p->goRight;
            }
            if (p->goRight == NULL) //没有找到（这个其实不需要，我只是好理解一点）
            {
                character *temp = new character; //先向右移位
                p->goRight = temp;
                temp->goRight = NULL;
                temp->nextNode = NULL;
                temp->ch = s[x];
                temp->flag = false; //不是最后一个，所以false
                p = p->goRight;
                for (int j = x + 1; j < length; j++) //再向下移动
                {
                    character *temp = new character;
                    p->nextNode = temp;
                    temp->goRight = NULL;
                    temp->nextNode = NULL;
                    temp->ch = s[j];
                    if (j == length - 1) //最后一个
                    {
                        temp->flag = true;
                    }
                    else //不是最后一个
                    {
                        temp->flag = false;
                    }
                    p = p->nextNode;
                }
                return 0;
            }
        }
    }
}

int main(void)
{
    character *head = new character;
    head->goRight = NULL;
    head->nextNode = NULL;
    head->ch = 0;
    string s;
    while (cin >> s)
    {
        int test = insert(head, s, 0);
        if (test == 0)
        {
            cout << "successed" << endl;
        }
        else
        {
            cout << "failed" << endl;
        }
    }
    return 0;
}