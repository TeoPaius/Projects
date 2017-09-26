{$I-}
const fi='becuri.in'; fo='becuri.out'; fc='corect.txt'; fr='becuri.rez';
var n,m,i,j,k,min:integer;
    sw:boolean;
    a:array[1..100,1..100]of byte;
    f1,f2:text;
function cts(x:longint):string;
var s:string;
begin
     str(x,s); cts:=s;
end;
procedure err(s:string);
begin
     writeln(f2,s); close(f1); close(f2); halt;
end;
procedure doIt;
begin
     assign(f1,fo); reset(f1);
     assign(f2,fr); append(f2);
     if ioresult<>0 then rewrite(f2);
     if ioresult<>0 then err('0 -- Fisier de iesire inexistent!');
     read(f1,i);
     if ioresult<>0 then err('0 -- Format de iesire incorect!');
     if i<>-1 then err('0 -- Solutie incorecta!');
     err('10 -- CORECT! (10 puncte)');
end;
begin
     assign(f1,fi); reset(f1);
     readln(f1,n,m);
     for i:=1 to n do begin
         for j:=1 to m do read(f1,a[i,j]); readln(f1);
     end; close(f1);
     assign(f1,fc); reset(f1); min:=0;
     sw:=true;
     while not seekeof(f1) do begin
           read(f1,i);
           if sw then begin
              if i=-1 then doIt;
              sw:=false;
           end;
           if i<>0 then inc(min);
     end; close(f1);

     assign(f1,fo); reset(f1);
     if ioresult<>0 then err('0 -- Fisier de iesire inexistent!');

     assign(f2,fr); append(f2);
     if ioresult<>0 then rewrite(f2);

     k:=0;
     while (not seekeof(f1))and(k<min+10) do begin
           read(f1,i);
           if ioresult<>0 then err('0 -- Format de iesire incorect!');
           if i<>0 then inc(k);
     end;
     if not seekeof(f1) then err('0 -- Numar prea mare de comutari!');
     if k<min then err('0 -- Numar prea mic de comutari!');
     reset(f1);
     while not seekeoln(f1) do begin
           read(f1,i);
           if (i<0)or(i>m) then err('0 -- Indice de coloana in afara [1..N] !');
           if i>0 then
           for j:=1 to n do if a[j,i]=0 then a[j,i]:=1
           else a[j,i]:=0;
     end; readln(f1);
     while not seekeoln(f1) do begin
           read(f1,i);
           if (i<0)or(i>n) then err('0 -- Indice de linie in afara [1..M] !');
           if i>0 then
           for j:=1 to m do if a[i,j]=0 then a[i,j]:=1
           else a[i,j]:=0;
     end;
     for i:=1 to n do
         for j:=1 to m do if a[i,j]<>0 then err('0 -- Solutie incorecta!');
     err('10 -- CORECT! (10 puncte)');
end.
