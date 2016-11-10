/*
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Radio_Button.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Bar.H>

#include "Customer.h"

using namespace std;

//for debugging only. (for now)
int counter = 0; //button_press_counter
string user = "";
//


Customer BC;




//Begin Widgets
Fl_Double_Window *win;
Fl_Menu_Bar *menubar;


//Callbacks
void exit_button(Fl_Widget *win, void *p)
{
	cout << "Exit" << endl;
	exit(0);
};

void other_button(Fl_Widget *win, void *p)
{
	counter++;
	//Testing for button-clicks
	cout << "Button_pressed " << counter << " times." << endl;
};
//End Callbacks


//Begin_MenuBar
Fl_Menu_Item menuitems[] =
{
	{ "&File", 0, 0, 0, FL_SUBMENU },
		{ "&New ", FL_ALT + 'n', (Fl_Callback *)other_button },
		{ "&Open ", FL_ALT + 'o', (Fl_Callback *)other_button },
		{ "&Save ", FL_ALT + 's', (Fl_Callback *)other_button },
		{ "Save &As ", FL_ALT + 'a', (Fl_Callback *)other_button },
		{ "Quit ", FL_ALT + 'q', (Fl_Callback *)exit_button },
		{ 0 },

	{ "&Edit", 0, 0, 0, FL_SUBMENU },
		{ "Undo ", FL_CTRL + 'z', (Fl_Callback *)other_button },
		{ "Cut ", FL_CTRL + 'x', (Fl_Callback *)other_button },
		{ "Copy ", FL_CTRL + 'c', (Fl_Callback *)other_button },
		{ "Paste ", FL_CTRL + 'v', (Fl_Callback *)other_button },
		{ 0 },

	{ "&Create", 0, 0, 0, FL_SUBMENU },
		{ "&Order ", 0, (Fl_Callback *)other_button, 0, FL_MENU_DIVIDER },
		{ "&Customer ", 0, (Fl_Callback *)other_button },
		{ "Sales &Associate ", 0, (Fl_Callback *)other_button, 0, FL_MENU_DIVIDER },
		{ "&Robot Part ", 0, (Fl_Callback *)other_button, 0, FL_MENU_INACTIVE },
		{ "&Robot Model ", 0, (Fl_Callback *)other_button, 0, FL_MENU_INACTIVE },
		{ 0 },

	{ "&Browse", 0, 0, 0, FL_SUBMENU },
		{ "&Parts Catalog   ", 0, (Fl_Callback *)other_button },
		{ "&Models Catalog  ", 0, (Fl_Callback *)other_button },
		{ 0 },

	{ "&Report", 0, 0, 0, FL_SUBMENU },
		{ "&Invoice   ", 0, (Fl_Callback *)other_button },
		{ 0 },

	{ "&Help", 0, 0, 0, FL_SUBMENU },
		{ "&About", 0, (Fl_Callback *)other_button },
	    { 0 }
								
};
//End_MenuBar

//Begin_MAIN
int main() {
	
	//set_resolution
	const int x = 800;
	const int y = 600;
	
	//TEST2
	int stat=0;
	cout << "Enter User:: " << endl;
	cin >> user;

	if (BC.is_active(user))
		Fl_Menu_Bar *item = menubar->find_item("Customer");

	else
		stat = 0;

	//


	//Main_Window
	win = new Fl_Double_Window(x, y, "Robbie Robot Shop Manager");
	win->color(FL_WHITE);
	win->resizable(win);
	win->size_range(400, 400, 1920, 1080);

	//install menu bar
	menubar = new Fl_Menu_Bar(0, 0, x, 20);
	menubar->menu(menuitems);
	
	//show window
	win->show();
	return(Fl::run());
}
*/

#include <FL/Fl.H> 
#include <FL/Fl_Window.H> 
#include <FL/Fl_Menu_Bar.H> 
#include <FL/Fl_Button.H> 

#include "head.h"

// 
// Demonstrate toggling the File -> Quit menu item (toggle 'graying it out') 
//LOGIN MENU
// 


Fl_Window *logon = new Fl_Window(300, 200);

// Make the menubar with a few menu items 
Fl_Menu_Bar *main_menubar;;

void main_window(int x)
{
	// Make the window 
	Fl_Window *win = new Fl_Window(800, 600);
	main_menubar = new Fl_Menu_Bar(0, 0, 400, 25);
	//
	main_menubar->add("File/Quit", 0, 0, 0);
	main_menubar->add("Create/Order", 0, 0, 0);
	main_menubar->add("Create/Sales Associate", 0, 0, 0);
	main_menubar->add("Create/Customer", 0, 0, 0);
	main_menubar->add("Create/Robot Part", 0, 0, 0);
	main_menubar->add("Create/Robot Model", 0, 0, 0);
	//
	if (x == 1)
		BC_CB(win, (void*)main_menubar);
	else if (x == 2)
		SA_CB(win, (void*)main_menubar);
	else
		PM_CB(win, (void*)main_menubar);

	win->end();
	win->show();
	Fl::run();
}


//
//CALLBACKS
//

//For Customer
void BC_CB(Fl_Widget *w, void *data) {
	logon->hide();
	Fl_Menu_Bar *menubar = (Fl_Menu_Bar*)data;
	Fl_Menu_Item *item = (Fl_Menu_Item*)menubar->find_item("Create/Customer");
	item->flags ^= FL_MENU_INACTIVE;

	item = (Fl_Menu_Item*)menubar->find_item("Create/Sales Associate");
	item->flags ^= FL_MENU_INACTIVE;

	item = (Fl_Menu_Item*)menubar->find_item("Create/Robot Part");
	item->flags ^= FL_MENU_INACTIVE;

	item = (Fl_Menu_Item*)menubar->find_item("Create/Robot Model");
	item->flags ^= FL_MENU_INACTIVE;
}


//For Sales Associate
void SA_CB(Fl_Widget *w, void *data) {
	logon->hide();
	Fl_Menu_Bar *menubar = (Fl_Menu_Bar*)data;

	Fl_Menu_Item *item = (Fl_Menu_Item*)menubar->find_item("Create/Sales Associate");
	item->flags ^= FL_MENU_INACTIVE;

	item = (Fl_Menu_Item*)menubar->find_item("Create/Robot Part");
	item->flags ^= FL_MENU_INACTIVE;

	item = (Fl_Menu_Item*)menubar->find_item("Create/Robot Model");
	item->flags ^= FL_MENU_INACTIVE;
}

//For Product Manager
void PM_CB(Fl_Widget *w, void *data) {
	logon->hide();
	Fl_Menu_Bar *menubar = (Fl_Menu_Bar*)data;

	Fl_Menu_Item *item = (Fl_Menu_Item*)menubar->find_item("Create/Order");
	item->flags ^= FL_MENU_INACTIVE;

	item = (Fl_Menu_Item*)menubar->find_item("Create/Customer");
	item->flags ^= FL_MENU_INACTIVE;

	item = (Fl_Menu_Item*)menubar->find_item("Create/Sales Associate");
	item->flags ^= FL_MENU_INACTIVE;
}





int main() {

	// Make a button to toggle the File/Quit menu item's activation state 
	Fl_Button *butt_bc = new Fl_Button(30, 50, 100, 25, "Customer");
	Fl_Button *butt_sa = new Fl_Button(30, 100, 100, 25, "SA");
	Fl_Button *butt_pm = new Fl_Button(30, 150, 100, 25, "PM");

	//Call Callbacks when pressed
	butt_bc->callback(main_window, 1);
	butt_sa->callback(main_window, 2);
	butt_pm->callback(main_window, 3);

	logon->end();
	logon->show();
	
	return(Fl::run());
}
