{prof. Sorin Bardac}
program help_alice;
var
  f,g:text;
  n,k,i,nr_usi,c,cmin,cmax:integer;
  usa,par,aux,usa9,z:longint;
  magic:boolean;

begin
par:=-1;
nr_usi:=0;
assign(f,'alice.in');
reset(f);
readln(f,n,k);
for i:=1 to n do
  begin
  read(f,usa);
  if (usa mod 2=0)and(usa>par) then
    par:=usa;
  magic:=true;
  while magic and(usa>9)do
    begin
    aux:=usa;
    cmin:=10;
    cmax:=-1;
    repeat
      c:=aux mod 10;
      aux:=aux div 10;
      if c>cmax then
        cmax:=c;
      if c<cmin then
        cmin:=c
    until aux=0;
    if (c<>cmin)and(c<>cmax)then
      magic:=false
    else
      begin
      usa9:=0;
      aux:=usa;
      z:=1;
      repeat
        c:=aux mod 10;
        aux:=aux div 10;
        usa9:=usa9+z*(cmax-c);
        z:=z*10
      until aux=0;
      usa:=usa9
      end
    end;
  if usa=k then
    nr_usi:=nr_usi+1
  end;
close(f);
assign(g,'alice.out');
rewrite(g);
writeln(g,par);
writeln(g,nr_usi);
close(g)
end.
