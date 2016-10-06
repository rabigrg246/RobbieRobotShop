 #ifndef __ELEVATOR_H
 #define __ELEVATOR_H 2016
 class Elevator {
   public:
     Elevator(int max_floors) : top_floor(max_floors),
       current_floor(1), desired_floor(1),
       going_up(true), idle(false) {}
     Elevator() : Elevator(9) {}

     class Invalid_floor {}; // Exception
     void goto_floor(int floor);
     void move();

     int get_current_floor();
     int get_desired_floor();
     bool is_going_up();
     bool has_arrived();
     bool is_idle();

   private:
     int top_floor;
     int current_floor;
     int desired_floor;
     bool going_up;
     bool idle;
 };
 #endif
