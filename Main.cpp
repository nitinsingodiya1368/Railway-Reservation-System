#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Node {
public:
    string name;
    string gen;
    int age;
    shared_ptr<Node> link;
};

shared_ptr<Node> start = nullptr;

// Function declarations
void details(int);
int seat(int);
int cal(int, int, int);
void bill(int, int);
void add_node(const string&, const string&, int);

// Global variables
string source, des, train;
string station, cla;
int time1, time2;
vector<int> a(55);

int main() {
    int i, j, a1, a2, b, c, x = 0, d, e, r;
    char o;
    cout << "Enter Number Of Passengers: ";
    cin >> j;

    // Calling details() function with argument number of passengers
    details(j);
    cout << "Enter The Source Place: ";
    cin.ignore();
    getline(cin, source);
    cout << "Enter The Destination Place: ";
    getline(cin, des);
    cout << "\t\tThe Following Trains Are Available.....\n";
    cout << "\t\t1. Rajdhani Express.......10:00 a.m........Sealdah Station\n";
    cout << "\t\t2. Satabdi Express.......05:00 p.m........Howrah Station\n";
    cout << "\t\t3. Humsafar Express.......11:00 p.m........Kolkata Chitpur Station\n";
    cout << "\t\t4. Garib-Rath Express.........05:00 p.m........Sealdah Station\n";
    cout << "\t\t5. Duronto Express.........07:00 a.m.........Santraganchi Station\n";
    cin >> i;
    do {
        switch (i) {
        case 1: {
            train = "Rajdhani Express";
            station = "Sealdah Station";
            time1 = 10;
            time2 = 00;
            a1 = 2099;
            a2 = 1560;
            d = cal(a1, a2, j);
            cout << "Total Bill Amount: " << d << endl;
        } break;
        case 2: {
            train = "Satabdi Express";
            station = "Howrah Station";
            time1 = 05;
            time2 = 00;
            a1 = 1801;
            a2 = 981;
            d = cal(a1, a2, j);
            cout << "Total Bill Amount: " << d << endl;
        } break;
        case 3: {
            train = "Humsafar Express";
            station = "Kolkata Chitpur Express";
            time1 = 11;
            time2 = 00;
            a1 = 2199;
            a2 = 1780;
            d = cal(a1, a2, j);
            cout << "Total Bill Amount: " << d << endl;
        } break;
        case 4: {
            train = "Garib-Rath Express";
            station = "Sealdah Station";
            time1 = 05;
            time2 = 00;
            a1 = 1759;
            a2 = 1200;
            d = cal(a1, a2, j);
            cout << "Total Bill Amount: " << d << endl;
        } break;
        case 5: {
            train = "Duronto Express";
            station = "Santraganchi Station";
            time1 = 07;
            time2 = 00;
            a1 = 2205;
            a2 = 1905;
            d = cal(a1, a2, j);
            cout << "Total Bill Amount: " << d << endl;
        } break;
        default:
            cout << "Enter Correct choice.....\n";
            x = 1;
            break;
        }
    } while (x);
    cout << "Now Book Your Seats......\n";
    seat(j);
    bill(d, j);

    return 0;
}

// Function for calculation of amount
int cal(int y1, int y2, int h) {
    int b, c, i, t, r, n;
    cout << "\t\tEnter Your Choice......\n";
    cout << "\t\t1. Sleeper Class....\n";
    cout << "\t\t2. A.C Class.......\n";
    cin >> i;
    switch (i) {
    case 1: {
        cla = "Sleeper Class";
        b = y2 * h;
        c = b + (b * 0.18);
    } break;
    case 2: {
        cout << "\t\tEnter Your Choice....\n";
        cout << "\t\t1. 3A Class....\n";
        cout << "\t\t2. 2A Class....\n";
        cout << "\t\t3. 1st Class A.C.....\n";
        cin >> n;
        switch (n) {
        case 1: {
            cla = "3A Class";
            b = y1 * h;
            c = b + (b * 0.18);
        } break;
        case 2: {
            cla = "2A Class";
            b = (y1 + 1000) * h;
            c = b + (b * 0.18);
        } break;
        case 3: {
            cla = "1st Class A.C.";
            b = (y1 + 5000) * h;
            c = b + (b * 0.18);
        } break;
        default:
            cout << "\t\tEnter Right Choice......\n";
        }
    } break;
    default:
        cout << "\t\tEnter Right Choice......\n";
    }
    return c;
}

// Function for taking details of passengers
void details(int k) {
    for (int i = 1; i <= k; i++) {
        string val, gen;
        int a;
        cout << "Enter The " << i << "th Passenger Name: ";
        cin.ignore();
        getline(cin, val);
        cout << "Enter The " << i << "th Passenger Gender: ";
        getline(cin, gen);
        cout << "Enter The " << i << "th Passenger Age: ";
        cin >> a;

        add_node(val, gen, a);
    }
}

// Function to add details in node for each passenger
void add_node(const string& lol, const string& der, int b) {
    auto newptr = make_shared<Node>();
    newptr->name = lol;
    newptr->gen = der;
    newptr->age = b;
    newptr->link = nullptr;

    if (start == nullptr)
        start = newptr;
    else {
        auto ptr = start;
        while (ptr->link != nullptr)
            ptr = ptr->link;
        ptr->link = newptr;
    }
}

// Function for choosing seats
int seat(int p) {
    cout << "\t\t -:SEAT MATRIX:-\n";
    cout << "\t(U) (M)  (L) (L)  (U)\n\n";
    cout << "\t01 02   03  04   05\n\n";
    cout << "\t06 07   08  09   10\n";
    cout << "\t11 12   13  14   15\n\n";
    cout << "\t16 17   18  19   20\n";
    cout << "\t21 22   23  24   25\n\n";
    cout << "\t26 27   28  29   30\n";
    cout << "\t31 32   33  34   35\n\n";
    cout << "\t36 37   38  39   40\n";
    cout << "\t41 42   43  44   45\n\n";
    cout << "\t46 47   48  49   50\n";
    cout << "\t51 52   53  54   55\n\n";
    cout << "\t56 57   58  59   60\n";
    cout << "\tEnter Seat Numbers: \n";
    for (int i = 0; i < p; i++) {
        cin >> a[i];
    }
    return 0;
}

// Function for printing receipt
void bill(int y, int j) {
    auto ptr = start;
    for (int i = 1; i <= j; i++) {
        cout << "\t\t" << i << "st Passenger Name: " << ptr->name << endl;
        cout << "\t\t" << i << "st Passenger Gender: " << ptr->gen << endl;
        cout << "\t\t" << i << "st Passenger Age: " << ptr->age << endl << endl;
        ptr = ptr->link;
    }
    cout << "\t\tSource Place: " << source << endl;
    cout << "\t\tDestination Place: " << des << endl;
    cout << "\t\tThe Boarding Station: " << station << endl;
    cout << "\t\tTrain Is: " << train << endl;
    cout << "\t\tAllocated Class: " << cla << endl;
    cout << "\t\tBoarding Time: " << time1 << ":" << time2 << endl;
    cout << "\t\tTotal Bill Amount: " << y << endl;
    cout << "\t\tAllocated Seats Are: \n";
    for (int i = 0; i < j; i++) {
        cout << "\t\t" << a[i] << " ";
    }
    cout << "\n";
    cout << "\t\t\t\tThank You......\n";
}
