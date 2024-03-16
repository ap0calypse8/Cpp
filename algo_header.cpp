#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<ctime>

int main(){ //seed the random generator with time  fucntion 
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<int> vec(20); //%100 limits the range of the rand()
    std::generate(vec.begin(), vec.end(),[]{ return std::rand()%100; });

    std::cout<<"The vector is"<<std::endl;
    for(auto it :vec){
        std::cout<<it<<" "<<std::endl;
    }
    
    //sorting the vector
    std::sort(vec.begin(),vec.end());
    std::cout<<"The vector after sorting is "<<std::endl;
    for(auto it:vec){
        std::cout<<it<<std::endl;
    }

    //using find fucntion to search for value within the vector
    int value =50;
    auto found= std::find(vec.begin(),vec.end(),value);
    if(found!=vec.end()){
        std::cout<<"The value is found : "<<value<<std::endl;
    }
    else{
        std::cout<<"The value is not found"<<std::endl;
    }

    //finding the max and min element from the vector
    auto minMaxPair=std::minmax_element(vec.begin(),vec.end());
    int minval=*minMaxPair.first;
    int maxval=*minMaxPair.second;
    std::cout<<"Mininum value is: "<< minval<<std::endl;
    std::cout<<"Maximum value is: "<< maxval<<std::endl;

    //
    std::transform(vec.begin(),vec.end(),vec.begin(),[](int n){return n+1;});
    std::cout<<"vector after transformation(adding one to each element)"<<std::endl;
    for(auto i:vec){
        std::cout<<i<<std::endl;
    }
    

}

