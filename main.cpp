#include<cstring>
#include<iostream>
#include<algorithm>
#include<chrono>
using namespace std;
char *Text=new char[23];
char *pattern=new char[7];
int *fl_arr_p=new int[8];
char *prefix=new char[strlen(pattern)-1];     // [ 7-1 ]  == 6 --> form 0--->5 == size of large prefix == AGAAGA
int * proparsuffix=new int[strlen(prefix)-1]; // [ 6-1 ]  == 5 --> form 0-->4 ==size of large proper suffix == AGAAG

void getprefixx(int end_prefix,char* current_prefix) //here in this function i will find the prefix for each Char in the Pattern
{
    int End=0;

  //cout<<"preffix for index "<<end_prefix<<" in pattern"<< " is = ";

    for(int j=0; j<end_prefix; j++) // i will take this  char in prefix  until reach to real index of char of pattern  (end prefix)
    {

        current_prefix[j]=pattern[j];
        //cout<<current_prefix[j];
        End=j;

    }
    //cout<<endl;
    current_prefix[End+1]='\0';  // that mean this prefix not take any char again
}
int getproparsuffixx(int * current_propartsuffix,char *current_prefix)
{   int Max=0;  // this is the real index of failure links for the char in pattern
    int z=0;
    for(int i=0; i<strlen(current_prefix)-1; i++)  // this for it build to loop on the char char of the prefix
    {
        //cout<<"proper suffix "<<"for inedx "<<i<<" in prefix is = ";
        for(int j=i+1; j<strlen(current_prefix); j++)  // in this loop i will loop on the pattern text to compare the char in the proper suffix with the pattern char
        {
            //cout<<current_prefix[j];

           if(current_prefix[j]==pattern[z])
           {
               Max++;  // this will depend on the index of failure links of char
               if(j==strlen(current_prefix)-1)
               {
                   return Max; // that mean i reach the last proper suffix in this prefix
               }

               z++;  // this counter for move from one char to another in the pattern
           }
           else
           {
            Max=0;  // her that mean the proper suffix is not match with the pattern so i will break
            z=0;
            break;
            }


        }
       z=0;  // i will set Z zero because each proper suffix i will compare each char with each char in the pattern
        //cout<<endl;
    }
    return Max;  // this is the real value of failure links for this char in the pattern
}
char *preprocessing(char *pattern) // 1)  here in this function i will find the prefix for each part of the pattern
                                   // 2) then i will find the proper suffix for this one prefix
                                   // 3) calculate finally the failure links for this char in the pattern
{

    fl_arr_p[0]=-1;
    for(int i=1; i<=strlen(pattern); i++)
    {


        getprefixx(i,prefix);  // prefix calculate done
        if(i==1)
        {
            fl_arr_p[i]=0;  // if i stand in the index 1 in the pattern i will set the failure links for this char to zero 0
            continue;
        }
        fl_arr_p[i]=getproparsuffixx(proparsuffix,prefix); // failure links for this char is done
        //cout<<endl;
    }

}

void Search(int *fl_arr_p,char *Text,char*pattern)  // in this search void i will search for this pattern where will match with the real Text and return the indexes of this Match
{
    int i=0;
    int j=0;
    while(i<=strlen(Text))
    {
        if(Text[i]==pattern[j]) // That mean i will continue in the compare between the pattern and Text
        {
            cout<<"(t"<<i<<","<<"p"<<j<<")"<<endl;
            i++; //counter of Text
            j++; //counter of Pattern
        }
        else
        {
            cout<<"Not equal in "<<"(t"<<i<<","<<"p"<<j<<")"<<endl;
            if(j==0)
            {
                i++; // here that mean i reach in again to the first char in the pattern so i have to move cursor of the Text
            }
            else
            j=fl_arr_p[j]; // else i will use the failure links for this char to return to the last match char with Text in the pattern
        }

        if(j==strlen(pattern)) // here that mean i get one Match between the Text and the all of that pattern
        {
            cout<<"Rep("<<i-j<<")";
        }
        if(i==strlen(Text)&&j==-1)  // here is the base cause where i will return and i have move at the all Text .
        {
            return ;
        }

    }
}
int main()
{
    Text="AGAGAAGAGGAGAAGAGAAGAGA";
    pattern="AGAAGAG";
    preprocessing(pattern); // here i get each of prefix , proper suffix and index of failure links of this char in the pattern .
    Search(fl_arr_p,Text,pattern); // here when i will find the indexes of Match between the Text and Pattern with the help of failure links of each char in the pattern .

    return 0;
}
