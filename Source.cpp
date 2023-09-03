#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<cstring>
using namespace std;

int main()
{
    char opr = 'Y';
    int win = 0, lose = 0;
    int totalgames = 0;

    while (opr == 'Y')
    {
        cout << "\n\n\n";
        cout << "\t\t\t  ,---." << endl;
        cout << "\t\t\t  |   |" << endl;
        cout << "\t\t\t  O   |" << endl;
        cout << "\t\t\t /|\\  |" << endl;
        cout << "\t\t\t / \\  |" << endl;
        cout << "\t\t\t      |" << endl;
        cout << "\t\t\t=========" << endl;
        cout << "\t\t\t HANGMAN" << endl;
        cout << "\n\n\n";
        int correct = 0;
        int wrong = 0;
        int temp;

        string words[7] = { "computer","mouse","speaker","keyboard","monitor","joystick","television" };
        srand(time(0));
        int n;
        n = rand() % 7;

        for (int i = 0; i < words[n].size(); i++)
        {
            cout << "*";
        }
        cout << endl;

        temp = words[n].size();
        char* arr = new char[temp];

        for (int j = 0; j < temp; j++)
        {
            arr[j] = words[n][j];
        }
        char enter = '\0';
        char* test = new char[temp];

        for (int l = 0; l < temp; l++)
        {
            while (true)
            {
                cout << "Enter a single character: ";
                cin >> enter;
                // Check if the input is a single character
                if (cin.fail() || cin.peek() != '\n')
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a single character." << endl;
                }
                else
                {
                    break;
                }
            }
            test[l] = enter;
            if (arr[l] == test[l])
            {
                cout << "Correct word move on" << endl;
                correct++;
            }
            else if (arr[l] != test[l])
            {
                cout << "Invalid" << endl;
                l--;
                wrong++;
            }
            if (wrong == 1)
            {
                cout << "\t\t\t\t|===" << endl;
                cout << "\t\t\t\t|  O" << endl;
                cout << "\t\t\t\t|" << endl;
                cout << "\t\t\t\t|" << endl;
                cout << "\t\t\t\t|" << endl;
            }
            else if (wrong == 2)
            {
                cout << "\t\t\t\t|===" << endl;
                cout << "\t\t\t\t|  O" << endl;
                cout << "\t\t\t\t|  |" << endl;
                cout << "\t\t\t\t|" << endl;
                cout << "\t\t\t\t|" << endl;
            }
            else if (wrong == 3)
            {
                cout << "\t\t\t\t|===" << endl;
                cout << "\t\t\t\t|  O" << endl;
                cout << "\t\t\t\t| -|" << endl;
                cout << "\t\t\t\t|" << endl;
                cout << "\t\t\t\t|" << endl;
            }
            else if (wrong == 4)
            {
                cout << "\t\t\t\t|===" << endl;
                cout << "\t\t\t\t|  O" << endl;
                cout << "\t\t\t\t| -|-" << endl;
                cout << "\t\t\t\t|" << endl;
                cout << "\t\t\t\t|" << endl;
            }
            else if (wrong == 5)
            {
                cout << "\t\t\t\t|===" << endl;
                cout << "\t\t\t\t|  O" << endl;
                cout << "\t\t\t\t| -|-" << endl;
                cout << "\t\t\t\t| /" << endl;
                cout << "\t\t\t\t|" << endl;
            }
            else if (wrong == 6)
            {
                cout << "\t\t\t\t|===" << endl;
                cout << "\t\t\t\t|  O" << endl;
                cout << "\t\t\t\t| -|-" << endl;
                cout << "\t\t\t\t| / \\" << endl;
                cout << "\t\t\t\t|\n YOU ARE DEAD" << endl;

                cout << "Game over bro! The word was: " << words[n] << endl;
                lose++;
                totalgames++;
                break;
            }
            if (correct == temp)
            {
                cout << "You Won" << endl;
                win++;
                totalgames++;
            }
        }

        delete[] arr;
        delete[] test;
        system("cls");
        cout << "\t\t\t\t              Score Card" << endl;
        cout << "\t\t\t\t****************************************" << endl;
        cout << "\t\t\t\t        Total Games Played " << totalgames << endl;
        cout << "\t\t\t\t****************************************" << endl;
        cout << "\t\t\t\t     Games won by Player" << win << endl;
        cout << "\t\t\t\t****************************************" << endl;
        cout << "\t\t\t\t     Computer won games" << lose << endl;
        cout << "\t\t\t\t****************************************" << endl;

        cout << "Enter Y to play again" << endl;
        cin >> opr;
    }

    cout << "\t\t\t\tMade By Muhammad Samiullah" << endl;
    return 0;
}
