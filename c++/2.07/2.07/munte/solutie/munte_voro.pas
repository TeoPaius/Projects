var a:array[0..64000] of longint;
    f,g:text;
    n,max,i,nr,x:longint;
    ok:boolean;

begin
 assign(f,'munte.in'); reset(f);
 assign(g,'munte.out'); rewrite(g);
 read(f,n);
 max:=0;
 for i:=1 to 64000 do
  a[i]:=0;
 for i:=1 to n do begin
  read(f,x);
  if max<x then
   max:=x;
  inc(a[x]);
 end;
 x:=1;
 nr:=0;
 ok:=false;
 for i:=1 to max do begin
  if a[i]>2 then
   x:=0;
  if (a[i]=1) and (i<>max) then
   inc(nr);
  if a[i]=2 then
   ok:=true;
 end;
 if a[max]>1 then
  x:=0;
 for i:=1 to nr do
  x:=(x shl 1) mod 12343;
 if ok=false then
  x:=(x+12343-2) mod 12343;
 writeln(g,x);
 close(f); close(g);
end.
