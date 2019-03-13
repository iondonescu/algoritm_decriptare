#include <iostream>
#include <fstream>

using namespace std;
ofstream fout("fisier");

// functie ce afiseaza litera din alfabet
char afiseaza (int cifra)
{
    char litera{};
    switch (cifra)
    {
        case 0:litera='A';break;
        case 1:litera='B';break;
        case 2:litera='C';break;
        case 3:litera='D';break;
        case 4:litera='E';break;
        case 5:litera='F';break;
        case 6:litera='G';break;
        case 7:litera='H';break;
        case 8:litera='I';break;
        case 9:litera='J';break;
        case 10:litera='K';break;
        case 11:litera='L';break;
        case 12:litera='M';break;
        case 13:litera='N';break;
        case 14:litera='O';break;
        case 15:litera='P';break;
        case 16:litera='Q';break;
        case 17:litera='R';break;
        case 18:litera='S';break;
        case 19:litera='T';break;
        case 20:litera='U';break;
        case 21:litera='V';break;
        case 22:litera='W';break;
        case 23:litera='X';break;
        case 24:litera='Y';break;
        case 25:litera='Z';break;
    }
  return litera;
}

// functie ce calculeaza modulo 26
int modulo26(int element)
{
    if (element>=0) return (element%26);
    else return (26+element%26);
}

int main()
{
    int a11{},a12{},a13{},a21{},a22{},a23{},a31{},a32{},a33{};//elementele matricii de criptare A
    int b11{},b12{},b13{},b21{},b22{},b23{},b31{},b32{},b33{};//elementele matricii B
    int bt11{},bt12{},bt13{},bt21{},bt22{},bt23{},bt31{},bt32{},bt33{};//elementele matricii transpuse B
    int c11{},c12{},c13{},c21{},c22{},c23{},c31{},c32{},c33{};//elementele matricii transpuse B
    int x[30]{17,6,12,12,8,8,21,0,18,23,3,18,10,16,11,1,23,4,16,5,17,1,14,0,2,10,17,24,20,23};// sirul mesajului criptat
    int y[30];// sirul mesajului initial
    int determinant{0};// determinatul matricii de criptare
    int invers_determinant{0}; // inversul determinantului 
    int contor{0}; //cate variate de siruri vreau sa afiseze
    int litera_inceput{0};
    //int contor_iteratie{0};
    
    for (a11=1;a11<26;a11++)
        for (a12=1;a12<26;a12++)
            for (a13=1;a13<26;a13++)
                for (a21=1;a21<26;a21++)
                    for (a22=1;a22<26;a22++)
                        for (a23=1;a23<26;a23++)
                            for (a31=1;a31<26;a31++)
                                for (a32=1;a32<26;a32++)
                                    for (a33=1;a33<26;a33++)
                                    {   
                                        // pt ca sunt doi de XX la sf
                                        //a12 = modulo26(18-a13);
                                        //a22 = modulo26(2-a23);
                                        //a32 = modulo26(1-a33);
                                        // calculul determinantului
                                        determinant = modulo26(a11*a22*a33+a12*a23*a31+a21*a32*a13-a13*a22*a31-a21*a12*a33-a32*a23*a11);
                                        
                                        // daca determinantul este in multimea elementelor inversabile din Z26
                                        if (determinant == 1 || determinant == 3 || determinant == 5 || determinant == 7 || determinant == 9
                                        || determinant == 11 || determinant == 15 || determinant == 17 || determinant == 19 || determinant == 21
                                        || determinant == 23 || determinant == 25)
                                        {

                                            
                                        // calculez matricea inversa
                                                
                                                // calculez inversul determinantului
                                            switch (determinant)
                                            {
                                                case 1:invers_determinant = 1;break;
                                                case 3:invers_determinant = 9;break;
                                                case 5:invers_determinant = 21;break;
                                                case 7:invers_determinant = 15;break;
                                                case 9:invers_determinant = 3;break;
                                                case 11:invers_determinant = 19;break;
                                                case 15:invers_determinant = 7;break;
                                                case 17:invers_determinant = 23;break;
                                                case 19:invers_determinant = 11;break;
                                                case 21:invers_determinant = 5;break;
                                                case 23:invers_determinant = 17;break;
                                                case 25:invers_determinant = 25;break;
                                            }
                                            // calculez matricea B 
                                            b11 = modulo26(a22*a33-a23*a32);
                                            b12 = modulo26(a23*a31-a21*a33);
                                            b13 = modulo26(a21*a32-a22*a31);
                                            b21 = modulo26(a13*a32-a12*a33);
                                            b22 = modulo26(a11*a33-a13*a31);
                                            b23 = modulo26(a12*a31-a11*a32);
                                            b31 = modulo26(a12*a23-a13*a22);
                                            b32 = modulo26(a13*a21-a11*a23);
                                            b33 = modulo26(a11*a22-a12*a21);
                                            
                                            // calculez matrice transpusa B = Bt                                    
                                            bt11 = b11;
                                            bt12 = b21;
                                            bt13 = b31;
                                            bt21 = b12;
                                            bt22 = b22;
                                            bt23 = b32;
                                            bt31 = b13;
                                            bt32 = b23;
                                            bt33 = b33;
                                            
                                            // calculez inversa matricii A = C
                                            c11 = modulo26(invers_determinant * bt11);
                                            c12 = modulo26(invers_determinant * bt12);
                                            c13 = modulo26(invers_determinant * bt13);
                                            c21 = modulo26(invers_determinant * bt21);
                                            c22 = modulo26(invers_determinant * bt22);
                                            c23 = modulo26(invers_determinant * bt23);
                                            c31 = modulo26(invers_determinant * bt31);
                                            c32 = modulo26(invers_determinant * bt32);
                                            c33 = modulo26(invers_determinant * bt33);
                                            
                                                                                        
                                            if (modulo26(c31*24+c32*20+c33*23) == 23)
                                            {   
                                                litera_inceput = (c11*x[0]+c12*x[1]+c13*x[2])%26;
                                                if (litera_inceput != 24 && litera_inceput != 23  && litera_inceput != 22 && litera_inceput != 16 ) 
                                                //sa nu inceapa fraza cu Y / X / W / Q
                                                 {
                                                        
                                                     contor +=1;
                                                        fout<<"Mesajul este:";
                                                        fout <<"\n--------------------------------------"<<endl;
                                                     for (int i=0;i<30;i+=3)
                                                        {                                                                                                  
                                                                y[i]=modulo26(c11*x[i]+c12*x[i+1]+c13*x[i+2]);fout<<afiseaza(y[i]);
                                                                y[i+1]=modulo26(c21*x[i]+c22*x[i+1]+c23*x[i+2]);fout<<afiseaza(y[i+1]);
                                                                y[i+2]=modulo26(c31*x[i]+c32*x[i+1]+c33*x[i+2]);fout<<afiseaza(y[i+2]);                    
                                                        }
                                                        fout <<"\n--------------------------------------"<<endl;
                                                          
                                                                fout <<"Matricea de criptare A este:"<<endl;
                                                                fout <<a11<<" "<<a12<<" "<<a13<<endl;
                                                                fout <<a21<<" "<<a22<<" "<<a23<<endl;
                                                                fout <<a31<<" "<<a32<<" "<<a33<<endl;
                                                                fout <<"\n--------------------------------------"<<endl;
//                                                                fout <<"Matricea B este:"<<endl;
//                                                                fout <<b11<<" "<<b12<<" "<<b13<<endl;
//                                                                fout <<b21<<" "<<b22<<" "<<b23<<endl;
//                                                                fout <<b31<<" "<<b32<<" "<<b33<<endl;
//                                                                fout <<"\n--------------------------------------"<<endl;
//                                                                fout <<"Matricea inversa Bt este:"<<endl;
//                                                                fout <<bt11<<" "<<bt12<<" "<<bt13<<endl;
//                                                                fout <<bt21<<" "<<bt22<<" "<<bt23<<endl;
//                                                                fout <<bt31<<" "<<bt32<<" "<<bt33<<endl;
//                                                                fout <<"\n--------------------------------------"<<endl;
//                                                                fout <<"Matricea inversa C este:"<<endl;
//                                                                fout <<c11<<" "<<c12<<" "<<c13<<endl;
//                                                                fout <<c21<<" "<<c22<<" "<<c23<<endl;
//                                                                fout <<c31<<" "<<c32<<" "<<c33<<endl;
//                                                            
                                                     
                                                     if (contor >100000) return 0;//  100000 de variante 
                                                }
                                            }
                                        }
                                    }
//return 0;
}

