function A=Jacobian
syms t1 t2 t3 t4 t5 t6 x1 x2 x3 x4 x5 x6 z1 z2 z3 z4 z5 z6
syms r11 r12 r13  r21 r22 r23 r31 r32 r33

T01=[cos(t1) 0 -sin(t1) 0;sin(t1) 0 cos(t1) 0;0 -1 0 z1;0 0 0 1];
T12=[cos(t2) sin(t2) 0 x2*cos(t2);sin(t2) cos(t2) 0 x2*sin(t2);0 0 1 0; 0 0 0 1];
T23=[cos(t3) 0 sin(t3) 0;sin(t3) 0 cos(t3) 0; 0 1 0 0;0 0 0 1];

T34=[cos(t4) 0 -sin(t4) 0;sin(t4) 0 cos(t4) 0;0 -1 0 z4;0 0 0 1];
T45=[sin(t5) 0 cos(t5) 0;cos(t5) 0 sin(t5) 0;0 -1 0 0;0 0 0 1];
T56=[cos(t6) -sin(t6) 0 0;sin(t6) cos(t6) 0 0; 0 0 1 z6;0 0 0 1];

T02=simplify(T01*T12);
T03=simplify(T02*T23);
T13=simplify(T12*T23);

T04=simplify(T03*T34);
T14=simplify(T13*T34);
T24=simplify(T23*T34);

T05=simplify(T04*T45);
T15=simplify(T14*T45);
T25=simplify(T24*T45);
T35=simplify(T34*T45);

T06=simplify(T05*T56);
T16=simplify(T15*T56);
T26=simplify(T25*T56);
T36=simplify(T35*T56);
R36=T36(1:3,1:3);
R03=T03(1:3,1:3);
R03inv=simplify(inv(R03));
R06=[r11 r12 r13;r21 r22 r23;r31 r32 r33];
C=R03inv*R06;
f1=C(1,1);
g1=R36(1,1);
f2=C(3,1);
g2=R36(3,1);
f3=C(2,3);
g3=R36(2,3);
F=[f1;f2;f3];
G=[g1;g2;g3];
Jg=jacobian(G,[t4,t5,t6]);
Jf=jacobian(F,[t1,t2,t3]);
Jginv=simplify(inv(Jg));
A2=simplify(Jginv*Jf)
