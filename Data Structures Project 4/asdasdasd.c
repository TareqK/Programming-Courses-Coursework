#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "sorts.h"
#include <curses.h>
#include <menu.h>
#include <time.h>
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4
int powers[]={0,0,0,0,0,0,0};
int sorts[]={0,0,0,0,0,0,0};
int values[]={1000,10000,100000,200000,500000,1000000,2000000,};
int selectedFile;
void *funcs[]={BubbleSort,InsertionSort,RadixSort,HeapSort,ShellSort,MergeSort,QuickSort};
void func(WINDOW *,char *);
void quit();
void zeroing();
void order();
void reverse();
void Random();
double result[7][7];

char* choices[]={ 
	
	"Bubble","Insertion","Radix","Heap","Shell","Merge","Quick"," All",
				};
	
char* choices2[]={
	"1000" , "10 000" , "100 000" ,"200 000","500 000" ,"1 000 000", "2 000 000","All ",
	};

char* choices3[]={"In Order","Reverse","Random","EXIT"};

 int main()
 
 {
	
	 zeroing();
	 WINDOW* my_win1,*my_win2,*my_win3; 
	 ITEM** my_items,**my_items2,**my_items3;
	 int c;
	 MENU* my_menu,*my_menu2,*my_menu3;
	 int n_choices,i,n_choices2,n_choices3;
	 int counterY=0;
	 initscr();
	 cbreak();
	 noecho();
	

	 keypad(stdscr,TRUE);//initializng the screen
	 
	 n_choices=ARRAY_SIZE(choices);
	 my_items=(ITEM**)calloc(n_choices+1,sizeof(ITEM*));//creating an array of items 
	 
	 n_choices2=ARRAY_SIZE(choices2);
	 my_items2=(ITEM**)calloc(n_choices2+1,sizeof(ITEM*));
	 
	  n_choices3=ARRAY_SIZE(choices3);
	 my_items3=(ITEM**)calloc(n_choices3+1,sizeof(ITEM*));
	 
	 for(i=0;i<n_choices;i++)//initializing the array of items
 {
	 my_items[i]=new_item(choices[i],choices[i]);
	 my_items[n_choices] = (ITEM*)NULL;
 }
 
 for(i=0;i<n_choices2;i++)
 {
	 my_items2[i]=new_item(choices2[i],choices2[i]);
	 my_items[n_choices2]=(ITEM*)NULL;
 }
 
  for(i=0;i<n_choices3;i++)
 {
	 my_items3[i]=new_item(choices3[i],choices3[i]);
	 my_items3[n_choices3]=(ITEM*)NULL;
	 
 }
set_item_userptr(my_items3[0], order);
set_item_userptr(my_items3[1], reverse);
set_item_userptr(my_items3[2], Random);
 set_item_userptr(my_items3[3], quit);
 my_menu = new_menu((ITEM **)my_items);//creating the menu
menu_opts_off(my_menu, O_SHOWDESC);//making the menu not show titles
menu_opts_off(my_menu, O_ONEVALUE);//making the menu a toggle menu
set_menu_format(my_menu, 2,4);//formating the menu

my_menu2=new_menu((ITEM**)my_items2);
menu_opts_off(my_menu2, O_SHOWDESC);//making the menu not show titles
menu_opts_off(my_menu2, O_ONEVALUE);//making the menu a toggle menu
set_menu_format(my_menu2,2,4);//formating the menu

my_menu3=new_menu((ITEM**)my_items3);
menu_opts_off(my_menu3, O_SHOWDESC);//making the menu not show titles
set_menu_format(my_menu3, 0,4);//formating the menu



 
 

	
	/* Set main window and sub window */
        set_menu_win(my_menu, stdscr);
        set_menu_sub(my_menu, derwin(stdscr, 5, 80,0 , 0));
         set_menu_mark(my_menu, " * ");
         
       
        set_menu_win(my_menu2,stdscr);
        set_menu_sub(my_menu2, derwin(stdscr,5, 80,5 , 0));
        set_menu_mark(my_menu2, " * ");
        
        set_menu_win(my_menu3,stdscr);
        set_menu_sub(my_menu3,derwin(stdscr,5, 80,10 , 0));
        set_menu_mark(my_menu3," * ");
        
             

        post_menu(my_menu);

        post_menu(my_menu2);
		post_menu(my_menu3);
		mvprintw(20,0,"Welcome! Please make your selections!");
		refresh();
		getch();
		
		
   
	
	
	/*do
	{
		mvwprintw(my_win3,3,0,"Welcome! Please make your selections!");
				refresh()
			if(counterY<2){
		    c = wgetch(my_win1);
		       switch(c)
	        {	case KEY_RIGHT:
				menu_driver(my_menu, REQ_RIGHT_ITEM);
				break;
			case KEY_LEFT:
				menu_driver(my_menu, REQ_LEFT_ITEM);
				break;
			case ' ':
				menu_driver(my_menu, REQ_TOGGLE_ITEM);
				break;
			case KEY_DOWN:
				counterY++;
				menu_driver(my_menu,REQ_DOWN_ITEM);
			break;
			case KEY_UP:
				if(counterY!=0){
				counterY--;
		}
			menu_driver(my_menu,REQ_UP_ITEM);
				
				break;
			}
			
		}
			
		else{
		if(counterY==2)
		{
			wmove(my_win2,0,0);
		}
		if(counterY>=2&&counterY<=3){
		 c = wgetch(my_win2);
		 switch(c)
	        {	case KEY_RIGHT:
				menu_driver(my_menu2, REQ_RIGHT_ITEM);
				break;
			case KEY_LEFT:
				menu_driver(my_menu2, REQ_LEFT_ITEM);
				break;
			case ' ':
				menu_driver(my_menu2, REQ_TOGGLE_ITEM);
				break;
			case KEY_UP:
			counterY--;
			if(counterY==1){
			wmove(my_win1,0,0);
		}
			menu_driver(my_menu2,REQ_UP_ITEM);
			break;
			case KEY_DOWN:
			counterY++;
		
			menu_driver(my_menu2,REQ_DOWN_ITEM);
		}
	}
		else{
		if(counterY==4)
		{
			wmove(my_win3,0,0);
			
			c=wgetch(my_win3);
			switch(c){
			
			case KEY_UP:
			counterY--;
			wmove(my_win3,0,0);
			break;
			
			case KEY_LEFT:
			menu_driver(my_menu3,REQ_LEFT_ITEM);
			break;
			
			case KEY_RIGHT:
			menu_driver(my_menu3,REQ_RIGHT_ITEM);
			break;
			
			case 10: /* Enter 
			{	ITEM *cur;
				void (*p)();

				
				for(i = 0; i < 7; i++){
					if(item_value(my_items[i]) == TRUE ){
						sorts[i]=1;
					}
					else
					{
						sorts[i]=0;
					}
				}
					if(item_value(my_items[7]) ==TRUE)
					{
							int j;
						for(j=0;j<7;j++)
						{
							sorts[j]=1;
							
						}
					}
					
				
				
					for(i = 0; i < 7; i++){
					if(item_value(my_items2[i]) == TRUE ){
						powers[i]=1;
					}
					else
					{
						powers[i]=0;
					}
				}
					if(item_value(my_items2[7]) ==TRUE)
					{
							int j;
						for(j=0;j<7;j++)
						{
							powers[j]=1;
							
						}
					}
				cur = current_item(my_menu3);
				p = item_userptr(cur);
				p();
				pos_menu_cursor(my_menu3);
			
				
				break;
				
				
			}
		}
		}
		
		
	}
	
		
	}		
refresh();

}while(1);
*/





	/* Unpost and free all the memory taken up */
        unpost_menu(my_menu);
        free_menu(my_menu);
        for(i = 0; i < n_choices; ++i)
                free_item(my_items[i]);
                
        unpost_menu(my_menu2);
        free_menu(my_menu2);
        for(i = 0; i < n_choices2; ++i)
                free_item(my_items2[i]);
                
        unpost_menu(my_menu3);
        free_menu(my_menu3);
        for(i = 0; i < n_choices3; ++i)
                free_item(my_items3[i]);
              
	endwin();
}

void quit(){
	endwin();
	exit(0);
}

void zeroing()
{
	int i,j;
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			result[i][j]=0;
		}
	}
}
void printResult()
{
	FILE *out;
	switch(selectedFile){
	case 0:
	out=fopen("Ordered.csv","w");
	break;
	case 1:
	out=fopen("Random.csv","w");
	break;
	case 2:
	out=fopen("Reverse.csv","w");
	break;
	default:	
	out=fopen("output.csv","w");
	break;
}
	scr_dump("screen");
	clear();
	refresh();
	int i,j,x,y;
	float t;
	int exp;
	fprintf(out," n,Bubble,Insertion,Radix,Heap,Shell,Merge,Quick, \n");
	mvprintw(0,0,"n ");
	mvprintw(0,10,"Bubble");
	mvprintw(0,20,"Insertion");
	mvprintw(0,30,"Radix");
	mvprintw(0,40,"Heap");
	mvprintw(0,50,"Shell");
	mvprintw(0,60,"Merge");
	mvprintw(0,70,"Quick");
	
	
	mvprintw(1,0,"1000");
	mvprintw(2,0,"10000");
	mvprintw(3,0,"100000");
	mvprintw(4,0,"200000");
	mvprintw(5,0,"500000");
	mvprintw(6,0,"1000000");
	mvprintw(7,0,"2000000");
	
	for(i=0;i<7;i++){
		
		fprintf(out,"%d,",values[i]);
		for(j=0;j<7;j++){
			y=i+1;
			x=10+(j*10);
			t=result[i][j];
			exp=0;
			if(t>10){
			while(t>10){
			t=t/10;
			exp++;
			}
		}
		else if(t<1&&t>0.000000001)
		{
			while(t<1)
			{
				t=t*10;
				exp--;
			}
		}
		mvprintw(y,x,"%0.1f*10^%1d",t,exp);
		doupdate();
		fprintf(out,"%f*10^%d,",t,exp);
		
	}
	fprintf(out,"\n");
				
		}
		mvprintw(15,0,"Output has been print to File. Press any key to return");
		
		getch();
		
		
		clear();
		refresh();
		fclose(out);
		scr_restore("screen");
}

void order()
{
	int i,j;
	clock_t t;
	int* a;
	
	
	for(i=0;i<7;i++)
	{
		if(sorts[i]==1)
		{	
			for(j=0;j<7;j++){
				
			if(powers[j]==1){
			
			a=(int*)calloc(values[j],sizeof(int));
			initInOrder(a,values[j]);
			
			if(i<5){
			void (*p)(int*,int);
			p=funcs[i];
			 t = clock();
			p(a,values[j]);
			 t = clock()-t;
			double time_taken = ((double)t)/CLOCKS_PER_SEC; 
			result[j][i]=time_taken;
			}
			
			else{
			void (*p)(int*,int,int);
			p=funcs[i];
			t = clock();
			p(a,0,values[j]-1);
			 t = clock()-t;
			 double time_taken = ((double)t)/CLOCKS_PER_SEC; 
			result[j][i]=time_taken;
			
			free(a);
		}
		
			
			
			 
			
			
			}	
}
}}



	
		
	selectedFile=0;
	printResult();
	zeroing();
	
}

void Random()
{
	int i,j;
	clock_t t;
	int* a;
	
	
	for(i=0;i<7;i++)
	{
		if(sorts[i]==1)
		{	
			for(j=0;j<7;j++){
				
			if(powers[j]==1){
			
			a=(int*)calloc(values[j],sizeof(int));
			initRandom(a,values[j]);
			
			if(i<5){
			void (*p)(int*,int);
			p=funcs[i];
			 t = clock();
			p(a,values[j]);
			 t = clock()-t;
			double time_taken = ((double)t)/CLOCKS_PER_SEC; 
			result[j][i]=time_taken;
			}
			
			else{
			void (*p)(int*,int,int);
			p=funcs[i];
			t = clock();
			p(a,0,values[j]-1);
			 t = clock()-t;
			 double time_taken = ((double)t)/CLOCKS_PER_SEC; 
			result[j][i]=time_taken;
			
			free(a);
		}
		
			
			
			 
			
			
			}	
}
}}



	
		
	selectedFile=1;
	printResult();
	zeroing();
	
}

void reverse()
{
	int i,j;
	clock_t t;
	int* a;
	
	
	for(i=0;i<7;i++)
	{
		if(sorts[i]==1)
		{	
			for(j=0;j<7;j++){
				
			if(powers[j]==1){
			
			a=(int*)calloc(values[j],sizeof(int));
			initReverseOrder(a,values[j]);
			
			if(i<5){
			void (*p)(int*,int);
			p=funcs[i];
			 t = clock();
			p(a,values[j]);
			 t = clock()-t;
			double time_taken = ((double)t)/CLOCKS_PER_SEC; 
			result[j][i]=time_taken;
			}
			
			else{
			void (*p)(int*,int,int);
			p=funcs[i];
			t = clock();
			p(a,0,values[j]-1);
			 t = clock()-t;
			 double time_taken = ((double)t)/CLOCKS_PER_SEC; 
			result[j][i]=time_taken;
			
			free(a);
		}
		
			
			
			 
			
			
			}	
}
}}



	
		
	selectedFile=2;
	printResult();
	zeroing();
	
}

