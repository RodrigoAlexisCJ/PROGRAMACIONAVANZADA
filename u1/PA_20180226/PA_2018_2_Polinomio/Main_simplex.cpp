#include <iostream>
//#include "Rac.h"
#include "Polinomio.h"
#include "cloak.h"
#define NdV(pre,suf)	PRIMITIVE_CAT(pre, suf )
#define PRED(state, ...) BOOL(state)
#define OP(state, ...) DEC(state), c ## state, __VA_ARGS__	/* 0, c1, c2, c3, ..., c9, REVISAR preprocesando*/
#define OP1(state, ...) DEC(state), r1 ## state, __VA_ARGS__	/* 0, r11, r12, r13, ..., r19 REVISAR preprocesando */
#define OP2(state, ...) DEC(state), r2 ## state, __VA_ARGS__	/* 0, r21, r22, r23, ... */
#define OP3(state, ...) DEC(state), F ## state, __VA_ARGS__     /*0, F1, F2, F3, ... */
//#define MACRO(state) state

using namespace std; /*cout*/

int main(){
	Rac c1(2,1),c2(3,1),c3(0,1),c4(0,1),c5(0,1);     // <--------
	Rac r11(2,1),r12(1,1),r13(1,1),r14(0,1),r15(4,1);
	Rac r21(1,1),r22(2,1),r23(0,1),r24(1,1),r25(5,1);
	Rac *Cj=new Rac[5];
	//Cj[0]=c1;/*    Cj[k]=*(Cj+k)     */
//	*Cj=NdV(c,1);
//	Cj[1]=NdV(c,2);/*    *(Cj+1)=c2;       */
//	*(Cj+2)=NdV(c,3);
//	*(Cj+3)=NdV(c,4);
//	*(Cj+4)=NdV(c,5);
    Rac Arr[]={(Rac)            // Esta es una forma de declarar un arreglo 
    EVAL(WHILE(PRED, OP, 5,))	// de objetos Rac por extensi\'on; con la 
    (Rac)0};                    // particularidad de que los identificadores 
    for(int i=0;i<5;i++){       // de los objetos ser\'an c1, c2, c3, c4 y c5,
    	*(Cj+i)= Arr[i+1];      // esto es, con los nombres que se est\'an usando 
    }                           // en la l\'inea con la flecha <-------- arriba
                                // En la clase Rac fuen necesario agregar el 
                                // constructor Rac::Rac(int){ }

	Polinomio Fz(4,Cj);
	cout<<Fz<<endl;
	Rac *rPt1=new Rac[5],*rPt2=new Rac[5];
//	*(rPt1+0)=NdV(r1,1);
//	*(rPt1+1)=NdV(r1,2);/*    *(Cj+1)=c2;       */
//	*(rPt1+2)=NdV(r1,3);
//	*(rPt1+3)=NdV(r1,4);
//	*(rPt1+4)=NdV(r1,5);
    Rac Arr1[]={(Rac)
    EVAL(WHILE(PRED, OP2, 5,))
    (Rac)0};
    for(int i=0;i<5;i++){
    	*(rPt1+i)= Arr1[i+1];
    }
	
//	*(rPt2+0)=NdV(r2,1);
//	*(rPt2+1)=NdV(r2,2);/*    *(Cj+1)=c2;       */
//	*(rPt2+2)=NdV(r2,3);
//	*(rPt2+3)=NdV(r2,4);
//	*(rPt2+4)=NdV(r2,5);
    Rac Arr2[]={(Rac)
    EVAL(WHILE(PRED, OP2, 5,))
    (Rac)0};
    for(int i=0;i<5;i++){
    	*(rPt2+i)= Arr2[i+1];
    }
	
	Polinomio F1(4,rPt1),F2(4,rPt2);
	cout<<F1<<endl;
	cout<<F2<<endl;
	
	Polinomio *PolPt=new Polinomio[2];
//	*PolPt=F1;
//	*(PolPt+1)=F2;
    Polinomio Arr3[]={(Polinomio)
    EVAL(WHILE(PRED, OP3, 2,))
    (Polinomio)0};
    for(int i=0;i<2;i++){
    	*(PolPt+i)= Arr3[i+1];
    }
    
	cout<<*(PolPt+1)<<endl;
	return 0;
}//end main

#undef PRED
#undef OP
#undef OP1
#undef OP2
#undef OP3
#undef MACRO
