#include <iostream>
#include <cstdio>
#include <limits>
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

struct TPlayer {
    char team[30];
    char fullName[30];
    int age;
};

TPlayer players[30];
int count = 0;

void clearScreen() {
    cout << "\033[2J\033[H";
}

void waitKey() {
#ifdef _WIN32
    _getch();
#else
    struct termios old;
    tcgetattr(STDIN_FILENO, &old);
    struct termios raw = old;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
#endif
}

int readInt(const char *prompt, int min, int max) {
    int n;
    bool first = true;
    while (true) {
        if (!first) cout << "\033[A\033[2K\r";
        first = false;
        cout << prompt;
        if (cin >> n && n >= min && n <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return n;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void readLine(const char *prompt, char *buf, int size) {
    cout << prompt;
    cin.getline(buf, size);
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int menu() {
    cout << "Choose:" << endl;
    cout << "1. Input list & save to file" << endl;
    cout << "2. Open file" << endl;
    cout << "3. Show players under 18" << endl;
    cout << "4. Write result to text file" << endl;
    cout << "5. Exit" << endl;
    return readInt("Your choice: ", 1, 5);
}

void inputList() {
    char fileName[64];
    readLine("Enter binary file name: ", fileName, sizeof(fileName));

    FILE *fl = fopen(fileName, "wb");
    if (fl == NULL) {
        cout << "Error creating file" << endl;
        return;
    }

    count = readInt("Enter number of players: ", 1, 30);
    for (int i = 0; i < count; i++) {
        readLine("Enter team: ", players[i].team, sizeof(players[i].team));
        readLine("Enter name: ", players[i].fullName, sizeof(players[i].fullName));
        players[i].age = readInt("Enter age: ", 1, 120);
        fwrite(&players[i], sizeof(TPlayer), 1, fl);
    }
    fclose(fl);
    cout << "Saved " << count << " players" << endl;
}

void openFile() {
    char fileName[64];
    readLine("Enter binary file name: ", fileName, sizeof(fileName));

    FILE *fl = fopen(fileName, "rb");
    if (fl == NULL) {
        cout << "Error opening file" << endl;
        return;
    }

    count = 0;
    TPlayer p;
    while (count < 30 && fread(&p, sizeof(TPlayer), 1, fl) == 1) {
        players[count] = p;
        cout << players[count].team << " " << players[count].fullName << " " << players[count].age << endl;
        count++;
    }
    fclose(fl);
    if (count == 0) cout << "File is empty" << endl;
}

void showResult() {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (players[i].age < 18) {
            cout << players[i].team << " " << players[i].fullName << " " << players[i].age << endl;
            found++;
        }
    }
    if (found == 0) cout << "Players under 18 not found" << endl;
}

void writeToFile() {
    char name[64];
    readLine("Enter output file name: ", name, sizeof(name));

    FILE *ft = fopen(name, "w");
    if (ft == NULL) {
        cout << "Error creating file" << endl;
        return;
    }

    int written = 0;
    for (int i = 0; i < count; i++) {
        if (players[i].age < 18) {
            fprintf(ft, "%s %s %d\n", players[i].team, players[i].fullName, players[i].age);
            written++;
        }
    }
    fclose(ft);
    cout << "Written " << written << " players" << endl;
}

int main() {
    while (true) {
        switch (menu()) {
            case 1: inputList(); break;
            case 2: openFile(); break;
            case 3: showResult(); break;
            case 4: writeToFile(); break;
            case 5: return 0;
        }
        cout << "Press any key to continue" << endl;
        waitKey();
        clearScreen();
    }
}
