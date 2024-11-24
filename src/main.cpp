// CTRL + SHIFT + P for code pallete
// Edit code using CTRL + I
// CTRL + L for AI cascade help (chat)

// DRAGON FOLLOWS YOU

// Project made by Alexander Alexeev (bnT91)
// My profile https://github.com/bnt91
// Enjoy the game!

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <conio.h>

// Color constants
#define COLOR_DEFAULT 7
#define COLOR_RED 12
#define COLOR_GREEN 10
#define COLOR_BLUE 9
#define COLOR_YELLOW 14

using namespace std;

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

signed main()
{
    SetConsoleOutputCP(CP_UTF8); 
    // Using ifstream instead of freopen for better UTF-8 support
    ifstream easy("D:\\DRAGON_FOLLOWS_YOU\\questions\\questions_light.txt");
    ifstream medium("D:\\DRAGON_FOLLOWS_YOU\\questions\\questions_medium.txt");
    ifstream hard("D:\\DRAGON_FOLLOWS_YOU\\questions\\questions_hard.txt");
    
    if (!easy.is_open() || !medium.is_open() || !hard.is_open()) {
        cout << "Error: Could not open file!" << endl;
        return 1;
    }

    string line;
    vector<string> easy_questions;
    vector<string> medium_questions;
    vector<string> hard_questions;

    while (getline(easy, line)) {
        easy_questions.push_back(line);
    }
    while (getline(medium, line)) {
        medium_questions.push_back(line);
    }
    while (getline(hard, line)) {
        hard_questions.push_back(line);
    }

    easy.close();
    medium.close();
    hard.close();

    setTextColor(COLOR_BLUE);

    cout << "Hello! You are trapped in dragon's cave. But the dragon loves riddles!\n\
So, you found the opportunity to escape. The way is to attack the dragon with riddles. There are 3 levels of difficulty:\n";
setTextColor(COLOR_GREEN);
cout << "\
\n\
1. Easy\n";
setTextColor(COLOR_YELLOW);
cout << "\
2. Medium\n";
setTextColor(COLOR_RED);
cout << "\
3. Hard\n\
\n";
setTextColor(COLOR_BLUE);
cout << "\
Every turn you choose the level of difficulty and answer the question. If you answer correctly, the dragon's HP goes down by the level of difficulty.\n\
If you answer incorrectly, your HP goes down by 1. If your HP reaches 0, you lose immidiately. If the dragon's HP reaches 0, you win!\n\
\n";
setTextColor(COLOR_YELLOW);
cout << "Your initial HP is 2.\n\
Dragon's initial HP is 15.\n";
setTextColor(COLOR_BLUE);
cout << "\n\
(yep, looks OP, but it's a game)\n\
\n\
Good luck and let's start the game! (enter 's' to start)\n";

    setTextColor(COLOR_DEFAULT);

    string skip__;
    cin >> skip__;

    return 0;
}