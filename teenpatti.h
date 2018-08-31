#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;

namespace teenpatti{
class card
{
public:
    int x,y,z,q,w,e;
    void shuffle()
    {
        srand(time(NULL));

        x=1+rand()%52;
        do
        {
            y=1+rand()%52;
        }
        while(x==y);
        do
        {
            z=1+rand()%52;
        }
        while(z==x||z==y);
        do
        {
            q=1+rand()%52;
        }
        while(q==x||q==y||q==z);
        do
        {
            w=1+rand()%52;
        }
        while(w==x||w==y||w==z||w==q);
        do
        {
            e=1+rand()%52;
        }
        while(e==x||e==y||e==z||e==q||e==w);
    }
};
class cardtype:public card
{
public:
    int acnum[6];
    int type[6];
    void give(int givex,int givenum)
    {
        if(givex<=13)
        {
            acnum[givenum]=givex;
            type[givenum] = 0;
        }
        else if(givex<=26)
        {
            if(givex<26)
            {
                acnum[givenum]=givex%13;
                type[givenum] = 1;
            }
            else
            {
                acnum[givenum]=13;
                type[givenum] = 1;
            }
        }
        else if(givex<=39)
        {
            if(givex<39)
            {
                acnum[givenum] = givex%13;
                type[givenum] = 2;
            }
            else
            {
                acnum[givenum] = 13;
                type[givenum] = 2;
            }
        }
        else if(givex<=52)
        {
            if(givex<52)
            {
                acnum[givenum] = givex%13;
                type[givenum] = 3;
            }
            else
            {
                acnum[givenum] = 13;
                type[givenum] = 3;
            }
        }
    }
};
class game:public cardtype
{
public:
    char a[21],b[21],c[21],aa[21],bb[21],cc[21],sa[3],sb[3],sc[3],sd[3],se[3],sf[3],name[20],checkshow[1];
    int i=0,showcard=0,amtplayer=10000,amtcomp=10000,totalbet=0,win[2];
      int be=0;
    char sphade[21]= {' ',' ','.',' ',' ',' ','/',' ','\\',' ','(','_',' ','_',')',' ','/','_','\\',' ','\0'},heart[21]= {' ','_',' ','_',' ','(',' ','\'',' ',')',' ','\\',' ','/',' ',' ',' ','V',' ',' ','\0'},diamond[21]= {' ',' ','^',' ',' ',' ','/',' ','\\',' ',' ','\\',' ','/',' ',' ',' ','V',' ',' ','\0'},club[21]= {' ',' ','_',' ',' ',' ','(','_',')',' ','(','_',')','_',')',' ','/','_','\\',' ','\0'};
    void gameplay()
    {
        shuffle();
        give(x,0);
        give(y,1);
        give(z,2);
        give(q,3);
        give(w,4);
        give(e,5);

        cout<<"\t\tEnter your name :"<<endl;
        cin.getline(name,20);
        do
        {
            show();
            cout<<"\n\ntotal bet is :"<<totalbet*2<<endl;
            cout<<"\n\n\t\tDo you want SHOW: PRESS Y OR y TO SHOW\n\t\tTo keep playing press N or n"<<endl;
            cin>>checkshow;
            if(strcmp(checkshow,"y")!=0&&strcmp(checkshow,"Y")!=0)
            {
                betting();
            }
        }
        while(strcmp(checkshow,"y")!=0&&strcmp(checkshow,"Y")!=0);
        checkwin();
        show();
        cout<<"\n\n"<<endl;
        winamt();
        cout<<"\n\n\n"<<endl;
    }
    void betting()
    {
        int bet;
        cout<<"\n\t\tplace your bet :"<<endl;
        cin>>bet;
        if(bet>amtplayer)
        {
            cout<<"\n\tyou dont have that much money"<<endl;
        }
        else
        {
            amtcomp=amtcomp-bet;
            amtplayer=amtplayer-bet;
            totalbet=totalbet+bet;
        }
        if(amtplayer==0)
        {
            cout<<"\n\t\tyou have bet all in.....its automatically show"<<endl;
            strcpy(checkshow,"y");
        }
}
    void show()
    {
        int  xx=0,yy=0;
        shuffle();
        do
        {
            switch(type[xx])
            {
            case 3:
                if(xx==0)
                    strcpy(a,sphade);
                if(xx==1)
                    strcpy(b,sphade);
                if(xx==2)
                    strcpy(c,sphade);
                if(xx==3)
                    strcpy(aa,sphade);
                if(xx==4)
                    strcpy(bb,sphade);
                if(xx==5)
                    strcpy(cc,sphade);
                break;
            case 2:
                if(xx==0)
                    strcpy(a,heart);
                if(xx==1)
                    strcpy(b,heart);
                if(xx==2)
                    strcpy(c,heart);
                if(xx==3)
                    strcpy(aa,heart);
                if(xx==4)
                    strcpy(bb,heart);
                if(xx==5)
                    strcpy(cc,heart);
                break;
            case 1:
                if(xx==0)
                    strcpy(a,diamond);
                if(xx==1)
                    strcpy(b,diamond);
                if(xx==2)
                    strcpy(c,diamond);
                if(xx==3)
                    strcpy(aa,diamond);
                if(xx==4)
                    strcpy(bb,diamond);
                if(xx==5)
                    strcpy(cc,diamond);
                break;
            case 0:
                if(xx==0)
                    strcpy(a,club);
                if(xx==1)
                    strcpy(b,club);
                if(xx==2)
                    strcpy(c,club);
                if(xx==3)
                    strcpy(aa,club);
                if(xx==4)
                    strcpy(bb,club);
                if(xx==5)
                    strcpy(cc,club);
                break;
            }
            ++xx;
        }
        while(xx<6);
        do
        {
            switch(acnum[yy])
            {
            case 13:
                if(yy==0)
                    strcpy(sa," A");
                if(yy==1)
                    strcpy(sb," A");
                if(yy==2)
                    strcpy(sc," A");
                if(yy==3)
                    strcpy(sd," A");
                if(yy==4)
                    strcpy(se," A");
                if(yy==5)
                    strcpy(sf," A");
                break;
            case 1:
                if(yy==0)
                    strcpy(sa," 2");
                if(yy==1)
                    strcpy(sb," 2");
                if(yy==2)
                    strcpy(sc," 2");
                if(yy==3)
                    strcpy(sd," 2");
                if(yy==4)
                    strcpy(se," 2");
                if(yy==5)
                    strcpy(sf," 2");
                break;
            case 2:
                if(yy==0)
                    strcpy(sa," 3");
                if(yy==1)
                    strcpy(sb," 3");
                if(yy==2)
                    strcpy(sc," 3");
                if(yy==3)
                    strcpy(sd," 3");
                if(yy==4)
                    strcpy(se," 3");
                if(yy==5)
                    strcpy(sf," 3");
                break;
            case 3:
                if(yy==0)
                    strcpy(sa," 4");
                if(yy==1)
                    strcpy(sb," 4");
                if(yy==2)
                    strcpy(sc," 4");
                if(yy==3)
                    strcpy(sd," 4");
                if(yy==4)
                    strcpy(se," 4");
                if(yy==5)
                    strcpy(sf," 4");
                break;
            case 4:
                if(yy==0)
                    strcpy(sa," 5");
                if(yy==1)
                    strcpy(sb," 5");
                if(yy==2)
                    strcpy(sc," 5");
                if(yy==3)
                    strcpy(sd," 5");
                if(yy==4)
                    strcpy(se," 5");
                if(yy==5)
                    strcpy(sf," 5");
                break;
            case 5:
                if(yy==0)
                    strcpy(sa," 6");
                if(yy==1)
                    strcpy(sb," 6");
                if(yy==2)
                    strcpy(sc," 6");
                if(yy==3)
                    strcpy(sd," 6");
                if(yy==4)
                    strcpy(se," 6");
                if(yy==5)
                    strcpy(sf," 6");
                break;
            case 6:
                if(yy==0)
                    strcpy(sa," 7");
                if(yy==1)
                    strcpy(sb," 7");
                if(yy==2)
                    strcpy(sc," 7");
                if(yy==3)
                    strcpy(sd," 7");
                if(yy==4)
                    strcpy(se," 7");
                if(yy==5)
                    strcpy(sf," 7");
                break;
            case 7:
                if(yy==0)
                    strcpy(sa," 8");
                if(yy==1)
                    strcpy(sb," 8");
                if(yy==2)
                    strcpy(sc," 8");
                if(yy==3)
                    strcpy(sd," 8");
                if(yy==4)
                    strcpy(se," 8");
                if(yy==5)
                    strcpy(sf," 8");
                break;
            case 8:
                if(yy==0)
                    strcpy(sa," 9");
                if(yy==1)
                    strcpy(sb," 9");
                if(yy==2)
                    strcpy(sc," 9");
                if(yy==3)
                    strcpy(sd," 9");
                if(yy==4)
                    strcpy(se," 9");
                if(yy==5)
                    strcpy(sf," 9");
                break;
            case 9:
                if(yy==0)
                    strcpy(sa,"10");
                if(yy==1)
                    strcpy(sb,"10");
                if(yy==2)
                    strcpy(sc,"10");
                if(yy==3)
                    strcpy(sd,"10");
                if(yy==4)
                    strcpy(se,"10");
                if(yy==5)
                    strcpy(sf,"10");
                break;
            case 10:
                if(yy==0)
                    strcpy(sa," J");
                if(yy==1)
                    strcpy(sb," J");
                if(yy==2)
                    strcpy(sc," J");
                if(yy==3)
                    strcpy(sd," J");
                if(yy==4)
                    strcpy(se," J");
                if(yy==5)
                    strcpy(sf," J");
                break;
            case 11:
                if(yy==0)
                    strcpy(sa," Q");
                if(yy==1)
                    strcpy(sb," Q");
                if(yy==2)
                    strcpy(sc," Q");
                if(yy==3)
                    strcpy(sd," Q");
                if(yy==4)
                    strcpy(se," Q");
                if(yy==5)
                    strcpy(sf," Q");
                break;
            case 12:
                if(yy==0)
                    strcpy(sa," K");
                if(yy==1)
                    strcpy(sb," K");
                if(yy==2)
                    strcpy(sc," K");
                if(yy==3)
                    strcpy(sd," K");
                if(yy==4)
                    strcpy(se," K");
                if(yy==5)
                    strcpy(sf," K");
                break;
            }
            ++yy;
        }
        while(yy<6);
        if(strcmp(checkshow,"y")==0||strcmp(checkshow,"Y")==0)
        {
            cout<<"\t"<<" _____    _____    _____ "<<endl;
            cout<<"\t"<<"|"<<sd<<"   |  "<<"|"<<se<<"   |  "<<"|"<<sf<<"   |"<<endl;
            cout<<"\t"<<"|"<<aa[0]<<aa[1]<<aa[2]<<aa[3]<<aa[4]<<"|  |"<<bb[0]<<bb[1]<<bb[2]<<bb[3]<<bb[4]<<"|  |"<<cc[0]<<cc[1]<<cc[2]<<cc[3]<<cc[4]<<"|    Computer"<<endl;
            cout<<"\t"<<"|"<<aa[5]<<aa[6]<<aa[7]<<aa[8]<<aa[9]<<"|  |"<<bb[5]<<bb[6]<<bb[7]<<bb[8]<<bb[9]<<"|  |"<<cc[5]<<cc[6]<<cc[7]<<cc[8]<<cc[9]<<"|"<<endl;
            cout<<"\t"<<"|"<<aa[10]<<aa[11]<<aa[12]<<aa[13]<<aa[14]<<"|  |"<<bb[10]<<bb[11]<<bb[12]<<bb[13]<<bb[14]<<"|  |"<<cc[10]<<cc[11]<<cc[12]<<cc[13]<<cc[14]<<"|    Balance:"<<amtcomp<<endl;
            cout<<"\t"<<"|"<<aa[15]<<aa[16]<<aa[17]<<aa[18]<<aa[19]<<"|  |"<<bb[15]<<bb[16]<<bb[17]<<bb[18]<<bb[19]<<"|  |"<<cc[15]<<cc[16]<<cc[17]<<cc[18]<<cc[19]<<"|"<<endl;
            cout<<"\t"<<"|_____|  |_____|  |_____|"<<endl;
        }
        else
        {
            cout<<"\t"<<" _____    _____    _____ "<<endl;
            cout<<"\t"<<"|     |  |     |  |     |"<<endl;
            cout<<"\t"<<"|     |  |     |  |     |    Computer"<<endl;
            cout<<"\t"<<"|     |  |     |  |     |"<<endl;
            cout<<"\t"<<"|     |  |     |  |     |    Balance:"<<amtcomp<<endl;
            cout<<"\t"<<"|     |  |     |  |     |"<<endl;
            cout<<"\t"<<"|_____|  |_____|  |_____|"<<endl;
        }
        cout<<"_______________________________________________________________"<<endl;
        cout<<"\t"<<" _____    _____    _____ "<<endl;
        cout<<"\t"<<"|"<<sa<<"   |  "<<"|"<<sb<<"   |  "<<"|"<<sc<<"   |"<<endl;
        cout<<"\t"<<"|"<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<"|  |"<<b[0]<<b[1]<<b[2]<<b[3]<<b[4]<<"|  |"<<c[0]<<c[1]<<c[2]<<c[3]<<c[4]<<"|    "<<name<<endl;
        cout<<"\t"<<"|"<<a[5]<<a[6]<<a[7]<<a[8]<<a[9]<<"|  |"<<b[5]<<b[6]<<b[7]<<b[8]<<b[9]<<"|  |"<<c[5]<<c[6]<<c[7]<<c[8]<<c[9]<<"|"<<endl;
        cout<<"\t"<<"|"<<a[10]<<a[11]<<a[12]<<a[13]<<a[14]<<"|  |"<<b[10]<<b[11]<<b[12]<<b[13]<<b[14]<<"|  |"<<c[10]<<c[11]<<c[12]<<c[13]<<c[14]<<"|    Balance:"<<amtplayer<<endl;
        cout<<"\t"<<"|"<<a[15]<<a[16]<<a[17]<<a[18]<<a[19]<<"|  |"<<b[15]<<b[16]<<b[17]<<b[18]<<b[19]<<"|  |"<<c[15]<<c[16]<<c[17]<<c[18]<<c[19]<<"|"<<endl;
        cout<<"\t"<<"|_____|  |_____|  |_____|"<<endl;
    }
    void winamt()
    {
        do
        {
            switch(win[be])
            {
            case 1:
                if(be==0)
                {
                    cout<<name<<" wins same number"<<endl;
                    goto last;
                }
                if(be==1)
                {
                    cout<<"computer wins same number"<<endl;
                goto last;
                }
                break;
            case 2:
                if(be==0)
                {
                    cout<<name<<" wins same number"<<endl;
                goto last;
                }
                if(be==1)
                {
                    cout<<"computer wins same number"<<endl;
               goto last;
                }
                break;
            case 3:
                if(be==0)
                {
                    cout<<name<<" wins same type ,number in sequence."<<endl;
                goto last;
                }
                if(be==1)
                {
                    cout<<"computer wins same type ,number in sequence."<<endl;
                goto last;
                }
                break;
            case 4:
                if(be==0)
                {
                    cout<<name<<" wins same type ,number in sequence."<<endl;
                goto last;
                }
                if(be==1)
                {
                    cout<<"computer wins same type ,number in sequence."<<endl;
                goto last;
                }
                break;
            case 5:
                if(be==0)
                {
                    cout<<name<<" wins same type ,number in sequence."<<endl;
                goto last;
                }
                if(be==1)
                {
                    cout<<"computer wins same type ,number in sequence."<<endl;
                goto last;
                }
                break;
            case 6:
                if(be==0)
                {
                    cout<<name<<" wins sequence of number."<<endl;
                goto last;
                }
                if(be==1)
                {
                    cout<<"computer wins sequence of number."<<endl;
                goto last;
                }
                break;
            case 7:
                if(be==0)
                {
                    cout<<name<<" wins sequence of number."<<endl;
                goto last;
                }
                if(be==1)
                {
                    cout<<"computer wins sequence of number."<<endl;
                goto last;
                }
                break;
            case 8:
                if(be==0)
                {
                    cout<<name<<" wins sequence of number"<<endl;
                goto last;
                }
                if(be==1)
                {
                    cout<<"computer wins sequence of number"<<endl;
                goto last;
                }
                break;
            case 9:
                if(be==0)
                {
                    cout<<name<<" wins all cards same type but "<<name<<" has high card"<<endl;
                goto last;
                }
                if(be==1)
                {
                    cout<<"computer wins all cards same type but computer has high card"<<endl;
                goto last;
                }
                break;
            case 10:
                if(be==0)
                {
                    cout<<name<<" wins both have cards of respective same types but "<<name<<" has high type of card"<<endl;
                goto last;
                }
                if(be==1)
                {
                    cout<<"computer wins both have cards of respective same types but computer has high type of card"<<endl;
                goto last;
                }
                break;
            case 11:
                if(be==0)
                {
                    cout<<name<<" wins same type of card"<<endl;
                goto last;
                }
                if(be==1)
                {
                    cout<<"computer wins same type of card"<<endl;
                goto last;
                }
                break;
            case 12:
                if(be==0)
                {
                    cout<<name<<" wins high card."<<endl;
                goto last;
                }
                if(be==1)
                {
                    cout<<"computer wins high card."<<endl;
                goto last;
                }
                break;
            case 13:
                if(be==0)
                {
                    cout<<name<<" wins high card."<<endl;
                goto last;
                }
                if(be==1)
                {
                    cout<<"computer wins high card."<<endl;
                goto last;
                }
                break;
            }
            be++;
        }
        while(be==1);
        last:
            cout<<endl;
    }
    void checkwin()
    {
        int maxc=3,maxp=0;

        if(acnum[0]>acnum[maxp])
        {
            maxp=0;
        }
        if(acnum[0]==acnum[maxp] &&  type[0]>type[maxp])
        {
            maxp=0;
        }
        if(acnum[1]>acnum[maxp])
        {
            maxp=1;
        }
        if(acnum[1]==acnum[maxp] && type[1]>type[maxp])
        {
            maxp=1;
        }
        if(acnum[2]>acnum[maxp])
        {
            maxp=2;
        }
        if(acnum[2]==acnum[maxp] && type[2]>type[maxp])
        {
            maxp=2;
        }
        if(acnum[3]>acnum[maxc])
        {
            maxc=3;
        }
        if(acnum[3]==acnum[maxc] && type[3]>type[maxc])
        {
            maxc=3;
        }
        if(acnum[4]>acnum[maxc])
        {
            maxc=4;
        }
        if(acnum[4]==acnum[maxc] && type[4]>type[maxc])
        {
            maxc=4;
        }
        if(acnum[5]>acnum[maxc])
        {
            maxc=5;
        }
        if(acnum[5]==acnum[maxc] && type[5]>type[maxc])
        {
            maxc=5;
        }
///same number
        if(acnum[0]==acnum[1] && acnum[1]==acnum[2])
        {
            if(acnum[3]==acnum[4] && acnum[4]==acnum[5])
            {
                if(acnum[0]>acnum[3])
                {
                    amtplayer=amtplayer+(totalbet*2);
                    win[0]=1;
                }
                else
                {
                    amtcomp=amtcomp+(totalbet*2);
                    win[1]=1;
                }
            }
            else
            {
                amtplayer=amtplayer+(totalbet*2);
                win[0]=2;
            }
        }
        else if(acnum[3]==acnum[4] && acnum[4]==acnum[5])
        {
            amtcomp=amtcomp+(totalbet*2);
            win[1]=2;
        }
        ///same type ,number in sequence.
        else if((type[0]==type[1] && type[1]==type[2])&&((acnum[0]==acnum[1]+1 && acnum[1]==acnum[2]+1)||(acnum[0]==acnum[2]+1 && acnum[2]==acnum[1]+1)||(acnum[2]==acnum[0]+1 && acnum[0]==acnum[1]+1)||(acnum[1]==acnum[0]+1 && acnum[0]==acnum[2]+1)||(acnum[1]==acnum[2]+1 && acnum[2]==acnum[0]+1)||(acnum[2]==acnum[1]+1 && acnum[1]==acnum[0]+1)))
        {
            if((type[3]==type[4] && type[4]==type[5])&&((acnum[3]==acnum[4]+1 && acnum[4]==acnum[5]+1)||(acnum[3]==acnum[5]+1 && acnum[5]==acnum[4]+1)||(acnum[5]==acnum[3]+1 && acnum[3]==acnum[4]+1)||(acnum[4]==acnum[3]+1 && acnum[3]==acnum[5]+1)||(acnum[4]==acnum[5]+1 && acnum[5]==acnum[3]+1)||(acnum[5]==acnum[4]+1 && acnum[4]==acnum[3]+1)))
            {
                if(acnum[maxc]>acnum[maxp])
                {
                    amtcomp=amtcomp+(totalbet*2);
                    win[1]=3;
                }
                else if(acnum[maxc]<acnum[maxp])
                {
                    amtplayer=amtplayer+(totalbet*2);
                    win[0]=3;
                }
                else if(acnum[maxc]==acnum[maxp])
                {
                    if(type[0]>type[3])
                    {
                        amtplayer=amtplayer+(totalbet*2);
                        win[0]=4;
                    }
                    else
                    {
                        amtcomp=amtcomp+(totalbet*2);
                        win[1]=4;
                    }
                }
            }
            else
            {
                amtplayer=amtplayer+(totalbet*2);
                win[0]=5;
            }
        }
        else if((type[3]==type[4] && type[4]==type[5])&&((acnum[3]==acnum[4]+1 && acnum[4]==acnum[5]+1)||(acnum[3]==acnum[5]+1 && acnum[5]==acnum[4]+1)||(acnum[5]==acnum[3]+1 && acnum[3]==acnum[4]+1)||(acnum[4]==acnum[3]+1 && acnum[3]==acnum[5]+1)||(acnum[4]==acnum[5]+1 && acnum[5]==acnum[3]+1)||(acnum[5]==acnum[4]+1 && acnum[4]==acnum[3]+1)))
        {
            amtcomp=amtcomp+(totalbet*2);
            win[1]=5;
        }
        ///sequence of number.
        else if((acnum[0]==acnum[1]+1 && acnum[1]==acnum[2]+1)||(acnum[0]==acnum[2]+1 && acnum[2]==acnum[1]+1)||(acnum[2]==acnum[0]+1 && acnum[0]==acnum[1]+1)||(acnum[1]==acnum[0]+1 && acnum[0]==acnum[2]+1)||(acnum[1]==acnum[2]+1 && acnum[2]==acnum[0]+1)||(acnum[2]==acnum[1]+1 && acnum[1]==acnum[0]+1))
        {
            if((acnum[3]==acnum[5]+1 && acnum[5]==acnum[4]+1)||(acnum[5]==acnum[3]+1 && acnum[3]==acnum[4]+1)||(acnum[4]==acnum[3]+1 && acnum[3]==acnum[5]+1)||(acnum[4]==acnum[5]+1 && acnum[5]==acnum[3]+1)||(acnum[5]==acnum[4]+1 && acnum[4]==acnum[3]+1))
            {
                if(acnum[maxc]>acnum[maxp])
                {
                    amtcomp=amtcomp+(totalbet*2);
                    win[1]=6;
                }
                else if(acnum[maxc]<acnum[maxp])
                {
                    amtplayer=amtplayer+(totalbet*2);
                    win[0]=6;
                }
                else if(acnum[maxc]==acnum[maxp])
                {
                    if(type[maxp]>type[maxc])
                    {
                        amtplayer=amtplayer+(totalbet*2);
                        win[0]=7;
                    }
                    else
                    {
                        amtcomp=amtcomp+(totalbet*2);
                        win[1]=7;
                    }
                }
            }
            else
            {
                amtplayer=amtplayer+(totalbet*2);
                win[0]=8;
            }
        }
        else if((acnum[3]==acnum[5]+1 && acnum[5]==acnum[4]+1)||(acnum[5]==acnum[3]+1 && acnum[3]==acnum[4]+1)||(acnum[4]==acnum[3]+1 && acnum[3]==acnum[5]+1)||(acnum[4]==acnum[5]+1 && acnum[5]==acnum[3]+1)||(acnum[5]==acnum[4]+1 && acnum[4]==acnum[3]+1))
        {
            amtcomp=amtcomp+(totalbet*2);
            win[1]=8;
        }
        ///all cards same type
        else if((type[0]==type[1] && type[1]==type[2] && type[2]==type[3] && type[3]==type[4] && type[4]==type[5]))
        {
            if(acnum[maxc]>acnum[maxp])
            {
                amtcomp=amtcomp+(totalbet*2);
                win[1]=9;
            }
            else
            {
                amtplayer=amtplayer+(totalbet*2);
                win[0]=9;
            }
        }
        ///same type
        else if(type[0]==type[1] && type[1]==type[2])
        {
            if(type[3]==type[4] && type[4]==type[5])
            {
                if(type[0]>type[3])
                {
                    amtplayer=amtplayer+(totalbet*2);
                    win[0]=10;
                }
                else
                {
                    amtcomp=amtcomp+(totalbet*2);
                    win[1]=10;
                }
            }
            else
            {
                amtplayer=amtplayer+(totalbet*2);
                win[0]=11;
            }
        }
        else if(type[3]==type[4] && type[4]==type[5])
        {
            amtcomp=amtcomp+(totalbet*2);
            win[1]=11;
        }
        ///high card.
        else
        {
            if(acnum[maxc]>acnum[maxp])
            {
                amtcomp=amtcomp+(totalbet*2);
                win[1]=12;
            }
            else if(acnum[maxc]<acnum[maxp])
            {
                amtplayer=amtplayer+(totalbet*2);
                win[0]=12;
            }
            else if(acnum[maxc]==acnum[maxp])
            {
                if(type[maxp]>type[maxc])
                {
                    amtplayer=amtplayer+(totalbet*2);
                    win[0]=13;
                }
                else
                {
                    amtcomp=amtcomp+(totalbet*2);
                    win[1]=13;
                }
            }
        }
    }
};
}
