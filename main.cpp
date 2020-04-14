//
// Created by ABlack on 4/05/2020.
//
#include <fstream>
#include <iostream>
using namespace std;

#ifdef _WIN32
const string python = "python";
#else
const string python = "python3";
#endif

/*
 * Prompt
 * Requires: Nothing
 * Modifies: Nothing
 * Effects: Prints the programs menu and usage instructions.
 */
void prompt();
/*
 * Get Filename
 * Requires: Nothing
 * Modifies: cin
 * Effects: Prompts user to enter a filename/file path, validates the input, then returns the input as a string.
 */
string get_filename();
/*
 * Get Extension
 * Requires: string
 * Modifies: Nothing
 * Effects: Takes the filename string, extracts the file extension, then returns it as a string.
 *          No input uses the default sound file.
 */
string get_extension(const string& path);
/*
 * Get Choice
 * Requires: Nothing
 * Modifies: cin
 * Effects: Prompts user to enter in a character that corresponds to one of the listed options.
 *          The input is validated, and then returns the input as a character.
 */
char get_choice();
/*
 * Get Rate
 * Requires: string
 * Modifies: cin
 * Effects: Prompts user to enter in a rate if the "speed" or "tempo" option has been selected.
 *          The input is validated, and then returns the input as a double.
 */
double get_rate(const string& type);

int main() {
    prompt();
    string filename = get_filename();
    string ext = get_extension(filename);
    char choice = get_choice();
    double rate;
    string command;
    switch (choice) {
        case 'a':
            cout << "Processing..." << endl;
            command = python + " manipulator.py " + filename + " " + ext + " reverse";
            system(command.c_str());
            break;
        case 'b':
            rate = get_rate("speed");
            cout << "Processing..." << endl;
            command = python + " manipulator.py " + filename + " " + ext + " speed " + to_string(rate);
            system(command.c_str());
            break;
        case 'c':
            rate = get_rate("tempo");
            cout << "Processing..." << endl;
            command = python + " manipulator.py " + filename + " " + ext + " tempo " + to_string(rate);
            system(command.c_str());
            break;
        case 'd':
            cout << "Processing..." << endl;
            command = python + " manipulator.py " + filename + " " + ext + " reverb";
            system(command.c_str());
            break;
        case 'e':
            cout << "Closing..";
            break;
    }
    return 0;
}

void prompt() {
    cout << "Welcome to the Sound Manipulator." << endl;
    cout << "This program allows you to take a sound file, and add effects to it!" << endl;
    cout << "Here are your options:" << endl;
    cout << "Enter (a) to reverse" << endl;
    cout << "Enter (b) to change speed" << endl;
    cout << "Enter (c) to change tempo" << endl;
    cout << "Enter (d) to add reverb" << endl;
    cout << "Enter (e) to exit this program" << endl;
    cout << "" << endl;
}

string get_filename() {
    cout << "Enter filename (example.mp3) or path to file (C:/.../example.wav), "
            "or enter nothing to use the default sound file: ";
    string filename;
    ifstream file;
    string junk;

    getline(cin,filename);
    if (filename.empty()) {
        return "test.wav";
    }

    file.open(filename);
    while (file.fail()) {
        cout << "Error opening file. Enter correct filename or path: ";
        cin.clear();
        file.close();

        getline(cin, filename);
        if (filename.empty()) {
            return "test.wav";
        }
        file.open(filename);
    }
    file.close();

    cout << "File found..." << endl;
    return "\"" + filename + "\"";
}

string get_extension(const string& path) {
    int i = path.rfind('.', path.length());
    if (i != string::npos) {
        string ext = path.substr(i+1, path.length() - i);
        ext.erase(ext.end()-1);
        return ext;
    }

    return "Extension Error";
}

char get_choice() {
    cout << "Enter manipulation choice: ";
    char choice;
    string junk;
    while (!(cin >> choice) || (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'e')) {
        cout << "Invalid option. Enter manipulation choice: ";
        cin.clear();
        getline(cin, junk);
    }
    return choice;
}

double get_rate(const string& type) {
    cout << "Enter the " + type + " rate (must be > 0): ";
    double rate;
    string junk;
    while (!(cin >> rate) || rate <= 0) {
        cout << "Invalid option. Enter manipulation choice: ";
        cin.clear();
        getline(cin, junk);
    }

    return rate;
}