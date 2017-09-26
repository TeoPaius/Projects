{programul genereaza fisierele de test}
program generator;
const nr=ord('z')-ord('a')+1;
var f:text;
    s:string;
    a:array[0..9] of char;
    c:set of char;
    i,n:longint;j:byte;
    x:char;
{generez setul 10 de caractere}
procedure initializare;
begin
c:=[];
randomize;
for i:=0 to 9 do
 begin
   repeat
     x:=chr(ord('a')+random(nr));
   until not(x in c);
   c:=c+[x];
   a[i]:=x;
 end;
end;
{genereaza k siruri si le scrie in fisier}
procedure genereaza(k:longint);
begin
for i:=0 to 9 do write(f,a[i]);writeln(f);
for i:=1 to k do
 begin
  s:='';
  for j:=1 to 4 do s:=s+a[random(10)];
  writeln(f,s);
 end;
end;
begin
{generez primul fisier, ar trebui sa mearga doar cu sortare a unui tablou}
assign(f,'1.in');
rewrite(f);
initializare;
genereaza(1000);
close(f);
{generez fisierul 2, doar varianta optima, eventual liste, ar functiona}
assign(f,'2.in');
rewrite(f);
initializare;
genereaza(40000);
close(f);
{doar o varianta optima ar functiona pentru acest test}
assign(f,'3.in');
rewrite(f);
initializare;
genereaza(100000);
close(f);
{testeaza daca un element se poate repeta de mai mult de 32767(maxint) ori}
assign(f,'4.in');
rewrite(f);
initializare;
for i:=0 to 9 do write(f,a[i]);writeln(f);
for i:=1 to 36000 do
 writeln(f,a[2],a[5],a[3],a[8]);
close(f);
{testeaza daca un element se poate repeta de mai mult de 65535 ori}
assign(f,'5.in');
rewrite(f);
initializare;
for i:=0 to 9 do write(f,a[i]);writeln(f);
for i:=1 to 70000 do
 writeln(f,a[3],a[1],a[6],a[9]);
close(f);

{testeaza daca un element se poate repeta de mai mult de 65535 ori}
assign(f,'6.in');
rewrite(f);
initializare;
for i:=0 to 9 do write(f,a[i]);writeln(f);
for i:=1 to 100000 do
 writeln(f,a[2],a[1],a[6],a[9]);
close(f);

{testeaza daca un element se poate repeta de mai mult de 65535 ori}
assign(f,'7.in');
rewrite(f);
initializare;
for i:=0 to 9 do write(f,a[i]);writeln(f);
for i:=1 to 150000 do
 writeln(f,a[3],a[2],a[4],a[9]);
close(f);

{testeaza daca un element se poate repeta de mai mult de 65535 ori}
assign(f,'8.in');
rewrite(f);
initializare;
for i:=0 to 9 do write(f,a[i]);writeln(f);
for i:=1 to 200000 do
 writeln(f,a[2],a[1],a[6],a[3]);
close(f);

{testeaza daca un element se poate repeta de mai mult de 65535 ori}
assign(f,'9.in');
rewrite(f);
initializare;
genereaza(150000);
close(f);

assign(f,'10.in');
rewrite(f);
initializare;
genereaza(200000);
close(f);




end.
