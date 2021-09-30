#include<iostream>
#include<string>
using namespace std;
/*
    其实kmp就是一个overlap的方法，而且这个前缀不是轴对称，abcabc最后一个是3，而abcba最后一个是1
    a a b b a a f
    0 1 0 0 1 2 0 is one of the next arraies
    but if we use the next array, we need to minus 1
    so if we let the location+1
    then
   -1 0 1 0 0 1 2
   so we can easily use the next array, and needless to minus 1
*/
void Next(int a[], int n, string s)// a[] is next array, n is the length of the string or the number of the array, s is the standared of the string
{
    int i = 0, ans = -1; // i is the location of the array , ans is the answer of the next array
    a[0] = ans; // let us define the a[0] is -1
    while(i < s.length()-1)//to calculate each next number
    {
        if(ans == -1 || s[i] == s[ans])//ans == -1 means (1.it is the a[1], and it is clearly that it is 0; 2. there is no same between start and end, and it is clearly 0),当然，当相等时，我们就ans++
        {
            i++;
            ans++;
            a[i] = ans;
        }
        else//这个else就是不相等的时候，通过自己和自己比对得出的，，记住，这里是while，而这里没有i++，如果不一样就不断往前跳，直到一样，或者跳到-1；
        {
            ans = a[ans];
        }  
    } 
    return;
}
int main(void)
{
    string standard;
    string s;
    cout << "please write the search word" << endl;
    cin >> standard;
    cout << "please write the whole string" << endl;
    cin >> s;
    int length = standard.length();
    int next[length];
    Next(next, length, standard);
    // for(int i = 0; i < length; i++)
    // {
    //     cout << next[i] << " ";
    // }
    // cout << endl;
    int start = 0;
    bool flag = false;
    /*
     * abcabcd  
     * abcd
     * -1000
     */
    for(int i = 0; i < s.length(); i++)
    {
        while(start != standard.length()  && i != s.length()) // compare
        {
            if(standard[start] == s[i])// same
            {
                i++;
                start++;
            }
            else if(start != 0) //different
            {
                start = next[start];
            }
            else if(start == 0) //different
            {
                i++;
            }
        }
        if(start == standard.length())
        {
            flag = true;
            cout << "yes" << endl;
            cout << "from " << i-start + 1 << " to " << i << endl;
            break;
        }
        else
        {
            cout << "no" << endl;
        }
        
    }
    return 0;
}
