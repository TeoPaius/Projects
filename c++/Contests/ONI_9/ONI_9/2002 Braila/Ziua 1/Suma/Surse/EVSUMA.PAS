{
Utilizarea evaluatorului:
Pentru evaluarea UNUI test fisierele urmatoare trebuie sa contina:
SUMA.IN             -- inputul testului curent
SUMA.OUT            -- outputul concurentului la testul curent
CORECT.OUT          -- outputul comisiei la testul curent
REZULTAT.TXT        -- aici se va afisa rezultatul evaluarii testuli...
                       mesajul va incepe cu un intreg 1 sau 0 dupa cum testul
                       a fost trecut sau nu... evaluatorul COMISIEI ar trebui
                       sa stearga acest fisier inainte de a evalua un concurent
                       integral prin folosirea acestui evaluator pe toate
                       testele... pentru ca fiecare mesaj/linie din fisier
                       incepe cu 0 sau 1, se poate calcula automat punctajul
                       de catre un alt program!

Am incercat sa dau mesaje de eroare cat mai "informative" pentru a identifica
rapid greseala concurentului in caz de contestatie.
}

{$I-}

const fi='suma.in'; fo='suma.out'; fc='corect.txt'; fr='rezultat.txt';

type vect=array[1..50000]of boolean;

var ss,s,nc,n,d,i,k:longint;
    v1,v2:^vect;
    f,ff:text;

procedure err(s:string);
begin
     writeln(ff,s); close(ff);
     dispose(v1); dispose(v2);
     halt;
end;

function cts(x:longint):string;
var s:string;
begin
     str(x,s); cts:=s;
end;

function setIt(i:longint):boolean;
begin
     if i<=50000 then begin
        if not v1^[i] then begin
           v1^[i]:=true; setIt:=true;
        end else setIt:=false;
     end else begin
         if not v2^[i-50000] then begin
            v2^[i-50000]:=true; setIt:=true;
         end else setIt:=false;
     end;
end;

begin

     new(v1); new(v2);
     fillchar(v1^,sizeof(v1^),false); fillchar(v2^,sizeof(v2^),false);

     assign(f,fi); reset(f);
     read(f,s); close(f);

     assign(f,fc); reset(f);
     read(f,nc); close(f);

     assign(ff,fr); append(ff);
     if ioresult<>0 then rewrite(ff);

     assign(f,fo); reset(f);
     if ioresult<>0 then err('0 -- Fisierul de iesire nu poate fi deschis!');
     readln(f,n);
     if ioresult<>0 then err('0 -- Format de iesire incorect la linia 1 !');
     if n<>nc then err('0 -- Solutie gresita! comisie: N='+cts(nc)+'    concurent: N='+cts(n));
     ss:=s; s:=(n*(n+1))div 2; k:=1;
     while not seekeof(f) do begin
           readln(f,i); inc(k);
           if ioresult<>0 then err('0 -- Format de iesire incorect la linia '+cts(k)+' !');
           if (i<1)or(i>n) then err('0 -- Termen scazut in afara [1..N] la linia '+cts(k)+' !');
           if not setIt(i) then err('0 -- Termen scazut a doua oara la linia '+cts(k)+' !');
           dec(s,2*i);
           if s<ss then err('0 -- Se scad prea multi termeni incepand cu linia '+cts(k)+' !');
     end;
     if s>ss then err('0 -- Nu se scad suficienti termeni a mai ramas '+cts(s)+' din suma!');
     close(f);

     err('10 -- Solutie CORECTA!');

end.