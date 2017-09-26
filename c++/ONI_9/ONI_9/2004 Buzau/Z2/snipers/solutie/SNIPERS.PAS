program snipers;
const nmax=1000;
type coord=record
            x,y,k:longint;{coord. si pe cine kill-ere}
           end;
var t,c:array[1..nmax] of coord;{tragatori si capetenii}
      n:integer;
procedure citire;
var f:text;i:integer;
begin
  fillchar(t,sizeof(t),0);
  fillchar(c,sizeof(c),0);
  assign(f,'snipers.in');reset(f);
  readln(f,n);
  for i:=1 to n do
    with t[i] do  readln(f,x,y);
  for i:=1 to n do
    with c[i] do  readln(f,x,y);
  close(f);
end;
procedure scrie;
var f:text;i:integer;
begin
  assign(f,'snipers.out');rewrite(f);
  for i:=1 to n do
    writeln(f,t[i].k);
  close(f);
end;
{ne spune de ce parte a dreptei ce trece prin a, b se afla punctul p}
function s(p,a,b:coord):real;
begin
  s:=1.0*p.y*(b.x-a.x)-1.0*p.x*(b.y-a.y)+1.0*a.x*b.y-1.0*b.x*a.y;
end;
{testeaza daca segmentul[a1,b1] se inersecteaza cu [a2,b2]}
function inter(a1,b1,a2,b2:coord):boolean;
begin
 inter:=(s(a2,a1,b1)*s(b2,a1,b1)<0)and
 (s(a1,a2,b2)*s(b1,a2,b2)<0);
 {a2 si b2 se afla de o parte si de alta a lui [a1,b1]
  si
  a1 si b1 se afla de o parte si de alta a lui [a2,b2] }
end;

procedure rezolva;
 var i,j,aux:word; e_int,ok:boolean;
begin
  for i:=1 to n do t[i].k:=i;{tragatorul i trage in capetenia i, pentru inceput}
  if n>1 then
  repeat
    ok:=true;{am gasit o combinatie valida tragator-capetenie}
    i:=1;
    repeat
      j:=i;
      repeat
        j:=j+1;
        {verifica daca traiectoria de la sniper i la tinta sa nu se intersecteaza
        cu traiectoria de la sniper j la tinta sa }
        e_int:=inter(t[i],c[t[i].k],t[j],c[t[j].k]);
        {daca da le interschimbam tintele, si notam ca nu avem o combinatie buna}
        if e_int then
          begin aux:=t[i].k;t[i].k:=t[j].k;t[j].k:=aux;ok:=false; end;
      until (j=n)or e_int;
      if not e_int then inc(i);{daca nu jeneaza pe numeni trecem al urmatorul sniper}
    until i=n;{pana terminam lista de tragatori}
  until ok;
end;
BEGIN
citire;
rezolva;
scrie;
END.
