uses dos;
const dl:array[1..8] of -1..1=(-1,-1,-1,0,0,1,1,1);
      dc:array[1..8] of -1..1=(-1,0,1,-1,1,-1,0,1);
type pelem=^elem;
     elem=record l,c:byte; next:pelem end;
var lac:array[0..100,0..100] of 0..1;
    cost:array[0..100,0..100] of byte;
    directie:array[0..100,0..100] of 1..8;
    pc,uc,p0,u0:pelem;
    min,nl,nc,i,j:byte;
    h,m,s,hs:word;

procedure push(linie,coloana:byte; var p,u:pelem);
var q:pelem;
begin
   new(q);
   q^.l:=linie; q^.c:=coloana;
   q^.next:=nil;
   if p=nil
      then p:=q
      else u^.next:=q;
   u:=q;
end;

procedure pop(var linie,coloana:byte; var p,u:pelem);
var q:pelem;
begin
   q:=p;
   linie:=q^.l; coloana:=q^.c;
   if p=u then u:=nil;
   p:=p^.next;
   dispose(q);
end;


procedure init;
var i,j,i1,j1:byte;
    f:text;
begin
   assign(f,'lac.in'); reset(f);
   readln(f,nl,nc);
   fillchar(lac,sizeof(lac),0);
   fillchar(directie,sizeof(directie),7); { directia in jos }
{  for i:=0 to nc+1 do cost[0,i]:=9;} { Bordare sa n-o ia in sus }
   for i:=1 to nl do
      begin
         cost[i,0]:=i; cost[i,nc+1]:=i;
         for j:=1 to nc do
            begin
               read(f,lac[i,j]);
               cost[i,j]:=i;
               if lac[i,j]=0
                  then
                     push(i,j,p0,u0); { salveaza in coada toate casutele cu uscat }
            end;
         readln(f);
      end;
   for j:=0 to nc+1 do
      cost[nl+1,j]:=nl+1;
   close(f);
end;

function OK (l0,c0:byte):boolean; { true - nu sunt vecini cu cost mai mic ?}
var l1,c1,i:byte;  
begin
   OK:=true;
   for i:=1 to 8 do
      begin
         l1:=l0+dl[i]; c1:=c0+dc[i];
         if cost[l1,c1]<cost[l0,c0]    { vecinii de sus se incadreaza la    }
            then
               begin                          { recalc costul pct de uscat }
                  cost[l0,c0]:=cost[l1,c1]; directie[l0,c0]:=9-i; { directia de la vecin la punctul curent }
                  OK:=false; {  vecin cu cost mai mic }
               end;
      end;
end;

procedure reconfig;   { pornind de la vecinii pct de uscat, se recalc costurile pt toti pct din matrice care au suferit modificari } 
var l0,c0,l1,c1,nou,i,j:byte;     { se repeta racurgerea pana nu mai sunt modif } 
begin
   while pc<>nil do
      begin
         pop(l0,c0,pc,uc); {prim cost, ultim cost }
         for i:=1 to 8 do
            begin
               l1:=l0+dl[i]; c1:=c0+dc[i]; { recalculeaza costul vecinilor punctelor de uscat }
               nou:=cost[l0,c0]+lac[l1,c1]; {unde e uscat nu costa nimic sa trec lac[i, j] = 0 }
               if nou<cost[l1,c1]
                  then { daca nu sunt pe borduri }
                     if l1*c1*(nl+1-l1)*(nc+1-c1)<>0 { (l1 <> 0) and (c1 <> 0) and (l1 <> n1 + 1 ) and ( c1 <> nc + 1) } 
                        then
                           begin
                              push(l1,c1,pc,uc); { vecinii pt. de uscat care au suferit modificari se pun in aceeasi coada }
                              cost[l1,c1]:=nou; directie[l1,c1]:=i;
                           end;
            end;
      end;
end;

procedure config;
var l0,c0,i1,j1:byte;
begin
   while p0<>nil do { cat timp mai am casute cu uscat in lista }
      begin
         pop(l0,c0,p0,u0); { scoate prima }
         if not OK(l0,c0) { daca sunt vecini cu cost mai mic, se recalculeaza costul pt. l0, c0}  
         	then
               begin
                  push(l0,c0,pc,uc); { pun in alta coada casuta numai pozitiile care au suferit modificari }
                  reconfig;
               end;
      end;
end;

procedure solutie;
var i,l0,c0,i1,j1,x1,y1:byte;
begin
   config;
   min:=cost[nl,1]; { costul minim este pe ultima linie de costuri }
   c0:=1;
   for i:=2 to nc do
      begin
         if cost[nl,i]<min
            then
               begin
                  min:=cost[nl,i]; c0:=i;
               end;
      end;
   l0:=nl;
   repeat
      x1:=l0; y1:=c0; { c0 - col pe care se afla costul minim }
      { intoarcere pe drumul de cost minim si marcarea lui cu 2 }
      lac[l0,c0]:=lac[l0,c0]+2; { daca e apa, lac[i, j] = 3 }
      i:=directie[l0,c0];
      l0:=l0-dl[i];
      c0:=c0-dc[i];
   until l0=0;
end;

procedure afisare;
var i,j:integer;
    g:text;
begin
   assign(g,'lac.out'); rewrite(g);
   writeln(g,min);
   for i:=1 to nl do
      for j:=1 to nc do
         if lac[i,j]=3  { se pune ponton }
            then writeln(g,i,' ',j);
   close(g);
end;

BEGIN
   init;
   solutie;
   afisare;
END.

