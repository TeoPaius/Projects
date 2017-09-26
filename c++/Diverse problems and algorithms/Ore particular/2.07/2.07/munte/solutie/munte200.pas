program lazi_munte;
const modulo=12343;
      fin='munte.in';
      fout='munte.out';
type sir=array[0..64000] of byte;
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
begin
  assign(f,fin);
  reset(f);
  readln(f,n);
  max:=0;
  distincte:=0;
  egale:=false;
  for i:=1 to n do
    begin
      read(f,x);
      if x>max then max:=x;
      inc(a[x]);
      if a[x]=1 then
        inc(distincte)
      else
        if a[x]=2 then
          begin
            egale:=true;
            dec(distincte);
          end
        else
          begin
            assign(g,fout);
            rewrite(g);
            writeln(g,0);
            close(g);
            close(f);
            halt;
          end
    end;
  close(f);
  if a[max]=2 then
    begin
      assign(g,fout);
      rewrite(g);
      writeln(g,0);
      close(g);
      halt;
    end
  else
    if egale then
      nrsol:=doila(distincte-1)
    else
      nrsol:=(doila(distincte-1)-2+modulo) mod modulo;
  assign(g,fout);
  rewrite(g);
  writeln(g,nrsol);
  close(g);
end.