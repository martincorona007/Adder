#include <iostream>
#include <map>
#include <stdio.h>
void L(int l=1);
void R(int);
void Left2(char);
void Right2(char);
void sigma(char);
void print();

//check the states
int transition_Function(int,char);
int adder(int);
void test();

char read();

//char c_out();

typedef std::map<int,char> tape;
typedef std::map<int,char>::iterator it;
typedef std::map<int,char>::reverse_iterator itt;

int itera();

it iter;
itt iterb;
tape t;

int Ra=9;//--move
int Rb=9;//static move
int Rc=1;//++where we count the carry
int Rs=10;//-- where we move to write in s
int Lef=29;//-- we move to the left

int header=0;

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
    printf("Running:");
    print();
  /*  R(16);
    printf("carry %c",c_out());
*/
    printf("\n\n\n");


    test();
    //R(8);
    printf("\n\n\n");

    print();
    return 0;
}
int transition_Function(int q){
  /*Ra-=1;//--move
    //Rb=9;//static move
    Rc+=1;//++where we count the carry
    Rs-=1;//-- where we move to write in s
    Lef-=1;//-- we move to the left
    */
   // printf("Ra [%i] Rb[%i ]Rc [%i] Rs [%i] Left [%i]\n",Ra,Rb,Rc,Rs,Lef);

    //if(Ra==-1&&Rc==11&&Rs==0&&Lef==19){
            //print();
      //  return 20;
    //}else{
            switch(q){


                case 1:


                    print();

                    Ra-=1;
                            Rb=9;//static move
                            Rc+=1;//++where we count the carry
                            Rs-=1;//-- where we move to write in s
                            Lef-=1;//-- we move to the left

                    R(Ra);
                    printf("honey");
                 //   R(Ra);
                       //R(Ra);
                    if(read()=='0'){
                        printf("return 2");

                         print();

                        return 2;

                    }
                  //  R(Ra);
                    if(read()=='1'){
                        printf("return 4");

                         print();
                        return 4;

                    }
                break;
                case 2:
                   R(Rb);

                    if(read()=='0'){
                        printf("return 5");
                         print();

                        return 5;

                    }
                   // R(Rb);
                    if(read()=='1'){
                        printf("return 3");
                         print();
                        return 3;

                    }
                    break;
                case 3:
                    R(Rc);
                        printf("RC %i",Rc);
                    if(read()=='1'){
                        printf("return 17");
                        sigma('1');
                         print();
                        return 17;

                    }
                   // R(Rb);
                    if(read()!='0'||read()!=32){
                        printf("return 15");
                        sigma('0');
                         print();
                        return 15;

                    }
                    break;
                case 4:
                    R(Rb);

                    if(read()=='0'){
                        printf("return 3");
                         print();
                        return 3;

                    }
                   // R(Rb);
                    if(read()=='1'){
                        printf("return 10");
                         print();
                        return 10;

                    }
                    break;
                case 5:

                    R(Rc);
                        printf("Rc %i",Rc);
                    if(read()=='0'||read()=='\0'||read()==32){
                        printf("return 6");
                        //here i call to sigma to write


                        sigma('0');
                     //   printf("\n");

                        print();
                        return 6;
                    }
                    if(read()=='1'){
                        printf("return 8");
                         print();
                         sigma('0');
                        //here i call to sigma to write
                        return 8;
                    }
                    break;
                case 6:

                    R(Rs);

                    if(read()==32){
                        printf("return 7");

                        sigma('0');
                     //  printf("\n");
                        print();

                        return 7;
                    }

                    break;

                case 7:
                        L(Lef);
                        printf("return 1");
                        printf("LEFT");
                        print();
                        return 1;
                    break;
                case 8:
                    R(Rs);
                    printf("RC %i+",Rc);
                    if(read()==32){
                        printf("return 9");

                         sigma('1');
                         print();
                        //here i call to sigma to write
                        return 9;
                    }
                        break;
                case 9:
                   L(Lef);
                        printf("return 1");
                       printf("LEFT");

                        print();
                        return 1;
                    break;
                case 10:
                    R(Rc);
                        printf("RC %i",Rc);
                    if(read()=='0'||read()=='\0'||read()==32){
                        printf("return 11");
                        //here i call to sigma to write


                        sigma('1');
                     //   printf("\n");

                        print();
                        return 11;
                    }
                    if(read()!='1'){
                        printf("return 13");

                         sigma('1');
                         print();
                        //here i call to sigma to write
                        return 13;
                    }
                    break;
                case 11:
                    R(Rs);

                    if(read()==32){
                        printf("return 12");

                        sigma('0');
                     //  printf("\n");
                        print();

                        return 12;
                    }
                    break;
                case 12:
                    L(Lef);
                        printf("return 1");
                       printf("LEFT");
                        print();
                    return 1;
                    break;
                case 13:
                    R(Rs);

                    if(read()==32){
                        printf("return 14");

                        sigma('1');
                     //  printf("\n");
                        print();

                        return 14;
                    }
                    break;
                case 14:
                    L(Lef);
                        printf("return 1");
                       printf("LEFT");
                        print();
                    return 1;
                    break;
                case 15:
                     R(Rs);

                    if(read()==32){
                        printf("return 16");

                        sigma('1');
                     //  printf("\n");
                        print();

                        return 16;
                    }
                    break;
                case 16:
                    L(Lef);
                        printf("return 1");
                       printf("LEFT");
                        print();
                    return 1;
                    break;

                case 17:
                    R(Rs);

                    if(read()==32){
                        printf("return 18");

                        sigma('0');
                     //  printf("\n");
                        print();

                        return 18;
                    }
                    break;
                case 18:
                    L(Lef);
                        printf("return 1");
                       printf("LEFT");
                        print();
                    return 1;
                    break;
            }


   // }


}
int adder(int qq){
    int q=0;
    int a=0;
    if(qq==24){

                printf("died");

    }else{

        q=transition_Function(qq);


        a=adder(q);

    }
    return a;
}
void test(){
    printf("\nSTATE: %i",adder(1));
   /* R(Ra);
    printf("1=%c",read());
    R(Rb);
    printf("2=%c",read());
    R(Rc);
    printf("3=%c",read());
    R(Rs);
    printf("4=%c",read());

    //L(Lef);
    L();*/

}

void L(int l){
    if(l>=21&&l<=28){
        header=0;
    }else{
        header=l;
    }
//printf("h1 %i",header);

   /* header-=l;

    if(l>=21&&l<=28){
        iterb=t.rbegin();
        header=iterb->first;

    }
printf("h1 %i",header);

*/
}
void R(int r=1){
    header+=r;
    printf(" >header %i< ",header);


    /*for (iter=t.begin(); iter<=7; ++iter){
            std::cout <<"in R " << read();
    }*//*
    for (iter=t.begin(); iter!=t.end(); ++iter){
        if(iter->first==r){//check the if the key is equals to r
            //printf("%i ->%c",r ,read());
            printf(" R[%c] ",read());

            //read();
            printf("<I[%i]>",itera());
           // itera();
        }
    }*/
  /*  iter=t.find(r);

    if(iter!=t.end()){
         printf(" R[%c] ",read());


            printf("<I[%i]>",itera());

    }
*/
}
void sigma(char s){
    //iter->second=s;
   // iter=t.begin(itera());
   // if(iter
    t[header]=s;
/*PROBLEM HERE*/
    /*
    iter=t.begin();
    if(iter!=t.find(sum)))

    iter->second=s;*/
   /* for(iter;iter!=t.end();++iter){
        iter->second=s;
    }*/
//t[Rs]=s;nope
}

char read(){

    iter=t.find(header);

    if(iter!=t.end()){

        return  iter->second;

    }

}

void print(){printf("\n");
                if(header==0){
                    std::cout<<".";
                }
    for(iter=t.begin();iter!=t.end();++iter){


                if(header==iter->first){
                    std::cout<<".";
                }
                std::cout <<"["<<iter->second<<"]";
    }

}
