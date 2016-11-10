#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <iostream>

using namespace std;

const int bsize = 64; 

class Head : public Fl_Pack {
public:
    Head(int X,int Y,int W,int H):Fl_Pack(X,Y,W,H) {
      type(Fl_Pack::HORIZONTAL);    
      box(FL_UP_FRAME);         
      spacing(10);           
      end();
    }

    void AddButton(const char *name, Fl_PNG_Image *img=0,Fl_Callback *cb=0, void *data=0) {
        begin();
          Fl_Button *b = new Fl_Button(0,0,bsize,bsize);
          b->box(FL_UP_BOX);   
          b->clear_visible_focus();
          if ( name ) b->tooltip(name);
          if ( img  ) b->image(img);
          if ( cb   ) b->callback(cb,data);
        end();
    }
}; 
void antennae_CB(Fl_Widget*,void*) {
    cout << "Head Antennae.." << endl;
} 
void asymmetric_CB(Fl_Widget*,void*) {
    cout << "Head Asymmetric" << endl;
} 
void orange_CB(Fl_Widget*,void*) {
    cout << "Head Orange" << endl;
} 
void satellite_CB(Fl_Widget*,void*) {
    cout << "Head Satellite" << endl;
} 
void smart_CB(Fl_Widget*,void*) {
    cout << "Head Smart" << endl;
} 
void soldier_CB(Fl_Widget*,void*) {
    cout << "Head Soldier" << endl;
} 
int main() {
    // Create Window
    Fl_Window win(720,400,"Head Demo");
    win.begin();

      // Load toolbar button images
      Fl_PNG_Image *antennae_png = new Fl_PNG_Image{"head_antennae.png"};
      Fl_PNG_Image *asymmetric_png = new Fl_PNG_Image{"head_asymmetric_antenna.png"};
      Fl_PNG_Image *orange_png  = new Fl_PNG_Image{"head_orange.png"};
      Fl_PNG_Image *satellite_png = new Fl_PNG_Image{"head_satellite_dish.png"};
      Fl_PNG_Image *smart_png = new Fl_PNG_Image{"head_smart.png"};
      Fl_PNG_Image *soldier_png = new Fl_PNG_Image{"head_soldier.png"};

      // Create the toolbar
      Head head(0,0,win.w(),bsize);
      head.AddButton("Head Antennae", antennae_png, antennae_CB);
      head.AddButton("Head Asymmetric", asymmetric_png, asymmetric_CB);
      head.AddButton("Head Orange", orange_png, orange_CB);
      head.AddButton("Head Satellite", satellite_png, satellite_CB);
      head.AddButton("Head Smart", smart_png, smart_CB);
      head.AddButton("Head Soldier", soldier_png, soldier_CB);
    win.end();
    win.show();
    return(Fl::run());
}
