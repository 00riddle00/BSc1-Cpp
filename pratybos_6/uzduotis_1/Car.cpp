//: C14:Car.cp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Public composition
// modified by i.m. on 9 nov 2008
//
//
#include <iostream>
using namespace std;

class Vehicle {
    std::string make;
    std::string model;
    int price;
    bool moving;

    public:
        Vehicle(const std::string& ma, const std::string& mo, int pr, bool mv) 
            : make(ma), model(mo), price(pr), moving(mv) { 
              cout << "Vehicle object is created with given parameters" << endl;
            }

        ~Vehicle() {
            cout << "Vehicle object is destroyed" << endl;
        }
        void move() { moving = true; cout << "The vehicle is moving" << endl; }
        void stop() { moving = false; cout << "The vehicle stopped" << endl; }
};

class Engine {
    std::string identification;
    std::string type;
    float capacity;
    int rpm;
    bool is_running;
public:
  Engine(const std::string& id, const std::string& t, float cp, int r, bool run)
      : identification(id), type(t), capacity(cp), rpm(r), is_running(run) {
          cout << "Engine object is created with given parameters" << endl;
      }

    ~Engine() {
        cout << "Engine object is destroyed" << endl;
    }

  void start() { is_running = true; cout << "The engine has started" << endl; }
  void rev() const { cout << "The engine revolutions: " << rpm << " RPM" << endl; }
  void stop() { is_running = false; cout << "The engine has stopped" << endl; }
};

class Wheels {
    int diameter;
    int pressure;
    bool has_winter_tires;
public:
  Wheels(int d, int p, bool wt)
      : diameter(d), pressure(p), has_winter_tires(wt) {
          cout << "Wheels object is created with given parameters" << endl;
      }

    ~Wheels() {
        cout << "Wheels object is destroyed" << endl;
    }
  void inflate(int psi) { pressure = psi; cout << "The wheels are inflated to " << psi << " psi" << endl; }
};

class Window {
    bool is_open;
    bool is_tinted;
    bool has_sun_protection;
public:
  Window(bool op, bool tnt, bool sp) 
      : is_open(op), is_tinted(tnt), has_sun_protection(sp) {
          cout << "Window object is created with given parameters" << endl;
      }

    ~Window() {
        cout << "Window object is destroyed" << endl;
    }
  void rollup() { is_open = true; cout << "The window has been rolled up" << endl; }
  void rolldown() { is_open = false; cout << "The window has been rolled down" << endl; }
};

class Door {
    bool is_open;
public:
  Door(bool car_op, bool w_op, bool w_tnt, bool w_sp) 
      : is_open(car_op), window(w_op, w_tnt, w_sp) {
      cout << "Door object is created with given parameters" << endl;
  }
    ~Door() {
        cout << "Door object is destroyed" << endl;
    }

  Window window;
  void open() const { cout << "The door has been opened" << endl; }
  void close() const { cout << "The door has been closed" << endl; }
};

class Car : public Vehicle {
    std::string type;
public:
  Car(
      const string& v_ma,
      const string& v_mo,
      int v_pr,
      bool v_mv,
      const std::string& type,
      const std::string& e_id,
      const std::string& e_t,
      float e_cp,
      int e_r,
      bool e_run,
      int wh_d,
      float wh_p,
      bool wh_wt,
      bool ld_w_op,
      bool ld_w_tnt,
      bool ld_w_sp,
      bool ld_car_op,
      bool rd_w_op,
      bool rd_w_tnt,
      bool rd_w_sp,
      bool rd_car_op
  ) 
  : Vehicle(v_ma, v_mo, v_pr, v_mv), 
    type(type),
    engine(e_id, e_t, e_cp, e_r, e_run),
    wheels(wh_d, wh_p, wh_wt),
    left(ld_w_op, ld_w_tnt, ld_w_sp, ld_car_op),
    right(rd_w_op, rd_w_tnt, rd_w_sp, rd_car_op) {

      cout << "Car object is created with given parameters" << endl;
  }

    ~Car() {
        cout << "Car object is destroyed" << endl;
    }
  Engine engine;
  Wheels wheels;
  Door left, right; // 2-door
};

int main() {
          Car car(
               // Vehicle
              "BMW",
              "520",
              2000,
              false,

               // Car type
              "sedan",

              // Engine
              "JT0123123",
              "diesel",
              3.0,
              0,
              false,

              // Wheels
              15,
              2,
              false,

              // Left door
              false,
              true,
              false,
              false,

              // Right door
              false,
              true,
              false,
              false
          ); 
 
          cout << "---------------------------" << endl;

          car.left.window.rollup(); 
          car.wheels.inflate(72);
          cout << "===========[Vehicle inherited methods]============" << endl;
          car.move();
          car.stop();
          cout << "===========[/Vehicle inherited methods]===========" << endl;
          cout << "---------------------------" << endl;
} ///:~
