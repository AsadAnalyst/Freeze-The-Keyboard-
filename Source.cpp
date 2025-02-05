#include<iostream>
#include<conio.h>

using namespace std;

bool freeze()
{
    cout << "\n-----------------\n";
    cout << " Keyboard Freezed.\n";
    cout << "-----------------\n";
    return true;
}

bool unFreeze()
{
    cout << "\n--------------------\n";
    cout << " Keyboard UnFreezed.\n";
    cout << "--------------------\n";
    return false;
}

int main()
{
    bool flag = false;
    bool flag2 = true;
    cout << "\n----------------- Instruction ----------------------\n";
    cout << " 1--> Enter < F > or < f > For Freez and UnFreez \n";
    cout << " 2--> Enter < ESCAPE > For Terminate Program ";
    cout << "\n----------------------------------------------------\n";
    while (flag2)
    {
        if (_kbhit())   // User Mode
        {
            char ch = _getch();  // Here System Call then Kernal Mode Detect the Key and return to User Mode 

            if (ch == 'F' || ch == 'f')
            {
                if (flag)
                {
                    flag = unFreeze();  // when F key pressed then keyboard is diable and flag is true
                }
                else
                {
                    flag = freeze(); // when F key pressed then keyboard is diable and flag is false 
                }
            }
            else if (!flag)
            {
                cout << " Key " << ch << " is Entered\n";
            }
            if (ch == 27) // ESCAPE for exit 
            {
                flag2 = false;
            }
        }
    }

    return 0;
}
