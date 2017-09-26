{ arme O(n*n) }
{Nistor Mot}
program arme;
type vect=array[1..1001] of integer;
var n,m,i: integer; s:longint;
    a,b:vect;
    fi,fo:text;
procedure sort(var x:vect; n:integer);
var i,o,t:integer;
begin
repeat
 o:=1;
 for i:=1 to n-1 do
   if x[i]>x[i+1] then
      begin t:=x[i]; x[i]:=x[i+1]; x[i+1]:=t; o:=0 end;
until o=1
end;
begin
assign(fi,'arme.in'); reset(fi);
assign(fo,'arme.out'); rewrite(fo);
readln(fi,n,m);
for i:=1 to n do read(fi,a[i]);
for i:=1 to m do read(fi,b[i]);
sort(a,n); sort(b,m);
for i:=1 to n do
   if (i<=m) and (b[m+1-i]>a[i]) then s:=s+b[m+1-i]
   else s:=s+a[i];
writeln(fo,s);
close(fo)
end.


