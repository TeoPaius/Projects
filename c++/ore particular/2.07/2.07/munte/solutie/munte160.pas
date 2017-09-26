program lazi_munte;
const modulo=12343;
      fin='munte.in';
      fout='munte.out';
type sir=array[0..32000] of word;
var a:sir;
    n:word;
    max,i,x:word;
    distincte,nrsol:longint;
    egale:boolean;
    f,g:text;
function doila(n:word):word;
var p,p2:longint;
begin
  p:=2;p2:=1;
  while n>0 do
    begin
      if odd(n) then p2:=(p2*p) mod modulo;
      p:=(p*p) mod modulo;
      n:=n div 2;
    end;
  doila:=p2;
end;
procedure scufundare(var a:sir;n,i:word);
var pozmax,aux:word;
begin
  pozmax:=i;
  if 2*i<=n then
    if a[2*i]>a[pozmax] then
      pozmax:=2*i;
  if 2*i+1<=n then
    if a[2*i+1]>a[pozmax] then
      pozmax:=2*i+1;
  if pozmax<>i then
    begin
      aux:=a[pozmax];
      a[pozmax]:=a[i];
      a[i]:=aux;
      scufundare(a,n,pozmax);
    end;
end;
procedure heapsort(var a:sir;n:word);
var aux,i:word;

begin
  for i:=n div 2 downto 1 do
    scufundare(a,n,i);
  for i:=n downto 2 do
    begin
      aux:=a[1];
      a[1]:=a[i];
      a[i]:=aux;
      scufundare(a,i-1,1);
    end;
end;
begin
  assign(f,fin);
  reset(f);
  readln(f,n);
  for i:=1 to n do
    read(f,a[i]);
  close(f);
  heapsort(a,n);

  if a[n]=a[n-1] then
    begin
      assign(g,fout);
      rewrite(g);
      writeln(g,0);
      close(g);
      HALT;
    end
  else
    begin
      distincte:=2;egale:=false;
      for i:=2 to n-1 do
        if a[i]<>a[i-1] then
          inc(distincte)
        else
          if a[i]=a[i+1] then
            begin
              assign(g,fout);
              rewrite(g);
              writeln(g,0);
              close(g);
              halt;
            end
          else
            begin
              dec(distincte);
              egale:=true;
            end;
    end;
    if egale then
      nrsol:=doila(distincte-1) mod modulo
    else
      nrsol:=(doila(distincte-1)-2+modulo) mod modulo;
  assign(g,fout);
  rewrite(g);
  writeln(g,nrsol);
  close(g);
end.