{prof.Sorin Bardac}
program culesul_porumbului;
var
  f,g:text;
  nrtot,nrx:integer;
  n,x,ult,a:longint;

begin
assign(f,'porumb.in');
reset(f);
read(f,n,x);
close(f);
a:=(n+1) div 2;
ult:=1;
nrtot:=1;
while n>1 do
  begin
  n:=n div 2;
  nrtot:=nrtot+1;
  ult:=ult*2
  end;
nrx:=1;
while x mod 2=0 do
  begin
  x:=x div 2;
  nrx:=nrx+1
  end;
assign(g,'porumb.out');
rewrite(g);
writeln(g,a);
writeln(g,nrtot);
writeln(g,nrx);
writeln(g,ult);
close(g)
end.
