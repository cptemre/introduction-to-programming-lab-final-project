#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
using namespace std;

string three_char_words[] = { "dog", "cat", "sun", "car", "man", "air", "sea", "row", "low", "top" };
string four_char_words[] = { "book", "food", "tree", "door", "bike", "hair", "skin", "rock", "sand", "fire" };
string five_char_words[] = { "apple", "table", "shirt", "watch", "light", "water", "plant", "house", "woman", "music" };
string six_char_words[] = { "banana", "orange", "butter", "camera", "flower", "letter", "market", "planet", "summer", "system" };
string seven_char_words[] = { "computer", "example", "language", "picture", "program", "research", "science", "species", "variety", "weather" };
string eight_char_words[] = { "airplane", "building", "creature", "football", "government", "holiday", "island", "journey", "knowledge", "library" };
string nine_char_words[] = { "agriculture", "atmosphere", "biotechnology", "capitalism", "economics", "education", "environment", "evolution", "geography", "history" };
string ten_char_words[] = { "architecture", "astronomy", "biology", "chemistry", "engineering", "geology", "mathematics", "medicine", "philosophy", "physics" };
string eleven_char_words[] = { "anthropology", "botany", "criminology", "demography", "ecology", "geography", "linguistics", "oceanography", "psychology", "sociology" };
string twelve_char_words[] = { "archaeology", "astrophysics", "biochemistry", "cardiology", "electronics", "genetics", "immunology", "meteorology", "neuroscience", "orthodontics" };
string thirteen_char_words[] = { "biological_science", "computer_science", "environmental_science", "materials_science", "mathematical_science", "social_science", "space_science", "statistical_science", "theoretical_science", "earth_science" };
string fourteen_char_words[] = { "agricultural_science", "architectural_science", "astronautical_science", "biomedical_science", "environmental_management", "forestry_science", "geodetic_science", "oceanographic_science", "pharmaceutical_science", "psychological_science" };
string fifteen_char_words[] = { "aerospace_engineering", "agricultural_engineering", "chemical_engineering", "civil_engineering", "computer_engineering", "electrical_engineering", "environmental_engineering", "geotechnical_engineering", "mechanical_engineering", "software_engineering" };

string input_word;
string file_path = "D:\\Collegium Da Vinci\\10-Introduction to Programming Lab\\Final\\Final\\score.txt";

// MENU FUNCTION
void menu() {
    cout << "1) New Game" << endl;
    cout << "2) Highest Score" << endl;
    cout << "3) Press Another Key To Exit" << endl;
    cout << "Select an option: ";
}

// FILE HANDLE FUNCTION
void check_and_update_file(int parameter) {
    ifstream file_in(file_path);
    ofstream file_out(file_path, ios::app);

    // Check if file already exists
    if (file_in) {
        int line1, line2;
        file_in >> line1 >> line2;

        // Update line1 with parameter
        line1 = parameter;

        // Check and update line2 with parameter if necessary
        if (line2 < parameter) {
            line2 = parameter;
        }

        // Clear the contents of the file and write the updated values
        file_out.close();
        file_out.open(file_path);
        file_out << line1 << endl << line2;

        cout << "Score is updated." << endl;
    }
    else {
        // Create the file and write the parameter to both line1 and line2
        file_out << parameter << endl << parameter;

        cout << "File created. Parameter written to Line1 and Line2." << endl;
    }

    file_in.close();
    file_out.close();
}

// SHOW SCORE BY READING THE FILE
void read_file() {
    ifstream file(file_path);
    if (!file.good()) {
        cout << "There is no previous record." << endl;
    }
    else {
        int line1, line2;
        file >> line1 >> line2;
        cout << "Last Score: " << line1 << endl;
        cout << "Highest Score: " << line2 << endl;
        file.close();
    }
}

void new_game() {
    int score = 0;
    string correct_words[100];
    int count_down = 7;
    int word_length = 3;
    while (count_down > 0) {
        string random_word;
        string input_word;
        srand(time(0));
        int index = rand() % 10;
        count_down--;
        if (word_length == 3) {
            random_word = three_char_words[index];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // 2 is for green color
            Beep(261, 500); // C4 note for half a second
        }
        else if (word_length == 4) {
            random_word = four_char_words[index];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // 6 is for yellow color
            Beep(329, 500); // E4 note for half a second
        }
        else if (word_length == 5) {
            random_word = five_char_words[index];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); // 3 is for cyan color
            Beep(392, 500); // G4 note for half a second
        }
        else if (word_length == 6) {
            random_word = six_char_words[index];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5); // 5 is for magenta color
            Beep(493, 500); // B4 note for half a second
        }
        else if (word_length == 7) {
            random_word = seven_char_words[index];
            SetConsoleTextAttribute(GetStdHandle
            (STD_OUTPUT_HANDLE), 11); // 11 is for light blue color
            Beep(587, 500); // D5 note for half a second
        }
        else if (word_length == 8) {
            random_word = eight_char_words[index];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); // 13 is for light purple color
            Beep(698, 500); // F5 note for half a second
        }
        else if (word_length == 9) {
            random_word = nine_char_words[index];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // 10 is for light green color
            Beep(784, 500); // G5 note for half a second
        }
        else if (word_length == 10) {
            random_word = ten_char_words[index];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // 14 is for light yellow color
            Beep(880, 500); // A5 note for half a second
        }
        else if (word_length == 11) {
            random_word = eleven_char_words[index];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // 9 is for light cyan color
            Beep(988, 500); // C6 note for half a second
        }
        else if (word_length == 12) {
            random_word = twelve_char_words[index];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); // 13 is for light purple color
            Beep(1046, 500); // C#6 note for half a second
        }
        else if (word_length == 13) {
            random_word = thirteen_char_words[index];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // 11 is for light blue color
            Beep(1175, 500); // D#6 note for half a second
        }
        else if (word_length == 14) {
            random_word = fourteen_char_words[index];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5); // 5 is for magenta color
            Beep(1396, 500); // F#6 note for half a second
        }
        else if (word_length == 15) {
            cout << "Congratulations, you have reached the final word" << endl;
            cout << "Total score: " << score << endl;
            cout << "Correct words: ";
            for (int i = 1; i <= score; i++) {
                cout << correct_words[i] << " ";
            }
            break;
        }
        while (count_down >= 0) {
            cout << "Time left: " << count_down << endl;
            if (count_down % 2 == 0 && count_down != 0)
            {
                cout << "////////////////";
            }
            else if (count_down % 2 == 1) {
                cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
            }
            else {
                cout << "****************";

            }
            cout << endl;
            if (count_down <= 4) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            }
            cout << "Word: " << random_word << endl;
            if (_kbhit()) {
                cin >> input_word;
                if (input_word == random_word) {
                    count_down = 7;
                    word_length++;
                    score++;
                    check_and_update_file(score);
                    if (word_length > 15) {
                        cout << "Congratulations! You have completed the game!" << endl;
                        break;
                    }
                }
                else {
                    cout << "Incorrect! Game Over!" << endl;
                    check_and_update_file(score);
                    count_down = 0;
                    break;
                }
                break;
            }
            count_down--;

            Sleep(1000);
            system("cls");
        }
    }
}



int main() {
    while (true) {
        menu();
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            new_game();
            break;
        case 2:
            system("cls");
            read_file();
            break;
        default:
            cout << "Program is turned off.";
            return 0;
            break;
        }
    }
    return 0;
}

