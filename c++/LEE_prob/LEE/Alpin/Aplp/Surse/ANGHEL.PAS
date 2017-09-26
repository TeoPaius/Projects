
{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}

{Anghelache Florin - problema 20 sursa oficiala}

{  La primul punct am numarat de cate ori se repeta o forma de relief tinand
cont ca intr-o regiune formele de relief sunt (de)scrise in ordine crescatoare
a altitudinilor lor- treaba asta am implementat-o in vreo 5-10 min;
  La cel de-al doilea punct am avut mai mult de lucru.Pana la urma am gasit o
dinamica care intra in timp pe majoritatea testelor, mai putin cele peste 50,45 (m,n)
Cam atat.
Pana la urmatoarea problema,
                                Numai bine.}

program alpinistul;
var f:text;
    a:array[0..32000] of byte;
    h:array[1..52,1..52] of integer;
    h1:array[1..52,1..52] of byte;
    t:array[1..52,1..52] of record
                       x,y:integer;
                       end;
    x,y,max,i,j,n,m,k,p,q:integer;

procedure cit;
var rr,k1,max3:integer;
begin
assign(f,'harta.in');reset(f);
readln(f,n,m);max3:=0;
for i:=1 to n do begin
                 k:=0;
                 for j:=1 to m do begin
                                  read(f,h[i,j]);
                                  if k<>h[i,j] then inc(a[h[i,j]]);
                                  k:=h[i,j];

                                  if max3<a[h[i,j]] then begin
                                                         max3:=a[h[i,j]];
                                                         k1:=h[i,j];
                                                         end;
                                  end;
                 readln(f);
                 end;
close(f);
assign(f,'harta1.out');rewrite(f);
writeln(f,k1);
for i:=1 to n do
                 for j:=1 to m do if h[i,j]=k1 then begin
                                                   write(f,i,' ');
                                                   j:=m;
                                                   if k1=rr then begin i:=n; j:=m; end;
                                                   end;
close(f);
end;

procedure tipar(x,y:integer);
begin
if h1[x,y]=0 then writeln(f,x,' ',y)
             else begin
                  tipar(t[x,y].x,t[x,y].y);
                  writeln(f,x,' ',y);
                  end;

end;

begin
cit;
assign(f,'harta2.out');rewrite(f);
fillchar(h1,sizeof(h1),0);
fillchar(t,sizeof(t),0);max:=0;x:=0;y:=0;
for i:=1 to n do
     for j:=1 to m do begin
                      for p:=1 to i-1 do
                          for q:=1 to m do
     if (h[i,j]>h[p,q])and(h1[i,j]<h1[p,q]+1) then begin
                                                 h1[i,j]:=h1[p,q]+1;
                                                 t[i,j].x:=p;t[i,j].y:=q;
                                                 if max<h1[i,j] then begin
                                                                     max:=h1[i,j];
                                                                     x:=i;
                                                                     y:=j;
                                                                     end;
                                                 end;
                      end;
tipar(x,y);
close(f);
end.


------------------------------
K Free E-mail http://www.k.ro/
by KappaNet http://www.kappa.ro/


