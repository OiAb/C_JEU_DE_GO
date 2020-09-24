#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{ HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte); }
int in_chaine(int L[100][2],int i, int j){
int l,c=0;
for (l=0;l<100;l++){if (L[l][0]==i &&L[l][1]==j) {c=1;break;}
else l++;}
return c;}
int capture_chaine(char tab[33][80],int a,int b, char tabvide[33][80]){ //don't forget a*4 and b*8 !!!!! a 5. b +65
int i=0,c=0;
int L[100][2];
if (specific_degree(tab,a,b,tabvide)==0){
    if(in_chaine(L,a,b)==0){
    L[i][0]=a;
    L[i][1]=b;
    i++;
    if (a==0&&b==0){if (tab[a+4][b]==tab[a][b]&&tab[a][b+8]==tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide);}
                    else if (tab[a+4][b]!=tab[a][b]&&tab[a][b+8]==tab[a][b]){
                       c=capture_chaine(tab,a,b+8,tabvide);}
                    else if(tab[a+4][b]==tab[a][b]&&tab[a][b+8]!=tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide);}}
    else if (a==0&&b==72){if (tab[a+4][b]==tab[a][b]&&tab[a][b-8]==tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
                    else if (tab[a+4][b]!=tab[a][b]&&tab[a][b-8]==tab[a][b]){
                       c=capture_chaine(tab,a,b-8,tabvide);}
                    else if(tab[a+4][b]==tab[a][b]&&tab[a][b-8]!=tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide);}}
    else if (a==36&&b==0){if (tab[a-4][b]==tab[a][b]&&tab[a][b+8]==tab[a][b]){
                       c=capture_chaine(tab,a-4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide);}
                    else if (tab[a-4][b]!=tab[a][b]&&tab[a][b+8]==tab[a][b]){
                       c=capture_chaine(tab,a,b+8,tabvide);}
                    else if(tab[a-4][b]==tab[a][b]&&tab[a][b+8]!=tab[a][b]){
                       c=capture_chaine(tab,a-4,b,tabvide);}}
    else if (a==36&&b==72){if (tab[a-4][b]==tab[a][b]&&tab[a][b-8]==tab[a][b]){
                       c=capture_chaine(tab,a-4,b,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
                    else if (tab[a-4][b]!=tab[a][b]&&tab[a][b-8]==tab[a][b]){
                       c=capture_chaine(tab,a,b-8,tabvide);}
                    else if(tab[a-4][b]==tab[a][b]&&tab[a][b-8]!=tab[a][b]){
                       c=capture_chaine(tab,a-4,b,tabvide);}}
    else if (a==0&&b!=0&&b!=72){if (tab[a+4][b]==tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b-8]==tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide);capture_chaine(tab,a,b-8,tabvide);}
                    else if (tab[a+4][b]!=tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b-8]==tab[a][b]){
                      c=capture_chaine(tab,a,b+8,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
                    else if (tab[a+4][b]==tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a][b-8]==tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
                    else if (tab[a+4][b]==tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b-8]!=tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide);}
                    else if (tab[a+4][b]!=tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a][b-8]==tab[a][b]){
                       c=capture_chaine(tab,a,b-8,tabvide);}
                    else if (tab[a+4][b]==tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a][b-8]!=tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide);}
                    else if (tab[a+4][b]!=tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b-8]!=tab[a][b]){
                       c=capture_chaine(tab,a,b+8,tabvide);}
                       }
    else if (b==0&&a!=0&&a!=36){if (tab[a+4][b]==tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a-4][b]==tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide)+capture_chaine(tab,a-4,b,tabvide);}
                    else if (tab[a+4][b]!=tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a-4][b]==tab[a][b]){
                      c=capture_chaine(tab,a,b+8,tabvide)+capture_chaine(tab,a-4,b,tabvide);}
                    else if (tab[a+4][b]==tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a-4][b]==tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a-4,b,tabvide);}
                    else if (tab[a+4][b]==tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a-4][b]!=tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide);}
                    else if (tab[a+4][b]!=tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a-4][b]==tab[a][b]){
                       c=capture_chaine(tab,a-4,b,tabvide);}
                    else if (tab[a+4][b]==tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a-4][b]!=tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide);}
                    else if (tab[a+4][b]!=tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a-4][b]!=tab[a][b]){
                       c=capture_chaine(tab,a,b+8,tabvide);}
                       }
    else if (b==72&&a!=0&&a!=36){if (tab[a+4][b]==tab[a][b]&&tab[a][b-8]==tab[a][b]&&tab[a-4][b]==tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a,b-8,tabvide)+capture_chaine(tab,a-4,b,tabvide);}
                    else if (tab[a+4][b]!=tab[a][b]&&tab[a][b-8]==tab[a][b]&&tab[a-4][b]==tab[a][b]){
                      c=capture_chaine(tab,a,b-8,tabvide)+capture_chaine(tab,a-4,b,tabvide);}
                    else if (tab[a+4][b]==tab[a][b]&&tab[a][b-8]!=tab[a][b]&&tab[a-4][b]==tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a-4,b,tabvide);}
                    else if (tab[a+4][b]==tab[a][b]&&tab[a][b-8]==tab[a][b]&&tab[a-4][b]!=tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
                    else if (tab[a+4][b]!=tab[a][b]&&tab[a][b-8]!=tab[a][b]&&tab[a-4][b]==tab[a][b]){
                       c=capture_chaine(tab,a-4,b,tabvide);}
                    else if (tab[a+4][b]==tab[a][b]&&tab[a][b-8]!=tab[a][b]&&tab[a-4][b]!=tab[a][b]){
                       c=capture_chaine(tab,a+4,b,tabvide);}
                    else if (tab[a+4][b]!=tab[a][b]&&tab[a][b-8]==tab[a][b]&&tab[a-4][b]!=tab[a][b]){
                       c=capture_chaine(tab,a,b-8,tabvide);}
                       }
     else if(a==36&&b!=0&&b!=72){if (tab[a-4][b]==tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b-8]==tab[a][b]){
                       c=capture_chaine(tab,a-4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
                    else if (tab[a-4][b]!=tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b-8]==tab[a][b]){
                      c=capture_chaine(tab,a,b+8,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
                    else if (tab[a-4][b]==tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a][b-8]==tab[a][b]){
                       c=capture_chaine(tab,a-4,b,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
                    else if (tab[a-4][b]==tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b-8]!=tab[a][b]){
                       c=capture_chaine(tab,a-4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide);}
                    else if (tab[a-4][b]!=tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a][b-8]==tab[a][b]){
                       c=capture_chaine(tab,a,b-8,tabvide);}
                    else if (tab[a-4][b]==tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a][b-8]!=tab[a][b]){
                       c=capture_chaine(tab,a-4,b,tabvide);}
                    else if (tab[a-4][b]!=tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b-8]!=tab[a][b]){
                       c=capture_chaine(tab,a,b+8,tabvide);}
                       }
    else {if (tab[a+4][b]==tab[a][b]&&tab[a-4][b]==tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b]==tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a-4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
          else if (tab[a+4][b]!=tab[a][b]&&tab[a-4][b]==tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b]==tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a-4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
          else if (tab[a+4][b]==tab[a][b]&&tab[a-4][b]!=tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b]==tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
          else if (tab[a+4][b]==tab[a][b]&&tab[a-4][b]==tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a][b]==tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a-4,b,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
          else if (tab[a+4][b]==tab[a][b]&&tab[a-4][b]==tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b]!=tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a-4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide);}
          else if (tab[a+4][b]!=tab[a][b]&&tab[a-4][b]!=tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b]==tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a,b+8,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
          else if (tab[a+4][b]==tab[a][b]&&tab[a-4][b]!=tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a][b]==tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a-4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide);}
          else if (tab[a+4][b]!=tab[a][b]&&tab[a-4][b]==tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a][b]==tab[a][b-8]){                       //centre
                      c=capture_chaine(tab,a-4,b,tabvide)+capture_chaine(tab,a,b-8,tabvide);}
          else if (tab[a+4][b]!=tab[a][b]&&tab[a-4][b]==tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b]!=tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a-4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide);}
          else if (tab[a+4][b]==tab[a][b]&&tab[a-4][b]!=tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b]!=tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a,b+8,tabvide);}
          else if (tab[a+4][b]==tab[a][b]&&tab[a-4][b]==tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a][b]!=tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a+4,b,tabvide)+capture_chaine(tab,a-4,b,tabvide);}
          else if (tab[a+4][b]!=tab[a][b]&&tab[a-4][b]!=tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a][b]==tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a,b-8,tabvide);}
          else if (tab[a+4][b]==tab[a][b]&&tab[a-4][b]!=tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a][b]!=tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a+4,b,tabvide);}
          else if (tab[a+4][b]!=tab[a][b]&&tab[a-4][b]==tab[a][b]&&tab[a][b+8]!=tab[a][b]&&tab[a][b]!=tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a-4,b,tabvide);}
          else if (tab[a+4][b]!=tab[a][b]&&tab[a-4][b]!=tab[a][b]&&tab[a][b+8]==tab[a][b]&&tab[a][b]!=tab[a][b-8]){                       //centre
                       c=capture_chaine(tab,a,b+8,tabvide);}

    }}
    else {c=0;}}
else{c++;}
return c ;}
void capture_complete_chaine(char tab[37][80],int a,int b,char tabvide[37][80]){
     if (tab[a*4][b*8]=='B'){
     if (a==0&&b==0){if (capture_chaine(tab,a*4,(b+1)*8,tabvide)==0){kill_B(tab,a*4,(b+1)*8,tabvide);kill_W(tab,a*4,(b+1)*8,tabvide);}
                     else if (capture_chaine(tab,(a+1)*4,b*8,tabvide)==0){kill_B(tab,(a+1)*4,b*8,tabvide);kill_W(tab,(a+1)*4,b*8,tabvide);}}
     else if (a==0&&b*8==72){if (capture_chaine(tab,a*4,(b-1)*8,tabvide)==0){kill_B(tab,a*4,(b-1)*8,tabvide);kill_W(tab,a*4,(b-1)*8,tabvide);}
                           else if (capture_chaine(tab,(a+1)*4,b*8,tabvide)==0){kill_B(tab,(a+1)*4,b*8,tabvide);kill_W(tab,(a+1)*4,b*8,tabvide);}}
     else if (a*4==36&&b==0){if (capture_chaine(tab,a*4,(b+1)*8,tabvide)==0){kill_B(tab,a*4,(b+1)*8,tabvide);kill_W(tab,a*4,(b+1)*8,tabvide);}
                           else if (capture_chaine(tab,(a-1)*4,b*8,tabvide)==0){kill_B(tab,(a-1)*4,b*8,tabvide);kill_W(tab,(a-1)*4,b*8,tabvide);}}
     else if (a*4==36&&b*8==72){if (capture_chaine(tab,a*4,(b-1)*8,tabvide)==0){kill_B(tab,a*4,(b-1)*8,tabvide);kill_W(tab,a*4,(b-1)*8,tabvide);}
                           else if (capture_chaine(tab,(a-1)*4,b*8,tabvide)==0){kill_B(tab,(a-1)*4,b*8,tabvide);kill_W(tab,(a-1)*4,b*8,tabvide);}}
     else if (a==0&&b!=0&&b*8!=72){if (capture_chaine(tab,a*4,(b-1)*8,tabvide)==0){kill_B(tab,a*4,(b-1)*8,tabvide);kill_W(tab,a*4,(b-1)*8,tabvide);}
                           else if (capture_chaine(tab,(a+1)*4,b*8,tabvide)==0){kill_B(tab,(a+1)*4,b*8,tabvide);kill_W(tab,(a+1)*4,b*8,tabvide);}
                           else if (capture_chaine(tab,a*4,(b+1)*8,tabvide)==0){kill_B(tab,a*4,(b+1)*8,tabvide);kill_W(tab,a*4,(b+1)*8,tabvide);};}
     else if (b==0&&a!=0&&a*4!=36){if (capture_chaine(tab,(a-1)*4,(b-1)*8,tabvide)==0){kill_B(tab,(a-1)*4,(b-1)*8,tabvide);kill_W(tab,(a-1)*4,(b-1)*8,tabvide);}
                           else if (capture_chaine(tab,(a+1)*4,b*8,tabvide)==0){kill_B(tab,(a+1)*4,b*8,tabvide);kill_W(tab,(a+1)*4,b*8,tabvide);}
                           else if (capture_chaine(tab,a*4,(b+1)*8,tabvide)==0){kill_B(tab,a*4,(b+1)*8,tabvide);kill_W(tab,a*4,(b+1)*8,tabvide);};}
     else if (b*8==72&&a!=0&&a*4!=36){if (capture_chaine(tab,a*4,(b-1)*8,tabvide)==0){kill_B(tab,a*4,(b-1)*8,tabvide);kill_W(tab,a*4,(b-1)*8,tabvide);}
                           else if (capture_chaine(tab,(a+1)*4,b*8,tabvide)==0){kill_B(tab,(a+1)*4,b*8,tabvide);kill_W(tab,(a+1)*4,b*8,tabvide);}
                           else if (capture_chaine(tab,(a-1)*4,b*8,tabvide)==0){kill_B(tab,(a-1)*4,(b+1)*8,tabvide);kill_W(tab,(a-1)*4,(b+1)*8,tabvide);};}
    else if(a*4==36&&b!=0&&b*8!=72){if (capture_chaine(tab,a*4,(b-1)*8,tabvide)==0){kill_B(tab,a*4,(b-1)*8,tabvide);kill_W(tab,a*4,(b-1)*8,tabvide);}
                           else if (capture_chaine(tab,(a-1)*4,b*8,tabvide)==0){kill_B(tab,(a-1)*4,b*8,tabvide);kill_W(tab,(a-1)*4,b*8,tabvide);}
                           else if (capture_chaine(tab,a*4,(b+1)*8,tabvide)==0){kill_B(tab,a*4,(b+1)*8,tabvide);kill_W(tab,a*4,(b+1)*8,tabvide);};}
    else {if (capture_chaine(tab,a*4,(b-1)*8,tabvide)==0){kill_B(tab,a*4,(b-1)*8,tabvide);kill_W(tab,a*4,(b-1)*8,tabvide);}
          else if (capture_chaine(tab,(a+1)*4,b*8,tabvide)==0){kill_B(tab,(a+1)*4,b*8,tabvide);kill_W(tab,(a+1)*4,b*8,tabvide);}
          else if (capture_chaine(tab,a*4,(b+1)*8,tabvide)==0){kill_B(tab,a*4,(b+1)*8,tabvide);kill_W(tab,a*4,(b+1)*8,tabvide);}
          else if (capture_chaine(tab,(a-1)*4,b*8,tabvide)==0){kill_B(tab,(a-1)*4,b*8,tabvide);kill_W(tab,(a-1)*4,b*8,tabvide);}}}
    else if (tab[a*4][b*8]=='W'){
     if (a==0&&b==0){if (capture_chaine(tab,a*4,(b+1)*8,tabvide)==0){kill_B(tab,a*4,(b+1)*8,tabvide);kill_W(tab,a*4,(b+1)*8,tabvide);}
                     else if (capture_chaine(tab,(a+1)*4,b*8,tabvide)==0){kill_B(tab,(a+1)*4,b*8,tabvide);kill_W(tab,(a+1)*4,b*8,tabvide);}}
     else if (a==0&&b*8==72){if (capture_chaine(tab,a*4,(b-1)*8,tabvide)==0){kill_B(tab,a*4,(b-1)*8,tabvide);kill_W(tab,a*4,(b-1)*8,tabvide);}
                           else if (capture_chaine(tab,(a+1)*4,b*8,tabvide)==0){kill_B(tab,(a+1)*4,b*8,tabvide);kill_W(tab,(a+1)*4,b*8,tabvide);}}
     else if (a*4==36&&b==0){if (capture_chaine(tab,a*4,(b+1)*8,tabvide)==0){kill_B(tab,a*4,(b+1)*8,tabvide);kill_W(tab,a*4,(b+1)*8,tabvide);}
                           else if (capture_chaine(tab,(a-1)*4,b*8,tabvide)==0){kill_B(tab,(a-1)*4,b*8,tabvide);kill_W(tab,(a-1)*4,b*8,tabvide);}}
     else if (a*4==36&&b*8==72){if (capture_chaine(tab,a*4,(b-1)*8,tabvide)==0){kill_B(tab,a*4,(b-1)*8,tabvide);kill_W(tab,a*4,(b-1)*8,tabvide);}
                           else if (capture_chaine(tab,(a-1)*4,b*8,tabvide)==0){kill_B(tab,(a-1)*4,b*8,tabvide);kill_W(tab,(a-1)*4,b*8,tabvide);}}
     else if (a==0&&b!=0&&b*8!=72){if (capture_chaine(tab,a*4,(b-1)*8,tabvide)==0){kill_B(tab,a*4,(b-1)*8,tabvide);kill_W(tab,a*4,(b-1)*8,tabvide);}
                           else if (capture_chaine(tab,(a+1)*4,b*8,tabvide)==0){kill_B(tab,(a+1)*4,b*8,tabvide);kill_W(tab,(a+1)*4,b*8,tabvide);}
                           else if (capture_chaine(tab,a*4,(b+1)*8,tabvide)==0){kill_B(tab,a*4,(b+1)*8,tabvide);kill_W(tab,a*4,(b+1)*8,tabvide);};}
     else if (b==0&&a!=0&&a*4!=36){if (capture_chaine(tab,(a-1)*4,(b-1)*8,tabvide)==0){kill_B(tab,(a-1)*4,(b-1)*8,tabvide);kill_W(tab,(a-1)*4,(b-1)*8,tabvide);}
                           else if (capture_chaine(tab,(a+1)*4,b*8,tabvide)==0){kill_B(tab,(a+1)*4,b*8,tabvide);kill_W(tab,(a+1)*4,b*8,tabvide);}
                           else if (capture_chaine(tab,a*4,(b+1)*8,tabvide)==0){kill_B(tab,a*4,(b+1)*8,tabvide);kill_W(tab,a*4,(b+1)*8,tabvide);};}
     else if (b*8==72&&a!=0&&a*4!=36){if (capture_chaine(tab,a*4,(b-1)*8,tabvide)==0){kill_B(tab,a*4,(b-1)*8,tabvide);kill_W(tab,a*4,(b-1)*8,tabvide);}
                           else if (capture_chaine(tab,(a+1)*4,b*8,tabvide)==0){kill_B(tab,(a+1)*4,b*8,tabvide);kill_W(tab,(a+1)*4,b*8,tabvide);}
                           else if (capture_chaine(tab,(a-1)*4,b*8,tabvide)==0){kill_B(tab,(a-1)*4,(b+1)*8,tabvide);kill_W(tab,(a-1)*4,(b+1)*8,tabvide);};}
    else if(a*4==36&&b!=0&&b*8!=72){if (capture_chaine(tab,a*4,(b-1)*8,tabvide)==0){kill_B(tab,a*4,(b-1)*8,tabvide);kill_W(tab,a*4,(b-1)*8,tabvide);}
                           else if (capture_chaine(tab,(a-1)*4,b*8,tabvide)==0){kill_B(tab,(a-1)*4,b*8,tabvide);kill_W(tab,(a-1)*4,b*8,tabvide);}
                           else if (capture_chaine(tab,a*4,(b+1)*8,tabvide)==0){kill_B(tab,a*4,(b+1)*8,tabvide);kill_W(tab,a*4,(b+1)*8,tabvide);};}
    else {if (capture_chaine(tab,a*4,(b-1)*8,tabvide)==0){kill_B(tab,a*4,(b-1)*8,tabvide);kill_W(tab,a*4,(b-1)*8,tabvide);}
          else if (capture_chaine(tab,(a+1)*4,b*8,tabvide)==0){kill_B(tab,(a+1)*4,b*8,tabvide);kill_W(tab,(a+1)*4,b*8,tabvide);}
          else if (capture_chaine(tab,a*4,(b+1)*8,tabvide)==0){kill_B(tab,a*4,(b+1)*8,tabvide);kill_W(tab,a*4,(b+1)*8,tabvide);}
          else if (capture_chaine(tab,(a-1)*4,b*8,tabvide)==0){kill_B(tab,(a-1)*4,b*8,tabvide);kill_W(tab,(a-1)*4,b*8,tabvide);}}
    }}
void kill_W(char tab[37][80],int a,int b,char tabvide[37][80])
{ if (tab[a][b]=='W'){
      tab[a][b]=tabvide[a][b];
      if (a==0&&b==0){
      kill_W(tab,a+4,b,tabvide);kill_W(tab,a,b+8,tabvide);}
      else if (a==0&&b==72)
        {kill_W(tab,a+4,b,tabvide);kill_W(tab,a,b-8,tabvide);}
      else if (a==36&&b==0)
        {kill_W(tab,a-4,b,tabvide);kill_W(tab,a,b+8,tabvide);}
      else if (a==36&&b==72)
        {kill_W(tab,a-4,b,tabvide);kill_W(tab,a,b-8,tabvide);}
      else if (a==0&&b!=0&&b!=72)
        {kill_W(tab,a+4,b,tabvide);kill_W(tab,a,b-8,tabvide);kill_W(tab,a,b+8,tabvide);}
      else if (b==0&&a!=0&&a!=36)
        {kill_W(tab,a-4,b,tabvide);kill_W(tab,a+4,b,tabvide);kill_W(tab,a,b+8,tabvide);}
      else if (b==72&&a!=0&&a!=36)
        {kill_W(tab,a-4,b,tabvide);kill_W(tab,a+4,b,tabvide);kill_W(tab,a,b-8,tabvide);}
      else if(a==36&&b!=0&&b!=72)
        {kill_W(tab,a-4,b,tabvide);kill_W(tab,a,b-8,tabvide);kill_W(tab,a,b+8,tabvide);}
      else
        {kill_W(tab,a-4,b,tabvide);kill_W(tab,a+4,b,tabvide);kill_W(tab,a,b-8,tabvide);kill_W(tab,a,b+8,tabvide);}}}
void kill_B(char tab[37][80],int a,int b,char tabvide[37][80])
{  if (tab[a][b]=='B'){
      tab[a][b]=tabvide[a][b];
      if (a==0&&b==0)
        {kill_B(tab,a+4,b,tabvide);kill_B(tab,a,b+8,tabvide);}
      else if (a==0&&b==72)
        {kill_B(tab,a+4,b,tabvide);kill_B(tab,a,b-8,tabvide);}
      else if (a==36&&b==0)
        {kill_B(tab,a-4,b,tabvide);kill_W(tab,a,b+8,tabvide);}
      else if (a==36&&b==72)
        {kill_B(tab,a-4,b,tabvide);kill_W(tab,a,b-8,tabvide);}
      else if (a==0&&b!=0&&b!=72)
        {kill_B(tab,a+4,b,tabvide);kill_B(tab,a,b-8,tabvide);kill_B(tab,a,b+8,tabvide);}
      else if (b==0&&a!=0&&a!=36)
        {kill_B(tab,a-4,b,tabvide);kill_B(tab,a+4,b,tabvide);kill_B(tab,a,b+8,tabvide);}
      else if (b==72&&a!=0&&a!=36)
        {kill_B(tab,a-4,b,tabvide);kill_B(tab,a+4,b,tabvide);kill_B(tab,a,b-8,tabvide);}
      else if(a==36&&b!=0&&b!=72)
        {kill_B(tab,a-4,b,tabvide);kill_B(tab,a,b-8,tabvide);kill_B(tab,a,b+8,tabvide);}
      else
        {kill_B(tab,a-4,b,tabvide);kill_B(tab,a+4,b,tabvide);kill_B(tab,a,b-8,tabvide);kill_B(tab,a,b+8,tabvide);}}}

    void first_interface()
{
Color(15,0);
printf("\n");
printf("\t\t         /   GGGGGGGGG      OOOOOOOO   \\      \n");
printf("\t\t        /    G      GG      O      O    \\     \n");
printf("\t     __________/     G              O      O     \\__________     \n");
printf("\t\t       \\     G    GGGG      O      O     /    \n");
printf("\t\t        \\    G       G      O      O    /    \n");
printf("\t\t         \\   GGGGGGGGG      OOOOOOOO   /     \n");
printf("\t\t               ___________________\n");
printf("\t\t               CHALLENGE YOURSELF\n");
printf("\t\t               -------------------\n");
printf("\n");
printf("\t\t\t\t\t       			                                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t       			    	                                  *                           * \n");
printf("\t\t\t\t\t        			    	                        *         1 |  P L A Y          *\n");
printf("\t\t\t\t\t        			    	                          *                           *\n");
printf("\t\t\t\t\t          			    	                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t       			        	                                                    \n");
printf("\t\t\t\t\t       			                                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t        			    	                          *                           * \n");
printf("\t\t\t\t\t        			    	                        *      2 |  G O  R U L E S      *\n");
printf("\t\t\t\t\t        			    	                          *                           *\n");
printf("\t\t\t\t\t          			    	                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t       			        	                          \n");
printf("\t\t\t\t\t       			                                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t        			    	                          *                           * \n");
printf("\t\t\t\t\t        			    	                        *         3 |  Q U I T          *\n");
printf("\t\t\t\t\t        			    	                          *                           *\n");
printf("\t\t\t\t\t          			    	                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
}
void second_interface()
{
Color(15,0);
printf("\n");
printf("\t\t         /   GGGGGGGGG      OOOOOOOO   \\      \n");
printf("\t\t        /    G      GG      O      O    \\     \n");
printf("\t     __________/     G              O      O     \\__________     \n");
printf("\t\t       \\     G    GGGG      O      O     /    \n");
printf("\t\t        \\    G       G      O      O    /    \n");
printf("\t\t         \\   GGGGGGGGG      OOOOOOOO   /     \n");
printf("\t\t               ___________________\n");
printf("\t\t               CHALLENGE YOURSELF\n");
printf("\t\t               -------------------\n");
printf("\n");
printf("\t\t\t\t\t       			                                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t       			    	                                  *                           * \n");
printf("\t\t\t\t\t        			    	                        *        1 |  V S  C P U        *\n");
printf("\t\t\t\t\t        			    	                          *                           *\n");
printf("\t\t\t\t\t          			    	                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t       			        	                                                    \n");
printf("\t\t\t\t\t       			                                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t        			    	                          *                           * \n");
printf("\t\t\t\t\t        			    	                        *      2 | 2 P L A Y E R S      *\n");
printf("\t\t\t\t\t        			    	                          *                           *\n");
printf("\t\t\t\t\t          			    	                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t       			        	                                                   \n");
printf("\t\t\t\t\t       			                                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t        			    	                          *                           * \n");
printf("\t\t\t\t\t        			    	                        *       3 |  R E T U R N        *\n");
printf("\t\t\t\t\t        			    	                          *                           *\n");
printf("\t\t\t\t\t          			    	                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
}
void third_interface()
{
Color(15,0);
printf("\n");
printf("\t\t         /   GGGGGGGGG      OOOOOOOO   \\      \n");
printf("\t\t        /    G      GG      O      O    \\     \n");
printf("\t     __________/     G              O      O     \\__________     \n");
printf("\t\t       \\     G    GGGG      O      O     /    \n");
printf("\t\t        \\    G       G      O      O    /    \n");
printf("\t\t         \\   GGGGGGGGG      OOOOOOOO   /     \n");
printf("\t\t               ___________________\n");
printf("\t\t               CHALLENGE YOURSELF\n");
printf("\t\t               -------------------\n");
printf("\n");
printf("\t\t\t\t\t       			                                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t       			    	                                  *                           * \n");
printf("\t\t\t\t\t        			    	                        *     1 |  B E G I N N E R      *\n");
printf("\t\t\t\t\t        			    	                          *                           *\n");
printf("\t\t\t\t\t          			    	                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t       			        	                                                    \n");
printf("\t\t\t\t\t       			                                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t        			    	                          *                           * \n");
printf("\t\t\t\t\t        			    	                        *  2 | I N T E R M E D I A T E  *\n");
printf("\t\t\t\t\t        			    	                          *                           *\n");
printf("\t\t\t\t\t          			    	                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t       			        	                                                   \n");
printf("\t\t\t\t\t       			                                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t        			    	                          *                           * \n");
printf("\t\t\t\t\t        			    	                        *      3 |  A D V A N C E D     *\n");
printf("\t\t\t\t\t        			    	                          *                           *\n");
printf("\t\t\t\t\t          			    	                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t       			                                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
printf("\t\t\t\t\t        			    	                          *                           * \n");
printf("\t\t\t\t\t        			    	                        *       4 |  R E T U R N        *\n");
printf("\t\t\t\t\t        			    	                          *                           *\n");
printf("\t\t\t\t\t          			    	                            * ~~~~~~~~~~~~~~~~~~~~~ *\n");
char aze;
getch(aze);
}
void rules(){
Color (15,0);
printf("\n\t\t\t     *****Go Rules*****  \n\n");
printf("\t\t\tI  Players and equipments:\n\n");
printf("*Players:\n -Go is a game between two players, called Black and White.\n");
printf("*Board:\n -Go is played on a plain grid of 9 horizontal and 9 vertical lines, called a   board.\n");
printf(" -An \"intersection\" defines a point on the board where a horizontal line meets avertical line.\n");
printf(" -Two intersections are said to be \"adjacent\" if they are connected by a        horizontal or vertical line with no other intersections between them.\n");
printf("*Stones:\n -Go is played with playing tokens known as stones. Each player has at their    disposal an adequate supply of stones of the same color.\n");
printf("\n\t\t\t II Positions:\n\n");
printf(" -A position consists of an indication of the state of each intersection;       weither it is empty, occupied by a black stone, or by a white one.\n");
printf(" -Two placed stones of the same color (or two empty intersections) are said to  be \"connected\" if it is possible to draw a path from one intersection to the    other by passing through adjacent intersections of the same state (empty,       occupied by white, or occupied by black).\n");
printf(" -A liberty of a stone is an empty intersection adjacent to that stone or       adjacent to a stone which is connected to that stone.\n");
printf("\n\t\t\t III Play:\n\n");
printf(" -Initial position: At the beginning of the game, the board is empty.\n");
printf(" -Turns: Black moves first. The players alternate thereafter.\n");
printf(" -Moving: When it is their turn, a player may either pass or play. A play       consists of the following steps:\n");
printf("     °Step 1. (Playing a stone) Placing a stone of their color on an empty      intersection. It can never be moved to another intersection after being played.\n");
printf("     °Step 2. (Capture) Removing from the board any stones of their opponent's  color that have no liberties.\n");
printf("     °Step 3. (Self-capture) Removing from the board any stones of their own    color that have no liberties.\n");
printf(" -Optional Rule Prohibition of suicide: A play is illegal if one or more stones of that player's color would be removed in Step 3 of that play.\n");
printf(" -Prohibition of repetition: A play is illegal if it would have the effect      (after all steps of the play have been completed) of creating a position that   has occurred previously in the game.\n\n");
printf("\t\t\tIV  When does the game end?:\n\n");
printf(" -The game ends when both players have passed consecutively. The final position is the position on the board at the time the players pass consecutively.\n");
printf(" -An empty intersection is said to belong to a player's \"territory\" if all      stones adjacent to it or to an empty intersection connected to it are of that   player's color.\n");
printf(" -In the final position, an intersection is said to belong to a player's area ifeither: it belongs to that player's territory; or it is occupied by a stone of  that player's color.\n");
printf(" - A player's score is the number of intersections in their area in the final   position.\n");
printf(" -If one player has a higher score than the other, then that player wins.       Otherwise, the game is drawn.\n");
}

int cw=0,cb=0;
void comptage_territoire_blanc(char tab[33][80]){//une fonction qui compte le nombre total des pierres blanches
    int i,j;
    for (i=0;i<33;i++)
    {
        for (j=0;j<65;j++){
                if(i%4==0 && j%8==0){
                if (tab[i][j]=='W'){cw++;}}}
    }
}
void comptage_territoire_noir(char tab[33][80]){//une fonction qui compte le nombre total des pierres noires
    int i,j;
    for (i=0;i<33;i++)
    {
        for (j=0;j<65;j++){
                if(i%4==0 && j%8==0){
                if (tab[i][j]=='B'){cb++;}}}
    }
}
int specific_degree(char tab[33][80],int i,int j){//pour vérifier est ce qu'il existe encore des degrés de liberté pour une pierre de l'intersection (i,j)
                if (i==0 && j==0){
                    if(tab[i][j+8]=='_' || tab[i+4][j]=='|'){
                            return 1;
                    }
                    else {return 0;}
                    }
                else if(i==32 && j==64){
                    if(tab[i-4][j]=='|' || tab[i][j-8]=='_'){return 1;}
                    else {return 0;}}
                else if(i==0 && j==64){
                    if(tab[i][j-8]=='_' || tab[i+4][j]=='|'){return 1;}
                    else{return  0;}
                }
                else if (i==32 && j==0){
                    if(tab[i][j+8]=='_' || tab[i-4][j]=='|'){
                            return 1;
                    }
                    else {return 0;}
                    }
                else if(i==0 && j!=0 && j!=64 && j!=56 ){
                    if(tab[i][j+8]=='_' || tab[i+4][j]=='_' || tab[i][j-8]=='_'){return 1;}
                    else {return 0;}
                }
                else if(i==0 && j==56){
                    if(tab[i][j+8]==' ' || tab[i+4][j]=='_' || tab[i][j-8]=='_'){return 1;}
                    else {return 0;}
                }
                else if(i==32 && j!=0 && j!=64 && j!=8 && j!=56){
                    if(tab[i][j+8]=='_' || tab[i-4][j]=='_' || tab[i][j-8]=='_'){return 1;}
                    else {return 0;}
                }
                else if(i==32 && j==8){
                    if(tab[i][j+8]=='_' || tab[i-4][j]=='_' || tab[i][j-8]=='|'){return 1;}
                    else {return 0;}
                }
                else if(i==32 && j==56){
                    if(tab[i][j+8]=='|' || tab[i-4][j]=='_' || tab[i][j-8]=='_'){return 1;}
                    else {return 0;}
                }
                else if(i!=0 && i!=32 && i!=4 && j==0){
                    if(tab[i+4][j]=='|' || tab[i-4][j]=='|' || tab[i][j+8]=='_'){return 1;}
                    else {return 0;}
                }
                else if(i==4 && j==0){
                    if(tab[i-4][j]=='_' || tab[i+4][j]=='|' || tab[i][j+8]=='_'){return 1;}
                    else {return 0;}
                }
                else if(i!=0 && i!=32 && j==64 && i!=4){
                    if(tab[i+4][j]=='|' || tab[i-4][j]=='|' || tab[i][j-8]=='_'){return 1;}
                    else{return 0;}
                }
                else if(i==4 && j==64){
                    if(tab[i-4][j]==' ' || tab[i+4][j]=='|' || tab[i][j-8]=='_'){return 1;}
                    else{return 0;}
                }
                else if(j==8 && i<32 && i>0){
                    if(tab[i+4][j]=='_' || tab[i-4][j]=='_' || tab[i][j-8]=='|' || tab[i][j+8]=='_'){return 1;}
                    else{return 0;}
                }
                else if(j==56 && i<32 && i>0){
                    if(tab[i+4][j]=='_' || tab[i-4][j]=='_' || tab[i][j-8]=='_' || tab[i][j+8]=='|'){return 1;}
                    else{return 0;}
                }
                else {
                    if(tab[i][j+8]=='_' || tab[i][j-8]=='_' || tab[i+4][j]=='_' || tab[i-4][j]=='_'){return 1;}
                    else{return 0;}
                }
}
int global_degree(char tab[33][80]){//pour vérifier est ce qu'il existe encore des degrés de liberté dans tout le goban
       int i,j;
       for (i=0;i<33;i++)
    {
       for (j=0;j<65;j++){
       if (i==0 && j==0){
                    if(tab[i][j+8]=='_' || tab[i+4][j]=='|'){
                            return 1;break;
                    }
                    else {return 0;}
                    }
                else if(i==32 && j==64){
                    if(tab[i-4][j]=='|' || tab[i][j-8]=='_'){return 1;break;}
                    else {return 0;}}
                else if(i==0 && j==64){
                    if(tab[i][j-8]=='_' || tab[i+4][j]=='|'){return 1;break;}
                    else{return  0;}
                }
                else if (i==32 && j==0){
                    if(tab[i][j+8]=='_' || tab[i-4][j]=='|'){
                            return 1;break;
                    }
                    else {return 0;}
                    }
                else if(i==0 && j!=0 && j!=64 && j!=56 ){
                    if(tab[i][j+8]=='_' || tab[i+4][j]=='_' || tab[i][j-8]=='_'){return 1;break;}
                    else {return 0;}
                }
                else if(i==0 && j==56){
                    if(tab[i][j+8]==' ' || tab[i+4][j]=='_' || tab[i][j-8]=='_'){return 1;break;}
                    else {return 0;}
                }
                else if(i==32 && j!=0 && j!=64 && j!=8 && j!=56){
                    if(tab[i][j+8]=='_' || tab[i-4][j]=='_' || tab[i][j-8]=='_'){return 1;break;}
                    else {return 0;}
                }
                else if(i==32 && j==8){
                    if(tab[i][j+8]=='_' || tab[i-4][j]=='_' || tab[i][j-8]=='|'){return 1;break;}
                    else {return 0;}
                }
                else if(i==32 && j==56){
                    if(tab[i][j+8]=='|' || tab[i-4][j]=='_' || tab[i][j-8]=='_'){return 1;break;}
                    else {return 0;}
                }
                else if(i!=0 && i!=32 && i!=4 && j==0){
                    if(tab[i+4][j]=='|' || tab[i-4][j]=='|' || tab[i][j+8]=='_'){return 1;break;}
                    else {return 0;}
                }
                else if(i==4 && j==0){
                    if(tab[i-4][j]=='_' || tab[i+4][j]=='|' || tab[i][j+8]=='_'){return 1;break;}
                    else {return 0;}
                }
                else if(i!=0 && i!=32 && j==64 && i!=4){
                    if(tab[i+4][j]=='|' || tab[i-4][j]=='|' || tab[i][j-8]=='_'){return 1;break;}
                    else{return 0;}
                }
                else if(i==4 && j==64){
                    if(tab[i-4][j]==' ' || tab[i+4][j]=='|' || tab[i][j-8]=='_'){return 1;break;}
                    else{return 0;}
                }
                else if(j==8 && i<32 && i>0){
                    if(tab[i+4][j]=='_' || tab[i-4][j]=='_' || tab[i][j-8]=='|' || tab[i][j+8]=='_'){return 1;break;}
                    else{return 0;}
                }
                else if(j==56 && i<32 && i>0){
                    if(tab[i+4][j]=='_' || tab[i-4][j]=='_' || tab[i][j-8]=='_' || tab[i][j+8]=='|'){return 1;break;}
                    else{return 0;}
                }
                else {
                    if(tab[i][j+8]=='_' || tab[i][j-8]=='_' || tab[i+4][j]=='_' || tab[i-4][j]=='_'){return 1;break;}
                    else{return 0;}
                }
}}}
int capture_assure(char tab[33][80],int i,int j){//reflète la règle de la capture et faire disparaitre la pierre entourée par les pierres adversaires
                if(i%4==0 && j%8==0){
                if (i==0 && j==0){
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i+4][j]=='B'){return 1;}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i+4][j]=='W'){
                            return 1;}
                    else{return 0;}
                    }
                else if(i==32 && j==64){
                    if(tab[i][j]=='W' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i][j]=='B' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){return 1;}
                    else{return 0;}
                    }

                else if(i==0 && j==64){
                    if(tab[i][j]=='W' && tab[i][j-8]=='B' && tab[i+4][j]=='B'){return 1;}
                    else if(tab[i][j]=='B' && tab[i][j-8]=='W' && tab[i+4][j]=='W'){return 1;}
                    else{return 0;}
                }
                else if(i==32 && j==0){
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i-4][j]=='B'){return 1;}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i-4][j]=='W'){return 1;}
                    else{return 0;}
                }
                else if(i==0 && j!=0 && j!=64){
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i+4][j]=='B' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i][j-8]=='W'){return 1;}
                    else{return 0;}
                }
                if (i==32 && j==0){
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i-4][j]=='B'){return 1;}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i-4][j]=='W'){
                            return 1;}
                    else{return 0;}
                    }
                else if(i==32 && j!=0 && j!=64){
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){return 1;}
                    else{return 0;}
                }
                else if(i!=0 && i!=32 && j==0){
                    if(tab[i][j]=='W' && tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j+8]=='B'){return 1;}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){return 1;}
                    else{return 0;}
                }
                else if(i!=0 && i!=32&& j==64){
                    if(tab[i][j]=='W' && tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i][j]=='B' && tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){return 1;}
                    else{return 0;}
                }
                else {
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i][j-8]=='B' && tab[i+4][j]=='B' && tab[i-4][j]=='B'){
                            return 1;}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i][j-8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){
                            return 1;}
                    else{return 0;}
                }}
}
int listew[1000][2],listeb[1000][2];
int capture_suicide(char tab[33][80],int i,int j){//reflète la règle de la capture et faire disparaitre la pierre entourée par les pierres adversaires
                if(i%4==0 && j%8==0){
                if (i==0 && j==0){
                    if(capture_assure(tab,i,j)==1){
                        if(capture_assure(tab,i,j+8)==1 && capture_assure(tab,i+4,j)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j+8;
                            listeb[i+4][0]=i+4; listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j+8;
                            listew[i+4][0]=i+4; listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==1 && capture_assure(tab,i+4,j)==0 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;
                            listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;
                            listew[i][1]=j+8;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==0 && capture_assure(tab,i+4,j)==1 ){
                            if(tab[i][j]=='W'){listeb[i+4][0]=i+4;
                            listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i+4][0]=i+4;
                            listew[i+4][1]=j;
                            return 1;}}
                         else if(capture_assure(tab,i,j+8)==0 && capture_assure(tab,i+4,j)==0 ){return 0;}}
                    else{return 1;}}
                else if(i==32 && j==64){
                    if(capture_assure(tab,i,j)==1){
                        if(capture_assure(tab,i,j-8)==1 && capture_assure(tab,i-4,j)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j-8;
                            listeb[i-4][0]=i-4; listeb[i-4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j-8;
                            listew[i-4][0]=i-4; listew[i-4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i,j-8)==1 && capture_assure(tab,i-4,j)==0 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;
                            listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;
                            listew[i][1]=j-8;
                            return 1;}}
                        else if(capture_assure(tab,i,j-8)==0 && capture_assure(tab,i-4,j)==1 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;
                            listeb[i-4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;
                            listew[i-4][1]=j;
                            return 1;}}
                         else if(capture_assure(tab,i,j-8)==0 && capture_assure(tab,i-4,j)==0 ){return 0;}}
                    else{return 1;}}
                else if(i==0 && j==64){
                    if(capture_assure(tab,i,j)==1){
                        if(capture_assure(tab,i,j-8)==1 && capture_assure(tab,i+4,j)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j-8;
                            listeb[i+4][0]=i+4; listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j-8;
                            listew[i+4][0]=i+4; listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i,j-8)==1 && capture_assure(tab,i+4,j)==0 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;
                            listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;
                            listew[i][1]=j-8;
                            return 1;}}
                        else if(capture_assure(tab,i,j-8)==0 && capture_assure(tab,i+4,j)==1 ){
                            if(tab[i][j]=='W'){listeb[i+4][0]=i+4;
                            listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i+4][0]=i+4;
                            listew[i+4][1]=j;
                            return 1;}}
                         else if(capture_assure(tab,i,j-8)==0 && capture_assure(tab,i+4,j)==0 ){return 0;}}
                    else{return 1;}}
                if (i==32 && j==0){
                    if(capture_assure(tab,i,j)==1){
                        if(capture_assure(tab,i,j+8)==1 && capture_assure(tab,i-4,j)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j+8;
                            listeb[i-4][0]=i-4; listeb[i-4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j+8;
                            listew[i-4][0]=i-4; listew[i-4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==1 && capture_assure(tab,i-4,j)==0 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;
                            listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;
                            listew[i][1]=j+8;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==0 && capture_assure(tab,i-4,j)==1 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;
                            listeb[i-4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;
                            listew[i-4][1]=j;
                            return 1;}}
                         else if(capture_assure(tab,i,j+8)==0 && capture_assure(tab,i-4,j)==0 ){return 0;}}
                    else{return 1;}}
                else if(i==0 && j!=0 && j!=64){
                    if(capture_assure(tab,i,j)==1){
                        if(capture_assure(tab,i,j+8)==1 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j+8;listeb[i+4][0]=i+4;
                            listeb[i+4][1]=j; listeb[i][0]=i;listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j+8;listew[i+4][0]=i+4;
                            listew[i+4][1]=j;listew[i][0]=i;listew[i][1]=j-8;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==1 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==0 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j+8;
                            listeb[i+4][0]=i+4; listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j+8;
                            listew[i+4][0]=i+4; listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==1 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j+8;
                            listeb[i][0]=i; listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j+8;
                            listew[i][0]=i; listew[i][1]=j-8;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==0 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j-8;
                            listeb[i+4][0]=i+4; listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j-8;
                            listew[i+4][0]=i+4; listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==0 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==0 ){
                            if(tab[i][j]=='W'){listeb[i+4][0]=i+4;
                            listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i+4][0]=i+4;
                            listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==0 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;
                            listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;
                            listew[i][1]=j-8;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==1 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==0 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;
                            listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;
                            listew[i][1]=j+8;
                            return 1;}}
                         else if(capture_assure(tab,i,j+8)==0 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==0 ){return 0;}}
                    else{return 1;}}
                else if(i==32 && j!=0 && j!=64){
                    if(capture_assure(tab,i,j)==1){
                        if(capture_assure(tab,i,j+8)==1 && capture_assure(tab,i-4,j)==1 && capture_assure(tab,i,j-8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j+8;listeb[i-4][0]=i-4;
                            listeb[i-4][1]=j; listeb[i][0]=i;listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j+8;listew[i-4][0]=i-4;
                            listew[i-4][1]=j;listew[i][0]=i;listew[i][1]=j-8;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==1 && capture_assure(tab,i-4,j)==1 && capture_assure(tab,i,j-8)==0 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j+8;
                            listeb[i-4][0]=i-4; listeb[i-4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j+8;
                            listew[i-4][0]=i-4; listew[i-4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==1 && capture_assure(tab,i-4,j)==0 && capture_assure(tab,i,j-8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j+8;
                            listeb[i][0]=i; listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j+8;
                            listew[i][0]=i; listew[i][1]=j-8;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==0 && capture_assure(tab,i-4,j)==1 && capture_assure(tab,i,j-8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j-8;
                            listeb[i-4][0]=i-4; listeb[i-4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j-8;
                            listew[i-4][0]=i-4; listew[i-4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==0 && capture_assure(tab,i-4,j)==1 && capture_assure(tab,i,j-8)==0 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;
                            listeb[i-4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;
                            listew[i-4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==0 && capture_assure(tab,i-4,j)==0 && capture_assure(tab,i,j-8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;
                            listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;
                            listew[i][1]=j-8;
                            return 1;}}
                        else if(capture_assure(tab,i,j+8)==1 && capture_assure(tab,i-4,j)==0 && capture_assure(tab,i,j-8)==0 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;
                            listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;
                            listew[i][1]=j+8;
                            return 1;}}
                         else if(capture_assure(tab,i,j+8)==0 && capture_assure(tab,i-4,j)==0 && capture_assure(tab,i,j-8)==0 ){return 0;}}
                    else{return 1;}}
                else if(i!=0 && i!=32 && j==0){
                    if(capture_assure(tab,i,j)==1){
                        if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j+8)==1 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;listeb[i][1]=j;listeb[i+4][0]=i+4;
                            listeb[i+4][1]=j; listeb[i][0]=i;listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;listew[i-4][1]=j;listew[i+4][0]=i+4;
                            listew[i+4][1]=j;listew[i][0]=i;listew[i][1]=j+8;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j+8)==0 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;listeb[i-4][1]=j;
                            listeb[i+4][0]=i+4; listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;listew[i-4][1]=j;
                            listew[i+4][0]=i+4; listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j+8)==1 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;listeb[i-4][1]=j;
                            listeb[i][0]=i; listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;listew[i-4][1]=j;
                            listew[i][0]=i; listew[i][1]=j+8;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j+8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j+8;
                            listeb[i+4][0]=i+4; listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j+8;
                            listew[i+4][0]=i+4; listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j+8)==0 ){
                            if(tab[i][j]=='W'){listeb[i+4][0]=i+4;
                            listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i+4][0]=i+4;
                            listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j+8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;
                            listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;
                            listew[i][1]=j+8;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j+8)==0 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;
                            listeb[i-4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;
                            listew[i-4][1]=j;
                            return 1;}}
                         else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j+8)==0 ){return 0;}}
                    else{return 1;}}
                else if(i!=0 && i!=32 && j==64){
                    if(capture_assure(tab,i,j)==1){
                        if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==1 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;listeb[i][1]=j;listeb[i+4][0]=i+4;
                            listeb[i+4][1]=j; listeb[i][0]=i;listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;listew[i-4][1]=j;listew[i+4][0]=i+4;
                            listew[i+4][1]=j;listew[i][0]=i;listew[i][1]=j-8;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==0 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;listeb[i-4][1]=j;
                            listeb[i+4][0]=i+4; listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;listew[i-4][1]=j;
                            listew[i+4][0]=i+4; listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==1 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;listeb[i-4][1]=j;
                            listeb[i][0]=i; listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;listew[i-4][1]=j;
                            listew[i][0]=i; listew[i][1]=j-8;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j-8;
                            listeb[i+4][0]=i+4; listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j-8;
                            listew[i+4][0]=i+4; listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==0 ){
                            if(tab[i][j]=='W'){listeb[i+4][0]=i+4;
                            listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i+4][0]=i+4;
                            listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;
                            listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;
                            listew[i][1]=j-8;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==0 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;
                            listeb[i-4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;
                            listew[i-4][1]=j;
                            return 1;}}
                         else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==0 ){return 0;}}
                    else{return 1;}}
                else {
                     if(capture_assure(tab,i,j)==1){
                        if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==1 && capture_assure(tab,i,j+8)==1 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;listeb[i][1]=j;listeb[i+4][0]=i+4;
                            listeb[i+4][1]=j; listeb[i][0]=i;listeb[i][1]=j-8;listeb[i][0]=i;listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;listew[i][1]=j;listew[i+4][0]=i+4;
                            listew[i+4][1]=j; listew[i][0]=i;listew[i][1]=j-8;listew[i][0]=i;listew[i][1]=j+8;
                            return 1;}}
                      else if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==0 && capture_assure(tab,i,j+8)==1){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;listeb[i-4][1]=j;
                            listeb[i+4][0]=i+4; listeb[i+4][1]=j;listeb[i][0]=i;listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;listew[i-4][1]=j;
                            listew[i+4][0]=i+4; listew[i+4][1]=j;listew[i][0]=i;listew[i][1]=j+8;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==1 && capture_assure(tab,i,j+8)==1 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;listeb[i-4][1]=j;
                            listeb[i][0]=i; listeb[i][1]=j-8;listeb[i][0]=i;listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;listew[i-4][1]=j;
                            listew[i][0]=i; listew[i][1]=j-8;listew[i][0]=i;listew[i][1]=j+8;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==1 && capture_assure(tab,i,j+8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j-8;
                            listeb[i+4][0]=i+4; listeb[i+4][1]=j;listeb[i][0]=i;listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j-8;
                            listew[i+4][0]=i+4; listew[i+4][1]=j;listew[i][0]=i;listew[i][1]=j+8;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==0 && capture_assure(tab,i,j+8)==1 ){
                            if(tab[i][j]=='W'){listeb[i+4][0]=i+4;
                            listeb[i+4][1]=j;listeb[i][0]=i;listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i+4][0]=i+4;
                            listew[i+4][1]=j;listew[i][0]=i;listew[i][1]=j+8;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==1 && capture_assure(tab,i,j+8)==1){
                            if(tab[i][j]=='W'){listeb[i][0]=i;
                            listeb[i][1]=j-8;listeb[i][0]=i;listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;
                            listew[i][1]=j-8;listew[i][0]=i;listew[i][1]=j+8;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==0 && capture_assure(tab,i,j+8)==1 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;
                            listeb[i-4][1]=j;listeb[i][1]=i;listeb[i][2]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;
                            listew[i-4][1]=j;listew[i][0]=i;listew[i][1]=j+8;
                            return 1;}}
                         else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==0 && capture_assure(tab,i,j+8)==1 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;
                            listeb[i][1]=j+8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;
                            listew[i][1]=j+8;
                            return 1;}}
                         else if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==1 && capture_assure(tab,i,j+8)==0 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;listeb[i][1]=j;listeb[i+4][0]=i+4;
                            listeb[i+4][1]=j; listeb[i][0]=i;listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;listew[i-4][1]=j;listew[i+4][0]=i+4;
                            listew[i+4][1]=j;listew[i][0]=i;listew[i][1]=j-8;
                            return 1;}}
                         else if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==0 && capture_assure(tab,i,j+8)==0 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;listeb[i-4][1]=j;
                            listeb[i+4][0]=i+4; listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;listew[i-4][1]=j;
                            listew[i+4][0]=i+4; listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==1 && capture_assure(tab,i,j+8)==0 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;listeb[i-4][1]=j;
                            listeb[i][0]=i; listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;listew[i-4][1]=j;
                            listew[i][0]=i; listew[i][1]=j-8;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==1 && capture_assure(tab,i,j+8)==0){
                            if(tab[i][j]=='W'){listeb[i][0]=i;listeb[i][1]=j-8;
                            listeb[i+4][0]=i+4; listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;listew[i][1]=j-8;
                            listew[i+4][0]=i+4; listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==1 && capture_assure(tab,i,j-8)==0 && capture_assure(tab,i,j+8)==0 ){
                            if(tab[i][j]=='W'){listeb[i+4][0]=i+4;
                            listeb[i+4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i+4][0]=i+4;
                            listew[i+4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==1 && capture_assure(tab,i,j+8)==0 ){
                            if(tab[i][j]=='W'){listeb[i][0]=i;
                            listeb[i][1]=j-8;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i][0]=i;
                            listew[i][1]=j-8;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==1 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==0 && capture_assure(tab,i,j+8)==0 ){
                            if(tab[i][j]=='W'){listeb[i-4][0]=i-4;
                            listeb[i-4][1]=j;
                            return 1;}
                            else if(tab[i][j]=='B'){listew[i-4][0]=i-4;
                            listew[i-4][1]=j;
                            return 1;}}
                        else if(capture_assure(tab,i-4,j)==0 && capture_assure(tab,i+4,j)==0 && capture_assure(tab,i,j-8)==0 && capture_assure(tab,i,j+8)==0 ){return 0 ;}}
                      else{return 1;}
                }}
}
void capture(char tab[33][80],int i,int j){//reflèter la règle de la capture et faire disparaitre la pierre entourée par les pierres adversaires
       for (i=0;i<33;i++)
    {
        for (j=0;j<65;j++){
                if(i%4==0 && j%8==0){
                if (i==0 && j==0){
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i+4][j]=='B'){
                          if(capture_assure(tab,i+4,j)==1 || capture_assure(tab,i,j+8)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='_';cb++;}}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i+4][j]=='W'){
                            if(capture_assure(tab,i+4,j)==1 || capture_assure(tab,i,j+8)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='_';cw++;}}
                    }
                else if(i==32 && j==64){
                    if(tab[i][j]=='W' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){
                        if(capture_assure(tab,i-4,j)==1 || capture_assure(tab,i,j-8)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='|';cb++;}}
                    else if(tab[i][j]=='B' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){
                            if(capture_assure(tab,i-4,j)==1 || capture_assure(tab,i,j-8)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='|';cw++;}}
                    }
                else if(i==0 && j==64){
                    if(tab[i][j]=='W' && tab[i][j-8]=='B' && tab[i+4][j]=='B'){
                           if(capture_assure(tab,i+4,j)==1 || capture_assure(tab,i,j-8)==1){capture_else(tab,i,j);}
                            else{tab[i][j]=' ';cb++;}}
                    else if(tab[i][j]=='B' && tab[i][j-8]=='W' && tab[i+4][j]=='W'){
                        if(capture_assure(tab,i+4,j)==1 || capture_assure(tab,i,j-8)==1){capture_else(tab,i,j);}
                            else{tab[i][j]=' ';cw++;}}
                }
                if (i==32 && j==0){
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i-4][j]=='B'){
                           if(capture_assure(tab,i-4,j)==1 || capture_assure(tab,i,j+8)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='|';cb++;}}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i-4][j]=='W'){
                           if(capture_assure(tab,i-4,j)==1 || capture_assure(tab,i,j+8)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='|';cw++;}}
                    }
                else if(i==0 && j!=0 && j!=64){
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i+4][j]=='B' && tab[i][j-8]=='B'){
                            if(capture_assure(tab,i,j-8)==1 || capture_assure(tab,i,j+8)==1 || capture_assure(tab,i+4,j)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='_';cb++;}}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i][j-8]=='W'){
                        if(capture_assure(tab,i,j-8)==1 || capture_assure(tab,i,j+8)==1 || capture_assure(tab,i+4,j)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='_';cw++;}}
                }
                else if(i==32 && j!=0 && j!=64){
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){
                            if(capture_assure(tab,i-4,j)==1 || capture_assure(tab,i,j+8)==1 || capture_assure(tab,i,j-8)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='_';cb++;}}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){
                        if(capture_assure(tab,i-4,j)==1 || capture_assure(tab,i,j+8)==1 || capture_assure(tab,i,j-8)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='_';cw++;}}
                }
                else if(i!=0 && i!=32 && j==0){
                    if(tab[i][j]=='W' && tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j+8]=='B'){
                           if(capture_assure(tab,i-4,j)==1 || capture_assure(tab,i,j+8)==1 || capture_assure(tab,i+4,j)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='|';cb++;}}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){
                        if(capture_assure(tab,i-4,j)==1 || capture_assure(tab,i,j+8)==1 || capture_assure(tab,i+4,j)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='|';cw++;}}
                }
                else if(i!=0 && i!=32 && j==64){
                    if(tab[i][j]=='W' && tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){
                            if(capture_assure(tab,i-4,j)==1 || capture_assure(tab,i,j-8)==1 || capture_assure(tab,i+4,j)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='|';cb++;}}
                    else if(tab[i][j]=='B' && tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){
                            if(capture_assure(tab,i-4,j)==1 || capture_assure(tab,i,j-8)==1 || capture_assure(tab,i+4,j)==1){capture_else(tab,i,j);}
                            else{tab[i][j]='|';cw++;}}
                }
                else {
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i][j-8]=='B' && tab[i+4][j]=='B' && tab[i-4][j]=='B'){
                            if(capture_assure(tab,i,j+8)==1 || capture_assure(tab,i,j-8)==1 || capture_assure(tab,i+4,j)==1 || capture_assure(tab,i-4,j)==1  ){capture_else(tab,i,j);}
                            else{tab[i][j]='_';cb++;}}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i][j-8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){
                            if(capture_assure(tab,i,j+8)==1 || capture_assure(tab,i,j-8)==1 || capture_assure(tab,i+4,j)==1 || capture_assure(tab,i-4,j)==1  ){capture_else(tab,i,j);}
                            else{tab[i][j]='_';cw++;}}
                }}
        }
    }
}
void capture_else(char tab[33][80],int x,int y){//reflète la règle de la capture et faire disparaitre la pierre entourée par les pierres adversaires
      int i,j;
      for (i=0;i<33;i++)
    {
        for (j=0;j<65;j++){
                if(i%4==0 && j%8==0){
                if(i==x && j==y){continue;}
                else if (i==0 && j==0){
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i+4][j]=='B'){
                            tab[i][j]='_';
                            cb++;
                    }
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i+4][j]=='W'){
                            tab[i][j]='_';
                            cw++;
                    }}
                else if(i==32 && j==64){
                    if(tab[i][j]=='W' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){tab[i][j]='|';cb++;}
                    else if(tab[i][j]=='B' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){tab[i][j]='|';cw++;}
                    }
                else if(i==0 && j==64){
                    if(tab[i][j]=='W' && tab[i][j-8]=='B' && tab[i+4][j]=='B'){tab[i][j]=' ';cb++;}
                    else if(tab[i][j]=='B' && tab[i][j-8]=='W' && tab[i+4][j]=='W'){tab[i][j]=' ';cw++;}
                }
                else if(j==0 && i==32){
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i-4][j]=='B'){tab[i][j]='|';cb++;}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i-4][j]=='W'){tab[i][j]='|';cw++;}
                }
                else if(i==0 && j!=0 && j!=64){
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i+4][j]=='B' &&tab[i][j-8]=='B'){tab[i][j]='_';cb++;}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i][j-8]=='W'){tab[i][j]='_';cw++;}
                }
                else if(i==32 && j!=0 && j!=64){
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i-4][j]=='B' &&tab[i][j-8]=='B'){tab[i][j]='_';cb++;}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){tab[i][j]='_';cw++;}
                }
                else if(i!=0 && i!=32 && j==0){
                    if(tab[i][j]=='W' && tab[i+4][j]=='B' && tab[i-4][j]=='B' &&tab[i][j+8]=='B'){tab[i][j]='|';cb++;}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){tab[i][j]='|';cw++;}
                }
                else if(i!=0 && i!=32 && j==64){
                    if(tab[i][j]=='W' && tab[i+4][j]=='B' && tab[i-4][j]=='B' &&tab[i][j-8]=='B'){tab[i][j]='|';cb++;}
                    else if(tab[i][j]=='B' && tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){tab[i][j]='|';cw++;}
                }
                else {
                    if(tab[i][j]=='W' && tab[i][j+8]=='B' && tab[i][j-8]=='B' &&tab[i+4][j]=='B' && tab[i-4][j]=='B'){
                            tab[i][j]='_';cb++;}
                    else if(tab[i][j]=='B' && tab[i][j+8]=='W' && tab[i][j-8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){
                            tab[i][j]='_';cw++;}
                }}
        }
    }
}
void dominance_territoire(char tab[33][80]){//une fonction qui positionne le territoire dominé du blan et noir et incrémente leurs comptes,ce sont les positions de suicide
      int i,j;
      for (i=0;i<33;i++)
    {
        for (j=0;j<65;j++){
                if(i%4==0 && j%8==0){
                if (i==0 && j==0){
                    if(tab[i][j]=='_' && tab[i][j+8]=='B' && tab[i+4][j]=='B'){
                            cb++;}
                    else if(tab[i][j]==' ' && tab[i][j+8]=='W' && tab[i+4][j]=='W'){
                            cw++;
                    }}
                else if(i==32 && j==64){
                    if(tab[i][j]=='|' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){cb++;}
                    else if(tab[i][j]=='|' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){cw++;}
                    }
                else if(i==0 && j==64){
                    if(tab[i][j]==' ' && tab[i][j-8]=='B' && tab[i+4][j]=='B'){cb++;}
                    else if(tab[i][j]==' ' && tab[i][j-8]=='W' && tab[i+4][j]=='W'){cw++;}
                }
                else if(j==0 && i==32){
                    if(tab[i][j]=='|' && tab[i][j-8]=='B' && tab[i+4][j]=='B'){cb++;}
                    else if(tab[i][j]=='|' && tab[i][j-8]=='W' && tab[i+4][j]=='W'){cw++;}
                }
                else if(i==0 && j!=0 && j!=64){
                    if(tab[i][j]=='_' && tab[i][j+8]=='B' && tab[i+4][j]=='B' &&tab[i][j-8]=='B'){cb++;}
                    else if(tab[i][j]=='_' && tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i][j-8]=='W'){cw++;}
                }
                else if(i==32 && j!=0 && j!=64){
                    if(tab[i][j]=='_' && tab[i][j+8]=='B' && tab[i-4][j]=='B' &&tab[i][j-8]=='B'){cb++;}
                    else if(tab[i][j]=='_' && tab[i][j+8]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){cw++;}
                }
                else if(i!=0 && i!=32 && j==0){
                    if(tab[i][j]=='|' && tab[i+4][j]=='B' && tab[i-4][j]=='B' &&tab[i][j+8]=='B'){cb++;}
                    else if(tab[i][j]=='|' && tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){cw++;}
                }
                else if(i!=0 && i!=32 && j==64){
                    if(tab[i][j]=='|' && tab[i+4][j]=='B' && tab[i-4][j]=='B' &&tab[i][j-8]=='B'){cb++;}
                    else if(tab[i][j]=='|' && tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){cw++;}
                }
                else {
                    if(tab[i][j]=='_' && tab[i][j+8]=='B' && tab[i][j-8]=='B' &&tab[i+4][j]=='B' && tab[i-4][j]=='B'){
                            cb++;}
                    else if(tab[i][j]=='_' && tab[i][j+8]=='W' && tab[i][j-8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){
                            cw++;}
                }}
        }
    }
}
void gagnant(char tab[33][80]){
    system("cls");
    comptage_territoire_blanc(tab);
    comptage_territoire_noir(tab);
    dominance_territoire(tab);
    if(cw>cb){printf("The white player! You are the winner ! Congratulations\n");}
    else if(cb>cw){printf("The black player! You are the winner ! Congratulations\n");}
    else if(cw==cb){cw=cw+7;gagnant(tab);}//le komi : ajouter 7 points pour le blanc car c'est toujours le noir qui commence
printf("\n\n\t\t\t\t            ___________    ____ \n");
printf("\t\t\t\t     ______/   \\__//   \\__/____\\ \n");
printf("\t\t\t\t   _/   \\_/  :           //____\\\\  \n");
printf("\t\t\t\t  /|      :  :  ..      /        \\ \n");
printf("\t\t\t\t | |     ::     ::      \\        / \n");
printf("\t\t\t\t | |     :|     ||     \\ \\______/ \n");
printf("\t\t\t\t | |     ||     ||      |\\  /  |  \n");
printf("\t\t\t\t  \\|     ||     ||      |   / | \\ \n");
printf("\t\t\t\t   |     ||     ||      |  / /_\\ \\ \n");
printf("\t\t\t\t   | ___ || ___ ||      | /  /    \\ \n");
printf("\t\t\t\t    \\_-_/  \\_-_/ | ____ |/__/      \\ \n");
printf("\t\t\t\t                 _\\_--_/    \\      /  \n");
printf("\t\t\t\t                /____             /  \n");
printf("\t\t\t\t               /     \\           /  \n");
printf("\t\t\t\t               \\______\\_________/ \n");
printf("points de noir : %d\npoints de blanc :%d",cb,cw);
exit(0);
}
int h=0;
int handicap=1;
char reponse;
//Fin functions of technical and basic rules of capture/suicide/winner + global variables
// Functions of the game automatization and tsumego + global variables
int limitb[1][2];limitw[1][2];
void limitation_white(char tab[33][80]){//renvoie la position de l'intersection (i,j) qui reste comme degré de liberté pour la pierre blanche et la met dans une listeb pour que la cpu pose la pierre là
               int i,j;
               for (i=0;i<33;i++)
    {
        for (j=0;j<65;j++){
            if(tab[i][j]=='W'){
                if (i==0 && j==0){
                    if(tab[i][j+8]=='_' && tab[i+4][j]!='|'){
                            limitb[0][0]=i;limitb[0][1]=j+8;break;
                    }
                    else if(tab[i][j+8]!='_' && tab[i+4][j]=='|'){limitb[0][0]=i+4;limitb[0][1]=j;break;}

                    }
                else if(i==32 && j==64){
                    if(tab[i-4][j]=='|' && tab[i][j-8]!='_'){limitb[0][0]=i-4;limitb[0][1]=j;break;}
                    else if(tab[i-4][j]!='|' && tab[i][j-8]=='_'){limitb[0][0]=i;limitb[0][1]=j-8;break;}
                    }
                else if(i==0 && j==64){
                    if(tab[i][j-8]=='_' && tab[i+4][j]!='|'){limitb[0][0]=i;limitb[0][1]=j-8;break;}
                    else if(tab[i][j-8]!='_' && tab[i+4][j]=='|'){limitb[0][0]=i+4;limitb[0][1]=j;break;}

                }
                if (i==32 && j==0){
                    if(tab[i][j+8]=='_' && tab[i-4][j]!='|'){limitb[0][0]=i;limitb[0][1]=j+8;break;}
                    else if(tab[i][j+8]!='_' && tab[i-4][j]=='|'){limitb[0][0]=i-4;limitb[0][1]=j;break;}
                    }
                else if(i==0 && j!=0 && j!=64 && j!=56 ){
                    if(tab[i][j+8]!='_' && tab[i+4][j]!='_' && tab[i][j-8]=='_'){limitb[0][0]=i;limitb[0][1]=j-8;break;}
                    else if(tab[i][j+8]!='_' && tab[i+4][j]=='_' && tab[i][j-8]!='_'){limitb[0][0]=i+4;limitb[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i+4][j]!='_' && tab[i][j-8]!='_'){limitb[0][0]=i;limitb[0][1]=j+8;break;}

                }
                else if(i==0 && j==56){
                    if(tab[i][j+8]!=' ' && tab[i+4][j]!='_' && tab[i][j-8]=='_'){limitb[0][0]=i;limitb[0][1]=j-8;break;}
                    else if(tab[i][j+8]!=' ' && tab[i+4][j]=='_' && tab[i][j-8]!='_'){limitb[0][0]=i+4;limitb[0][1]=j;break;}
                    else if(tab[i][j+8]==' ' && tab[i+4][j]!='_' && tab[i][j-8]!='_'){limitb[0][0]=i;limitb[0][1]=j+8;break;}

                }
                else if(i==32 && j!=0 && j!=64 && j!=8 && j!=56){
                    if(tab[i][j+8]!='_' && tab[i-4][j]!='_' && tab[i][j-8]=='_'){limitb[0][0]=i;limitb[0][1]=j-8;break;}
                    else if(tab[i][j+8]!='_' && tab[i-4][j]=='_' && tab[i][j-8]!='_'){limitb[0][0]=i-4;limitb[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]!='_' && tab[i][j-8]!='_'){limitb[0][0]=i;limitb[0][1]=j+8;break;}

                }
                else if(i==32 && j==8){
                    if(tab[i][j+8]!='_' && tab[i-4][j]!='_' && tab[i][j-8]=='|'){limitb[0][0]=i;limitb[0][1]=j-8;break;}
                    else if(tab[i][j+8]!='_' && tab[i-4][j]=='_' && tab[i][j-8]!='|'){limitb[0][0]=i-4;limitb[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]!='_' && tab[i][j-8]!='|'){limitb[0][0]=i;limitb[0][1]=j+8;break;}

                }
                else if(i==32 && j==56){
                    if(tab[i][j+8]!='|' && tab[i-4][j]!='_' && tab[i][j-8]=='_'){limitb[0][0]=i;limitb[0][1]=j-8;break;}
                    else if(tab[i][j+8]!='|' && tab[i-4][j]=='_' && tab[i][j-8]!='_'){limitb[0][0]=i-4;limitb[0][1]=j;break;}
                    else if(tab[i][j+8]=='|' && tab[i-4][j]!='_' && tab[i][j-8]!='_'){limitb[0][0]=i;limitb[0][1]=j+8;break;}

                }
                else if(i!=0 && i!=32 && i!=4 && j==0){
                    if(tab[i+4][j]!='|' && tab[i-4][j]!='|' && tab[i][j+8]=='_'){limitb[0][0]=i;limitb[0][1]=j+8;break;}
                    else if(tab[i+4][j]!='|' && tab[i-4][j]=='|' && tab[i][j+8]!='_'){limitb[0][0]=i-4;limitb[0][1]=j;break;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]!='|' && tab[i][j+8]!='_'){limitb[0][0]=i+4;limitb[0][1]=j;break;}

                }
                else if(i==4 && j==0){
                    if(tab[i-4][j]!='_' && tab[i+4][j]!='|' && tab[i][j+8]=='_'){limitb[0][0]=i;limitb[0][1]=j+8;break;}
                    else if(tab[i-4][j]!='_' && tab[i+4][j]=='|' && tab[i][j+8]!='_'){limitb[0][0]=i+4;limitb[0][1]=j;break;}
                    else if(tab[i-4][j]=='_' && tab[i+4][j]!='|' && tab[i][j+8]!='_'){limitb[0][0]=i-4;limitb[0][1]=j;break;}

                }
                else if(i!=0 && i!=32 && j==64 && i!=4){
                    if(tab[i+4][j]!='|' && tab[i-4][j]!='|' && tab[i][j-8]=='_'){limitb[0][0]=i;limitb[0][1]=j-8;break;}
                    else if(tab[i+4][j]!='|' && tab[i-4][j]=='|' && tab[i][j-8]!='_'){limitb[0][0]=i-4;limitb[0][1]=j;break;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]!='|' && tab[i][j-8]!='_'){limitb[0][0]=i+4;limitb[0][1]=j;break;}

                }
                else if(i==4 && j==64){
                    if(tab[i-4][j]!=' ' && tab[i+4][j]!='|' && tab[i][j-8]=='_'){limitb[0][0]=i;limitb[0][1]=j-8;break;}
                    else if(tab[i-4][j]!=' ' && tab[i+4][j]=='|' && tab[i][j-8]!='_'){limitb[0][0]=i+4;limitb[0][1]=j;break;}
                    else if(tab[i-4][j]==' ' && tab[i+4][j]!='|' && tab[i][j-8]!='_'){limitb[0][0]=i-4;limitb[0][1]=j;break;}

                }
                else if(j==8 && i!=32 && i!=0){
                    if(tab[i+4][j]!='_' && tab[i-4][j]!='_' && tab[i][j-8]!='|' && tab[i][j+8]=='_'){limitb[0][0]=i;limitb[0][1]=j+8;break;}
                    else if(tab[i+4][j]!='_' && tab[i-4][j]!='_' && tab[i][j-8]=='|' && tab[i][j+8]!='_'){limitb[0][0]=i;limitb[0][1]=j-8;break;}
                    else if(tab[i+4][j]!='_' && tab[i-4][j]=='_' && tab[i][j-8]!='|' && tab[i][j+8]!='_'){limitb[0][0]=i-4;limitb[0][1]=j;break;}
                    else if(tab[i+4][j]=='_' && tab[i-4][j]!='_' && tab[i][j-8]!='|' && tab[i][j+8]!='_'){limitb[0][0]=i+4;limitb[0][1]=j;break;}

                }
                else if(j==56 && i!=32 && i!=0){
                    if(tab[i+4][j]!='_' && tab[i-4][j]!='_' && tab[i][j-8]!='_' && tab[i][j+8]=='|'){limitb[0][0]=i;limitb[0][1]=j+8;break;}
                    else if(tab[i+4][j]!='_' && tab[i-4][j]!='_' && tab[i][j-8]=='_' && tab[i][j+8]!='|'){limitb[0][0]=i;limitb[0][1]=j-8;break;}
                    else if(tab[i+4][j]!='_' && tab[i-4][j]=='_' && tab[i][j-8]!='_' && tab[i][j+8]!='|'){limitb[0][0]=i-4;limitb[0][1]=j;break;}
                    else if(tab[i+4][j]=='_' && tab[i-4][j]!='_' && tab[i][j-8]!='_' && tab[i][j+8]!='|'){limitb[0][0]=i+4;limitb[0][1]=j;break;}

                }
                else {
                    if(tab[i][j+8]!='_' && tab[i][j-8]!='_' && tab[i+4][j]!='_' && tab[i-4][j]=='_'){limitb[0][0]=i-4;limitb[0][1]=j;break;}
                    else if(tab[i][j+8]!='_' && tab[i][j-8]!='_' && tab[i+4][j]=='_' && tab[i-4][j]!='_'){limitb[0][0]=i+4;limitb[0][1]=j;break;}
                    else if(tab[i][j+8]!='_' && tab[i][j-8]=='_' && tab[i+4][j]!='_' && tab[i-4][j]!='_'){limitb[0][0]=i;limitb[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='_' && tab[i][j-8]!='_' && tab[i+4][j]!='_' && tab[i-4][j]!='_'){limitb[0][0]=i;limitb[0][1]=j+8;break;}

                }}}
}}
void limitation_black(char tab[33][80]){//renvoie la position de l'intersection (i,j) qui reste comme degré et la met dans une listew pour que la cpu pose la pierre là
               int i,j;
               for (i=0;i<37;i++)
    {
        for (j=0;j<65;j++){
            if(tab[i][j]=='B'){
                if (i==0 && j==0){
                    if(tab[i][j+8]=='_' && tab[i+4][j]!='|'){
                            limitw[0][0]=i;limitw[0][1]=j+8;break;
                    }
                    else if(tab[i][j+8]!='_' && tab[i+4][j]=='|'){limitw[0][0]=i+4;limitw[0][1]=j;break;}

                    }
                else if(i==32 && j==64){
                    if(tab[i-4][j]=='|' && tab[i][j-8]!='_'){limitw[0][0]=i-4;limitw[0][1]=j;break;}
                    else if(tab[i-4][j]!='|' && tab[i][j-8]=='_'){limitw[0][0]=i;limitw[0][1]=j-8;break;}
                    }
                else if(i==0 && j==64){
                    if(tab[i][j-8]=='_' && tab[i+4][j]!='|'){limitw[0][0]=i;limitw[0][1]=j-8;break;}
                    else if(tab[i][j-8]!='_' && tab[i+4][j]=='|'){limitw[0][0]=i+4;limitw[0][1]=j;break;}

                }
                if (i==32 && j==0){
                    if(tab[i][j+8]=='_' && tab[i-4][j]!='|'){limitw[0][0]=i;limitw[0][1]=j+8;break;}
                    else if(tab[i][j+8]!='_' && tab[i-4][j]=='|'){limitw[0][0]=i-4;limitw[0][1]=j;break;}
                    }
                else if(i==0 && j!=0 && j!=64 && j!=56 ){
                    if(tab[i][j+8]!='_' && tab[i+4][j]!='_' && tab[i][j-8]=='_'){limitw[0][0]=i;limitw[0][1]=j-8;break;}
                    else if(tab[i][j+8]!='_' && tab[i+4][j]=='_' && tab[i][j-8]!='_'){limitw[0][0]=i+4;limitw[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i+4][j]!='_' && tab[i][j-8]!='_'){limitw[0][0]=i;limitw[0][1]=j+8;break;}

                }
                else if(i==0 && j==56){
                    if(tab[i][j+8]!=' ' && tab[i+4][j]!='_' && tab[i][j-8]=='_'){limitw[0][0]=i;limitw[0][1]=j-8;break;}
                    else if(tab[i][j+8]!=' ' && tab[i+4][j]=='_' && tab[i][j-8]!='_'){limitw[0][0]=i+4;limitw[0][1]=j;break;}
                    else if(tab[i][j+8]==' ' && tab[i+4][j]!='_' && tab[i][j-8]!='_'){limitw[0][0]=i;limitw[0][1]=j+8;break;}

                }
                else if(i==32 && j!=0 && j!=64 && j!=8 && j!=56){
                    if(tab[i][j+8]!='_' && tab[i-4][j]!='_' && tab[i][j-8]=='_'){limitw[0][0]=i;limitw[0][1]=j-8;break;}
                    else if(tab[i][j+8]!='_' && tab[i-4][j]=='_' && tab[i][j-8]!='_'){limitw[0][0]=i-4;limitw[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]!='_' && tab[i][j-8]!='_'){limitw[0][0]=i;limitw[0][1]=j+8;break;}

                }
                else if(i==32 && j==8){
                    if(tab[i][j+8]!='_' && tab[i-4][j]!='_' && tab[i][j-8]=='|'){limitw[0][0]=i;limitw[0][1]=j-8;break;}
                    else if(tab[i][j+8]!='_' && tab[i-4][j]=='_' && tab[i][j-8]!='|'){limitw[0][0]=i-4;limitw[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]!='_' && tab[i][j-8]!='|'){limitw[0][0]=i;limitw[0][1]=j+8;break;}

                }
                else if(i==32 && j==56){
                    if(tab[i][j+8]!='|' && tab[i-4][j]!='_' && tab[i][j-8]=='_'){limitw[0][0]=i;limitw[0][1]=j-8;break;}
                    else if(tab[i][j+8]!='|' && tab[i-4][j]=='_' && tab[i][j-8]!='_'){limitw[0][0]=i-4;limitw[0][1]=j;break;}
                    else if(tab[i][j+8]=='|' && tab[i-4][j]!='_' && tab[i][j-8]!='_'){limitw[0][0]=i;limitw[0][1]=j+8;break;}

                }
                else if(i!=0 && i!=32 && i!=4 && j==0){
                    if(tab[i+4][j]!='|' && tab[i-4][j]!='|' && tab[i][j+8]=='_'){limitw[0][0]=i;limitw[0][1]=j+8;break;}
                    else if(tab[i+4][j]!='|' && tab[i-4][j]=='|' && tab[i][j+8]!='_'){limitw[0][0]=i-4;limitw[0][1]=j;break;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]!='|' && tab[i][j+8]!='_'){limitw[0][0]=i+4;limitw[0][1]=j;break;}

                }
                else if(i==4 && j==0){
                    if(tab[i-4][j]!='_' && tab[i+4][j]!='|' && tab[i][j+8]=='_'){limitw[0][0]=i;limitw[0][1]=j+8;break;}
                    else if(tab[i-4][j]!='_' && tab[i+4][j]=='|' && tab[i][j+8]!='_'){limitw[0][0]=i+4;limitw[0][1]=j;break;}
                    else if(tab[i-4][j]=='_' && tab[i+4][j]!='|' && tab[i][j+8]!='_'){limitw[0][0]=i-4;limitw[0][1]=j;break;}

                }
                else if(i!=0 && i!=32 && j==64 && i!=4){
                    if(tab[i+4][j]!='|' && tab[i-4][j]!='|' && tab[i][j-8]=='_'){limitw[0][0]=i;limitw[0][1]=j-8;break;}
                    else if(tab[i+4][j]!='|' && tab[i-4][j]=='|' && tab[i][j-8]!='_'){limitw[0][0]=i-4;limitw[0][1]=j;break;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]!='|' && tab[i][j-8]!='_'){limitw[0][0]=i+4;limitw[0][1]=j;break;}

                }
                else if(i==4 && j==64){
                    if(tab[i-4][j]!=' ' && tab[i+4][j]!='|' && tab[i][j-8]=='_'){limitw[0][0]=i;limitw[0][1]=j-8;break;}
                    else if(tab[i-4][j]!=' ' && tab[i+4][j]=='|' && tab[i][j-8]!='_'){limitw[0][0]=i+4;limitw[0][1]=j;break;}
                    else if(tab[i-4][j]==' ' && tab[i+4][j]!='|' && tab[i][j-8]!='_'){limitw[0][0]=i-4;limitw[0][1]=j;break;}

                }
                else if(j==8 && i!=32 && i!=0){
                    if(tab[i+4][j]!='_' && tab[i-4][j]!='_' && tab[i][j-8]!='|' && tab[i][j+8]=='_'){limitw[0][0]=i;limitw[0][1]=j+8;break;}
                    else if(tab[i+4][j]!='_' && tab[i-4][j]!='_' && tab[i][j-8]=='|' && tab[i][j+8]!='_'){limitw[0][0]=i;limitw[0][1]=j-8;break;}
                    else if(tab[i+4][j]!='_' && tab[i-4][j]=='_' && tab[i][j-8]!='|' && tab[i][j+8]!='_'){limitw[0][0]=i-4;limitw[0][1]=j;break;}
                    else if(tab[i+4][j]=='_' && tab[i-4][j]!='_' && tab[i][j-8]!='|' && tab[i][j+8]!='_'){limitw[0][0]=i+4;limitw[0][1]=j;break;}

                }
                else if(j==56 && i!=32 && i!=0){
                    if(tab[i+4][j]!='_' && tab[i-4][j]!='_' && tab[i][j-8]!='_' && tab[i][j+8]=='|'){limitw[0][0]=i;limitw[0][1]=j+8;break;}
                    else if(tab[i+4][j]!='_' && tab[i-4][j]!='_' && tab[i][j-8]=='_' && tab[i][j+8]!='|'){limitw[0][0]=i;limitw[0][1]=j-8;break;}
                    else if(tab[i+4][j]!='_' && tab[i-4][j]=='_' && tab[i][j-8]!='_' && tab[i][j+8]!='|'){limitw[0][0]=i-4;limitw[0][1]=j;break;}
                    else if(tab[i+4][j]=='_' && tab[i-4][j]!='_' && tab[i][j-8]!='_' && tab[i][j+8]!='|'){limitw[0][0]=i+4;limitw[0][1]=j;break;}

                }
                else {
                    if(tab[i][j+8]!='_' && tab[i][j-8]!='_' && tab[i+4][j]!='_' && tab[i-4][j]=='_'){limitw[0][0]=i-4;limitw[0][1]=j;break;}
                    else if(tab[i][j+8]!='_' && tab[i][j-8]!='_' && tab[i+4][j]=='_' && tab[i-4][j]!='_'){limitw[0][0]=i+4;limitw[0][1]=j;break;}
                    else if(tab[i][j+8]!='_' && tab[i][j-8]=='_' && tab[i+4][j]!='_' && tab[i-4][j]!='_'){limitw[0][0]=i;limitw[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='_' && tab[i][j-8]!='_' && tab[i+4][j]!='_' && tab[i-4][j]!='_'){limitw[0][0]=i;limitw[0][1]=j+8;break;}

                }}}
}}

int forbidden_black (char tab[33][80],int i,int j){//renvoie 1 si la position de l'intersection (i,j) va mener à une capture de noir
            if(tab[i][j]=='B'){
                if (i==0 && j==0){
                    if(tab[i][j+8]=='_' && tab[i+4][j]=='W'){
                            return 1;
                    }
                    else if(tab[i][j+8]=='W' && tab[i+4][j]=='|'){return 1;}
                    else {return 0;}
                    }
                else if(i==32 && j==64){
                    if(tab[i-4][j]=='|' && tab[i][j-8]=='W'){return 1;}
                    else if(tab[i-4][j]=='W' && tab[i][j-8]=='_'){return 1;}
                    else {return 0;}}
                else if(i==0 && j==64){
                    if(tab[i][j-8]=='_' && tab[i+4][j]=='W'){return 1;}
                    else if(tab[i][j-8]=='W' && tab[i+4][j]=='|'){return 1;}
                    else{return  0;}
                }
                if (i==32 && j==0){
                    if(tab[i][j+8]=='_' && tab[i-4][j]=='W'){return 1;}
                    else if(tab[i][j+8]=='W' && tab[i-4][j]=='|'){return 1;}
                    else {return 0;}
                    }
                else if(i==0 && j!=0 && j!=64 && j!=56 ){
                    if(tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i][j-8]=='_'){return 1;}
                    else if(tab[i][j+8]=='W' && tab[i+4][j]=='_' && tab[i][j-8]=='W'){return 1;}
                    else if(tab[i][j+8]=='_' && tab[i+4][j]=='W' && tab[i][j-8]=='W'){return 1;}
                    else {return 0;}
                }
                else if(i==0 && j==56){
                    if(tab[i][j+8]=='W' && tab[i+4][j]=='_' && tab[i][j-8]=='W'){return 1;}
                    else if(tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i][j-8]=='_'){return 1;}
                    else if(tab[i][j+8]==' ' && tab[i+4][j]=='W' && tab[i][j-8]=='W'){return 1;}
                    else {return 0;}
                }
                else if(i==32 && j!=0 && j!=64 && j!=8 && j!=56){
                    if(tab[i][j+8]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='_'){return 1;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){return 1;}
                    else if(tab[i][j+8]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W'){return 1;}
                    else {return 0;}
                }
                else if(i==32 && j==8){
                    if(tab[i][j+8]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='|'){return 1;}
                    else if(tab[i][j+8]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W'){return 1;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){return 1;}
                    else {return 0;}
                }
                else if(i==32 && j==56){
                    if(tab[i][j+8]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='_'){return 1;}
                    else if(tab[i][j+8]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W'){return 1;}
                    else if(tab[i][j+8]=='|' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){return 1;}
                    else {return 0;}
                }
                else if(i!=0 && i!=32 && i!=4 && j==0){
                    if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j+8]=='_'){return 1;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='|' && tab[i][j+8]=='W'){return 1;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]=='W' && tab[i][j+8]=='W'){return 1;}
                    else {return 0;}
                }
                else if(i==4 && j==0){
                    if(tab[i-4][j]=='_' && tab[i+4][j]=='W' && tab[i][j+8]=='W'){return 1;}
                    else if(tab[i-4][j]=='W' && tab[i+4][j]=='|' && tab[i][j+8]=='W'){return 1;}
                    else if(tab[i-4][j]=='W' && tab[i+4][j]=='W' && tab[i][j+8]=='_'){return 1;}
                    else {return 0;}
                }
                else if(i!=0 && i!=32 && j==64 && i!=4){
                    if(tab[i+4][j]=='|' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){return 1;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='|' && tab[i][j-8]=='W'){return 1;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='_'){return 1;}
                    else{return 0;}
                }
                else if(i==4 && j==64){
                    if(tab[i-4][j]==' ' && tab[i+4][j]=='W' && tab[i][j-8]=='W'){return 1;}
                    else if(tab[i-4][j]=='W' && tab[i+4][j]=='|' && tab[i][j-8]=='W'){return 1;}
                    else if(tab[i-4][j]=='W' && tab[i+4][j]=='W' && tab[i][j-8]=='_'){return 1;}
                    else{return 0;}
                }
                else if(j==8 && i!=32 && i!=0){
                    if(tab[i+4][j]=='_' && tab[i-4][j]=='W' && tab[i][j-8]=='W' && tab[i][j+8]=='W'){return 1;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W' && tab[i][j+8]=='W'){return 1;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='|' && tab[i][j+8]=='W'){return 1;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W' && tab[i][j+8]=='_'){return 1;}
                    else{return 0;}
                }
                else if(j==56 && i!=32 && i!=0){
                    if(tab[i+4][j]=='_' && tab[i-4][j]=='W' && tab[i][j-8]=='W' && tab[i][j+8]=='W'){return 1;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W' && tab[i][j+8]=='W'){return 1;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='_' && tab[i][j+8]=='W'){return 1;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W' && tab[i][j+8]=='|'){return 1;}
                    else{return 0;}
                }
                else {
                    if(tab[i][j+8]=='_' && tab[i][j-8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){return 1;}
                    else if(tab[i][j+8]=='W' && tab[i][j-8]=='_' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){return 1;}
                    else if(tab[i][j+8]=='W' && tab[i][j-8]=='W' && tab[i+4][j]=='_' && tab[i-4][j]=='W'){return 1;}
                    else if(tab[i][j+8]=='W' && tab[i][j-8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='_'){return 1;}
                    else{return 0;}
                }
}}
int forbidden_white(char tab[33][80],int i,int j){//renvoie 1 si la position de l'intersection (i,j) va mener à une capture de blanc
            if(tab[i][j]=='W'){
                if (i==0 && j==0){
                    if(tab[i][j+8]=='_' && tab[i+4][j]=='B'){
                            return 1;
                    }
                    else if(tab[i][j+8]=='B' && tab[i+4][j]=='|'){return 1;}
                    else {return 0;}
                    }
                else if(i==32 && j==64){
                    if(tab[i-4][j]=='|' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i-4][j]=='B' && tab[i][j-8]=='_'){return 1;}
                    else {return 0;}}
                else if(i==0 && j==64){
                    if(tab[i][j-8]=='_' && tab[i+4][j]=='B'){return 1;}
                    else if(tab[i][j-8]=='B' && tab[i+4][j]=='|'){return 1;}
                    else{return  0;}
                }
                if (i==32 && j==0){
                    if(tab[i][j+8]=='_' && tab[i-4][j]=='B'){return 1;}
                    else if(tab[i][j+8]=='B' && tab[i-4][j]=='|'){return 1;}
                    else {return 0;}
                    }
                else if(i==0 && j!=0 && j!=64 && j!=56 ){
                    if(tab[i][j+8]=='B' && tab[i+4][j]=='B' && tab[i][j-8]=='_'){return 1;}
                    else if(tab[i][j+8]=='B' && tab[i+4][j]=='_' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i][j+8]=='_' && tab[i+4][j]=='B' && tab[i][j-8]=='B'){return 1;}
                    else {return 0;}
                }
                else if(i==0 && j==56){
                    if(tab[i][j+8]=='B' && tab[i+4][j]=='_' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i][j+8]=='B' && tab[i+4][j]=='B' && tab[i][j-8]=='_'){return 1;}
                    else if(tab[i][j+8]==' ' && tab[i+4][j]=='B' && tab[i][j-8]=='B'){return 1;}
                    else {return 0;}
                }
                else if(i==32 && j!=0 && j!=64 && j!=8 && j!=56){
                    if(tab[i][j+8]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='_'){return 1;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i][j+8]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B'){return 1;}
                    else {return 0;}
                }
                else if(i==32 && j==8){
                    if(tab[i][j+8]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='|'){return 1;}
                    else if(tab[i][j+8]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){return 1;}
                    else {return 0;}
                }
                else if(i==32 && j==56){
                    if(tab[i][j+8]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='_'){return 1;}
                    else if(tab[i][j+8]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i][j+8]=='|' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){return 1;}
                    else {return 0;}
                }
                else if(i!=0 && i!=32 && i!=4 && j==0){
                    if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j+8]=='_'){return 1;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='|' && tab[i][j+8]=='B'){return 1;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]=='B' && tab[i][j+8]=='B'){return 1;}
                    else {return 0;}
                }
                else if(i==4 && j==0){
                    if(tab[i-4][j]=='_' && tab[i+4][j]=='B' && tab[i][j+8]=='B'){return 1;}
                    else if(tab[i-4][j]=='B' && tab[i+4][j]=='|' && tab[i][j+8]=='B'){return 1;}
                    else if(tab[i-4][j]=='B' && tab[i+4][j]=='B' && tab[i][j+8]=='_'){return 1;}
                    else {return 0;}
                }
                else if(i!=0 && i!=32 && j==64 && i!=4){
                    if(tab[i+4][j]=='|' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='|' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='_'){return 1;}
                    else{return 0;}
                }
                else if(i==4 && j==64){
                    if(tab[i-4][j]==' ' && tab[i+4][j]=='B' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i-4][j]=='B' && tab[i+4][j]=='|' && tab[i][j-8]=='B'){return 1;}
                    else if(tab[i-4][j]=='B' && tab[i+4][j]=='B' && tab[i][j-8]=='_'){return 1;}
                    else{return 0;}
                }
                else if(j==8 && i<32 && i>0){
                    if(tab[i+4][j]=='_' && tab[i-4][j]=='B' && tab[i][j-8]=='B' && tab[i][j+8]=='B'){return 1;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B' && tab[i][j+8]=='B'){return 1;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='|' && tab[i][j+8]=='B'){return 1;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='B' && tab[i][j+8]=='_'){return 1;}
                    else{return 0;}
                }
                else if(j==56 && i<32 && i>0){
                    if(tab[i+4][j]=='_' && tab[i-4][j]=='B' && tab[i][j-8]=='B' && tab[i][j+8]=='B'){return 1;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B' && tab[i][j+8]=='B'){return 1;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='_' && tab[i][j+8]=='B'){return 1;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='B' && tab[i][j+8]=='|'){return 1;}
                    else{return 0;}
                }
                else {
                    if(tab[i][j+8]=='_' && tab[i][j-8]=='B' && tab[i+4][j]=='B' && tab[i-4][j]=='B'){return 1;}
                    else if(tab[i][j+8]=='B' && tab[i][j-8]=='_' && tab[i+4][j]=='B' && tab[i-4][j]=='B'){return 1;}
                    else if(tab[i][j+8]=='B' && tab[i][j-8]=='B' && tab[i+4][j]=='_' && tab[i-4][j]=='B'){return 1;}
                    else if(tab[i][j+8]=='B' && tab[i][j-8]=='B' && tab[i+4][j]=='B' && tab[i-4][j]=='_'){return 1;}
                    else{return 0;}
                }
}}
int limiteb[1][2],limitew[1][2];
void capture_avoid_black(char tab[33][80]){//renvoie la position de l'intersection (i,j) qui reste comme degré et la met dans une listew pour que la cpu pose la pierre là
               int i,j;
               for (i=0;i<33;i++)
    {
        for (j=0;j<65;j++){
            if(tab[i][j]=='B'){
                if (i==0 && j==0){
                    if(tab[i][j+8]=='_' && tab[i+4][j]=='W'){
                            limiteb[0][0]=i;limiteb[0][1]=j+8;break;
                    }
                    else if(tab[i][j+8]=='W' && tab[i+4][j]=='|'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}

                    }
                else if(i==32 && j==64){
                    if(tab[i-4][j]=='|' && tab[i][j-8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i-4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    }
                else if(i==0 && j==64){
                    if(tab[i][j-8]=='_' && tab[i+4][j]=='W'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j-8]=='W' && tab[i+4][j]=='|'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}

                }
                if (i==32 && j==0){
                    if(tab[i][j+8]=='_' && tab[i-4][j]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}
                    else if(tab[i][j+8]=='W' && tab[i-4][j]=='|'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    }
                else if(i==0 && j!=0 && j!=64 && j!=56 ){
                    if(tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='W' && tab[i+4][j]=='_' && tab[i][j-8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i+4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}

                }
                else if(i==0 && j==56){
                    if(tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='W' && tab[i+4][j]=='_' && tab[i][j-8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]==' ' && tab[i+4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}

                }
                else if(i==32 && j!=0 && j!=64 && j!=8 && j!=56){
                    if(tab[i][j+8]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}

                }
                else if(i==32 && j==8){
                    if(tab[i][j+8]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='|'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}

                }
                else if(i==32 && j==56){
                    if(tab[i][j+8]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]=='|' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}

                }
                else if(i!=0 && i!=32 && i!=4 && j==0){
                    if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j+8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='|' && tab[i][j+8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]=='W' && tab[i][j+8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}

                }
                else if(i==4 && j==0){
                    if(tab[i-4][j]=='W' && tab[i+4][j]=='W' && tab[i][j+8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}
                    else if(tab[i-4][j]=='W' && tab[i+4][j]=='|' && tab[i][j+8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}
                    else if(tab[i-4][j]=='_' && tab[i+4][j]=='W' && tab[i][j+8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}

                }
                else if(i!=0 && i!=32 && j==64 && i!=4){
                    if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='|' && tab[i][j-8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}

                }
                else if(i==4 && j==64){
                    if(tab[i-4][j]=='W' && tab[i+4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i-4][j]=='W' && tab[i+4][j]=='|' && tab[i][j-8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}
                    else if(tab[i-4][j]==' ' && tab[i+4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}

                }
                else if(j==8 && i!=32 && i!=0){
                    if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W' && tab[i][j+8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='|' && tab[i][j+8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W' && tab[i][j+8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i+4][j]=='_' && tab[i-4][j]=='W' && tab[i][j-8]=='W' && tab[i][j+8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}

                }
                else if(j==56 && i==32 && i!=0){
                    if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W' && tab[i][j+8]=='|'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='_' && tab[i][j+8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W' && tab[i][j+8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i+4][j]=='_' && tab[i-4][j]=='W' && tab[i][j-8]=='W' && tab[i][j+8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}

                }
                else {
                    if(tab[i][j+8]=='W' && tab[i][j-8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='_'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]=='W' && tab[i][j-8]=='W' && tab[i+4][j]=='_' && tab[i-4][j]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]=='W' && tab[i][j-8]=='_' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='_' && tab[i][j-8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}

                }}}
}}
void capture_avoid_white(char tab[33][80]){//renvoie la position de l'intersection (i,j) qui reste comme degré et la met dans une listew pour que la cpu pose la pierre là
               int i,j;
               for (i=0;i<33;i++)
    {
        for (j=0;j<65;j++){
            if(tab[i][j]=='W'){
                if (i==0 && j==0){
                    if(tab[i][j+8]=='_' && tab[i+4][j]=='B'){
                            limitew[0][0]=i;limitew[0][1]=j+8;break;
                    }
                    else if(tab[i][j+8]=='B' && tab[i+4][j]=='|'){limitew[0][0]=i+4;limitew[0][1]=j;break;}

                    }
                else if(i==32 && j==64){
                    if(tab[i-4][j]=='|' && tab[i][j-8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i-4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    }
                else if(i==0 && j==64){
                    if(tab[i][j-8]=='_' && tab[i+4][j]=='B'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j-8]=='B' && tab[i+4][j]=='|'){limitew[0][0]=i+4;limitew[0][1]=j;break;}

                }
                if (i==32 && j==0){
                    if(tab[i][j+8]=='_' && tab[i-4][j]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}
                    else if(tab[i][j+8]=='B' && tab[i-4][j]=='|'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    }
                else if(i==0 && j!=0 && j!=64 && j!=56 ){
                    if(tab[i][j+8]=='B' && tab[i+4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='B' && tab[i+4][j]=='_' && tab[i][j-8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i+4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}

                }
                else if(i==0 && j==56){
                    if(tab[i][j+8]=='B' && tab[i+4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='B' && tab[i+4][j]=='_' && tab[i][j-8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]==' ' && tab[i+4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}

                }
                else if(i==32 && j!=0 && j!=64 && j!=8 && j!=56){
                    if(tab[i][j+8]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}

                }
                else if(i==32 && j==8){
                    if(tab[i][j+8]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='|'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}

                }
                else if(i==32 && j==56){
                    if(tab[i][j+8]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]=='|' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}

                }
                else if(i!=0 && i!=32 && i!=4 && j==0){
                    if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j+8]=='_'){limitew[0][0]=i;limitew[0][1]=j+8;break;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='|' && tab[i][j+8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]=='B' && tab[i][j+8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}

                }
                else if(i==4 && j==0){
                    if(tab[i-4][j]=='B' && tab[i+4][j]=='B' && tab[i][j+8]=='_'){limitew[0][0]=i;limitew[0][1]=j+8;break;}
                    else if(tab[i-4][j]=='B' && tab[i+4][j]=='|' && tab[i][j+8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}
                    else if(tab[i-4][j]=='_' && tab[i+4][j]=='B' && tab[i][j+8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}

                }
                else if(i!=0 && i!=32 && j==64 && i!=4){
                    if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='|' && tab[i][j-8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}

                }
                else if(i==4 && j==64){
                    if(tab[i-4][j]=='B' && tab[i+4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i-4][j]=='B' && tab[i+4][j]=='|' && tab[i][j-8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}
                    else if(tab[i-4][j]==' ' && tab[i+4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}

                }
                else if(j==8 && i!=32 && i!=0){
                    if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='B' && tab[i][j+8]=='_'){limitew[0][0]=i;limiteb[0][1]=j+8;break;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='|' && tab[i][j+8]=='B'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B' && tab[i][j+8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i+4][j]=='_' && tab[i-4][j]=='B' && tab[i][j-8]=='B' && tab[i][j+8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}

                }
                else if(j==56 && i==32 && i!=0){
                    if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='B' && tab[i][j+8]=='|'){limitew[0][0]=i;limitew[0][1]=j+8;break;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='_' && tab[i][j+8]=='B'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B' && tab[i][j+8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i+4][j]=='_' && tab[i-4][j]=='B' && tab[i][j-8]=='B' && tab[i][j+8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}

                }
                else {
                    if(tab[i][j+8]=='B' && tab[i][j-8]=='B' && tab[i+4][j]=='B' && tab[i-4][j]=='_'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]=='B' && tab[i][j-8]=='B' && tab[i+4][j]=='_' && tab[i-4][j]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]=='B' && tab[i][j-8]=='_' && tab[i+4][j]=='B' && tab[i-4][j]=='B'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='_' && tab[i][j-8]=='B' && tab[i+4][j]=='B' && tab[i-4][j]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}

                }}}
}}
void create_suicide_black(char tab[33][80]){//renvoie la position de l'intersection (i,j)(si la position traitée est vide) qui reste comme degré et la met dans une listew pour que la cpu pose la pierre làet ainsi crée un cas de suicide pr l'adversaire
               int i,j;
               for (i=0;i<33;i++)
    {
        for (j=0;j<65;j++){
            if(tab[i][j]!='W' && tab[i][j]!='B'){
                if (i==0 && j==0){
                    if(tab[i][j+8]=='_' && tab[i+4][j]=='B'){
                            limitew[0][0]=i;limitew[0][1]=j+8;break;
                    }
                    else if(tab[i][j+8]=='B' && tab[i+4][j]=='|'){limitew[0][0]=i+4;limitew[0][1]=j;break;}

                    }
                else if(i==32 && j==64){
                    if(tab[i-4][j]=='|' && tab[i][j-8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i-4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    }
                else if(i==0 && j==64){
                    if(tab[i][j-8]=='_' && tab[i+4][j]=='B'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j-8]=='B' && tab[i+4][j]=='|'){limitew[0][0]=i+4;limitew[0][1]=j;break;}

                }
                if (i==32 && j==0){
                    if(tab[i][j+8]=='_' && tab[i-4][j]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}
                    else if(tab[i][j+8]=='B' && tab[i-4][j]=='|'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    }
                else if(i==0 && j!=0 && j!=64 && j!=56 ){
                    if(tab[i][j+8]=='B' && tab[i+4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='B' && tab[i+4][j]=='_' && tab[i][j-8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i+4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}

                }
                else if(i==0 && j==56){
                    if(tab[i][j+8]=='B' && tab[i+4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='B' && tab[i+4][j]=='_' && tab[i][j-8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]==' ' && tab[i+4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}

                }
                else if(i==32 && j!=0 && j!=64 && j!=8 && j!=56){
                    if(tab[i][j+8]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}

                }
                else if(i==32 && j==8){
                    if(tab[i][j+8]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='|'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}

                }
                else if(i==32 && j==56){
                    if(tab[i][j+8]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]=='|' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}

                }
                else if(i!=0 && i!=32 && i!=4 && j==0){
                    if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j+8]=='_'){limitew[0][0]=i;limitew[0][1]=j+8;break;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='|' && tab[i][j+8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]=='B' && tab[i][j+8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}

                }
                else if(i==4 && j==0){
                    if(tab[i-4][j]=='B' && tab[i+4][j]=='B' && tab[i][j+8]=='_'){limitew[0][0]=i;limitew[0][1]=j+8;break;}
                    else if(tab[i-4][j]=='B' && tab[i+4][j]=='|' && tab[i][j+8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}
                    else if(tab[i-4][j]=='_' && tab[i+4][j]=='B' && tab[i][j+8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}

                }
                else if(i!=0 && i!=32 && j==64 && i!=4){
                    if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='|' && tab[i][j-8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}

                }
                else if(i==4 && j==64){
                    if(tab[i-4][j]=='B' && tab[i+4][j]=='B' && tab[i][j-8]=='_'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i-4][j]=='B' && tab[i+4][j]=='|' && tab[i][j-8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}
                    else if(tab[i-4][j]==' ' && tab[i+4][j]=='B' && tab[i][j-8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}

                }
                else if(j==8 && i!=32 && i!=0){
                    if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='B' && tab[i][j+8]=='_'){limitew[0][0]=i;limiteb[0][1]=j+8;break;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='|' && tab[i][j+8]=='B'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B' && tab[i][j+8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i+4][j]=='_' && tab[i-4][j]=='B' && tab[i][j-8]=='B' && tab[i][j+8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}

                }
                else if(j==56 && i==32 && i!=0){
                    if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='B' && tab[i][j+8]=='|'){limitew[0][0]=i;limitew[0][1]=j+8;break;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='B' && tab[i][j-8]=='_' && tab[i][j+8]=='B'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i+4][j]=='B' && tab[i-4][j]=='_' && tab[i][j-8]=='B' && tab[i][j+8]=='B'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i+4][j]=='_' && tab[i-4][j]=='B' && tab[i][j-8]=='B' && tab[i][j+8]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}

                }
                else {
                    if(tab[i][j+8]=='B' && tab[i][j-8]=='B' && tab[i+4][j]=='B' && tab[i-4][j]=='_'){limitew[0][0]=i-4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]=='B' && tab[i][j-8]=='B' && tab[i+4][j]=='_' && tab[i-4][j]=='B'){limitew[0][0]=i+4;limitew[0][1]=j;break;}
                    else if(tab[i][j+8]=='B' && tab[i][j-8]=='_' && tab[i+4][j]=='B' && tab[i-4][j]=='B'){limitew[0][0]=i;limitew[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='_' && tab[i][j-8]=='B' && tab[i+4][j]=='B' && tab[i-4][j]=='B'){limitew[0][0]=i;limitew[0][1]=j+8;break;}

                }}}
}}
void create_suicide_white(char tab[33][80]){//renvoie la position de l'intersection (i,j)(si la position est vide) qui reste comme degré et la met dans une listew pour que la cpu pose la pierre là et ainsi crée un cas de suicide pr l'adversaire
               int i,j;
               for (i=0;i<33;i++)
    {
        for (j=0;j<65;j++){
            if(tab[i][j]!='B' && tab[i][j]!='W' ){
                if (i==0 && j==0){
                    if(tab[i][j+8]=='_' && tab[i+4][j]=='W'){
                            limiteb[0][0]=i;limiteb[0][1]=j+8;break;
                    }
                    else if(tab[i][j+8]=='W' && tab[i+4][j]=='|'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}

                    }
                else if(i==32 && j==64){
                    if(tab[i-4][j]=='|' && tab[i][j-8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i-4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    }
                else if(i==0 && j==64){
                    if(tab[i][j-8]=='_' && tab[i+4][j]=='W'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j-8]=='W' && tab[i+4][j]=='|'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}

                }
                if (i==32 && j==0){
                    if(tab[i][j+8]=='_' && tab[i-4][j]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}
                    else if(tab[i][j+8]=='W' && tab[i-4][j]=='|'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    }
                else if(i==0 && j!=0 && j!=64 && j!=56 ){
                    if(tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='W' && tab[i+4][j]=='_' && tab[i][j-8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i+4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}

                }
                else if(i==0 && j==56){
                    if(tab[i][j+8]=='W' && tab[i+4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='W' && tab[i+4][j]=='_' && tab[i][j-8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]==' ' && tab[i+4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}

                }
                else if(i==32 && j!=0 && j!=64 && j!=8 && j!=56){
                    if(tab[i][j+8]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}

                }
                else if(i==32 && j==8){
                    if(tab[i][j+8]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='|'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]=='_' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}

                }
                else if(i==32 && j==56){
                    if(tab[i][j+8]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]=='|' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}

                }
                else if(i!=0 && i!=32 && i!=4 && j==0){
                    if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j+8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='|' && tab[i][j+8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]=='W' && tab[i][j+8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}

                }
                else if(i==4 && j==0){
                    if(tab[i-4][j]=='W' && tab[i+4][j]=='W' && tab[i][j+8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}
                    else if(tab[i-4][j]=='W' && tab[i+4][j]=='|' && tab[i][j+8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}
                    else if(tab[i-4][j]=='_' && tab[i+4][j]=='W' && tab[i][j+8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}

                }
                else if(i!=0 && i!=32 && j==64 && i!=4){
                    if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='|' && tab[i][j-8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i+4][j]=='|' && tab[i-4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}

                }
                else if(i==4 && j==64){
                    if(tab[i-4][j]=='W' && tab[i+4][j]=='W' && tab[i][j-8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i-4][j]=='W' && tab[i+4][j]=='|' && tab[i][j-8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}
                    else if(tab[i-4][j]==' ' && tab[i+4][j]=='W' && tab[i][j-8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}

                }
                else if(j==8 && i!=32 && i!=0){
                    if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W' && tab[i][j+8]=='_'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='|' && tab[i][j+8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W' && tab[i][j+8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i+4][j]=='_' && tab[i-4][j]=='W' && tab[i][j-8]=='W' && tab[i][j+8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}

                }
                else if(j==56 && i==32 && i!=0){
                    if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='W' && tab[i][j+8]=='|'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='W' && tab[i][j-8]=='_' && tab[i][j+8]=='W'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i+4][j]=='W' && tab[i-4][j]=='_' && tab[i][j-8]=='W' && tab[i][j+8]=='W'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i+4][j]=='_' && tab[i-4][j]=='W' && tab[i][j-8]=='W' && tab[i][j+8]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}

                }
                else {
                    if(tab[i][j+8]=='W' && tab[i][j-8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='_'){limiteb[0][0]=i-4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]=='W' && tab[i][j-8]=='W' && tab[i+4][j]=='_' && tab[i-4][j]=='W'){limiteb[0][0]=i+4;limiteb[0][1]=j;break;}
                    else if(tab[i][j+8]=='W' && tab[i][j-8]=='_' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){limiteb[0][0]=i;limiteb[0][1]=j-8;break;}
                    else if(tab[i][j+8]=='_' && tab[i][j-8]=='W' && tab[i+4][j]=='W' && tab[i-4][j]=='W'){limiteb[0][0]=i;limiteb[0][1]=j+8;break;}

                }}}
}}


int main()
{
    int c;
    char name[100];
    char rep;
    again11:
    system("cls");
    first_interface();
    scanf("%d",&c);
    if (c<=0||c>3){
        printf("\nErroned value\n");
        printf("Click anything");
        getch();
        goto again11;
        }
    if (c==1){
        again12:
        system("cls");
        second_interface();
        scanf("%d",&c);
        if (c<=0||c>3){
            printf("\nErroned value\n");
            printf("Click anything");
            getch();
            goto again12;
        }
        if (c==1){
            again21:
            system("cls");
            third_interface();
            scanf("%d",&c);
            if (c<=0||c>4){
                printf("\nErroned value\n");
                printf("Click anything");
                getch();
                goto again21;
                }
            if(c==4){goto again12;}
            if(c==1||c==2||c==3){
                system("cls");
                Color(15,0);
                printf("Hey ! my name is X-machina ! You are going to play with me.\n PLEASE ,write your name down!\n");
                scanf("%s",&name);
                system("cls");
                printf("All right %s let's play together ! But before starting,let's discover who will play first by a random choice!\nClick any key to continue\n\n",name);
                getch();
                system("cls");
                srand (time (NULL));
                int random = rand() % 2;
                if (random==0){printf("\t\t\t ---<<Unfortunately(only for you LOL) ,I'm going to play first and I'm the black player!>>---\n\t\t\t---<<Let's start!>>---\nClick any key to continue");
                getch();
                if(c==1){
int i,j,a,b,k;
    char tab[33][80];
    char tab2[33][80];
    printf("\n");
    printf("0       1       2       3       4       5       6       7       8\n");
    for (i=0;i<33;i++)
    {
        for (j=0;j<80;j++){
                if (j==0&&i!=0){tab[i][j]='|';}
                else if (i%4==0&&j<64){tab[i][j]='_';}
                else if (j==8||j==16||j==24||j==32||j==40||j==48||j==56){tab[i][j]='|';}
                else if (i!=0&&j==64){tab[i][j]='|';}
                else if (i==0&&j==66){tab[i][j]='0';}
                else if (i==4&&j==66){tab[i][j]='1';}
                else if (i==8&&j==66){tab[i][j]='2';}
                else if (i==12&&j==66){tab[i][j]='3';}
                else if (i==16&&j==66){tab[i][j]='4';}
                else if (i==20&&j==66){tab[i][j]='5';}
                else if (i==24&&j==66){tab[i][j]='6';}
                else if (i==28&&j==66){tab[i][j]='7';}
                else if (i==32&&j==66){tab[i][j]='8';}
                else {tab[i][j]=' ';}
                printf("%c",tab[i][j]);}}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
ran:// pour random
srand (time (NULL));
int random = rand() % 10;
a=random;
srand (time (NULL));
int random1 = rand() % 16;
b=random1;
fill:
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='B';
 for (k=0;k<65;k++){
   if(listeb[k][0]!='\0' && listeb[k][1]!='\0'){if (a*4==listeb[k][0] && b*8==listeb[k][1]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
   for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
   goto ran;}}}
   if(forbidden_black(tab2,a*4,b*8)==1){goto ran;}
   if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='B';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<33;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
  else{
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
 goto ran;}}
else {
    goto ran;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
again:
printf("It's your turn !\n");
printf("entrer la position de la pierre (numero de la ligne suivi de celui de la colonne separes par un espace) :");
printf("Remarque : si vous voulez passer le coup ! entrez 77 77\n\n");
scanf("%d %d",&a,&b);
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='W';
 for (k=0;k<65;k++){
   if(listew[k][0]!='\0' && listew[k][1]!='\0'){if (a*4==listew[k][0] && b*8==listew[k][1]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
  for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
   goto again;}}}
 if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='W';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<33;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
 else{printf("vous suicidez ! entrez une autre position\n");
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
 goto again;}}
else if(a==77 && b==77){gagnant(tab);}
else {
    printf("entrer une position exsitante et vide\n");
    goto again;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
goto ran;
}
if(c==2){
    int i,j,a,b,k,l,m;
    int p[100],y[100];
    p[0]=1;y[0]=4;p[1]=1;y[1]=2;p[2]=1;y[2]=1;p[3]=2;y[3]=0;p[4]=2;y[4]=1;p[5]=2;y[5]=3;p[6]=8;y[6]=8;p[7]=7;y[7]=7;p[8]=0;y[8]=2;p[9]=0;y[9]=0;
    //o[100],u[100];
    //o[0]=0;y[0]=4;o[1]=1;y[1]=0;o[2]=1;y[2]=4;o[3]=2;y[3]=2;o[4]=2;y[4]=3;o[5]=6;y[5]=6;o[6]=5;y[6]=7;o[7]=4;y[7]=8;o[8]=1;y[8]=2;o[9]=0;y[9]=2;
    char tab[33][80];
    char tab2[33][80];
    printf("\n");
    printf("0       1       2       3       4       5       6       7       8\n");
    for (i=0;i<33;i++)
    {
        for (j=0;j<80;j++){
                if (j==0&&i!=0){tab[i][j]='|';}
                else if (i%4==0&&j<64){tab[i][j]='_';}
                else if (j==8||j==16||j==24||j==32||j==40||j==48||j==56){tab[i][j]='|';}
                else if (i!=0&&j==64){tab[i][j]='|';}
                else if (i==0&&j==66){tab[i][j]='0';}
                else if (i==4&&j==66){tab[i][j]='1';}
                else if (i==8&&j==66){tab[i][j]='2';}
                else if (i==12&&j==66){tab[i][j]='3';}
                else if (i==16&&j==66){tab[i][j]='4';}
                else if (i==20&&j==66){tab[i][j]='5';}
                else if (i==24&&j==66){tab[i][j]='6';}
                else if (i==28&&j==66){tab[i][j]='7';}
                else if (i==32&&j==66){tab[i][j]='8';}
                else {tab[i][j]=' ';}
                printf("%c",tab[i][j]);}}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
m=0;
again7:
while (m<10){
    a=p[m],b=y[m];m++; goto fill2;}

//again7:
//while(m<10){
//        a=p[m],b=y[m];m++; goto fill;}

ran4:// pour random
srand (time (NULL));
int random = rand() % 10;
a=random;
srand (time (NULL));
int random1 = rand() % 16;
b=random1;
fill2:
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='B';
 for (k=0;k<65;k++){
   if(listeb[k][0]!='\0' && listeb[k][1]!='\0'){if (a*4==listeb[k][0] && b*8==listeb[k][1]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
   for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
   goto ran4;}}}
   if(forbidden_black(tab2,a*4,b*8)==1){
    for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
        goto ran4;}
   if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='B';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<33;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
  else{
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
 goto ran4;}}
else {
    goto again7;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
again8:
printf("It's your turn !\n");
printf("entrer la position de la pierre (numero de la ligne suivi de celui de la colonne separes par un espace) :");
printf("Remarque : si vous voulez passer le coup ! entrez 77 77\n\n");
scanf("%d %d",&a,&b);
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='W';
 for (k=0;k<65;k++){
   if(listew[k][0]!='\0' && listew[k][1]!='\0'){if (a*4==listew[k][0] && b*8==listew[k][1]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
  for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
   goto again8;}}}
 if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='W';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<33;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
 else{printf("vous suicidez ! entrez une autre position\n");
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
 goto again8;}}
 else if(a==77 && b==77){gagnant(tab);}
else {
    printf("entrer une position exsitante et vide\n");
    goto again8;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
goto again7;
                }




    if(c==3){
    int i,j,a,b,k,l,m;
    int f[100],g[100];
    f[0]=1;g[0]=0;f[7]=3;g[7]=0;
    int w[100],q[100];
    w[3]=3;q[3]=2;w[5]=0;q[5]=3;w[6]=1;q[6]=3;w[7]=1;q[7]=0;w[8]=1;q[8]=2;
    for (l=1;l<7;l++){f[l]=l;g[l]=1;}
    for (l=0;l<5;l++){if(l==3){continue;}else{w[l]=l;q[l]=1;}}
    char tab[33][80];
    char tab2[33][80];
    printf("\n");
    printf("0       1       2       3       4       5       6       7       8\n");
    for (i=0;i<33;i++)
    {
        for (j=0;j<80;j++){
                if (j==0&&i!=0){tab[i][j]='|';}
                else if (i%4==0&&j<64){tab[i][j]='_';}
                else if (j==8||j==16||j==24||j==32||j==40||j==48||j==56){tab[i][j]='|';}
                else if (i!=0&&j==64){tab[i][j]='|';}
                else if (i==0&&j==66){tab[i][j]='0';}
                else if (i==4&&j==66){tab[i][j]='1';}
                else if (i==8&&j==66){tab[i][j]='2';}
                else if (i==12&&j==66){tab[i][j]='3';}
                else if (i==16&&j==66){tab[i][j]='4';}
                else if (i==20&&j==66){tab[i][j]='5';}
                else if (i==24&&j==66){tab[i][j]='6';}
                else if (i==28&&j==66){tab[i][j]='7';}
                else if (i==32&&j==66){tab[i][j]='8';}
                else {tab[i][j]=' ';}
                printf("%c",tab[i][j]);}}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
m=0;
again1:
// tsumego 1 : trajet while(m<8){
//a=f[m];b=g[m];m++;goto fill;}
// tsumego 2 ; trajet
while(m<9){
a=w[m];b=q[m];m++;goto fill5;}
create_suicide_black(tab);
if(limitew[0][0]!='\0'){a=(limitew[0][0])/4;b=(limitew[0][1])/8;limitew[0][0]='\0';limitew[0][1]='\0';goto fill5;}
capture_avoid_black(tab);
if(limiteb[0][0]!='\0'){a=(limiteb[0][0])/4;b=(limiteb[0][1])/8;limiteb[0][0]='\0';limiteb[0][1]='\0';goto fill5;}
capture_avoid_white(tab);
if(limitew[0][0]!='\0'){a=(limitew[0][0])/4;b=(limitew[0][1])/8;limitew[0][0]='\0';limitew[0][1]='\0';goto fill5;}
limitation_white(tab);
if(limitb[0][0]!='\0'){a=(limitb[0][0])/4;b=(limitb[0][1])/8;limitb[0][0]='\0';limitb[0][1]='\0';goto fill5;}
ran1:// pour random
srand (time (NULL));
int random = rand() % 10;
a=random;
srand (time (NULL));
int random1 = rand() % 16;
b=random1;
fill5:
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='B';
 for (k=0;k<65;k++){
   if(listeb[k][0]!='\0' && listeb[k][1]!='\0'){if (a*4==listeb[k][0] && b*8==listeb[k][1]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
   for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
   goto ran1;}}}
   if(forbidden_black(tab2,a*4,b*8)==1){
    for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
        goto ran1;}
   if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='B';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<33;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
  else{
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
 goto ran1;}}
else {
    goto again1;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
again2:
printf("It's your turn !\n");
printf("entrer la position de la pierre (numero de la ligne suivi de celui de la colonne separes par un espace) :");
printf("Remarque : si vous voulez passer le coup ! entrez 77 77\n\n");
scanf("%d %d",&a,&b);
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='W';
 for (k=0;k<65;k++){
   if(listew[k][0]!='\0' && listew[k][1]!='\0'){if (a*4==listew[k][0] && b*8==listew[k][1]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
  for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
   goto again2;}}}
 if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='W';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<33;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
 else{printf("vous suicidez ! entrez une autre position\n");
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
 goto again2;}}
 else if(a==77 && b==77){gagnant(tab);}
else {
    printf("entrer une position exsitante et vide\n");
    goto again2;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
goto again1;
                }
            }
                else{printf("\t\t\t ---<<You are lucky ! You are going to start and you are the black player!>>---\n\t\t\t---<<Let's start!>>---\nClick any key to continue");
                getch();
               if(c==1){
    int i,j,a,b,k;
    char tab[33][80];
    char tab2[33][80];
    printf("\n");
    printf("0       1       2       3       4       5       6       7       8\n");
    for (i=0;i<33;i++)
    {
        for (j=0;j<80;j++){
                if (j==0&&i!=0){tab[i][j]='|';}
                else if (i%4==0&&j<64){tab[i][j]='_';}
                else if (j==8||j==16||j==24||j==32||j==40||j==48||j==56){tab[i][j]='|';}
                else if (i!=0&&j==64){tab[i][j]='|';}
                else if (i==0&&j==66){tab[i][j]='0';}
                else if (i==4&&j==66){tab[i][j]='1';}
                else if (i==8&&j==66){tab[i][j]='2';}
                else if (i==12&&j==66){tab[i][j]='3';}
                else if (i==16&&j==66){tab[i][j]='4';}
                else if (i==20&&j==66){tab[i][j]='5';}
                else if (i==24&&j==66){tab[i][j]='6';}
                else if (i==28&&j==66){tab[i][j]='7';}
                else if (i==32&&j==66){tab[i][j]='8';}
                else {tab[i][j]=' ';}
                printf("%c",tab[i][j]);}}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
again3:
printf("It's your turn !\n");
printf("entrer la position de la pierre (numero de la ligne suivi de celui de la colonne separes par un espace) :");
printf("Remarque : si vous voulez passer le coup ! entrez 77 77\n\n");
scanf("%d %d",&a,&b);
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='B';
 for (k=0;k<65;k++){
   if(listeb[k][0]!='\0' && listeb[k][1]!='\0'){if (a*4==listeb[k][0] && b*8==listeb[k][1]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
  for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
   goto again3;}}}
 if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='B';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<33;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
 else{printf("vous suicidez ! entrez une autre position\n");
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
 goto again3;}}
else if(a==77 && b==77){gagnant(tab);}
else {
    printf("entrer une position exsitante et vide\n");
    goto again3;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
ran2:// pour random
srand (time (NULL));
int random = rand() % 10;
a=random;
srand (time (NULL));
int random1 = rand() % 16;
b=random1;
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='W';
 for (k=0;k<65;k++){
   if(listew[k][0]!='\0' && listew[k][1]!='\0'){if (a*4==listew[k][0] && b*8==listew[k][1]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
   for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
   goto ran2;}}}
   if(forbidden_white(tab2,a*4,b*8)==1){goto ran2;}
   if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='W';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<33;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
  else{
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
 goto ran2;}}
else {
    goto ran2;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
goto again3;


                }
                if(c==2){
    int i,j,a,b,k,l,m;
    int p[100],y[100];
    p[0]=1;y[0]=4;p[1]=1;y[1]=2;p[2]=1;y[2]=1;p[3]=2;y[3]=0;p[4]=2;y[4]=1;p[5]=2;y[5]=3;p[6]=0;y[6]=2;p[7]=0;y[7]=0;
    //o[100],u[100];
    //o[0]=0;y[0]=4;o[1]=1;y[1]=0;o[2]=1;y[2]=4;o[3]=2;y[3]=2;o[4]=2;y[4]=3;o[5]=6;y[5]=6;o[6]=5;y[6]=7;o[7]=4;y[7]=8;o[8]=1;y[8]=2;o[9]=0;y[9]=2;
    char tab[33][80];
    char tab2[33][80];
    printf("\n");
    printf("0       1       2       3       4       5       6       7       8\n");
    for (i=0;i<33;i++)
    {
        for (j=0;j<80;j++){
                if (j==0&&i!=0){tab[i][j]='|';}
                else if (i%4==0&&j<64){tab[i][j]='_';}
                else if (j==8||j==16||j==24||j==32||j==40||j==48||j==56){tab[i][j]='|';}
                else if (i!=0&&j==64){tab[i][j]='|';}
                else if (i==0&&j==66){tab[i][j]='0';}
                else if (i==4&&j==66){tab[i][j]='1';}
                else if (i==8&&j==66){tab[i][j]='2';}
                else if (i==12&&j==66){tab[i][j]='3';}
                else if (i==16&&j==66){tab[i][j]='4';}
                else if (i==20&&j==66){tab[i][j]='5';}
                else if (i==24&&j==66){tab[i][j]='6';}
                else if (i==28&&j==66){tab[i][j]='7';}
                else if (i==32&&j==66){tab[i][j]='8';}
                else {tab[i][j]=' ';}
                printf("%c",tab[i][j]);}}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
again9:
printf("It's your turn !\n");
printf("entrer la position de la pierre (numero de la ligne suivi de celui de la colonne separes par un espace) :");
printf("Remarque : si vous voulez passer le coup ! entrez 77 77\n\n");
scanf("%d %d",&a,&b);
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='B';
 for (k=0;k<65;k++){
   if(listeb[k][0]!='\0' && listeb[k][1]!='\0'){if (a*4==listeb[k][0] && b*8==listeb[k][1]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
  for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
   goto again9;}}}
 if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='W';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<37;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
 else{printf("vous suicidez ! entrez une autre position\n");
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
 goto again9;}}
 else if(a==77 && b==77){gagnant(tab);}
else {
    printf("entrer une position exsitante et vide\n");
    goto again9;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
m=0;
again10:
while (m<8){
    a=p[m],b=y[m];m++; goto fill3;}
//again2:
//while(m<10){
//        a=p[m],b=y[m];m++; goto fill;}

ran5:// pour random
srand (time (NULL));
int random = rand() % 10;
a=random;
srand (time (NULL));
int random1 = rand() % 16;
b=random1;
fill3:
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='W';
 for (k=0;k<65;k++){
   if(listew[k][0]!='\0' && listew[k][1]!='\0'){if (a*4==listew[k][0] && b*8==listew[k][1]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
   for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
   goto ran5;}}}
   if(forbidden_white(tab2,a*4,b*8)==1){
    for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
        goto ran5;}
   if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='B';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<33;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
  else{
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
 goto ran5;}}
else {
    goto again10;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
goto again9;
                }


                if(c==3){
    int i,j,a,b,k,l,m;
    int f[100],g[100];
    f[0]=1;g[0]=0;f[7]=3;g[7]=0;
    int w[100],q[100];
    w[3]=3;q[3]=2;w[5]=0;q[5]=3;w[6]=1;q[6]=3;w[7]=1;q[7]=0;w[8]=1;q[8]=2;
    for (l=1;l<7;l++){f[l]=l;g[l]=1;}
    for (l=0;l<5;l++){if(l==3){continue;}else{w[l]=l;q[l]=1;}}
    char tab[33][80];
    char tab2[33][80];
    printf("\n");
    printf("0       1       2       3       4       5       6       7       8\n");
    for (i=0;i<32;i++)
    {
        for (j=0;j<80;j++){
                if (j==0&&i!=0){tab[i][j]='|';}
                else if (i%4==0&&j<64){tab[i][j]='_';}
                else if (j==8||j==16||j==24||j==32||j==40||j==48||j==56){tab[i][j]='|';}
                else if (i!=0&&j==64){tab[i][j]='|';}
                else if (i==0&&j==66){tab[i][j]='0';}
                else if (i==4&&j==66){tab[i][j]='1';}
                else if (i==8&&j==66){tab[i][j]='2';}
                else if (i==12&&j==66){tab[i][j]='3';}
                else if (i==16&&j==66){tab[i][j]='4';}
                else if (i==20&&j==66){tab[i][j]='5';}
                else if (i==24&&j==66){tab[i][j]='6';}
                else if (i==28&&j==66){tab[i][j]='7';}
                else if (i==32&&j==66){tab[i][j]='8';}
                else {tab[i][j]=' ';}
                printf("%c",tab[i][j]);}}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
again4:
printf("It's your turn !\n");
printf("entrer la position de la pierre (numero de la ligne suivi de celui de la colonne separes par un espace) :");
printf("Remarque : si vous voulez passer le coup ! entrez 77 77\n\n");
scanf("%d %d",&a,&b);
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='B';
 for (k=0;k<73;k++){
   if(listeb[k][0]!='\0' && listeb[k][1]!='\0'){if (a*4==listeb[k][0] && b*8==listeb[k][1]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
  for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
   goto again4;}}}
 if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='B';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<33;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
 else{printf("vous suicidez ! entrez une autre position\n");
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
 goto again4;}}
 else if(a==77 && b==77){gagnant(tab);}
else {
    printf("entrer une position exsitante et vide\n");
    goto again4;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
m=0;
// tsumego 1 : trajet while(m<8){
//a=f[m];b=g[m];m++;goto fill;}
// tsumego 2 ; trajet
while(m<9){
a=w[m];b=q[m];m++;goto fill1;}
again5:
create_suicide_white(tab);
if(limiteb[0][0]!='\0'){a=(limiteb[0][0])/4;b=(limiteb[0][1])/8;limiteb[0][0]='\0';limiteb[0][1]='\0';goto fill1;}
capture_avoid_white(tab);
if(limitew[0][0]!='\0'){a=(limitew[0][0])/4;b=(limitew[0][1])/8;limitew[0][0]='\0';limitew[0][1]='\0';goto fill1;}
capture_avoid_black(tab);
if(limiteb[0][0]!='\0'){a=(limiteb[0][0])/4;b=(limiteb[0][1])/8;limiteb[0][0]='\0';limiteb[0][1]='\0';goto fill1;}
limitation_black(tab);
if(limitw[0][0]!='\0'){a=(limitw[0][0])/4;b=(limitw[0][1])/8;limitw[0][0]='\0';limitw[0][1]='\0';goto fill1;}
ran3:// pour random
srand (time (NULL));
int random = rand() % 10;
a=random;
srand (time (NULL));
int random1 = rand() % 16;
b=random1;
fill1:
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='W';
 for (k=0;k<65;k++){
   if(listew[k][0]!='\0' && listew[k][1]!='\0'){if (a*4==listew[k][0] && b*8==listew[k][1]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
   for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
   goto ran3;}}}
   if(forbidden_white(tab2,a*4,b*8)==1){
    for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
        goto ran3;}
   if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='W';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<33;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
  else{
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
 goto again5;}}
else {
    goto ran3;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]=tab[i][j];}}
       goto again4;

          }}}}
        if(c==2){system("cls");
            char nom_1[100], nom_2[100];
            printf("First player : \n");
            scanf("%s",&nom_1);
            printf("Second player :\n");
            scanf("%s",&nom_2);
            system("cls");
            printf("All right let's play ! But before starting ,let's discover who will play first by a random choice!\nClick any key to continue");
            getch();
            system("cls");
            srand (time (NULL));
            int random = rand() % 2;
            if (random==0){printf("\t\t\t ---<<You are lucky %s! You are going to start and you are the black player!>>---\n\t\t\t---<<Let's start!>>---\nClick any key to continue",nom_1);
             getch();
             }
            else{printf("\t\t\t ---<<You are lucky %s ! You are going to start and you are the black player!>>---\n\t\t\t---<<Let's start!>>---\nClick any key to continue",nom_2);}
            getch();
            printf("voulez-vous jouer un autre coup?(y/n)");
            scanf("%s",&rep);
            if(rep=='n'){handicap=0;}
   {

   int i,j,a,b,k;
    char tab[33][80];
    char tab2[33][80];
    printf("\n");
    printf("0       1       2       3       4       5       6       7       8\n");
    for (i=0;i<33;i++)
    {
        for (j=0;j<80;j++){
                if (j==0&&i!=0){tab[i][j]='|';}
                else if (i%4==0&&j<64){tab[i][j]='_';}
                else if (j==8||j==16||j==24||j==32||j==40||j==48||j==56){tab[i][j]='|';}
                else if (i!=0&&j==64){tab[i][j]='|';}
                else if (i==0&&j==66){tab[i][j]='0';}
                else if (i==4&&j==66){tab[i][j]='1';}
                else if (i==8&&j==66){tab[i][j]='2';}
                else if (i==12&&j==66){tab[i][j]='3';}
                else if (i==16&&j==66){tab[i][j]='4';}
                else if (i==20&&j==66){tab[i][j]='5';}
                else if (i==24&&j==66){tab[i][j]='6';}
                else if (i==28&&j==66){tab[i][j]='7';}
                else if (i==32&&j==66){tab[i][j]='8';}
                else {tab[i][j]=' ';}
                printf("%c",tab[i][j]);}}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]==tab[i][j];}}
again24:
printf("Remarque : si vous voulez passer le coup ! entrez 77 77\n\n");
printf("The Black player,It's your turn!\n");
printf("entrer la position de la pierre (numero de la ligne suivi de celui de la colonne separes par un espace) :");
scanf("%d %d",&a,&b);
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='B';
 for (k=0;k<73;k++){
   if(listeb[k][1]!='\0' && listeb[k][2]!='\0'){if (a*4==listeb[k][1] && b*8==listeb[k][2]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]==tab[i][j];}}
goto again24;}}}
 if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='B';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<33;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
 else{printf("vous suicidez ! entrez une autre position\n");
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]==tab[i][j];}}
 goto again24;}}
else if(a==77 && b==77){h++;if(h==2){gagnant(tab);}else{goto again13;}}
else {
    printf("entrer une position exsitante et vide\n");
    goto again24;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]==tab[i][j];}}
if(handicap==1){
 printf("voulez-vous jouer un autre coup?(y/n)");
 scanf("%s",&reponse);
   if(reponse=='y'){cw++;goto again24;}
   else{handicap=0;}}
again13:
printf("Remarque : si vous voulez passer le coup ! entrez 77 77\n\n");
printf("The white player, It's your turn !\n");
printf("entrer la position de la pierre (numero de la ligne suivi de celui de la colonne separes par un espace) :");
scanf("%d %d",&a,&b);
if (a<=8 && b<=8 && tab[a*4][b*8]!='W' && tab[a*4][b*8]!='B'){
 tab2[a*4][b*8]='W';
 for (k=0;k<65;k++){
   if(listew[k][1]!='\0' && listew[k][2]!='\0'){if (a*4==listew[k][1] && b*8==listew[k][2]){printf("vous ne respectez pas les regles ! entrez une autre position\n");
   for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]==tab[i][j];}}
   goto again13;}}}
 if(capture_suicide(tab2,a*4,b*8)==1){
      system("cls");
      tab[a*4][b*8]='W';
      capture(tab,a*4,b*8);
      printf("0       1       2       3       4       5       6       7       8\n");
      for (i=0;i<33;i++)
       {for (j=0;j<80;j++){
         if (tab[i][j]=='B'){Color(1,1);
         printf("%c",tab[i][j]);}
         else if (tab[i][j]=='W'){Color(15,15);
         printf("%c",tab[i][j]);}
         else{
          Color(15,0);
          printf("%c",tab[i][j]);}}}}
 else{printf("vous suicidez ! entrez une autre position\n");
 for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]==tab[i][j];}}
 goto again13;}}
else if(a==77 && b==77){h++;
if(h==2){gagnant(tab);}
else{goto again24;}}
else {
    printf("entrer une position exsitante et vide\n");
    goto again13;}
for (i=0;i<33;i++)
       {for (j=0;j<80;j++){tab2[i][j]==tab[i][j];}}
goto again24;

            }
        if(c==3){goto again11;}
    }
    if (c==3){
            system("cls");
    goto  again11;}}
    if (c==2){system ("cls");
    rules();
    printf("\n       Press any key to go to pevious menu");
    getch();
    system("cls");
    goto again11; }}
