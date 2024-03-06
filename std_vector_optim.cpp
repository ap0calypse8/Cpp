#include<iostream>
#include<vector>

int main(){
    std::vector<int> vec; //declaring my vector
    vec.reserve(7); //reserving space for 7 elements

    for(auto i= 0;i<7;i++){
        vec.emplace_back(i); //emplace_back constructs the elements directly into the vector
    }

    for(auto i= 0;i<vec.size();i++){
        std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;

}