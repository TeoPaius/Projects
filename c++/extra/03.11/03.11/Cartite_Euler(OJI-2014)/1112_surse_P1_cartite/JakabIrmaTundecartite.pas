program cartite;
const dl:array[0..3]of shortint=(-1,0,1,0);
      dc:array[0..3] of shortint=(0,1,0,-1);
type muchie=record
       i,j,k,h,ind1,ind2:integer;
     end;
     vector=array[0..1001] of integer;
var n,caz,k,h,n1,m1,k1,g1,Lx,Cx,Lmin,Cmin,Dmin:integer;
    a,a1,b1:array[0..300,0..300] of integer;
    v,d:array[0..10000]of integer;
    x1,y1,c,c1:vector;
    mu:array[0..1001] of muchie;
    f,g:text;

procedure ocupa(x,y,t:integer);
var i,j:integer;
begin
  if t=0 then a1[x][y]:=1;
  if t=1 then begin
    for j:=y-1 to y+1 do
        if (j>0) and (j<n1+1) then a1[x][j]:=1;
    for i:=x-1 to x+1 do
        if(i>0) and (i<m1+1) then a1[i][y]:=1;
  end;
  if t=2 then begin
    for j:=y-2 to y+2 do
        if (j>0) and (j<n1+1) then a1[x][j]:=1;
    for i:=x-2 to x+2 do
        if(i>0) and (i<m1+1) then a1[i][y]:=1;
    for j:=y-1 to y+1 do
        if(j>0) and (j<n1+1) and (x-1>0) then a1[x-1][j]:=1;
    for j:=y-1 to y+1 do
        if(j>0) and (j<n1+1) and (x+1<m1+1) then a1[x+1][j]:=1;
  end;
end;

procedure puncte_distincte(p,q:integer; var k1:integer);
var i,sw: integer;
begin
  sw:=0;
  for i:=1 to k1 do
    if (p=x1[i]) and (q=y1[i]) then begin
      sw:=1;
      break;
    end;
  if sw=0 then begin
    k1:=k1+1;x1[k1]:=p;y1[k1]:=q;
  end;
end;

function indice(p,q,k1:integer):integer;
var i: integer;
begin
  indice:=0;
  for i:=1 to k1 do
    if (p=x1[i]) and (q=y1[i]) then indice:=i;
end;

procedure cit;
var i,k,p,q,t:integer;
begin
  read(f,caz,m1,n1);
  read(f,Lx,Cx);
  read(f,k);
  for i:=1 to k do begin
    read(f,p,q,t);
    ocupa(p,q,t);
  end;
  read(f,g1);
  k1:=0;
  for i:=1 to g1 do begin
    read(f,mu[i].i,mu[i].j,mu[i].k,mu[i].h);
    puncte_distincte(mu[i].i,mu[i].j,k1);
    puncte_distincte(mu[i].k,mu[i].h,k1);
  end;
  for i:=1 to g1 do begin
    mu[i].ind1:=indice(mu[i].i,mu[i].j,k1);
    mu[i].ind2:=indice(mu[i].k,mu[i].h,k1);
  end;
end;

procedure Lee(Lxx,Cxx:integer);
var i0,j0,d0,i1,j1,d1,p,u,k,ind1:integer;
    cx,cy,cd:array[0..10000] of integer;
begin
  ind1:=indice(Lxx,Cxx,k1);
  if ind1>0 then begin Lmin:=Lxx;Cmin:=Cxx;Dmin:=0;end
  else begin
    p:=1;u:=1;
    cx[1]:=Lxx; cy[1]:=Cxx;cd[1]:=1;b1[Lxx][Cxx]:=1;
    while p<=u do begin
      i0:=cx[p];j0:=cy[p];d0:=cd[p];
      for k:=0 to 3 do begin
        i1:=i0+dl[k];j1:=j0+dc[k];d1:=d0+1;
        if (i1>0) and (i1<=m1) and (j1>0) and (j1<=n1) and (b1[i1][j1]=0)
           and (a1[i1][j1]=0) then begin
          u:=u+1;cx[u]:=i1; cy[u]:=j1; cd[u]:=d1; b1[i1][j1]:=d1;
          ind1:=indice(i1,j1,k1);
          if ind1>0 then begin
            Lmin:=i1;Cmin:=j1;Dmin:=d1-1; p:=u+1;break;
          end;
        end;
      end;
      p:=p+1;
    end;
  end;
end;

procedure cit1;
var i,x,y:integer;
begin
  n:=k1;
  for i:=1 to g1 do begin
    x:=mu[i].ind1;y:=mu[i].ind2;
    a[x][y]:=1; d[x]:=d[x]+1;
    a[y][x]:=1; d[y]:=d[y]+1;
  end;
end;

procedure afist;
begin
  writeln(g,Lmin,' ',Cmin,' ',Dmin);
end;

procedure depth(k:integer);
var i:integer;
begin
  v[k]:=1;
  for i:=1 to n do
    if (v[i]=0) and (a[k][i]=1) then depth(i);
end;

function verif:integer;
var i: integer;
begin
  verif:=1;
  for i:=1 to n do
    if (d[i] mod 2<>0) or (v[i]=0) then verif:=0;
end;

procedure ciclu(k:integer;var c:vector;var h:integer);
var i,p: integer;
begin
  h:=1; c[h]:=k; p:=k;
  repeat
    for i:=1 to n do
       if(a[p][i]<>0) then break;
    h:=h+1; c[h]:=i; d[i]:=d[i]-1; d[p]:=d[p]-1;
    a[p][i]:=0; a[i][p]:=0;
    p:=i;
  until p=k;
end;

function nod(k:integer):integer;
var i: integer;
begin
  nod:=0;
  for i:=1 to k-1 do
    if d[c[i]]>0 then nod:=i;
end;

procedure concat(i:integer; var k:integer; h:integer);
var j,dx:integer;
    x:vector;
begin
  dx:=i;
  for j:=1 to i do
    x[j]:=c[j];
  for j:=2 to h do begin
    dx:=dx+1;
    x[dx]:=c1[j];
  end;
  for j:=i+1 to k do begin
    dx:=dx+1;
    x[dx]:=c[j];
  end;
  k:=dx;
  for j:=1 to k do
    c[j]:=x[j];
end;

procedure afis;
var i:integer;
begin
  for i:=1 to k do
    write(g,c[i],' ');
end;

procedure afis1;
var i:integer;
begin
  for i:=1 to k do
    writeln(g,x1[c[i]],' ',y1[c[i]]);
end;

procedure eulerian;
var i:integer;
begin
  ciclu(1,c,k);
  i:=nod(k);
  while i>0 do begin
    ciclu(c[i],c1,h);
    concat(i,k,h);
    i:=nod(k);
  end;
  afis1;
end;

begin
	assign(f,'cartite.in');
	assign(g,'cartite.out');
	reset(f);
	rewrite(g);

	cit;
	cit1;
	depth(1);
	Lee(Lx,Cx);
	if caz=1 then afist
	else eulerian;
	close(f);
	close(g);
end.
