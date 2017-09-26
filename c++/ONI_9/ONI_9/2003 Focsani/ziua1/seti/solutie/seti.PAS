program seti;
var c:array['a'..'z'] of byte;
    n:array[0..9] of char;
    s:array[0..9999] of longint;
    f:text;i:byte;p:word;
    x:string;k:longint;
begin
assign(f,'seti.in');
reset(f);
readln(f,x);
for i:=0 to 9 do
 begin
  c[x[i+1]]:=i;
  n[i]:=x[i+1];
 end;
while not eof(f) do
 begin
   readln(f,x);
   p:=c[x[1]]*1000+c[x[2]]*100+c[x[3]]*10+c[x[4]];
   inc(s[p]);
 end;
close(f);
assign(f,'seti.out');
rewrite(f);
for p:=0 to 9999 do
  for k:=1 to s[p] do
  writeln(f,n[p div 1000]+n[(p div 100) mod 10]+n[(p div 10) mod 10]+n[p mod 10]);
close(f);
end.
