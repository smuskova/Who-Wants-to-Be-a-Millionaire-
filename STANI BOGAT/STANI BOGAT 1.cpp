#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<cstring>
#include <iomanip>
#include<fstream>
#include<ctime>
using namespace std;
struct StaniBogat
{
    string question;
    string right;
    string  ansA,ansB,ansC,ansD;
};
void print(ifstream&f)
{    string line;
    if (f.is_open())
    {
          while (getline(f, line))
        {
            printf( line.c_str());
            cout<<endl;
        }
    }
    f.close();
}
void read(vector<StaniBogat>& a)
{
    ifstream answers("questions.txt");
    string help;
    StaniBogat b;
    /// chetem ot faila, koito se kazva questions ,i vavejdame dannite vav vector
   while(!answers.eof())
    {
        getline(answers,b.question);
        getline(answers,b.ansA);
        getline(answers,b.ansB);
        getline(answers,b.ansC);
        getline(answers,b.ansD);
        getline(answers,b.right);
        a.push_back(b);
    }
    answers.close();

}
void write(vector<StaniBogat> a,int&suma)
{
    ///srand(time(NULL));
    string ch,ch2;
    int br=0, n=a.size();
    int nn=n;
    int broi_joker_1=1;
    int broi_joker_2=1;
    bool endGame=0;
    for(int i=0; i<nn&& !endGame; i++)
    {
        int pos=rand()%n;
        system("pause");
        cout<<endl;
            if(broi_joker_1>0)cout<<" Za 50/50-vavedi edno"<<endl;
                        else  cout<<" Izpolzval si purviqt  joker "<<endl;
            cout<<endl<<endl;
             if(broi_joker_2>0)  cout<<" Za pomosht ot priqtel- vavedi dve"<<endl;
                                    else cout<<"Izpolzvali ste vtoriqt joker"<<endl;
                          cout<<endl<<endl;


            cout<<a[pos].question<<endl;
            cout<<a[pos].ansA<<endl;
            cout<<a[pos].ansB<<endl;
            cout<<a[pos].ansC<<endl;
            cout<<a[pos].ansD<<endl;
            ///cout<<a[pos].right<<endl;
        do
        {   cout<<"Koi otgovor izbirate:";
            cin>>ch;

            if(ch=="edno" )
            {if(broi_joker_1>0)
               {
                  cout<<a[pos].question<<endl;
                if(a[pos].right=="A")
                    cout<<a[pos].ansA<<endl<<a[pos].ansC<<endl;
                if(a[pos].right=="B")
                    cout<<a[pos].ansB<<endl<<a[pos].ansC<<endl;
                if(a[pos].right=="C")
                    cout<<a[pos].ansA<<endl<<a[pos].ansC<<endl;
                if(a[pos].right=="D")
                    cout<<a[pos].ansB<<endl<<a[pos].ansD<<endl;
                broi_joker_1=0   ;
               }
               else cout<<"Nqmate  takav joker!\n";
            }
            else  if(ch=="dve")
            { if( broi_joker_2>0){
                cout<<endl<<endl;
                cout<<a[pos].question<<endl;
                cout<<a[pos].ansA<<endl;
                cout<<a[pos].ansB<<endl;
                cout<<a[pos].ansC<<endl;
                cout<<a[pos].ansD<<endl;
                broi_joker_2=0;
                cout<<"Spored men verniqt otgovor e "<<a[pos].right<<endl;

             }else cout<<"Nqmate  takav joker!\n";
             }

            else    if(ch==a[pos].right)
            {
                suma= suma+50;
                cout<<" Veren otgovor! Spechelihte "<<suma<<" leva."<<endl;
                br++;
                if(br==5)
                    cout<<" Pozdravleniq! Spechelihte purva sigurna suma 250"<<" leva."<<endl;
                if(br==10)
                    cout<<" Pozdravleniq! Spechelihte vtora sigurna suma 2500"<<" leva."<<endl;
                if(br==15)
                    cout<<" Pozdravleniq! Spechelihte 100 000"<<" leva."<<endl;
                break;
            }
            else
            {
                cout<<" Greshen otgovor!"<<endl;
                if(br<5)
                    cout<<"Vie spechelihte "<<suma/2<<" leva"<<endl;
                if(br>5 and br<10)
                    cout<<" Vie spechelihte 250"<<" leva."<<endl;
                if(br>10 and br<15)
                    cout<<" Vie spechelihte 2500"<<" leva."<<endl;
                {
                    endGame=1;
                    break;
                }
            }
        }
        while(true);
        swap(a[pos], a[n-1]);
        n--;
        system("pause");
        system("cls");

    }
}
int main()
{
    srand(time(NULL));
    int suma=0; ///purvonachalnata suma
    ///int num_quest=2;///broi na vuprosite
    vector<StaniBogat> information;
    ifstream logo("logo.txt",ios::in);
    print(logo);

    cout<<"START"<<endl;
    read(information);
    write(information,suma);
    return 0;


}
