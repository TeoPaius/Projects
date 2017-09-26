program coduri;
var n,i:integer;
    s:extended;
    f:text;
begin
 assign(f,'coduri.in');
 reset(f);
 readln(f,n);
 close(f);
 s:=n*(n+1)*(2*n+1)/6;
 s:=s*s*s*s;
 assign(f,'coduri1.out');
 rewrite(f);
 for i:=1 to n do
  writeln(f,s*i:0:0);
 close(f);
end.