#include<iostream>
#include<vector>
#include"algorithm"

using namespace std;

void displayBooks(const vector<string> &books ){
    cout<<"Library Collections: "<<endl;
    for(auto it=books.begin(); it!=books.end(); ++it){
        cout<<"- "<<*it<<endl;
    }
}

void addBook(vector<string> &books){
    cout<<"Enter book title to add "<<endl;
    string title;
    getline(cin,title);
    books.push_back(title);
    cout<<"Book added successfully."<<endl;
}

void removeBook(vector<string> &books){
    cout<<"Enter the book title to be removed"<<endl;
    string title;
    getline(cin,title);

    auto it=find(books.begin(),books.end(),title);
    if(it!= books.end()){
        books.erase(it);
        cout<<"Book removd successfully"<<endl;
    }
    else{
        cout<<"Book not found"<<endl;
    }
}

int main(){
    vector<string> books;
    int choice=0;
    
    do{
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Remove Book\n";
        std::cout << "3. Display Books\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); 
    
    switch (choice) {
            case 1:
                addBook(books);
                break;
            case 2:
                removeBook(books);
                break;
            case 3:
                displayBooks(books);
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
}
    while (choice != 4);

    return 0;
}
