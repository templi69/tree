#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> age;

    age["Ali"] = 21;
    age["Taha"] = 19;

    cout << "Ali's age: " << age["Ali"] << endl;

    return 0;
}


#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = { 1, 2, 2, 3, 3, 3 };
    unordered_map<int, int> freq;

    for (int i = 0; i < 6; i++) {
        freq[arr[i]]++;
    }

    for (auto pair : freq) {
        cout << pair.first << " appears " << pair.second << " times\n";
    }
}



#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
    string text = "this is a test this is";
    unordered_map<string, int> wordCount;
    string word;
    stringstream ss(text);

    while (ss >> word) {
        wordCount[word]++;
    }

    for (auto p : wordCount) {
        cout << p.first << ": " << p.second << endl;
    }
}


bool isAnagram(string a, string b) {
    if (a.length() != b.length()) return false;

    unordered_map<char, int> count;
    for (char c : a) count[c]++;
    for (char c : b) count[c]--;

    for (auto it : count)
        if (it.second != 0)
            return false;
    return true;
}



#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> students;
    int choice, roll;
    string name;

    while (true) {
        cout << "\n1. Add student\n2. Remove student\n3. Find student\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter roll no: ";
            cin >> roll;
            cout << "Enter name: ";
            cin >> name;
            students[roll] = name;
        }
        else if (choice == 2) {
            cout << "Enter roll to remove: ";
            cin >> roll;
            students.erase(roll);
        }
        else if (choice == 3) {
            cout << "Enter roll to find: ";
            cin >> roll;
            if (students.find(roll) != students.end()) {
                cout << "Name: " << students[roll] << endl;
            }
            else {
                cout << "Not found.\n";
            }
        }
        else break;
    }
    return 0;
}



#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = { 4, 3, 2, 7, 8, 2, 3, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int, int> freq;

    // Step 1: Count frequency
    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    // Step 2: Print duplicates
    cout << "Duplicate elements are:\n";
    for (auto pair : freq) {
        if (pair.second > 1) {
            cout << pair.first << " (appears " << pair.second << " times)" << endl;
        }
    }

    return 0;
}
