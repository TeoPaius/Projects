program lazi_munte;
const modulo=12343;
      fin='munte.in';
      fout='munte.out';
type sir=array[0..16001] of word;
var st,a:sir;
    n:word;
    k,i:word;
    distincte,nrsol:longint;
    urc,cobor,ev,as:boolean;
    f,g:text;

procedure selectsort(var a:sir;n:word);
var aux,i,j:word;
begin
  for i:=1 to n-1 do
   for j:=i+1 to n do
    if a[i]>a[j] then
    begin
      aux:=a[i];
      a[i]:=a[j];
      a[j]:=aux;
    end;
end;
procedure init;
begin
  if k=1 then
    st[k]:=0
  else st[k]:=st[k-1];
end;
procedure succesor;
begin
  if st[k]<n then
    begin
      as:=true;
      inc(st[k]);
      if a[st[k]]=a[st[k]+1] then
        begin
          inc(k);
          st[k]:=st[k-1]+1;
          succesor;
        end;
    end
  else
    as:=false;
end;
function solutie:boolean;
begin
  solutie:=st[k]=n;
end;
begin
  assign(f,fin);
  reset(f);
  readln(f,n);
  for i:=1 to n do
    read(f,a[i]);
  close(f);
  selectsort(a,n);
  if a[n]=a[n-1] then    {daca a vem maxim multiplu nu putem forma sirmunte}
    begin
      assign(g,fout);
      rewrite(g);
      writeln(g,0);
      close(g);
      halt;
    end;
  for i:=2 to n-2 do  {daca avem trei elemente egale nu putem avea sir munte}
    if (a[i-1]=a[i]) and (a[i]=a[i+1]) then
      begin
        assign(g,fout);
        rewrite(g);
        writeln(g,0);
        close(g);
        halt;
      end;
{  a[n+1]:=a[n]+1;   {un element de rezerva ca sa fim siguri ca varful difera
                     de elementul urmator== necesar la validare}
  k:=1;
  init;
  nrsol:=0;
  while k>0 do
    begin
      succesor;
      if as then
        if solutie then
          begin
            if (k<>n) and (k<>1) then
              begin
                inc(nrsol);
                if nrsol=modulo then
                  nrsol:=0;
              end;
          end
        else
          begin
            inc(k);
            init;
          end
      else
          repeat
            st[k]:=0;
            dec(k);
          until (k=0) or (a[st[k]]<>a[st[k]+1]);
    end;
  assign(g,fout);
  rewrite(g);
  writeln(g,nrsol);
  close(g);
end.