
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Radio_Button.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Bar.H>

using namespace std;

//for debugging only. (for now)
int counter = 0; //button_press_counter
bool is_active = true; //status_of_menu_items
//

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
	if (is_active)
		is_active = false;
	else
		is_active = true;


	cout << "Button_pressed " << counter << " times." << endl;
	cout << "Button status = " << is_active << " ." << endl;

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
