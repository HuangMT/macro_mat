#pragma once

#define DEC_1 0
#define DEC_2 1
#define DEC_3 2 
#define DEC_4 3 
#define DEC_5 4 
#define DEC_6 5 
#define DEC_7 6 
#define DEC_8 7 
#define DEC_9 8 
#define DEC_10 9
#define DEC_11 10
#define DEC_12 11 
#define DEC_13 12
#define DEC_14 13
#define DEC_15 14
#define DEC_16 15
#define DEC_17 16
#define DEC_18 17
#define DEC_19 18
#define DEC_20 19
#define DEC_21 20

#define DO_0(x,n,...) 
#define DO_1(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_2(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_3(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_4(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_5(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_6(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_7(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_8(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_9(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_10(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_11(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_12(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_13(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_14(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_15(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_16(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_17(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_18(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_19(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_20(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define DO_21(x,n,...) CON(DO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)

#define BIDO_0(x,n,...) 
#define BIDO_1(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_2(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_3(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_4(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_5(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_6(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_7(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_8(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_9(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_10(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_11(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_12(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_13(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_14(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_15(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_16(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_17(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_18(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_19(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_20(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)
#define BIDO_21(x,n,...) CON(BIDO_,DEC(n))(x,DEC(n),##__VA_ARGS__)x(n,##__VA_ARGS__)


#define DO_3PARA_0(x,n,p1,p2) 
#define DO_3PARA_1(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_2(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_3(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_4(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_5(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_6(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_7(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_8(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_9(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_10(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_11(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_12(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_13(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_14(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_15(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_16(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_17(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_18(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_19(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_20(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)
#define DO_3PARA_21(x,n,p1,p2) CON(DO_3PARA_,DEC(n))(x,DEC(n),p1,p2)x(n,p1,p2)

#define DEC( n ) DEC_##n
#define _CON( x, y ) x##y 
#define CON( x, y ) _CON( x, y )

#define DO(x,n,...) CON(DO_,n)(x,n,##__VA_ARGS__)
#define BIDO(x,n,...) CON(BIDO_,n)(x,n,##__VA_ARGS__)
#define DO_3PARA(x,n,p1,p2) CON(DO_3PARA_,n)(x,n,p1,p2)
