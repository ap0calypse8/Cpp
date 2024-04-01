#include<iostream>



template<typename... types>
class Tuple;

template <>
class Tuple<> {}; //empty tuple construction

template <typename Head , typename... Tail>
class Tuple<Head, Tail...> : public Tuple<Tail...> {
    public:
    Tuple(Head head,Tail... tail):Tuple<Tail...>(tail...), head_(head) {}

    Head head() const { return head_;} 

    private :
    Head head_;
};

int main() {
    Tuple<int,float,double>tuple(1,2.0f,3.0);
    std::cout <<"First element : "<<tuple.head();
    std::cout<<"\n";
    return 0;
}