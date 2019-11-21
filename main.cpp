/* Vibhavi Jayasinghe
Teacher: Dr_T
Inheritace1_Jayasinghe
01-05-2019
*/

#include <iostream>
using namespace std;

class Polygon{ // base class parent
  protected: // child can access these
    int width, height, side;
  public:
    void set_values(int a, int b){
      width = a; height = b;
    }
    void set_values(int c){
      side = c;
    }
};

class Rectangle : public Polygon{
  public:
    int area(){return width * height;}
};

class Triangle : public Polygon{
  public:
    int area(){return width * height * 0.5;}
};

class Pentagon : public Polygon{
  public:
    double area(){
      return (1/4)*(5*(5+2*(5^(1/2))^(1/2)))*(side*side);
    }
};

class Decagon : public Pentagon{
  public:
    double area(){
      return (5/2)*(side^2)*((5+(2*((5)^(1/2))))^(1/2));
      //return 2.5 * pow(width,2.0)*sqrt(5.0+2.0*sqrt(5.0));
    }
};

class Vehicle{ //parent
  protected:
    string manufacturer;
  public:
    //write a default constructeor for the vehicle
    Vehicle(){manufacturer = "Default Manufacturer";}
    //Vehicle(string m){manufacturer = m;} //write a parametized constructor for the vehicle, long way
    Vehicle(string m) : manufacturer(m) {} //new style for parameterized constructor. Short way
    void setManufacturer(string m){
      manufacturer = m;
    }
};

class Car : public Vehicle{ //child
  private:
    char transmissionType; // A or M
    string engineType;
    string color;
    string driveType;
  public:
    //write a default constructer for the car
    Car() : Vehicle(){
      transmissionType = 'A';
      engineType = "V6";
      color = "White";
      driveType = "AWD";
    }
    //write a parametized constructor for the vehicle
    Car(char t, string e, string c, string d, string m): Vehicle(m){
      transmissionType = t;
      engineType = e;
      color = c;
      driveType = d;

      manufacturer = "Cars default manufacturer";
    }

    void setTransmissionType(char t){transmissionType = t;}
    char getTransmissionType() const {return transmissionType;}
    void setEngineType(string e){engineType = e;}
    string getEngineType() const {return engineType;}
    void setColor(string c){color = c;}
    string getColor() const {return color;}
    void setDriveType(string dt) {driveType = dt;}
    string getDriveType() const {return driveType;}

    
    

    //function to print the vehicle to screen
    void printCar(){
      cout << "\nCar Details" << endl;
      cout << "Transmission Type: " << getTransmissionType() << endl;
      cout << "Engine Type: " << getEngineType() << endl;
      cout << "Color: " << getColor() << endl;
      cout << "Drive Type: " << getDriveType() << endl;
      cout << "Manufacturer: " << manufacturer << endl; //protected variable
    }
};

int main() {
  Rectangle rect; //instantiated a child object
  Triangle trgl; //instantiated a child object
  Pentagon pent;
  Decagon deca;
  rect. set_values(4, 5); //call the parent's member
  trgl.set_values(4, 5); //call the parent's member
  pent.set_values(5);
  deca.Polygon::set_values(4,1); //calling the parent set values
  deca.set_values(4);
  cout << "Rectangle Area: " << rect.area() << endl; //call the child's area() member
  cout << "Triangle Area: " << trgl.area() << endl; //call the child's area() member
  cout << "Pentagon Area: " << pent.area() << endl;
  cout << "Decagon Area: " << deca.area() << endl;

  char t = '\0';
    string e = "", c = "", d = "", m = "";
    cout << "t [space] e [space] c [space] d [space] m: " << endl;
    cin >> t >> e >> c >> d >> m;
    Car(t,e,c,d,m); // call the paramertized constructor

  Car genesis;
  genesis.printCar(); // print the child

  return 0;
}