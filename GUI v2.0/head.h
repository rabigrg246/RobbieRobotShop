#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>


const int bsize = 36; // size of each square button in pixels


class Head : public Fl_Pack {
public:
	Head(int X, int Y, int W, int H) :Fl_Pack(X, Y, W, H) {
		type(Fl_Pack::HORIZONTAL);    // horizontal packing of buttons
		box(FL_UP_FRAME);          // Default up, down & then up when clicked
		spacing(10);            // spacing between buttons in pixels
		end();
	}

	// Add a button to the toolbar - *name is the tooltip, *img is the loaded picture,
	//   *cb is the callback handler, and *data is the void* data for the callback
	void AddButton(const char *name, Fl_PNG_Image *img = 0,
		Fl_Callback *cb = 0, void *data = 0) {
		begin();
		Fl_Button *b = new Fl_Button(0, 0, bsize, bsize);
		b->box(FL_UP_BOX);    // buttons won't have 'edges'
		b->clear_visible_focus();
		if (name) b->tooltip(name);
		if (img) b->image(img);
		if (cb) b->callback(cb, data);
		end();
	}
};
