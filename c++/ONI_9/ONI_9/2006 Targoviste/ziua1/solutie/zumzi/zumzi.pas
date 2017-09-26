program probl;
const di:array[1..6] of -1..1=(1,1,0,-1,-1,0);
      dj:array[1..6] of -1..1=(0,-1,-1,0,1,1);

CONST MAXCELULE = 304;
      MAX = 21;
      fin='zumzi.in';
      fout='zumzi.out';

type fractie=record x,y:integer;
             end;
     nrmare= string[100];


var t:array[0..MAX,0..MAX] of integer;
    a:array[0..MAXCELULE] of integer;
    p1,p2:array[0..MAXCELULE] of nrmare;
    f:text;
    s1,s,t1,nrp,i,j,m,n,i1,j1,y,k:integer;
    poz : array[0..MAXCELULE] of fractie;

function zero(x:nrmare):boolean;
begin
  if (x='0') or (length(x)=0) then zero:=true
  else
    zero:=false;
end;

procedure adun(x,y:nrmare;var z:nrmare);
var c,t,i,zero:integer;
begin
  zero:=ord('0');
  while length(x)>length(y) do
    y:=y+'0';
  while length(y)>length(x) do
    x:=x+'0';
  z:='';
  for i:=1 to length(x) do
    z:=z+'0';
  t:=0;
  for i:=1 to length(x) do
    begin
      c:=ord(x[i])+ord(y[i])-2*zero+t;
      t:=c div 10;
      c:=c mod 10;
      z[i]:=chr(c+zero);
    end;
  if t>0 then
    z:=z+chr(t+zero);
end;

procedure compl;
var c,i,j,s:integer;
begin
  i:=k+1; j:=k+1; s:=1;
  t[i,j]:=s; poz[s].x:=i; poz[s].y:=j;
  s:=s+1;
  for c:=1 to k do
    begin
      i:=i+1;
      while i<=k+c+1 do
        begin
          t[i,j]:=s;
          poz[s].x:=i; poz[s].y:=j;
          s:=s+1;
          if s>n then exit;
          i:=i+1; j:=j-1;
        end;
      i:=i-1;
      while j>=k-c+1 do
        begin
          t[i,j]:=s;
          poz[s].x:=i; poz[s].y:=j;
          s:=s+1;
          if s>n then exit;
          j:=j-1;
        end;
      j:=j+1; i:=i-1;
      while i>=k+1 do
        begin
          t[i,j]:=s;
          poz[s].x:=i; poz[s].y:=j;
          s:=s+1;
          if s>n then exit;
          i:=i-1;
        end;
      j:=j+1;
      while i>=k-c+1 do
        begin
          t[i,j]:=s;
          poz[s].x:=i; poz[s].y:=j;
          s:=s+1;
          if s>n then exit;
          i:=i-1; j:=j+1;
        end;
      i:=i+1;
      while j<=k+c+1 do
        begin
          t[i,j]:=s;
          poz[s].x:=i; poz[s].y:=j;
          s:=s+1;
          if s>n then exit;
          j:=j+1;
        end;
      j:=j-1; i:=i+1;
      while i<=k+1 do
        begin
          t[i,j]:=s;
          poz[s].x:=i; poz[s].y:=j;
          s:=s+1;
          if s>n then exit;
          i:=i+1;
        end;
      i:=i-1;
    end;
end;

procedure scrie(x:nrmare);
var i:integer;
begin
  if length(x)=0 then
    writeln(f,0)
  else
    begin
     for i:=length(x) downto 1 do
       write(f,x[i]);
     writeln(f);
    end;
end;

begin
  assign(f,fin); reset(f);
  readln(f,n,m,nrp,y);  {n = numarul de celule, m = numarul de celule ocupate
                         nrp = numarul de pasi efectuati de ZUMZI
                         y = pozitia prietenului lui ZUMZI}
  k:=1; s:=1; s1:=s+k*6;
  while s1<n do
    begin
      s:=s1; k:=k+1;
      s1:=s+k*6;
    end;
  a[0]:=1;
  {a[i]=1 casuta i este ocupata
        0 casuta i este libera}
  for i:=1 to m do begin read(f,j); a[j]:=1; end;
  close(f);
  fillchar(p1,sizeof(p1),0);
  fillchar(p2,sizeof(p2),0);

  compl;

  p1[1]:='1';
  for i:=1 to nrp do
    begin
      fillchar(p2,sizeof(p2),0);
      for j:=1 to n do
        if not zero(p1[j]) then
          begin
            i1:=poz[j].x; j1:=poz[j].y;
            for m:=1 to 6 do
              begin
                t1:=t[i1+di[m],j1+dj[m]];
                if a[t1]=0 then  {poate sari in celula t1}
                    adun(p1[j],p2[t1],p2[t1])
              end;
          end;
      p1:=p2;
      fillchar(p1[y],sizeof(p1[y]),0);
    end;
  assign(f,fout); rewrite(f);
  scrie(p2[y]);
  close(f);
end.
