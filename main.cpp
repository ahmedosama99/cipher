#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a ;
    while(true)
    {
    cout<<"Ahlan ya user ya habibi."<<endl;
    cout<<"What do you like to do today?"<<endl;
    cout<<"1- Cipher a message"<<endl;
    cout<<"2- Decipher a message"<<endl;
    cout<<"3- End"<<endl;
    cin>>a;
        if(a!=1 && a!=2 && a!=3 ){
            cout<<"enter only 1 or 2 or 3 : ";
            cin >> a ;
        }
        else if(a==1)
        {
            string mas1 , mas2;
            int key , i , j , k=-1 , row=0 , col=0;
            cout<<"enter your message : ";
            cin.ignore();
            getline(cin,mas1);
            cout<<"enter key : ";
            cin>>key;
            for(int i=0 ; i<=mas1.length() ; i++)
            {
                if(mas1[i]!=' ')
                {
                    mas2=mas2+mas1[i];
                }
            }
            int len=mas2.size();
            char mat[key][len];
            for(i=0; i<key; i++){
                for(j=0; j<len; j++)
                    mat[i][j]='-';
            }
            for(i=0; i<len; i++)
            {
                mat[row][col]=mas2[i];
                if(row==0||row==key-1){
                    k=k*(-1);
                }
                row=row+k;
                col++;
            }
           for(i=0; i<key; i++){
                for(j=0; j<len; j++){
                        cout<<mat[i][j];
                }
                cout<<endl;
            }

            cout<<"\nencrypted message : ";
            for(i=0; i<key; i++){
                for(j=0; j<len; j++){
                    if(mat[i][j] != '-'){
                        cout<<mat[i][j];
                    }
                }
            }
            cout<<endl;
        }
        else if(a==2)
        {
            string mas;
            int key;
            int i,j,k=-1,row=0,col=0,s=0;
            cout<<"enter your encrypted message :";
            cin.ignore();
            getline(cin,mas);
            cout<<"enter key : ";
            cin>>key;
            int len=mas.size();
            char mat[key][len];
            for(i=0; i<key; i++)
                for(j=0; j<len; j++)
                    mat[i][j]='-';
            for(i=0; i<len; i++)
            {
                mat[row][col]='$';
                if(row==0||row==key-1){
                    k=k*(-1);
                }
                row=row+k;
                col++;
            }
            for(i=0; i<key; i++){
                for(j=0; j<len; j++){
                    if(mat[i][j]=='$'){
                        mat[i][j]=mas[s];
                        s++;
                    }
                }
            }
            row = col = 0;
            k = -1;
            cout<<"\ndecrypted message is : ";
            for(i=0; i<len; i++)
            {
                cout<<mat[row][col++];
                if(row==0||row==key-1)
                    k=k*(-1);
                row=row+k;
            }
            cout<<endl;
        }
        else if (a==3)
        {
            break;
        }
    }
    return 0;
}
