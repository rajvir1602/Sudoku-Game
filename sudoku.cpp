#include<iostream>
#include<fstream>
#include <string>
#include <windows.h>
#include<conio.h>
using namespace std;
class object{
	public:
	char d[9][9];
	int e[9][9];
	object()
	{
		for(int i=0;i<9;i++)
		{	for(int j=0;j<9;j++)
			{
				d[i][j] = 32;
				e[i][j] = 0;
			}
		}
		d[0][3]=50;d[0][7]=54;d[0][8]=51;d[1][0]=51;
		d[1][5]=53;d[1][6]=52;d[1][8]=49;d[2][2]=49;
		d[2][5]=51;d[2][6]=57;d[2][7]=56;d[3][7]=57;
		d[4][3]=53;d[4][4]=51;d[4][5]=56;d[5][1]=51;
		d[6][1]=50;d[6][2]=54;d[6][3]=51;d[6][6]=53;
		d[7][0]=53;d[7][2]=51;d[7][3]=55;d[7][8]=56;
		d[8][0]=52;d[8][1]=55;d[8][5]=49;
		e[0][3]=e[0][7]=e[0][8]=e[1][0]=e[1][5]=e[1][6]=e[1][8]=e[2][2]=e[2][5]=e[2][6]=e[2][7]=e[3][7]=e[4][3]=1;
		e[4][4]=e[4][5]=e[5][1]=e[6][1]=e[6][2]=e[6][3]=e[6][6]=e[7][0]=e[7][2]=e[7][3]=e[7][8]=e[8][0]=e[8][1]=e[8][5]=1;
	}
	object(char ch)
	{
		ifstream fp("file.txt",ios::in);
		int i,j;
		for(i=0;i<9;i++)
		{	for(j=0;j<9;j++)
			{
				fp>>ch;
				d[i][j]=ch;
			}
		}
	}
	object(char ch,char ch1)
	{
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
				d[i][j] = 32;

		d[0][0]=55;d[0][1]=57;d[0][6]=51;d[1][5]=54;
		d[2][0]=56;d[2][4]=51;d[2][7]=55;d[2][8]=54;
		d[3][5]=53;d[3][8]=50;d[4][2]=53;d[4][3]=52;
		d[4][4]=49;d[4][5]=56;d[4][6]=55;d[5][0]=52;
		d[5][3]=55;d[6][0]=54;d[6][1]=49;d[6][4]=57;
		d[6][8]=56;d[7][2]=50;d[7][3]=51;d[8][2]=57;
		d[8][7]=53;d[8][8]=52;d[1][6]=57;
		e[0][0]=e[0][1]=e[0][6]=e[1][5]=e[2][0]=e[2][4]=e[2][7]=e[2][8]=e[3][5]=e[3][8]=e[4][2]=e[4][3]=e[4][4]=1;
		e[4][5]=e[4][6]=e[5][0]=e[5][3]=e[6][0]=e[6][1]=e[6][4]=e[6][8]=e[7][2]=e[7][3]=e[8][2]=e[8][7]=e[8][8]=e[1][6]=1;
	}
	object(char ch,char ch1,char ch2)
	{
		ifstream fp("file1.txt",ios::in);
		int i,j;
		for(i=0;i<9;i++)
		{	for(j=0;j<9;j++)
			{
				fp>>ch;
				d[i][j]=ch;
			}
		}
	}
	object(int x)
	{
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
				d[i][j] = 32;

		d[0][0]=57;d[0][1]=54;d[0][4]=55;d[0][7]=53;
		d[0][8]=50;d[1][0]=55;d[1][1]=53;d[1][7]=52;
		d[1][8]=57;d[2][2]=52;d[2][6]=55;d[3][3]=51;
		d[3][5]=54;d[4][0]=49;d[4][4]=50;d[4][8]=56;
		d[5][3]=55;d[5][5]=53;d[6][2]=51;d[6][6]=52;
		d[7][0]=50;d[7][1]=55;d[7][7]=57;d[7][8]=51;
		d[8][0]=56;d[8][1]=52;d[8][4]=53;d[8][7]=54;d[8][8]=55;
		e[0][0]=e[0][1]=e[0][4]=e[0][7]=e[0][8]=e[1][0]=e[1][1]=e[1][7]=e[1][8]=e[2][2]=e[2][6]=e[3][3]=e[3][5]=e[8][4]=1;
		e[4][0]=e[4][4]=e[4][8]=e[5][3]=e[5][5]=e[6][2]=e[6][6]=e[7][0]=e[7][1]=e[7][7]=e[7][8]=e[8][0]=e[8][1]=e[8][7]=e[8][8]=1;
	}
	object(int x,int y)
	{
		char ch;
		ifstream fp("file2.txt",ios::in);
		int i,j;
		for(i=0;i<9;i++)
		{	for(j=0;j<9;j++)
			{
				fp>>ch;
				d[i][j]=ch;
			}
		}
	}
	int insert(int &row,int &col,int &value)
	{
		cout<<"\nEnter the row\t";
		cin>>row;
		if(row == 0)
			return 0;
		cout<<"Enter the column   ";
		cin>>col;
		if(col == 0)
			return 0;
		cout<<"Enter the value you want to insert   ";
		cin>>value;
		if(value == 0)
			return 0;
		if(((row<=9)&&(row>0))&&((row<=9)&&(row>0))&&((value<=9)&&(value>=1)))
		{
			if(e[row-1][col-1]==1)
				return -1;
			else
				d[row-1][col-1]=value+48;
		}
		else
		{
			return -1;
		}
	}
	void check(int row,int col,int value)
	{
		int i,j,c=0,l=0,m=0,p,q;
		for(i=0;i<9;i++)
		{
			if(d[row][i]==value)
			c++;
		}
		for(i=0;i<9;i++)
		{
			if(d[i][col]==value)
			l++;
		}
		q = row/3;
		q = q*3;
		p=col/3;
		p=p*3;
		for(i=q;i<q+3;i++)
		{
			for(j=p;j<p+3;j++)
			{
				if(d[i][j] == value)
				m++;
			}
		}
		if((l>1)||(c>1)||(m>1))
		{
			cout<<"\nWARNING...YOUR LATEST INPUT CAN CREATE AMBIGUITIES!! "<<row+1<<" and col = "<<col+1;
		}
	}
};
void draw(object &);
void get_solution(object &,object &);
int calculate(object &);
int main()
{
	string text = "SUDOKU GAME";
	int len = text.length();
    cout << endl << "\t\t\t\t\t\t\t\t\t";
    for ( int x=0;x<len;x++)
    {
		cout << text[x];
		Sleep(250);
	}
	start:char ch,ch1,ch2;
	int x,y,a,n,row,col,value,j,choice;
	object obj,obj1(ch),obj2(ch,ch1),obj3(ch,ch1,ch2),obj4(x),obj5(x,y);
	aaa:cout<<"\nEnter your choice. Select Level...\n1.Easy\n2.Medium\n3.Difficult\n";
	cin>>n;
	switch(n)
	{
		case 1: break;
		case 2: obj = obj2;
				obj1 = obj3;
				break;
		case 3: obj = obj4;
				obj1 = obj5;
				break;
		default:cout<<"Invalid choice\n";
				goto aaa;
	}
	system("cls");
	draw(obj);
	do{
		resume:j = obj.insert(row,col,value);
		system("cls");
		draw(obj);
		obj.check(row-1,col-1,value+48);
	}
	while(j!=0);
	
	again:cout<<"\nEnter your choice:\n1.Restart\n2.Quit\n3.Back to game again\n4.Submit\n5.Get solution\n";
	cin>>choice;
	switch(choice)
	{
		case 1: goto start;
		case 2: break;
		case 3: goto resume;
				break;
		case 4: a = calculate(obj);
				if(a==0)
					cout<<"CONGRATULATIONS!!!!!You have successfully completed.\n";
				else
					cout<<"You Lost\n";
		case 5: get_solution(obj,obj1);
				break;
		default:goto again;
	}
	//goto start;
}
void draw(object &obj)
{
	//object obj;
	unsigned char a;
	a= 178;
	int i,j,k=0,l=0;
	cout<<"\t\t\t\t\t\t\t\t";
	for(i=0;i<9;i++)
		cout<<"  "<<i+1<<" ";
	cout<<"\n\n";
	for(j=0;j<9;j++)
	{
		cout<<"\t\t\t\t\t\t\t\t";
		for(i=0;i<9;i++)
			if(j==0||j==3||j==6)
				cout<<"####";
			else
				cout<<"----";
		cout<<"#\n\t\t\t\t\t\t\t\t";
		for(i=0;i<9;i++)
			if(i==0||i==3||i==6)
				cout<<a<<"   ";
			else
				cout<<"|   ";
		cout<<a<<"\n\t\t\t\t\t\t\t"<<j+1<<"\t";
		for(i=0;i<9;i++)
		{
			if(i==0||i==3||i==6)
				cout<<a<<" "<<obj.d[j][i]<<" ";
			else
				cout<<"| "<<obj.d[j][i]<<" ";
		}
		cout<<a<<"\n\t\t\t\t\t\t\t\t";
		for(i=0;i<9;i++)
			if(i==0||i==3||i==6)
				cout<<a<<"   ";
			else
				cout<<"|   ";
		cout<<a<<"\n";
	}
	cout<<"\t\t\t\t\t\t\t\t";
	for(i=0;i<9;i++)
		cout<<"####";
		cout<<"#";
	cout<<"\nPRESS ZERO FOR MORE OPTIONS\n";
}
void get_solution(object &obj,object &obj1)
{
	unsigned char a;
	a= 178;
	int i,j,k=0,l=0;
	cout<<"\t\t\t";
	for(i=0;i<9;i++)
		cout<<"  "<<i+1<<" ";
	cout<<"\t\t\t\t\t\t\t\t\t";
	for(i=0;i<9;i++)
		cout<<"  "<<i+1<<" ";
	cout<<"\n\n";
	for(j=0;j<9;j++)
	{
		cout<<"\t\t\t";
		for(i=0;i<9;i++)
			if(j==0||j==3||j==6)
				cout<<"####";
			else
				cout<<"----";
		cout<<"#\t\t\t\t\t\t\t\t\t";
		for(i=0;i<9;i++)
			if(j==0||j==3||j==6)
				cout<<"####";
			else
				cout<<"----";
		cout<<"#\n\t\t\t";
		for(i=0;i<9;i++)
			if(i==0||i==3||i==6)
				cout<<a<<"   ";
			else
				cout<<"|   ";
		cout<<a<<"\t\t\t\t\t\t\t\t\t";
		for(i=0;i<9;i++)
			if(i==0||i==3||i==6)
				cout<<a<<"   ";
			else
				cout<<"|   ";
		cout<<a<<"\n\t\t"<<j+1<<"\t";
		for(i=0;i<9;i++)
		{
			if(i==0||i==3||i==6)
				cout<<a<<" "<<obj.d[j][i]<<" ";
			else
				cout<<"| "<<obj.d[j][i]<<" ";
		}
		cout<<a<<"\t\t\t\t\t\t\t\t"<<j+1<<"\t";
		for(i=0;i<9;i++)
		{
			if(i==0||i==3||i==6)
				cout<<a<<" "<<obj1.d[j][i]<<" ";
			else
				cout<<"| "<<obj1.d[j][i]<<" ";
		}
		cout<<a<<"\n\t\t\t";
		for(i=0;i<9;i++)
			if(i==0||i==3||i==6)
				cout<<a<<"   ";
			else
				cout<<"|   ";
		cout<<a<<"\t\t\t\t\t\t\t\t\t";
		for(i=0;i<9;i++)
			if(i==0||i==3||i==6)
				cout<<a<<"   ";
			else
				cout<<"|   ";
		cout<<a<<"\n";
	}
	cout<<"\t\t\t";
	for(i=0;i<9;i++)
		cout<<"####";
		cout<<"#\t\t\t\t\t\t\t\t\t";
	for(i=0;i<9;i++)
		cout<<"####";
		cout<<"#";
}
int calculate(object &obj)
{
	int i,j,k,p,q,value,c,row,col;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			if(obj.d[i][j]==32)
			   return -1;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			c=0;
			value = obj.d[i][j];
			for(k=0;k<9;k++)
			{
				if(obj.d[i][k] == value)
				c++;
			}
			if(c!=1)
			return -1;
		}
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			c=0;
			value = obj.d[j][i];
			for(k=0;k<9;k++)
			{
				if(obj.d[k][i] == value)
				c++;
			}
			if(c!=1)
			return -1;
		}
	}
	int r[9] = {0};
	for(row=0;row<3;row++)
	{
		for(col=0;col<3;col++)
		{
			q = row*3;
			p = col*3;
			int r[9] = {0};
			for(i=q;i<q+3;i++)
			{
				for(j=p;j<p+3;j++)
				{
					r[obj.d[i][j]-1]++;
				}
			}
			for(k=0;k<9;k++)
				if(r[i]>1)
					return -1;
		}
	}
	return 0;
}
