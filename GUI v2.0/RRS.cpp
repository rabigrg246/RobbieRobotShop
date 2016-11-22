/*RRS v2.0 GUI
Authors: Anil Poudel and Rabi Gurung
*/


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Text_Display.H>


using namespace std;


//Begin Main Window
Fl_Window win(800, 600, "Robbie Robot Shop");



//DECLARATIONS

void create_partCB(Fl_Window *g, void*);
Fl_Window *dialog;
Fl_Window *rm_dialog;
Fl_Window *order_dialog;
Fl_Window *brow;
Fl_Box *box1;
Fl_Box *box2;
Fl_Box *box3;
Fl_Box *box4;
Fl_Box *box5;
Fl_Box *box6;
Fl_Box *box7;
Fl_Box *box8;
Fl_Input *rp_name;
Fl_Input *rp_number;
Fl_Input *rp_type;
Fl_Input *rp_weight;
Fl_Input *rp_cost;
Fl_Input *rp_img;
Fl_Input *rp_desc;
Fl_Input *rm_part1;
Fl_Input *rm_part2;
Fl_Input *rm_part3;
Fl_Input *rm_part4;
Fl_Input *rm_part5;
Fl_Input *rm_part6;
Fl_Input *rm_name;
Fl_Input *rm_number;
//


//PM Callbacks
void Button_RPart(Fl_Widget *pm_win, void*)
{
	dialog = new Fl_Window(400,400,"Create Robot Part");
	rp_name = new Fl_Input(120, 10, 210, 25, "Name: ");
		rp_name->align(FL_ALIGN_LEFT);
	
		rp_number = new Fl_Input(120, 40, 210, 25, "Part Number: ");
		rp_number->align(FL_ALIGN_LEFT);
		rp_type = new Fl_Input(120, 70, 210, 25, "Type: ");
		rp_type->align(FL_ALIGN_LEFT);
		rp_weight = new Fl_Input(120, 100, 210, 25, "Weight: ");
		rp_weight->align(FL_ALIGN_LEFT);
		rp_cost = new Fl_Input(120, 130, 210, 25, "Cost: ");	
		rp_cost->align(FL_ALIGN_LEFT);
		rp_img = new Fl_Input(120, 160, 210, 25, "Image Name: ");
		rp_img->align(FL_ALIGN_LEFT);	
		rp_desc = new Fl_Multiline_Input(120, 190, 210, 75, "Description: ");
		rp_desc->align(FL_ALIGN_LEFT);
		Fl_Button *rp_create = new Fl_Button(145, 330, 120, 25, "Create");
		rp_create->callback((Fl_Callback*) create_partCB, 0);
		dialog->end();
		dialog->show();
};

//CREATE PART CALLBACK
void create_partCB(Fl_Window *g, void*)
{
	fstream file("datafile.csv", ios::in | ios::out | ios::app);
	
	if(file.is_open())
	{
		file << rp_name->value() << " " << rp_number->value() << " " << rp_type->value() << " " << rp_weight->value() << " " << rp_cost->value() << " " << rp_img->value() << " " << 
			rp_desc->value() << "\n";
	}
	file.close();
	dialog->hide();
	
};
//



// CREATE MODEL CALLNBACK
void create_modelCB(Fl_Widget *w, void*)
{
	fstream file2("datafile.csv", ios::in | ios:: out | ios::app);
	fstream file3("models.csv", ios::in | ios::out | ios::app);
			
	string name, number, type, weight, cost, img, desc;
	double tot_cost = 0.0;	

	while(file2 >> name >> number >> type >> weight >> cost >> img >> desc)
	{
		int money = (int) atoi(cost.c_str());
		if(name == rm_part1->value())
			tot_cost +=  money;
		if(name == rm_part2->value())
			tot_cost += money;		
		if(name == rm_part3->value())
			tot_cost += money;		
		if(name == rm_part4->value())
			tot_cost += money;
		if(name == rm_part5->value())
			tot_cost += money;		
		if(name == rm_part6->value())
			tot_cost += money;		
	}
	
	if(file3.is_open())
	{
		file3 << rm_name->value() << " " << rm_number->value() << " " << tot_cost << " "<< rm_part1->value() << " " << rm_part2->value() << " " << rm_part3->value() << " " << rm_part4->value() << " " << rm_part5->value() << " " << rm_part6->value() << "\n";
	}
	file2.close();
	file3.close();
	rm_dialog->hide();
	
}


//


void Button_RModel(Fl_Window *pm_win, void*)
{
		rm_dialog = new Fl_Window(600,400,"Create Robot Model");
	
		rm_name = new Fl_Input(200, 10, 210, 25, "Name: ");
		rm_name->align(FL_ALIGN_LEFT);
		rm_number = new Fl_Input(200, 40, 210, 25, "Model Number: ");
		rm_number->align(FL_ALIGN_LEFT);
		rm_part1 = new Fl_Input(200, 70, 210, 25, "Head Part Name: ");
		rm_part1->align(FL_ALIGN_LEFT);
		rm_part2 = new Fl_Input(200, 100, 210, 25, "Torso Part Name: ");
		rm_part2->align(FL_ALIGN_LEFT);
		rm_part3 = new Fl_Input(200, 130, 210, 25, "Left Arm Part: ");
		rm_part3->align(FL_ALIGN_LEFT);
		rm_part4 = new Fl_Input(200, 160, 210, 25, "Right Arm Part: ");
		rm_part4->align(FL_ALIGN_LEFT);
		rm_part5 = new Fl_Input(200, 190, 210, 25, "Locomotor Part Name: ");
		rm_part5->align(FL_ALIGN_LEFT);
		rm_part6 = new Fl_Input(200, 220, 210, 25, "Battery Part Name: ");
		rm_part6->align(FL_ALIGN_LEFT);
				
		Fl_Button *rm_create = new Fl_Button(245, 330, 120, 25, "Create");
		rm_create->callback((Fl_Callback*) create_modelCB,0);
		
		

		rm_dialog->end();
		rm_dialog->show();
};



//


// CREATE ORDER CALLBACK
void order_modelCB(Fl_Widget *w, void*)
{
	fstream file4("order.csv", ios::in | ios::out | ios::app);
	
	if(file4.is_open())
	{
		file4 << rm_name->value() << " " << rm_number->value() << " " << rm_part1->value() << " " << rm_part2->value() << " " << rm_part3->value() << "\n";
	}
	file4.close();
	order_dialog->hide();
	
}
//
//SA Callbacks
void Button_Order(Fl_Widget *sa_win, void*)
{
		order_dialog = new Fl_Window(600,300,"Create Robot Model");
	
		rm_name = new Fl_Input(200, 10, 210, 25, "Order Number: ");
		rm_name->align(FL_ALIGN_LEFT);
		rm_number = new Fl_Input(200, 40, 210, 25, "Model Name: ");
		rm_number->align(FL_ALIGN_LEFT);
		rm_part1 = new Fl_Input(200, 70, 210, 25, "Model Number: ");
		rm_part1->align(FL_ALIGN_LEFT);
		rm_part2 = new Fl_Input(200, 100, 210, 25, "Customer Name: ");
		rm_part2->align(FL_ALIGN_LEFT);
		rm_part3 = new Fl_Input(200, 130, 210, 25, "Date (MMDDYY): ");
		rm_part3->align(FL_ALIGN_LEFT);				
		Fl_Button *order_create = new Fl_Button(245, 230, 120, 25, "Order!");
		order_create->callback((Fl_Callback*) order_modelCB,0);
		
		order_dialog->end();
		order_dialog->show();

};

void Button_Bill(Fl_Window *sa_win, void*)
{
	fstream file("models.csv", ios::in | ios::out | ios::app);
	fstream file2("order.csv", ios::in | ios:: out | ios::app);
	
	Fl_Window *bill = new Fl_Window(800,600, "Bill Of Sale");
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20,20,760,560, "Bill of Sale");
	disp->buffer(buff);	
	bill->resizable(*disp);
	bill->show();	

	string model_name, name, number, onumber, cost, cname, date, mnum;
	string part1, part2, part3, part4, part5, part6, streeng;
	double tot_sale=0.0;
	
	streeng = "OrderNumber ModelName Price Customer Date\n";

	while(file2 >> onumber >> model_name >> mnum >> cname >> date)
	{
		while(file >> name >> number >> cost >> part1 >> part2 >> part3 >> part4 >> part5 >> part6 )
		{		
			if(name == model_name)
			{			
			int money = (int) atoi(cost.c_str());
			tot_sale += money;
			streeng = streeng + onumber+ "\t\t" + model_name+ "\t" + cost+ "\t" + cname+ "\t" + date + "\n";
			const char *c = streeng.c_str();
			buff->text(c);
			}
		}
	}
	file.close();
	file2.close();
};
//


//BC Callbacks
void Button_View_Order(Fl_Widget *bc_win, void*)
{
	fl_register_images();
	Fl_Window *catalog = new Fl_Window(800,600, "View Order");
	
	cout << "\t>> View Order" << endl;
	fstream file("order.csv", ios::in | ios:: out | ios::app);
	fstream file2("models.csv", ios::in | ios:: out | ios::app);
	fstream file3("datafile.csv", ios::in | ios:: out | ios::app);
	
	string model_name, part_name, testname, tempname, number, onumber, cost, cname, date, mnum;
	string part1, part2, part3, part4, part5, part6, streeng, type, weight, cost1, img, desc;
	int i=100,j=100, count=0;

	while(file >> onumber >> model_name >> mnum >> cname >> date)	//orders
	{
		while(file2 >> testname >> number >> cost >> part1 >> part2 >> part3 >> part4 >> part5 >> part6 ) //models
		{		
			if(testname == model_name)
			{
				while(file3 >> tempname >> number >> type >> weight >> cost1 >> img >> desc)
				{
					if(tempname == part1)
					{
					 i = 200; j = 100;
					 string img_src = img + ".jpg";
					 cout << "YES:: " << img_src << endl;
					 const char *c = streeng.c_str();
					 Fl_JPEG_Image jpeg(c);
					 Fl_Box head(i,j,100,100);
					 head.image(jpeg);
					}
					if(tempname == part2)
					{
					 i = 200; j =200;
					 string img_src = img + ".jpg";
					 const char *c = streeng.c_str();
					 Fl_JPEG_Image jpeg(c);
					 Fl_Box torso(i,j,100,100);
					 torso.image(jpeg);
					}
					if(tempname == part3)
					{
					 i = 100; j =200;
					 string img_src = img + ".jpg";
					 const char *c = streeng.c_str();
					 Fl_JPEG_Image jpeg(c);
					 Fl_Box larm(i,j,100,100);
					 larm.image(jpeg);
					}
					if(tempname == part4)
					{
					 i = 300; j =200;
					 string img_src = img + ".jpg";
					 const char *c = streeng.c_str();
					 Fl_JPEG_Image jpeg(c);
					 Fl_Box rarm(i,j,100,100);
					 rarm.image(jpeg);
					}	
					if(tempname == part5)
					{
					 i = 200; j =300;
					 string img_src = img + ".jpg";
					 const char *c = streeng.c_str();
					 Fl_JPEG_Image jpeg(c);
					 Fl_Box loco(i,j,100,100);
					 loco.image(jpeg);
					}
					if(tempname == part6)
					{
					 i = 200; j =400;
					 string img_src = img + ".jpg";
					 const char *c = streeng.c_str();
					 Fl_JPEG_Image jpeg(c);
					 Fl_Box batt(i,j,100,100);
					 batt.image(jpeg);
					}
					
					count+=2;
				}	
							
			}
			
		}
	}
	catalog->end();
	catalog->show();
	file.close();
	file2.close();
	file3.close();
	
};



void Button_Browse(Fl_Window *bc_win, void*)
{         
        brow = new Fl_Window(800,600,"Browse Catalog");
	fl_register_images();

        Fl_JPEG_Image *robot1 = new Fl_JPEG_Image("robot1.jpg");	
        box1 = new Fl_Box(150,30,100,100);
        box1->image(robot1);
        
        Fl_JPEG_Image *robot2 = new Fl_JPEG_Image("robot2.jpg");	
        box2 = new Fl_Box(150,180,100,100);
        box2->image(robot2);

        Fl_JPEG_Image *robot3 = new Fl_JPEG_Image("robot3.jpg");	
        box3 = new Fl_Box(150,330,100,100);
        box3->image(robot3);

        Fl_JPEG_Image *robot4 = new Fl_JPEG_Image("robot4.jpg");	
        box4 = new Fl_Box(150,480,100,100);
        box4->image(robot4);
        
        Fl_JPEG_Image *robot5 = new Fl_JPEG_Image("robot5.jpg");	
        box5 = new Fl_Box(500,30,100,100);
        box5->image(robot5);
        
        Fl_JPEG_Image *robot6 = new Fl_JPEG_Image("robot6.jpg");	
        box6 = new Fl_Box(500,180,100,100);
        box6->image(robot6);

        Fl_JPEG_Image *robot7 = new Fl_JPEG_Image("robot7.jpg");	
        box7 = new Fl_Box(500,330,100,100);
        box7->image(robot7);

        Fl_JPEG_Image *robot8 = new Fl_JPEG_Image("robot8.jpg");	
        box8 = new Fl_Box(500,480,100,100);
        box8->image(robot8);
        
brow->end();
brow->show();

	
	
};




///Main Callback
void Button_PM(Fl_Widget *win, void*)
{
	Fl_Window *pm_win = new Fl_Window(400, 400, "RRS - Logged in As Product Manager:");
	
	Fl_Button *rp = new Fl_Button(100,30,200,100,"Create Robot Part");
	Fl_Button *rm = new Fl_Button(100,180,200,100,"Create Robot Model");
	
	pm_win->end();

	rp->callback((Fl_Callback*) Button_RPart);
	rm->callback((Fl_Callback*) Button_RModel);
	pm_win->show();

};


void Button_SA(Fl_Widget *win, void*)
{
	Fl_Window *sa_win = new Fl_Window(400, 400, "RRS - Logged in As Sales Associate:");
	
	Fl_Button *odr = new Fl_Button(100,30,200,100,"Order Robot Model");
	Fl_Button *bill = new Fl_Button(100,180,200,100,"Bill Of Sale");
	
	sa_win->end();

	odr->callback((Fl_Callback*) Button_Order);
	bill->callback((Fl_Callback*) Button_Bill);
	sa_win->show();

};


void Button_BC(Fl_Widget *win, void*)
{	
	Fl_Window *bc_win = new Fl_Window(400, 500, "RRS - Logged in As Beloved Customer:");
	
	Fl_Button *browse = new Fl_Button(100,30,200,100,"Browse Robot Catalog");
	Fl_Button *vodr = new Fl_Button(100,180,200,100,"View my Order");
	Fl_Button *cbill = new Fl_Button(100,330,200,100,"View my Bill");
	
	bc_win->end();

	browse->callback((Fl_Callback*) Button_Browse);
	vodr->callback((Fl_Callback*) Button_View_Order);
	cbill->callback((Fl_Callback*) Button_Bill);
	bc_win->show();

};

void Button_Boss(Fl_Widget *win, void*)
{
	Fl_Window *boss_win = new Fl_Window(400, 400, "RRS - Logged in As BossMan");
	
	Fl_Button *order = new Fl_Button(100,30,200,100,"View Orders");
	Fl_Button *sales = new Fl_Button(100,180,200,100,"Sales Report");
	
	boss_win->end();

	order->callback((Fl_Callback*) Button_View_Order);
	sales->callback((Fl_Callback*) Button_Bill);
	boss_win->show();
};

//






//MAIN FUNCTION
int main()
{
	fl_register_images(); //initialize image library

	Fl_Box box(15,15,800,600);	
	Fl_JPEG_Image jpg("test.jpg");
	box.image(jpg);
	

	Fl_Button *pm = new Fl_Button(400,30,200,100,"Product Manager");
	Fl_Button *sa = new Fl_Button(400,180,200,100,"Sales Associate");
	Fl_Button *bc = new Fl_Button(400,330,200,100,"Customer");
	Fl_Button *boss = new Fl_Button(400,480,200,100,"Boss");
	

	win.end();

	pm->callback((Fl_Callback*) Button_PM);

	sa->callback((Fl_Callback*) Button_SA);

	bc->callback((Fl_Callback*) Button_BC);

	boss->callback((Fl_Callback*) Button_Boss);
	
	win.show();
	return Fl::run();
}
