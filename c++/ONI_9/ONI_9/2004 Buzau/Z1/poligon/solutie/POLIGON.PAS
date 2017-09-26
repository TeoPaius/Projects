type    mat=array[0..100,0..100] of byte;
        sir=array[0..50] of integer;
        dir=array[1..8] of byte;
        vecini=array[1..8] of byte;
const d:dir=(128,64,32,16,8,4,2,1);
      x1:vecini=(1,2,3,4,1,0,0,0);
      x2:vecini=(1,2,4,3,1,0,0,0);
      x3:vecini=(1,3,2,4,1,0,0,0);
var n,m,k,l,npol,nr:integer;
    x,e:sir;
    a:mat;
    f:text;
    time:longint absolute $000:$046C;
    timeinit:longint;

Procedure citire(var a:mat;var m,n,l:integer);
var i,j,k,v:byte;
    f:text;
begin
     assign(f,'poligon.in');
     reset(f);
     readln(f,m,n,l);
     for k:=1 to l do
             begin
             readln(f,i,j,v);
             a[i,j]:=v;
             e[k]:=(i-1)*m+j;
             end;
     close(f);
end;

Function traseu(vi,vf,i1,c1,i2:byte;c2:integer;c:byte):boolean;
var aux,i:byte;
begin
if vi>vf then begin aux:=vi;vi:=vf;vf:=aux end;
traseu:=true;
  for i:=vi to vf-1 do
    if a[i1+c1*i,i2+c2*i] and d[c] <> d[c] then
                          traseu:=false
end;

Function verif(var x:sir; p:integer):boolean;
var i,j,l1,c1,l2,c2,t,nc,nl,ndp,nds:byte;
begin
if p=1 then verif:=true
   else
begin

verif:=true;
nc:=0;nl:=0;ndp:=0;nds:=0;
l1:=(e[x[p]]-1) div n +1;
c1:=(e[x[p]]-1) mod n +1;
for i:=1 to p-1 do
    begin
    l2:=(e[x[i]]-1) div n +1;
    c2:=(e[x[i]]-1) mod n +1;
    if (c1=c2) then inc(nc);
    if (l1=l2) then inc(nl);
    if l1-l2=c1-c2 then inc(ndp);
    if l1-l2=c2-c1 then inc(nds);
    end;
if (nc>1) or (nl>1) or (ndp>1) or (nds>1) then verif:=false;
end;
end;
Function este(y:vecini):boolean;
var i,l1,c1,l2,c2,min,max:byte;
    cod:boolean;
begin
este:=true;
for i:=1 to k do
    begin
    cod:=false;
    l1:=(e[x[y[i+1]]]-1) div n +1;
    c1:=(e[x[y[i+1]]]-1) mod n +1;
    l2:=(e[x[y[i]]]-1) div n +1;
    c2:=(e[x[y[i]]]-1) mod n +1;
    min:=trunc(((l1+l2)-abs(l1-l2))/2);
    if (c1=c2) and traseu(l1,l2,0,1,c1,0,5) then cod:=true;
    if (l1=l2) and traseu(c1,c2,l1,0,0,1,3) then cod:=true;
    if (l1-l2=c1-c2) and traseu(0,abs(c1-c2),min,1,trunc(((c1+c2)-abs(c1-c2))/2),1,4) then cod:=true;
    if (l1-l2=c2-c1)  and traseu(0,abs(c1-c2),min,1,trunc(((c1+c2)+abs(c1-c2))/2),-1,6) then cod:=true;
    if not cod then este:=false;
    end;
end;

Procedure Poligon(x:sir;n:integer);
var i:byte;
begin
if este(x1) or este(x2) or este(x3) then
   begin
   inc(nr);
   {for i:=1 to n do
    write(f,e[x[i]],',');
   writeln(f);}
   end;
end;
procedure comb (p:integer);
var i:integer;
begin
     for i:=x[p-1]+1 to l do
       begin
        x[p]:=i;
        if verif(x,p) then
           if p=k then
              Poligon(x,k)
                 else
              comb(p+1);
       end;
end;

begin
{writeln('Incepem');
timeinit:=time;
writeln(time);}
nr:=0;
assign(f,'poligon.out');
rewrite(f);
k:=4;
citire(a,m,n,l);
comb(1);
writeln(f,nr);
close(f);
{writeln(time,'/',(timeinit-time)/18:4:2); }
end.
