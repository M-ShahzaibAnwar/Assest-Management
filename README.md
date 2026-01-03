# Assest-Management
A beginner friendly assest managment allows to use  basic CRUD operations (Create, Read, Update, Delete) and persistent storage in a text file.
# C++ Asset Manager

---

## Features

- Add new assets with **ID, Name, Type, Version, and Owner**  
- List all assets in a readable table  
- Update the version of an existing asset  
- Delete assets by ID  
- **Persistent storage** using a text file (`assets.txt`)  
- Handles **invalid numeric input safely** to prevent crashes or infinite loops  
- Fully implemented in **single-file C++**, beginner-friendly

---

## Skills Demonstrated

This project showcases:

- Basic **C++ programming** (structs, vectors, strings)  
- **File I/O** for persistent data storage  
- **Serialization and deserialization** of objects to/from text  
- **Input validation** to handle incorrect data gracefully  
- **CRUD operations** in a small system  
- **Logical structuring** of data and program flow  

---

## How It Works

1. The program loads existing assets from `assets.txt` at startup.  
2. The user chooses from a menu:
   - Add Asset  
   - List Assets  
   - Update Version  
   - Delete Asset  
   - Exit (saves changes)
3. Assets are stored in memory using a `vector<Asset>` and saved back to the file on exit.  
4. Input validation ensures the program does not crash when incorrect input is entered.

**Example of an asset in the file:**
