{$I-}
const fi='discuri.in'; fo='discuri.out'; fc='corect.txt'; fr='discuri.rez';
var n,nr,nrc,i,j,k:integer;
    vc,vcc:array[1..1000]of boolean;
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
begin
     assign(f1,fi); reset(f1);
     readln(f1,n);
     close(f1);
     assign(f1,fc); reset(f1);
     readln(f1,nr); fillchar(vc,sizeof(vc),true);
     for i:=1 to nr do begin
         readln(f1,j); vc[j]:=false;
     end; close(f1);
     assign(f2,fr); append(f2);
     if ioresult<>0 then rewrite(f2);
     assign(f1,fo); reset(f1);
     if ioresult<>0 then err('0 -- Fisier de iesire inexistent!');
     readln(f1,nrc);
     if ioresult<>0 then err('0 -- Format de iesire incorect la linia 1!');
     if nrc<>nr then err('0 -- Numar de discuri incorect! concurent: '+cts(nrc)+'; comisie: '+cts(nr));
     fillchar(vcc,sizeof(vcc),true);
     for i:=1 to nr do begin
         readln(f1,j);
         if ioresult<>0 then err('0 -- Format de iesire incorect la linia '+cts(i+1)+'!');
         if (j<1)or(j>n) then err('0 -- Disc in afara [1..N] la linia '+cts(i+1)+'!');
         if not vcc[j] then err('0 -- Discul nr. '+cts(j)+' este eliminat a doua oara la linia '+cts(i+1)+'!');
         vcc[j]:=false;
     end;
     for i:=1 to n do if vc[i]<>vcc[i] then err('0 -- Discurile sunt eliminate incorect!');
     err('10 -- CORECT! (10 puncte)');
end.
