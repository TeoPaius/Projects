{ Fie n si m doua numere naturale nenule.
  Fie c si r catul si respectiv retul impartirii unui numar la 2^k,
  unde k este un numar natural nenul.
  Asupra unui numar putem efectua urmatoarele operatii

         o1(k)=2^k(2*c+1)+r pentru orice rest

          o2(k)=2^(k-1)*c+r doar daca r<2^(k-1)
  Efectuati asupra numerelor n si m operatii succesive o1( sau o2
  astfel incat dupa un numar finit de operatii cele doua numere
  sa devina egale, iar valoarea obtinuta sa fie minima
  Exemplu:
  n=45
  m=11
  Operatii succesive asupra lui n asupra lui
  o1 2
  o1 4
  Operatii succesive asupra lui m asupra lui
  o1 3
  o2 2
  }
type    operatie=record
        o,k:byte;
        end;
        oper=array[1..50] of operatie;
var n,m,min:longint;
    k,l:byte;
    on,om:oper;
    f:text;

Procedure solutie(m:longint;om,on:oper;k,l:byte);

Procedure scrie(x:oper;n:byte);
var i:byte;
begin
     writeln(f,n);
     for i:=1 to n do
          writeln(f,x[i].o,' ',x[i].k);
end;

begin
     assign(f,'operatii.out');
     rewrite(f);
     writeln(f,m);
     scrie(om,k);
     scrie(on,l);
     close(f);
end;

Function o1(n,k:longint):longint;
var p,c,r:longint;
    i:byte;
Begin
p:=1;
for i:=1 to k do
    p:=p*2;
c:=n div p;
r:=n mod p;
o1:=p*(2*c+1)+r;
end;

Function o2(n,k:longint):longint;
var p,c,r:longint;
    i:byte;
Begin
p:=1;
for i:=1 to k do
    p:=p*2;
c:=n div p;
r:=n mod p;
if r<p div 2 then o2:=(p div 2)*c+r
             else o2:=n;
end;

Function elimin0(n:longint):byte;
var i,c:byte;
begin
c:=0;
i:=0;
while (n<>0) and (c=0) do
      begin
      inc(i);
      if n mod 2=0 then
            c:=i;
      n:=n div 2;
      end;
elimin0:=c;
end;

Procedure adaugaoperatii(var o:oper;var k:byte;m,n:longint);
begin
while m>n do
         begin
         inc(k);
         o[k].o:=1;
         o[k].k:=1;
         n:=o1(n,1);
         end;
end;

Procedure verif0(var o:oper;var k:byte;var n:longint);
begin
k:=0;
while elimin0(n)<>0 do
      begin
      inc(k);
      o[k].o:=2;
      o[k].k:=elimin0(n);
      n:=o2(n,o[k].k);
      end;

end;
begin
assign(f,'operatii.in');
reset(f);
readln(f,m,n);
close(f);
verif0(om,k,m);
verif0(on,l,n);
if m>n then
         begin
         min:=m;
         adaugaoperatii(on,l,m,n)
         end
       else
         begin
         min:=n;
         adaugaoperatii(om,k,n,m);
         end;
solutie(min,om,on,k,l);
writeln('n=',n,' m=',m);
readln;
end.

