#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to display categories
void showCategories() {
    cout << "\n========= ROAST CATEGORIES =========\n";
    cout << "1. School\n";
    cout << "2. Academics\n";
    cout << "3. Coding\n";
    cout << "4. Gaming\n";
    cout << "5. General Savage\n";
    cout << "====================================\n";
}

// Function to display difficulty levels
void showDifficulty() {
    cout << "\n======= DIFFICULTY LEVELS =======\n";
    cout << "1. Mild Roast 😄\n";
    cout << "2. Savage Roast 🔥\n";
    cout << "3. Extreme Roast ☠\n";
    cout << "=================================\n";
}

int main() {

    srand(time(0));

    string name;
    int categoryChoice, difficultyChoice;
    char again;

    cout << "=====================================\n";
    cout << "      ULTIMATE ROAST GENERATOR\n";
    cout << "=====================================\n";

    cout << "Enter your name: ";
    getline(cin, name);

    do {

        // Show category menu
        showCategories();
        cout << "Choose a category: ";
        cin >> categoryChoice;

        // Show difficulty menu
        showDifficulty();
        cout << "Choose difficulty level: ";
        cin >> difficultyChoice;

        vector<string> roasts;

        // ================= SCHOOL =================
        if(categoryChoice == 1) {

            if(difficultyChoice == 1) {
                roasts = {
                    name + " goes to school mainly for attendance.",
                    name + " treats homework like spam emails.",
                    "Teachers check if " + name + " is alive during class."
                };
            }

            else if(difficultyChoice == 2) {
                roasts = {
                    name + "'s report card needs emotional support.",
                    "Even the school bell gets tired waiting for " + name + " to understand the lesson.",
                    name + " studies so little that calculators feel unemployed."
                };
            }

            else {
                roasts = {
                    "If confusion had a face, it would probably be " + name + " during exams.",
                    name + "'s marks are proof that miracles don't happen every time.",
                    "Even the backbench is embarrassed of " + name + "."
                };
            }
        }

        // ================= ACADEMICS =================
        else if(categoryChoice == 2) {

            if(difficultyChoice == 1) {
                roasts = {
                    name + " opens books only to use them as pillows.",
                    name + " believes studying is a myth invented by toppers.",
                    "The syllabus fears " + name + " because it never gets touched."
                };
            }

            else if(difficultyChoice == 2) {
                roasts = {
                    name + "'s GPA is playing hide and seek.",
                    "Even Google struggles to understand " + name + "'s answers.",
                    name + " writes assignments with pure confidence and zero facts."
                };
            }

            else {
                roasts = {
                    "Exams see " + name + " coming and lower the expectations automatically.",
                    name + "'s brain goes on airplane mode during lectures.",
                    "If guessing answers were a subject, " + name + " would top the class."
                };
            }
        }

        // ================= CODING =================
        else if(categoryChoice == 3) {

            if(difficultyChoice == 1) {
                roasts = {
                    name + " writes code so slowly that even turtles complain.",
                    name + " thinks semicolons are optional decorations.",
                    "Debugging for " + name + " means restarting the laptop."
                };
            }

            else if(difficultyChoice == 2) {
                roasts = {
                    name + "'s code has more bugs than a rainforest.",
                    "Even Stack Overflow gets confused by " + name + "'s errors.",
                    name + " once fixed a bug and created five more."
                };
            }

            else {
                roasts = {
                    "NASA could use " + name + "'s code to discover new errors in space.",
                    name + "'s code quality makes viruses look professionally written.",
                    "The compiler sees " + name + "'s code and starts praying."
                };
            }
        }

        // ================= GAMING =================
        else if(categoryChoice == 4) {

            if(difficultyChoice == 1) {
                roasts = {
                    name + " blames lag for everything.",
                    name + " presses random buttons and calls it strategy.",
                    "NPCs feel bad after defeating " + name + "."
                };
            }

            else if(difficultyChoice == 2) {
                roasts = {
                    name + "'s teammates deserve compensation.",
                    "Even tutorial bots outperform " + name + ".",
                    name + " camps harder than people on vacation."
                };
            }

            else {
                roasts = {
                    "If losing were an esport, " + name + " would be world champion.",
                    "Even the loading screen has a higher IQ than " + name + "'s gameplay.",
                    name + "'s aim is so bad that enemies feel completely safe."
                };
            }
        }

        // ================= GENERAL SAVAGE =================
        else if(categoryChoice == 5) {

            if(difficultyChoice == 1) {
                roasts = {
                    name + " has the energy of a Monday morning.",
                    "If laziness had a mascot, it would be " + name + ".",
                    name + " could trip over a wireless connection."
                };
            }

            else if(difficultyChoice == 2) {
                roasts = {
                    name + " makes autocorrect question its own intelligence.",
                    "Even mirrors avoid eye contact with " + name + ".",
                    name + "'s life is basically a software beta version."
                };
            }

            else {
                roasts = {
                    "If bad decisions were currency, " + name + " would be a billionaire.",
                    name + "'s luck is so terrible that WiFi disconnects automatically.",
                    "Even reality struggles to process " + name + "."
                };
            }
        }

        else {
            cout << "\nInvalid category selected.\n";
            continue;
        }

        // Random roast selection
        int randomIndex = rand() % roasts.size();

        // Display roast
        cout << "\n🔥 GENERATED ROAST 🔥\n";
        cout << roasts[randomIndex] << endl;

        // Ask for another round
        cout << "\nDo you want another roast? (Y/N): ";
        cin >> again;

    } while(again == 'Y' || again == 'y');

    cout << "\nThanks for using the Roast Generator 😎\n";

    return 0;
}