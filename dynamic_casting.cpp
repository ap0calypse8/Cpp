#include<iostream>
#include<cmath>
#define PI 3.14

using namespace std;

class shape {
    public:
         //pure virtual function without any real implementation
        virtual double calculateArea() const =0; //this must be overriden by derived classes 
         //virtual destructor to ensure destructor of derived classes is called
        virtual ~shape() {}
};

    class rectangle : public shape {
        private:
            double width;
            double length;
        public:
            rectangle(auto w, auto l) { //constructor
                width=w;
                length=l;
            }
        double calculateArea() const override {
            return width*length;
        }
    };

    class circle : public shape {
        private:
            double radius;
        public:
            circle(auto r){ //constructor
                radius=r;
            }
            double calculateArea() const override {
                return PI * radius  * radius;
            }
    };

int main(){

    rectangle rect(9,6);
    circle circ(4);

    shape *shape_ptr = &rect;
    shape *shape_ptr2 = &circ;

    std::cout<<"Area of Rectangle is: "<<shape_ptr->calculateArea()<<std::endl;
    std::cout<<"Area of Circle is: "<<shape_ptr2->calculateArea()<<std::endl;

rectangle* rectanglePtr = dynamic_cast<rectangle*>(shape_ptr);//converting shape class pointer to rectangle class pointer
if(rectanglePtr){
    std::cout<<"Dynamic cast successful for rectangle"<<'\n';
}
else{
    std::cout<<"Dynamic casting failed for rectangle"<<'\n';
}

circle* circlePtr = dynamic_cast<circle*>(shape_ptr2);
if(circlePtr){
    std::cout<<"Dynamic casting is successfulv for circle"<<'\n';
}
else{
    std::cout<<"Dynamic casting failed for circle"<<'\n';
}
}