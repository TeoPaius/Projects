program coduri_cu_numere_mari;
type ve=array[1..300]of byte;

var n,i,m,j:longint;
    f:text;
    x,y,z,u,s,ii:ve;
    ds,dx,dy,dz,di:byte;
    er:integer;
    sm,si:string;

procedure  suma(x:ve;dx:byte;y:ve;dy:byte;var z:ve;var dz:byte);
var i,mi,dt,tr:byte;t:ve;
begin
if dx>dy then
 begin
  for i:=1 to dx-dy do
   t[i]:=0;
  dt:=dx-dy;
  for i:=1 to dy do
   begin
    inc(dt);
    t[dt]:=y[i];
   end;
  for i:=1 to dt do
   y[i]:=t[i];
  dy:=dx;
 end
         else
 if dy>dx then
  begin
   for i:=1 to dy-dx do
    t[i]:=0;
   dt:=dy-dx;
   for i:=1 to dx do
    begin
    inc(dt);
    t[dt]:=x[i];
    end;
   for i:=1 to dt do
    x[i]:=t[i];
   dx:=dy;
  end;
dt:=0;
mi:=0;
for i:=dx downto 1 do
 begin
  inc(dt);
  tr:=x[i]+y[i]+mi;
  t[dt]:=tr mod 10;
  mi:=tr div 10;
 end;
if mi>0 then
 begin
  inc(dt);
  t[dt]:=mi;
 end;
for i:=1 to dt do
 z[i]:=t[dt+1-i];
dz:=dt;
end;{suma}
procedure produs(x:ve;dx:byte;y:ve;dy:byte;var z:ve;var dz:byte);
var i,j,k,dt,du:byte;t,u:ve;
begin
dz:=1;z[1]:=0;
for i:=1 to dy do
begin
 t[1]:=0;dt:=1;
 for j:=1 to y[dy-i+1] do
  begin
   suma(x,dx,t,dt,u,du);
   dt:=du;
   for k:=1 to du do t[k]:=u[k];
  end;
 for j:=1 to i-1 do
  begin
   inc(dt);
   t[dt]:=0;
  end;
 suma(z,dz,t,dt,u,du);
 dz:=du;
 for j:=1 to du do z[j]:=u[j];
end;
end;{produs}

begin
 assign(f,'coduri.in');
 reset(f);
 readln(f,n);
 close(f);
 m:=n*(n+1)*(2*n+1) div 6;
 str(m,sm);
 ds:=length(sm);
 for i:=1 to ds do
  val(sm[i],s[i],er);
 produs(s,ds,s,ds,x,dx);
 s:=x;ds:=dx;
 produs(s,ds,s,ds,x,dx);
 s:=x;ds:=dx;

 assign(f,'coduri.out');
 rewrite(f);
 for i:=1 to n do
  begin
   str(i,si);
   di:=length(si);
   for j:=1 to di do
    val(si[j],ii[j],er);
   produs(ii,di,s,ds,x,dx);
   for j:=1 to dx do
    write(f,x[j]);
   writeln(f);
  end;
 close(f);
end.