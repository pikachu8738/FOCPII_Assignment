#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <random>
#include <limits>

using namespace std;

// Function to display categories
void showCategories() {

    cout << "\n=========== EXCUSE CATEGORIES ===========\n";
    cout << "1. Technology Excuses\n";
    cout << "2. School Excuses\n";
    cout << "3. Funny Excuses\n";
    cout << "4. Gaming Excuses\n";
    cout << "5. Extreme / Absurd Excuses\n";
    cout << "0. Exit\n";
    cout << "=========================================\n";
}

// Function to display difficulty levels
void showDifficulty() {

    cout << "\n=========== DIFFICULTY LEVELS ===========\n";
    cout << "1. Believable 😇\n";
    cout << "2. Funny 😂\n";
    cout << "3. Ridiculous ☠\n";
    cout << "=========================================\n";
}

// Function for validated numeric input
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
    cout << "       ULTIMATE EXCUSE GENERATOR\n";
    cout << "=========================================\n";

    cout << "Enter student name: ";

    getline(cin, name);

    // Empty name validation
    if (name.empty()) {

        cout << "Name cannot be empty.\n";

        return 0;
    }

    // Excuse database
    map<int, map<int, vector<string>>> excuseDB;

    // =====================================================
    // TECHNOLOGY EXCUSES
    // =====================================================

    excuseDB[1][1] = {

        name + " couldn't submit the assignment because the laptop battery died unexpectedly.",

        name + " tried finishing the homework, but the internet stopped working.",

        name + " lost the assignment after the system restarted automatically."
    };

    excuseDB[1][2] = {

        name + "'s computer updated itself for six straight hours.",

        name + " was about to submit the work when the Wi-Fi vanished mysteriously.",

        name + "'s keyboard suddenly decided retirement was necessary."
    };

    excuseDB[1][3] = {

        name + "'s file entered another dimension and never returned.",

        name + "'s assignment was deleted by what experts are calling 'ghost malware'.",

        "NASA is still investigating why " + name + "'s laptop exploded while opening the homework."
    };

    // =====================================================
    // SCHOOL EXCUSES
    // =====================================================

    excuseDB[2][1] = {

        name + " forgot the notebook at school.",

        name + " accidentally submitted the wrong file.",

        name + " couldn't complete the homework due to extra classes."
    };

    excuseDB[2][2] = {

        name + " spent two hours doing the wrong assignment.",

        name + "'s dog apparently graduated into homework destruction.",

        name + " studied so hard that sleep won the battle."
    };

    excuseDB[2][3] = {

        name + "'s backpack developed trust issues and hid the homework.",

        "Teachers may never recover from the mystery surrounding " + name + "'s missing assignment.",

        name + " claims the homework achieved self-awareness and escaped."
    };

    // =====================================================
    // FUNNY EXCUSES
    // =====================================================

    excuseDB[3][1] = {

        name + " was emotionally preparing to start the assignment.",

        name + " almost completed the homework in another timeline.",

        name + " ran out of motivation halfway through."
    };

    excuseDB[3][2] = {

        name + " accidentally opened YouTube and time disappeared.",

        name + " was fighting for survival against 47 browser tabs.",

        name + " tried focusing but the bed had stronger arguments."
    };

    excuseDB[3][3] = {

        name + "'s calculator demanded better working conditions.",

        name + " got distracted trying to remember why the assignment existed.",

        "Scientists are still researching how " + name + " managed to procrastinate that efficiently."
    };

    // =====================================================
    // GAMING EXCUSES
    // =====================================================

    excuseDB[4][1] = {

        name + " was one level away from saving the game.",

        name + " lost track of time during an online match.",

        name + " couldn't pause the game at the right moment."
    };

    excuseDB[4][2] = {

        name + "'s teammates emotionally blackmailed them into another match.",

        name + " fought bravely against lag instead of homework.",

        name + " planned to study after gaming but accidentally reached sunrise."
    };

    excuseDB[4][3] = {

        name + " believes the assignment was defeated in battle already.",

        "Even the game server told " + name + " to touch grass and finish homework.",

        name + " tried speedrunning the assignment and unlocked failure instead."
    };

    // =====================================================
    // EXTREME / ABSURD EXCUSES
    // =====================================================

    excuseDB[5][1] = {

        name + " misplaced the homework somewhere in the universe.",

        name + " experienced unexpected chaos at home.",

        name + " had a very dramatic day."
    };

    excuseDB[5][2] = {

        name + "'s cat walked across the keyboard and changed everything.",

        "Aliens would probably understand " + name + "'s assignment better.",

        name + " accidentally entered a motivational crisis."
    };

    excuseDB[5][3] = {

        "A secret government agency allegedly confiscated " + name + "'s homework.",

        name + " nearly finished the assignment before reality itself crashed.",

        "Experts confirm that " + name + "'s homework disappeared into a black hole."
    };

    int previousIndex = -1;

    while (true) {

        // Show category menu
        showCategories();

        cout << "Choose a category: ";

        int categoryChoice = getValidatedInput();

        // Exit option
        if (categoryChoice == 0) {

            cout << "\nThanks for using the Excuse Generator 😎\n";

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

        int difficultyChoice = getValidatedInput();

        // Difficulty validation
        if (difficultyChoice < 1 || difficultyChoice > 3) {

            cout << "\nInvalid difficulty level.\n";

            continue;
        }

        // Access excuse vector
        vector<string>& excuses = excuseDB[categoryChoice][difficultyChoice];

        // Safety check
        if (excuses.empty()) {

            cout << "\nNo excuses available.\n";

            continue;
        }

        // Generate non-repeating random excuse
        uniform_int_distribution<> dist(0, excuses.size() - 1);

        int randomIndex;

        do {

            randomIndex = dist(gen);

        } while (excuses.size() > 1 && randomIndex == previousIndex);

        previousIndex = randomIndex;

        // Display excuse
        cout << "\n📚 GENERATED EXCUSE 📚\n";

        cout << excuses[randomIndex] << endl;
    }

    return 0;
}