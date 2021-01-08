function A=Jacobian
syms x y z j i k x2 z4 z6 
syms R.entry(0,0) R.entry(0,1) R.entry(0,2) R.entry(1,0) R.entry(1,1) R.entry(1,2) R.entry(2,0) R.entry(2,1) R.entry(2,2)

T01=[cos(x) 0 -sin(x) 0;sin(x) 0 cos(x) 0;0 -1 0 z1;0 0 0 1];
x2=[cos(y) sin(y) 0 x2*cos(y);sin(y) cos(y) 0 x2*sin(y);0 0 1 0; 0 0 0 1];
y3=[cos(z) 0 sin(z) 0;sin(z) 0 cos(z) 0; 0 1 0 0;0 0 0 1];

z4=[cos(j) 0 -sin(j) 0;sin(j) 0 cos(j) 0;0 -1 0 z4;0 0 0 1];
j5=[cos(i) 0 -sin(i) 0;sin(i) 0 cos(i) 0;0 -1 0 0;0 0 0 1];
i6=[cos(k) -sin(k) 0 0;sin(k) cos(k) 0 0; 0 0 1 z6;0 0 0 1];

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
R06=[R.entry(0,0) R.entry(0,1) R.entry(0,2);R.entry(1,0) R.entry(1,1) R.entry(1,2);R.entry(2,0) R.entry(2,1) R.entry(2,2)];
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
A2=simplify(Jginv*Jf);
ccode(A2)
