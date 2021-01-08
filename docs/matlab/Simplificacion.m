syms q1 q2 q3 z1 z2 z3 z4 x2
 
T01=[cos(q1) 0 -sin(q1) 0; sin(q1) 0 cos(q1) 0; 0 -1 0 z1; 0 0 0 1]

T12=[cos(q2) -sin(q2) 0 x2*cos(q2);sin(q2) cos(q2) 0 x2*cos(q2);0 0 1 0; 0 0 0 1]

T23=[cos(q3) 0 -sin(q3) 0; sin(q3) 0 cos(q3) 0; 0 -1 0 0; 0 0 0 1]
P = [0; 0; z4; 1]
 
R04= T01*T12*T23*P

jacobian([R04],[q1,q2,q3])