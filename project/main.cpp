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


typedef std::map<int,char> tape;
typedef std::map<int,char>::iterator it;
typedef std::map<int,char>::reverse_iterator itt;



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

    printf("\n\n\n");


    test();
    printf("\n\n\n");

    print();
    return 0;
}
int transition_Function(int q){

            switch(q){


                case 1:


                    print();

                            Ra-=1;//--move
                            Rb=9;//static move
                            Rc+=1;//++where we count the carry
                            Rs-=1;//-- where we move to write in s
                            Lef-=1;//-- we move to the left

                    R(Ra);
                    if(read()=='0'){
                      //  printf("return 2");

                         print();

                        return 2;

                    }
                    if(read()=='1'){
                      //  printf("return 4");

                         print();
                        return 4;

                    }
                break;
                case 2:
                   R(Rb);

                    if(read()=='0'){
                      //  printf("return 5");
                         print();

                        return 5;

                    }
                    if(read()=='1'){
                      //  printf("return 3");
                         print();
                        return 3;

                    }
                    break;
                case 3:
                    R(Rc);
                    if(read()=='1'){
                      //  printf("return 17");
                        sigma('1');
                         print();
                        return 17;

                    }
                    if(read()!='0'||read()!=32){
                      //  printf("return 15");
                        sigma('0');
                         print();
                        return 15;

                    }
                    break;
                case 4:
                    R(Rb);

                    if(read()=='0'){
                       // printf("return 3");
                         print();
                        return 3;

                    }
                    if(read()=='1'){
                      //  printf("return 10");
                         print();
                        return 10;

                    }
                    break;
                case 5:

                    R(Rc);
                    if(read()=='0'||read()=='\0'||read()==32){
                      //  printf("return 6");
                        //here i call to sigma to write on the tape


                        sigma('0');
                        print();
                        return 6;
                    }
                    if(read()=='1'){
                      //  printf("return 8");
                         print();
                         sigma('0');
                        //here i call to sigma to write on the tape
                        return 8;
                    }
                    break;
                case 6:

                    R(Rs);

                    if(read()==32){
                      //  printf("return 7");

                        sigma('0');

                        print();

                        return 7;
                    }

                    break;

                case 7:
                        L(Lef);
                      //  printf("return 1");
                      //  printf("LEFT");
                        print();
                        return 1;
                    break;
                case 8:
                    R(Rs);
                    if(read()==32){
                      //  printf("return 9");

                         sigma('1');
                         print();
                        //here i call to sigma to write on the tape
                        return 9;
                    }
                        break;
                case 9:
                   L(Lef);
                     //   printf("return 1");
                     //  printf("LEFT");

                        print();
                        return 1;
                    break;
                case 10:
                    R(Rc);
                    if(read()=='0'||read()=='\0'||read()==32){
                     //   printf("return 11");
                        //here i call to sigma to write


                        sigma('1');


                        print();
                        return 11;
                    }
                    if(read()!='1'){
                      //  printf("return 13");

                         sigma('1');
                         print();
                        //here i call to sigma to write
                        return 13;
                    }
                    break;
                case 11:
                    R(Rs);

                    if(read()==32){
                   //     printf("return 12");

                        sigma('0');

                        print();

                        return 12;
                    }
                    break;
                case 12:
                    L(Lef);
                     //   printf("return 1");
                     //  printf("LEFT");
                        print();
                    return 1;
                    break;
                case 13:
                    R(Rs);

                    if(read()==32){
                    //    printf("return 14");

                        sigma('1');
                     //  printf("\n");
                        print();

                        return 14;
                    }
                    break;
                case 14:
                    L(Lef);
                     //   printf("return 1");
                    //   printf("LEFT");
                        print();
                    return 1;
                    break;
                case 15:
                     R(Rs);

                    if(read()==32){
                     //   printf("return 16");

                        sigma('1');
                     //  printf("\n");
                        print();

                        return 16;
                    }
                    break;
                case 16:
                    L(Lef);
                     //   printf("return 1");
                     //  printf("LEFT");
                        print();
                    return 1;
                    break;

                case 17:
                    R(Rs);

                    if(read()==32){
                     //   printf("return 18");

                        sigma('0');
                     //  printf("\n");
                        print();

                        return 18;
                    }
                    break;
                case 18:
                    L(Lef);
                    //    printf("return 1");
                    //   printf("LEFT");
                        print();
                    return 1;
                    break;
                default:
                    return 20;
                    break;
            }


    //}


}
int adder(int qq){
    int q=0;//the next state
    int a=0;
    if(qq==20){//undefinided state

            //    printf("died");

    }else{

        q=transition_Function(qq);


        a=adder(q);

    }
    return a;
}
void test(){
    adder(1);


}

void L(int l){
    if(l>=21&&l<=28){
        header=0;
    }else{
        header=l;
    }

}
void R(int r=1){
    header+=r;
  //  printf(" >header %i< ",header);

}
void sigma(char s){

    t[header]=s;


}

char read(){

    iter=t.find(header);

    if(iter!=t.end()){

        return  iter->second;

    }

}

void print(){
                printf("\n");
          if(header==0){
             std::cout<<".";
          }
          for(iter=t.begin();iter!=t.end();++iter){
                if(header==iter->first){
                    std::cout<<".";
                }
                std::cout <<iter->second;
          }

}

