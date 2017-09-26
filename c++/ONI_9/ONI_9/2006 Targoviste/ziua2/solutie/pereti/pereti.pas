type    mat=array[0..101,0..101] of byte;
        dir=array[1..4] of integer;
        elem=record
                   i,j:byte;
                   end;
        sir=array[1..11000] of elem;
const d:dir=(8,4,2,1);
      dx:dir=(-1,0,1,0);
      dy:dir=(0,1,0,-1);
var a:mat;
    x:sir;
    m,n:byte;
    f:text;
    k,l:integer;
    nr:longint;

Procedure citire(var a:mat;var m,n:byte);
var i,j:byte;
    f:text;
begin
     assign(f,'pereti.in');
     reset(f);
     readln(f,m,n);
     for i:=1 to m do
         begin
         for j:=1 to n do
                 read(f,a[i,j]);
         readln(f);
         end;
     close(f);
end;

procedure bordare(var a:mat;m,n:byte);
var i:byte;
begin
     for i:=0 to n+1 do
         begin
          a[0,i]:=8+ (a[1,i] and 8) div 4;
          a[m+1,i]:=2+ (a[m,i] and 2)* 4 ;
         end;
     for i:=0 to m+1 do
         begin
          a[i,0]:=a[i,0]+1+(a[i,1] and 1) * 4;
          a[i,n+1]:=a[i,n+1]+4+(a[i,n] and 4) div 4;
         end;
end;

Function numara(var a:mat;m,n:byte):longint;
var nr:longint;
    i,j:byte;
begin
nr:=0;
k:=1;
l:=1;
x[l].i:=0;
x[l].j:=0;
a[0,0]:=a[0,0]+16;
while k<=l do
begin
   for i:=1 to 4 do
     if ((a[x[k].i,x[k].j] and d[i])<>d[i])and (a[x[k].i+dx[i],x[k].j+dy[i]]<16) then
        begin
        inc(l);
        x[l].i:=x[k].i+dx[i];
        x[l].j:=x[k].j+dy[i];
        a[x[l].i,x[l].j]:=a[x[l].i,x[l].j]+16;
        end;
   case a[x[k].i,x[k].j] -16 of
        1,2,4,8:  nr:=nr+1;
        3,5,6,9,10,12:  nr:=nr+2;
        7,11,13,14:  nr:=nr+3;
   end;
inc(k);
end;
numara:=nr;
end;

begin
citire(a,m,n);
bordare(a,m,n);
assign(f,'pereti.out');
rewrite(f);
writeln(f,numara(a,m,n)-2*m-2*n-8);
close(f);
end.

