#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib> 

using namespace std;

// Struct to store asset info
struct Asset {
    int id;
    string name;
    string type;
    int version;
    string owner;
};

// safely read an integer
int readInt(string prompt) {
    int num;
    while (true) {
        cout << prompt;
        cin >> num;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();                 
            cin.ignore(10000, '\n');    
        } else {
            cin.ignore(10000, '\n');    
            return num;
        }
    }
}

// Serialize asset to string
string serialize(Asset a) {
    stringstream ss;
    ss << a.id << "," << a.name << "," << a.type << "," << a.version << "," << a.owner;
    return ss.str();
}

// Deserialize string to asset
Asset deserialize(string line) {
    Asset a;
    stringstream ss(line);
    string temp;

    getline(ss, temp, ',');
    a.id = atoi(temp.c_str());

    getline(ss, a.name, ',');
    getline(ss, a.type, ',');

    getline(ss, temp, ',');
    a.version = atoi(temp.c_str());

    getline(ss, a.owner, ',');

    return a;
}

// Load assets from file
void loadAssets(vector<Asset> &assets, string filename) {
    ifstream file(filename.c_str());
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line != "")
            assets.push_back(deserialize(line));
    }

    file.close();
}

// Save assets to file
void saveAssets(vector<Asset> &assets, string filename) {
    ofstream file(filename.c_str());
    for (int i = 0; i < assets.size(); i++) {
        file << serialize(assets[i]) << endl;
    }
    file.close();
}

// List all assets
void listAssets(vector<Asset> &assets) {
    cout << "\n--- Assets ---\n";
    for (int i = 0; i < assets.size(); i++) {
        cout << "ID: " << assets[i].id
             << " | Name: " << assets[i].name
             << " | Type: " << assets[i].type
             << " | Version: " << assets[i].version
             << " | Owner: " << assets[i].owner << endl;
    }
}

// Add new asset
void addAsset(vector<Asset> &assets) {
    Asset a;
    a.id = readInt("Enter ID: ");
    cout << "Enter Name: ";
    getline(cin, a.name);

    cout << "Enter Type: ";
    getline(cin, a.type);

    a.version = readInt("Enter Version: ");

    cout << "Enter Owner: ";
    getline(cin, a.owner);

    assets.push_back(a);
    cout << "Asset added successfully!\n";
}

// Update asset version
void updateVersion(vector<Asset> &assets) {
    int id = readInt("Enter Asset ID to update version: ");

    for (int i = 0; i < assets.size(); i++) {
        if (assets[i].id == id) {
            assets[i].version++;
            cout << "Version updated!\n";
            return;
        }
    }
    cout << "Asset not found!\n";
}

// Delete asset
void deleteAsset(vector<Asset> &assets) {
    int id = readInt("Enter Asset ID to delete: ");

    for (int i = 0; i < assets.size(); i++) {
        if (assets[i].id == id) {
            assets.erase(assets.begin() + i);
            cout << "Asset deleted!\n";
            return;
        }
    }
    cout << "Asset not found!\n";
}

// Main function
int main() {
    vector<Asset> assets;
    string filename = "assets.txt";

    loadAssets(assets, filename);

    int choice;
    while (true) {
        cout << "\n1. Add Asset\n2. List Assets\n3. Update Version\n4. Delete Asset\n5. Exit\nChoice: ";
        choice = readInt(""); 

        if (choice == 1) addAsset(assets);
        else if (choice == 2) listAssets(assets);
        else if (choice == 3) updateVersion(assets);
        else if (choice == 4) deleteAsset(assets);
        else if (choice == 5) {
            saveAssets(assets, filename);
            cout << "Data saved. Exiting...\n";
            break;
        }
        else cout << "Invalid choice! Try again.\n";
    }

    return 0;
}

