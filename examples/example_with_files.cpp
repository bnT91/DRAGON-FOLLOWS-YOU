#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    // Writing to a file
    if (freopen("example.txt", "w", stdout) == NULL) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }
    cout << "Hello, this is line 1!" << endl;
    cout << "This is line 2!" << endl;
    fclose(stdout);

    // Reset stdout to console
    freopen("CON", "w", stdout);
    cout << "Successfully wrote to the file" << endl;

    // Reading from file
    if (freopen("example.txt", "r", stdin) == NULL) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nReading file contents:" << endl;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        cout << buffer;
    }
    fclose(stdin);

    // Reset stdin to console
    freopen("CON", "r", stdin);

    // Appending to file
    if (freopen("example.txt", "a", stdout) == NULL) {
        cout << "Error opening file for appending!" << endl;
        return 1;
    }
    cout << "This line is appended!" << endl;
    fclose(stdout);

    // Reset stdout to console again
    freopen("CON", "w", stdout);
    cout << "\nSuccessfully appended to the file" << endl;

    // Reading updated file
    if (freopen("example.txt", "r", stdin) == NULL) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nReading updated file contents:" << endl;
    while (fgets(buffer, sizeof(buffer), stdin)) {
        cout << buffer;
    }
    fclose(stdin);

    // Final reset of stdin to console
    freopen("CON", "r", stdin);

    return 0;
}