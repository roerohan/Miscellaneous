#include<fstream.h>
#include<conio.h>
#include<stdio.h>

 ofstream f1;
 ifstream f2;

 int n=0;                 //for choice in main menu
 int pau=0,exi=0,gt=0,re=0;    //gt= for 1st game winning(for stats)
			       //re=to display intro once
 class chr
  {
    char a[9][6];
    public:
    void print(int , int);
    void game();
    int win();
    void display();

  }s1,s2;

 class stat
  {
    int winco , losco;
    public :
    void match(int ,int );
    void matchdis();
  }ab;

 void stat::match(int abw=0,int abl=0)
  {
    f1.open("jimin",ios::binary||ios::cur);
    if(gt==0)
      {
	ab.winco=0 ;
	ab.losco=0;
      }
    else
      {
	ab.winco=ab.winco+abw;      //player 1
	ab.losco=ab.losco+abl;      //player 2
      }
    f1.write((char*)&ab,sizeof(ab));
    f1.close();
  }
  void stat::matchdis()
  {
    clrscr();
    f2.open("jimin",ios::binary||ios::cur);
    while(f2.read((char*)&ab,sizeof(ab)))
	 {
	   cout<<"\n\nNO. OF GAMES WON BY PLAYER 1 : "<<ab.winco<<endl;
	   cout<<"\n\nNO. OF GAMES WON BY PLAYER 2 : "<<ab.losco<<endl;
	 }
    f2.close();
    cout<<"\n\nPRESS ANY KEY TO RETURN BACK TO THE MAINMENU "<<endl;
  }
  void rules()
    {
      clrscr();
      cout<<"\n\n\t\t\tWELCOME"<<endl;
      cout<<"   ABOUT THE GAME :"<<endl;
      cout<<" 1. The gameplay takes place in a 9x6 matrix generalized to 2 players only."<<endl;
      cout<<" 2. All cells are initially empty. Player 1 and Player 2 take turns to place \n    0 or 1 in their cells respectively."<<endl;
      cout<<" 3. As a result, to each of the adjacent cells, 0's or 1's are added depending\n    upon the player number."<<endl;
      cout<<" 4. When a 0 cell explodes and there are 1 cells around, the 1 cells are            converted to 0 and vice-versa."<<endl;
      cout<<" 5. The winner is the one who eliminates the component's cells."<<endl;
      cout<<"    RULES-"<<endl;
      cout<<" 1. PRESS 'g' TO FILL NO. INTO THE CELLS."<<endl;
      cout<<" 2. USE\n   w=UP\n   s=DOWN\n   a=LEFT\n   d=RIGHT\n YOU CAN PRESS w,a,s,d TOGETHER TO SKIP CELLS.\n for eg, if you want to go 3 cells up, press w 3 times continuously."<<endl;
      cout<<" 3. TO PAUSE THE GAME PRESS 'p'."<<endl;
      cout<<" 4. TO EXIT THE GAME PRESS 'e'."<<endl;
      cout<<"\nPRESS ANY KEY TO RETURN BACK TO THE MAINMENU "<<endl;
    }
  void mainmenu()
    {
      clrscr();
      if(re==0)
	{
	  cout<<"  \n\n\n\n\n\n\n\n      \t \t\t  WELCOME TO CHAIN REACTION "<<endl;
	  cout<<" \n\n\n\n\n\n\n\n\n\n   PRESS ANY KEY TO GO TO THE MAIN MENU";
	  getch();re++;
	  clrscr();
	}
      cout<<"           \n\n\n     CHOOSE THE FOLLOWING\n "<<endl;
      if(pau==0||exi!=0)
	{
	   cout<<"          1. RULES"<<endl;
	   cout<<"          2. PLAY NEW GAME "<<endl;
	}
      cout<<"          3. STATISTICS\n          4. EXIT\n          CHOICE : "<<endl;
      int z=0;
      do
	{
	   cin>>n;
	   switch(n)
	    {
	      case 1  : rules();
			getch();
			mainmenu();
			break;
	      case 2  : if(pau==0)
			  {
			    s1.game();
			    break;
			  }break;
	      case 3  : ab.matchdis();
			getch();
			mainmenu();
			break;
	      case 4  : exi++;
	      default : z++;break;
	    }
	   if(z!=0)
	   break;
	 }
      while(n!=4);
  }

 void chr::print(int r=20,int c=20)
    {
      clrscr();
      int i,j;
      for(i=0;i<9;i++)
	 {
	   for (j=0;j<6;j++)
	       {cout<<"\t     ";
		if(i==r&&j==c)
		  cout<<"# ";
		else
		  cout<<a[i][j]<<' ';
	       }
	   cout<<endl<<"\n";
	 }
    }

 int chr::win()
    {
      int i,j,x=0,y=0,won=0;
      for(i=0;i<9;i++)
	 {
	  for (j=0;j<6;j++)
	      {
	       if(a[i][j]=='1')
		 x++;
	       else if(a[i][j]=='2')
		 y++;
	      }
	 }
      won=x>=54?1:(y>=54?2:0);
      return won;
    }

 void chr::game()
   {
     clrscr();
     char ch;
     int i,j,fl=1,abw=0,abl=0;
     for(i=0;i<9;i++)
	{
	  for (j=0;j<6;j++)
	  a[i][j]='_';
	}
     for(int k=1;;k++)
	{
	  if(win()==1)
	    {
	      cout<<"Player 1 WINS";
	      getch();
	      abw++; gt++;
	      ab.match(abw); mainmenu();
	      break;
	    }
	  else if(win()==2)
	    {
	      cout<<"Player 2 WINS";
	      getch();
	      abl++; gt++;
	      ab.match(0,abl);mainmenu();
	      break;
	    }
	  int r=8,c=0,ex=0,p;
	  ch='0';
	  while(ex==0 && ch!='g)
	       {
		cout<<"\n  w=UP , s=DOWN , a=LEFT , d=RIGHT"<<endl;
		cout<<"  p=PAUSE , e=Exit "<<endl;
		if(!(fl%2==0))
		   cout<<"\n  PLAYER 1 ";
		else
		   cout<<"  PLAYER 2 ";
		cout<<"\n  CHOICE : ";
		cin>>ch;
		switch(ch)
		    {
		     case 'w':if(r>0)
			      r--;   //checking write else invalid move in all cases
			      break;
		     case 'a':if(c>0)
			      c--;
			      break;
		     case 'd':if(c<5)
			      c++;
			      break;
		     case 's':if(r<8)
			      r++;
			      break;
		     case 'p':clrscr();
			      char d;
			      cout<<"\n\n\n\n\n             PRESS ANY KEY TO RESUME \n\n                      OR\n\n              PRESS $ TO RETURN TO THE MAIN MENU "<<endl;
			      cin>>d;
			      if(d=='$')
			       mainmenu();
			      break;
		     case 'e':ex++;
			      exi++;
			      mainmenu();
			      break;
		     default :break;
		  }
		   if(ex==0&&exi==0)
		   print(r,c);
		   else
		   break;
		}
	  if(ch=='g')
	    {
	      for(i=r-1;i<=r+1;i++)
		 {
		   for(j=c-1;j<=c+1;j++)
		      {
		       if(i>=0&&i<9&&j>=0&&j<6)
			 {
			  if(fl%2==0)
			    a[i][j]='2';
			  else
			    a[i][j]='1';
			 }
		      }
		 }
	     }
	  if (ex==0&&exi==0)
	     print();
	  else
	    break;

	  fl++;
	
	}
  }
void main()
{
  clrscr();
  mainmenu();
  getch();
}





