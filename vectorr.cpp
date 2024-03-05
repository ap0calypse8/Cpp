#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

class vector3D {
public :
    double x,y,z; //values for each axis to hold vector components

    vector3D(double x_val=0.0, double y_val=0.0, double z_val=0.0){ //constructor for the vector

    x=x_val;
    y=y_val;
    z=z_val;
}
    vector3D operator+(const vector3D& vec)const { //operator  overloading for "+" 
        return vector3D(x+vec.x, y+vec.y, z+vec.z);
    }

    vector3D operator-(const vector3D& vec)const {
        return vector3D(x-vec.x, y-vec.y, z-vec.z);
    }

    vector3D operator*(double scalar)const{ //method for scalar multiplication
        return vector3D(x*scalar, y*scalar, z*scalar);
    }

    double dot( const vector3D& vec)const{
        return x*vec.x+ y*vec.y+ z*vec.z;
    }
    vector3D cross(const vector3D& vec) const{
    return vector3D(y*vec.z - z*vec.y, 
                    z*vec.x - x*vec.z,
                    x*vec.y - y*vec.x);
    }

    double magnitude() const {
        return std::sqrt(x*x+y*y+z*z);
    }

    vector3D normalize() const{
        double magni= magnitude();
        if(magni==0.0){
            return vector3D(0,0,0);
        }
        double x_normal=x/magni;
        double y_normal=y/magni;
        double z_normal=z/magni;
        return vector3D(x_normal,y_normal,z_normal);
    }

void print() const{
    cout<<"("<<x<<")"<<"("<<y<<")"<<"("<<z<<")"<<endl;
}

};


int main (){
    vector3D vec1(1.0,2.0,3.0);
    vector3D vec2(4.0,5.0,6.0);

    cout<<"first vector is ";
    vec1.print();
    cout<<"second vector is ";
    vec2.print();

    vector3D add = vec1 + vec2 ;
    cout<<"sum is: ";
    add.print();

    vector3D difference = vec1 - vec2;
    cout << "Difference is: ";
    difference.print();

    auto dotProduct = vec1.dot(vec2);
    cout<<"Dot Product is :"<< dotProduct << endl;

    vector3D cross_product = vec1.cross(vec2);
    cout<<"cross product is:";
    cross_product.print();

    vector3D scalar = vec2 * 3.0;
    cout<<"scalar  multiplication output is :";
    scalar.print();

    vector3D normalized = vec2.normalize();
    cout<<"Normalized vector is:";
    normalized.print();

    return 0;
}

