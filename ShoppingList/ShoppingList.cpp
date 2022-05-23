//                                                 SHOPPING LIST APP
// Ömer Furkan Özsoy
// 1306190073
// Shopping list App

#include <iostream>
#include <string>
#include <vector> 
using namespace std;

vector<vector<string> > list;

void makelist()
{
    cout << "Please enter names and counts(Apple 3 for example) , Press Q for exit : " << endl;
    string name = "x";
    vector<string> V1;
    while (name != "Q") {
        cin >> name;
        V1.push_back(name);
    }
    cout << endl;
    V1.pop_back();
    list.push_back(V1);
    cout << "Your lists :" << endl;
    for (int i = 0; i < V1.size(); i++) {
        cout << V1[i];
        if (i % 2 == 0) {
            cout << " ";
        }
        else {
            cout << endl;
        }
    }
    cout << endl;
    //for (int i = 0; i < list.size(); i++) {
    //   cout << list[i][i];  
}

void showlist() {
    //cout << "Please enter number of list that you want to see : ";
    //int w;
    //cin >> w;
    if (list.size() == 0) {
        cout << "You dont have any list" << endl;
    }
    else {
        for (int i = 0; i < list.size(); i++) {
            cout << " list : " << i + 1 << endl;
            for (int j = 0; j < list[i].size(); j++) {
                cout << list[i][j] << " ";
                if (j % 2 == 0) {
                    cout << " ";
                }
                else {
                    cout << endl;
                }

            }
            cout << endl;
        }
    }
}

void deletelist() {
    if (list.size() == 0) {
        cout << "You dont have any list" << endl;
    }

    else {
        int deletenumber;
        cout << "Which list do you want to delete : ";
        cin >> deletenumber;
        list.erase(list.begin() + deletenumber - 1);
        cout << "Your " << deletenumber << ". list deleted" << endl;
    }
}

void additem() {
    if (list.size() == 0) {
        cout << "You dont have any list" << endl;
    }
    else {

        int list_number;
        cout << "Please Choose list to add product : ";
        cin >> list_number;
        cout << endl;
        cout << "Please enter name and count (Apple 3 for example): " << endl;
        string name = "x";
        for (int i = 0; i < 2; i++) {
            cin >> name;
            list[list_number - 1].push_back(name);
        }
        cout << "Your list :" << endl;
        for (int i = 0; i < list[list_number - 1].size(); i++) {
            cout << list[list_number - 1][i];
            if (i % 2 == 0) {
                cout << " ";
            }
            else {
                cout << endl;
            }
        }
        cout << endl;
    }
}

void checkitem() {
    if (list.size() == 0) {
        cout << "You dont have any list" << endl;
    }
    else {
        int listNumber;
        int changeNumber;
        cout << "Choose list : ";
        cin >> listNumber;
        cout << endl;
        cout << "Enter line number of product that you want to mark check : ";
        cin >> changeNumber;
        list.at(listNumber - 1)[(2 * changeNumber) - 1] = "(X)";

        cout << "Your list :" << endl;
        for (int i = 0; i < list[listNumber - 1].size(); i++) {
            cout << list[listNumber - 1][i];
            if (i % 2 == 0) {
                cout << " ";
            }
            else {
                cout << endl;
            }
        }
    }
}

void changeAmountAndUncheck() {
    if (list.size() == 0) {
        cout << "You dont have any list" << endl;
    }
    else {
        int listNumber2;
        int changeNumber2;
        string newAmount;
        cout << "Choose list : ";
        cin >> listNumber2;
        cout << endl;
        cout << "Enter line number of product that you want to uncheck or change amount : ";
        cin >> changeNumber2;
        cout << endl << "Please choose new amount of product : ";
        cin >> newAmount;
        cout << endl;
        list.at(listNumber2 - 1)[(2 * changeNumber2) - 1] = newAmount;
        cout << "Your list :" << endl;
        for (int i = 0; i < list[listNumber2 - 1].size(); i++) {
            cout << list[listNumber2 - 1][i];
            if (i % 2 == 0) {
                cout << " ";
            }
            else {
                cout << endl;
            }
        }
    }
}

int main()
{

    int a;
    cout << "-------------------------Shopping List App-------------------------" << endl;
    cout << "Choose command " << endl;
    do
    {
        cout << "   1-) Make a list." << endl;
        cout << "   2-) Your Shopping Lists." << endl;
        cout << "   3-) Delete a list" << endl;
        cout << "   4-) Add an item to an existing list." << endl;
        cout << "   5-) Check a certain item as bought. " << endl;
        cout << "   6-) Uncheck a certain item as bought or change amount of product" << endl;
        cout << "   7-) Exit" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            makelist();
            break;
        case 2:
            showlist();
            break;
        case 3:
            deletelist();
            break;
        case 4:
            additem();
            break;
        case 5:
            checkitem();
            break;
        case 6:
            changeAmountAndUncheck();
            break;
        case 7:
            cout << "***CLOSING***";
            return 0;
        default:
            cout << "**ERROR** please enter numbers from 1 to 7";
            break;
        }
    } while (a != 7);
    return 0;
}