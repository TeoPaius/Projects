program lazi_munte;
const modulo=12343;
type sir=array[0..32000] of integer;
var a:sir;
    n:word;
    max,i,x:integer;
    distincte,nrsol:longint;
    egale:boolean;
    f,g:text;
function doila(n:word):integer;
var p,i:longint;
begin
  p:=1;
  for i:=1 to n do
    p:=(p*2) mod modulo;
  doila:=p;
end;
procedure selectsort(var a:sir;n:integer);
var aux,i,j:integer;
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
begin
  assign(f,'munte.in');
  reset(f);
  readln(f,n);
  for i:=1 to n do
    read(f,a[i]);
  close(f);
  selectsort(a,n);

  if a[n]=a[n-1] then
    begin
      assign(g,'munte.out');
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
              assign(g,'munte.out');
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
      nrsol:=doila(distincte-1)    {daca avem elemente egale, rezultatul
                                    este 2^(nr_elem_distincte-1) }
    else
      nrsol:=(doila(n-1)-2+modulo) mod modulo;
                                  {daca nu avem elemente egale, rezultatul
                                  este (2^(n-1))-2}
  assign(g,'munte.out');
  rewrite(g);
  writeln(g,nrsol);
  close(g);
end.