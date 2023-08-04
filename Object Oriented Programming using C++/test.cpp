/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    /*   char name[20];
    int count = 0;
    cin.getline(name, 20);
    
    for(int i = 0; i < sizeof(name); i++){
        if(name[i] == '\0')
            break;
        if(name[i] == ' '){
            count++;
        }
    }
    
    cout << count+1 << endl;
*/

    char s1[100] = "Gaurav", s2[100] = "Singh";
    int i = 0, j = strlen(s2);

    strcpy(s1, s2);
    /*while(s1[i] != '\0'){
        s1[i] = s2[i];
        i++;
    }*/
    //s1[i] = '\0';
    //cout << s1 << endl;

    while (i < j)
    {
        if (s1[i] != s2[j] || s1[i] == '\0')
        {
            cout << "Not a palindrome" << endl;
            break;
        }
        i++;
        j--;
    }

    // If not output then the string is palindrome

    return 0;
}

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char s1[100], s2[100] = "abbccbba";

    strcpy(s1, s2);
    //s1[strlen(s1)+1] = '\0';

    int i = 0, j = strlen(s1), f = 0;
    while (i < j)
    {
        if (s1[i] != s1[j - 1])
        {
            f = 1;
            //cout << i << endl;
            //break;
        }
        //cout << i << endl;
        ++i;
        --j;
    }

    if (f == 0)
        cout << "String is palindrome" << endl;
    else
        cout << "String is not palindrome" << endl;

    return 0;
}