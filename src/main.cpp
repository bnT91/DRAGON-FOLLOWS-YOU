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
#define COLOR_WHITE 15

using namespace std;

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

string lowercase(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
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

    vector<string> easy_answers;
    vector<string> medium_answers;
    vector<string> hard_answers;

    ifstream easy_answers_file("D:\\DRAGON_FOLLOWS_YOU\\answers\\answers_light.txt");
    ifstream medium_answers_file("D:\\DRAGON_FOLLOWS_YOU\\answers\\answers_medium.txt");
    ifstream hard_answers_file("D:\\DRAGON_FOLLOWS_YOU\\answers\\answers_hard.txt");

    if (!easy_answers_file.is_open() || !medium_answers_file.is_open() || !hard_answers_file.is_open()) {
        cout << "Error: Could not open file!" << endl;
        return 1;
    }

    while (getline(easy_answers_file, line)) {
        easy_answers.push_back(line);
    }
    while (getline(medium_answers_file, line)) {
        medium_answers.push_back(line);
    }
    while (getline(hard_answers_file, line)) {
        hard_answers.push_back(line);
    }

    setTextColor(COLOR_BLUE);

    cout << "Hello! You are trapped in a dragon's cave. But the dragon loves riddles!\n\
So, you found an opportunity to escape. The way is to attack the dragon with riddles. There are 3 levels of difficulty:\n";
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
Good luck and let's start the game! (by the way, answer all the questions in lowercase, in one word or number) (enter 's' to start)\n";

    setTextColor(COLOR_DEFAULT);

    string skip__;
    cin >> skip__;
    while (skip__ != "s")
    {
        cin >> skip__;
    }

    int dragon_hp = 15;
    int player_hp = 2;

    while (dragon_hp > 0 && player_hp > 0)
    {
        int level = 0;
        setTextColor(COLOR_WHITE);
        cout << "Choose the level of difficulty (just type the number):\n\n";
        setTextColor(COLOR_GREEN);
        cout << "1. Easy\n";
        setTextColor(COLOR_YELLOW);
        cout << "2. Medium\n";
        setTextColor(COLOR_RED);
        cout << "3. Hard\n\n";
        setTextColor(COLOR_DEFAULT);
        cin >> level;
        if (level == 2) 
        {
            if (medium_questions.size() == 0)
            {
                cout << "No more questions left! Please choose another difficulty level." << endl;
                continue;
            }
            int random_index = rand() % medium_questions.size();
            string question = medium_questions[random_index];
            setTextColor(COLOR_WHITE);
            cout << question << endl;
            string answer;
            cin >> answer;
            if (lowercase(answer) == medium_answers[random_index])
            {
                dragon_hp -= 2;
                setTextColor(COLOR_WHITE);
                cout << "Correct! Dragon's HP: " << dragon_hp << endl;
                setTextColor(COLOR_DEFAULT);
                medium_questions.erase(medium_questions.begin() + random_index);
                medium_answers.erase(medium_answers.begin() + random_index);
            }
            else {
                player_hp -= 1;
                setTextColor(COLOR_WHITE);
                cout << "Incorrect! " << "Correct answer was: " << medium_answers[random_index] << ". Your HP: " << player_hp << endl;
                setTextColor(COLOR_DEFAULT);
                medium_questions.erase(medium_questions.begin() + random_index);
                medium_answers.erase(medium_answers.begin() + random_index);
            }
        }
        else if (level == 3)
        {
            if (hard_questions.size() == 0)
            {
                cout << "No more questions left! Please choose another difficulty level." << endl;
                continue;
            }
            int random_index = rand() % hard_questions.size();
            string question = hard_questions[random_index];
            cout << question << endl;
            string answer;
            cin >> answer;
            if (lowercase(answer) == hard_answers[random_index])
            {
                dragon_hp -= 3;
                setTextColor(COLOR_WHITE);
                cout << "Correct! Dragon's HP: " << dragon_hp << endl;
                setTextColor(COLOR_DEFAULT);
                hard_questions.erase(hard_questions.begin() + random_index);
                hard_answers.erase(hard_answers.begin() + random_index);
            }
            else {
                player_hp -= 1;
                setTextColor(COLOR_WHITE);
                cout << "Incorrect! " << "Correct answer was: " << hard_answers[random_index] << ". Your HP: " << player_hp << endl;
                setTextColor(COLOR_DEFAULT);
                hard_questions.erase(hard_questions.begin() + random_index);
                hard_answers.erase(hard_answers.begin() + random_index);
            }
        }
        else
        {
            if (easy_questions.size() == 0)
            {
                cout << "No more questions left! Please choose another difficulty level." << endl;
                continue;
            }
            int random_index = rand() % easy_questions.size();
            string question = easy_questions[random_index];
            cout << question << endl;
            string answer;
            cin >> answer;
            if (lowercase(answer) == easy_answers[random_index])
            {
                dragon_hp -= 1;
                setTextColor(COLOR_WHITE);
                cout << "Correct! Dragon's HP: " << dragon_hp << endl;
                setTextColor(COLOR_DEFAULT);
                easy_questions.erase(easy_questions.begin() + random_index);
                easy_answers.erase(easy_answers.begin() + random_index);
            }
            else {
                player_hp -= 1;
                setTextColor(COLOR_WHITE);
                cout << "Incorrect! " << "Correct answer was: " << easy_answers[random_index] << ". Your HP: " << player_hp << endl;
                setTextColor(COLOR_DEFAULT);
                easy_questions.erase(easy_questions.begin() + random_index);
                easy_answers.erase(easy_answers.begin() + random_index);
            }
        }
        dragon_hp = max(dragon_hp, 0);
    }

    if (player_hp > 0)
    {
        setTextColor(COLOR_YELLOW);
        cout << "\n\n";
        cout << "You won! Congratulations!" << endl;
        setTextColor(COLOR_DEFAULT);
    }
    else
    {
        setTextColor(COLOR_RED);
        cout << "\n\n";
        cout << "You lost! Better luck next time!" << endl;
        setTextColor(COLOR_DEFAULT);
    }
    return 0;
}