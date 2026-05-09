#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <random>
#include <limits>

using namespace std;

// Function to display categories
void showCategories() {
    cout << "\n=========== ROAST CATEGORIES ===========\n";
    cout << "1. School\n";
    cout << "2. Academics\n";
    cout << "3. Coding\n";
    cout << "4. Gaming\n";
    cout << "5. General Savage\n";
    cout << "0. Exit\n";
    cout << "========================================\n";
}

// Function to display difficulty levels
void showDifficulty() {
    cout << "\n========== DIFFICULTY LEVELS ==========\n";
    cout << "1. Mild Roast 😄\n";
    cout << "2. Savage Roast 🔥\n";
    cout << "3. Extreme Roast ☠\n";
    cout << "=======================================\n";
}

// Function to safely take integer input
int getValidatedInput() {

    int choice;

    while (true) {

        cin >> choice;

        if (cin.fail()) {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input! Please enter a number: ";
        }

        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

int main() {

    // Modern random number generator
    random_device rd;
    mt19937 gen(rd());

    string name;

    cout << "=========================================\n";
    cout << "       ULTIMATE ROAST GENERATOR\n";
    cout << "=========================================\n";

    cout << "Enter your name: ";
    getline(cin, name);

    // Empty name validation
    if (name.empty()) {
        cout << "Name cannot be empty.\n";
        return 0;
    }

    // Roast database
    map<int, map<int, vector<string>>> roastDB;

    // ================= SCHOOL =================

    roastDB[1][1] = {
        name + " goes to school mainly for attendance.",
        name + " treats homework like spam emails.",
        "Teachers check if " + name + " is alive during class."
    };

    roastDB[1][2] = {
        name + "'s report card needs emotional support.",
        "Even the school bell gets tired waiting for " + name + " to understand the lesson.",
        name + " studies so little that calculators feel unemployed."
    };

    roastDB[1][3] = {
        "If confusion had a face, it would probably be " + name + " during exams.",
        name + "'s marks are proof that miracles don't happen every time.",
        "Even the backbench is embarrassed of " + name + "."
    };

    // ================= ACADEMICS =================

    roastDB[2][1] = {
        name + " opens books only to use them as pillows.",
        name + " believes studying is a myth invented by toppers.",
        "The syllabus fears " + name + " because it never gets touched."
    };

    roastDB[2][2] = {
        name + "'s GPA is playing hide and seek.",
        "Even Google struggles to understand " + name + "'s answers.",
        name + " writes assignments with pure confidence and zero facts."
    };

    roastDB[2][3] = {
        "Exams see " + name + " coming and lower the expectations automatically.",
        name + "'s brain goes on airplane mode during lectures.",
        "If guessing answers were a subject, " + name + " would top the class."
    };

    // ================= CODING =================

    roastDB[3][1] = {
        name + " writes code so slowly that even turtles complain.",
        name + " thinks semicolons are optional decorations.",
        "Debugging for " + name + " means restarting the laptop."
    };

    roastDB[3][2] = {
        name + "'s code has more bugs than a rainforest.",
        "Even Stack Overflow gets confused by " + name + "'s errors.",
        name + " once fixed a bug and created five more."
    };

    roastDB[3][3] = {
        "NASA could use " + name + "'s code to discover new errors in space.",
        name + "'s code quality makes viruses look professionally written.",
        "The compiler sees " + name + "'s code and starts praying."
    };

    // ================= GAMING =================

    roastDB[4][1] = {
        name + " blames lag for everything.",
        name + " presses random buttons and calls it strategy.",
        "NPCs feel bad after defeating " + name + "."
    };

    roastDB[4][2] = {
        name + "'s teammates deserve compensation.",
        "Even tutorial bots outperform " + name + ".",
        name + " camps harder than people on vacation."
    };

    roastDB[4][3] = {
        "If losing were an esport, " + name + " would be world champion.",
        "Even the loading screen has a higher IQ than " + name + "'s gameplay.",
        name + "'s aim is so bad that enemies feel completely safe."
    };

    // ================= GENERAL SAVAGE =================

    roastDB[5][1] = {
        name + " has the energy of a Monday morning.",
        "If laziness had a mascot, it would be " + name + ".",
        name + " could trip over a wireless connection."
    };

    roastDB[5][2] = {
        name + " makes autocorrect question its own intelligence.",
        "Even mirrors avoid eye contact with " + name + ".",
        name + "'s life is basically a software beta version."
    };

    roastDB[5][3] = {
        "If bad decisions were currency, " + name + " would be a billionaire.",
        name + "'s luck is so terrible that WiFi disconnects automatically.",
        "Even reality struggles to process " + name + "."
    };

    int categoryChoice;
    int difficultyChoice;

    int previousIndex = -1;

    while (true) {

        // Show categories
        showCategories();

        cout << "Choose a category: ";
        categoryChoice = getValidatedInput();

        // Exit option
        if (categoryChoice == 0) {
            cout << "\nThanks for using the Roast Generator 😎\n";
            break;
        }

        // Category validation
        if (categoryChoice < 1 || categoryChoice > 5) {
            cout << "\nInvalid category selected.\n";
            continue;
        }

        // Show difficulty menu
        showDifficulty();

        cout << "Choose difficulty level: ";
        difficultyChoice = getValidatedInput();

        // Difficulty validation
        if (difficultyChoice < 1 || difficultyChoice > 3) {
            cout << "\nInvalid difficulty level.\n";
            continue;
        }

        // Access roast vector
        vector<string>& roasts = roastDB[categoryChoice][difficultyChoice];

        // Safety check
        if (roasts.empty()) {
            cout << "\nNo roasts available.\n";
            continue;
        }

        // Generate non-repeating random roast
        uniform_int_distribution<> dist(0, roasts.size() - 1);

        int randomIndex;

        do {
            randomIndex = dist(gen);
        }
        while (roasts.size() > 1 && randomIndex == previousIndex);

        previousIndex = randomIndex;

        // Display roast
        cout << "\n🔥 GENERATED ROAST 🔥\n";
        cout << roasts[randomIndex] << endl;
    }

    return 0;
}
