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
var p,i:longint;
begin
  p:=1;
  for i:=1 to n do
    p:=(p*2) mod modulo;
  doila:=p;
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
      halt;
    end
  else
    begin
      distincte:=2;   {primul si ultimul element numaram din oficiu}
      egale:=false;
      for i:=2 to n-1 do
        if a[i]<>a[i-1] then    {numaram toate elementele distincte}
          inc(distincte)
        else
          if a[i]=a[i+1] then {daca gasim trei elemente egale, nu avem sol.}
            begin
              assign(g,fout);
              rewrite(g);
              writeln(g,0);
              close(g);
              halt;
            end
          else               {daca gasim doua elem. egale, inseamna ca}
            begin              {am numarat pe degeaba prima aparitie}
              dec(distincte); {fiindca nu va intra in calculul rezultatului}
              egale:=true;
            end;
    end;
    if egale then
      nrsol:=doila(distincte-1) mod modulo
                                {daca avem elemente egale, rezultatul
                                    este 2^(nr_elem_distincte-1) }
    else
      nrsol:=(doila(n-1)-2+modulo) mod modulo;
                                  {daca nu avem elemente egale, rezultatul
                                  este (2^(n-1))-2}
  assign(g,fout);
  rewrite(g);
  writeln(g,nrsol);
  close(g);
end.