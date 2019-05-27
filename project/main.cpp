#include <iostream>
#include <map>
#include <stdio.h>
void L(int);
void R(int);
void sigma(char);
void print();

int transition_Function(int,char);
int adder(int);
void test();

char read();

char c_out();

typedef std::map<int,char> tape;
typedef std::map<int,char>::iterator it;


it iter;
tape t;

int Ra=8;//--move
int Rb=9;//static move
int Rc=2;//++where we count the carry
int Rs=9;//-- where we move to write in s
int Lef=28;//-- we move to the left


int main()
{

    t[1]='1';
    t[2]='0';
    t[3]='0';
    t[4]='1';
    t[5]='0';
    t[6]='1';
    t[7]='1';
    t[8]='0';
    t[9]=':';
    t[10]='1';
    t[11]='0';
    t[12]='1';
    t[13]='0';
    t[14]='1';
    t[15]='0';
    t[16]='1';
    t[17]='0';
    t[18]='@';
    t[19]=' ';
    t[20]=':';
    t[21]=' ';
    t[22]=' ';
    t[23]=' ';
    t[24]=' ';
    t[25]=' ';
    t[26]=' ';
    t[27]=' ';
    t[28]=' ';

    print();
  /*  R(16);
    printf("carry %c",c_out());
*/
    printf("\n\n\n");


    test();


    return 0;
}
int transition_Function(int q){

    switch(q){

        case 1:

            R(Ra);

            if(iter->second==0){
                printf("return 2");
                return 2;

            }
            R(Ra);
            if(iter->second==1){
                printf("return 4");
                return 4;

            }
        break;
        case 2:
            R(Rb);
            if(iter->second==0){
                printf("return 5");
                return 5;

            }
            R(Rb);
            if(iter->second==1){
                printf("return 3");
                return 3;

            }
        break;
        case 5:
            R(Rc);
            if(iter->second==0||iter->second=='\0'){
                printf("simon");
                //here i call to sigma to write
                return 7;
            }else{
                printf("na");
            }

    }

}
int adder(int qq){
    int q=0;
    int a=0;
    if(qq==7){
                printf("died");

    }else{
        q=transition_Function(qq);
        a=adder(q);
    }
    return a;
}
void test(){
    adder(1);
}
/*
char c_out(){
     iter=t.find(19);
      return iter->second;
}*/
void L(int l){
    if(l>=21&&l<=28){
        iter=t.find(1);
        std::cout <<iter->first  <<"+"<<iter->second;
    }
}
void R(int r){
    /*for (iter=t.begin(); iter<=7; ++iter){
            std::cout <<"in R " << read();
    }*/
    for (iter=t.begin(); iter!=t.end(); ++iter){
        if(iter->first==r){//check the if the key is equals to r
            //printf("%i ->%c",r ,read());
            read();
        }
    }

}
void sigma(char s){

}
char read(){

return  iter->second;
}
void print(){
    for (iter=t.begin(); iter!=t.end(); ++iter)
    std::cout <<  iter->second;

}
