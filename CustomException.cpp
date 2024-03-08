#include<iostream>
#include<exception>
#include<string>
#include<fstream>

class FileException: public std::exception{ //custom exception class
    private:
        std::string message;
    public:
        FileException(const std::string& file, const std::string& operation)
            : message ("Failed to "+ operation +"file : "+ file)
        {}
    //overide the what() to return our custom message
    const char* what() const noexcept override{ //what() returns a c style string
        return message.c_str();
    }
};

void openFile(const std::string& fileName){ //Function to open file and handle exceptions
    std::ifstream file(fileName); //opens the file
    if(!file.is_open()){ //checksa if file opening failed
        throw FileException(fileName,"open");
    }

    std::cout<<"File opened successfully"<<std::endl;
    file.close();
}

int main(){
    std::string fileName = "nonexistent_file.txt";

    try
    {
        openFile(fileName);
    }
    catch(const FileException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e){
        std::cerr<<"Standard exception caught :"<<e.what()<< '\n';
    }
    catch(...){
        std::cerr<<"Unknown excepton"<<'\n';
    }
    
}