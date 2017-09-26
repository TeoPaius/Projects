{$I-}
const fi='pentagon.in'; fo='pentagon.out'; fc='corect.txt'; fr='rez.p1';
var f1,f2,f:text;
    k,c1,c2,p1,p2:word;
function cts(x:longint):string;
var s:string;
begin
     str(x,s); cts:=s;
end;
procedure err(s:string);
begin
     writeln(f,s); close(f); close(f1); close(f2); halt;
end;
begin
     assign(f,fr); append(f);
     if ioresult<>0 then rewrite(f);
     assign(f1,fo); reset(f1);
     if ioresult<>0 then err('0  Fisier de iesire inexistent!');
     assign(f2,fc); reset(f2); k:=0;
     while not seekeof(f2) do begin
           inc(k);
           readln(f2,c1,c2);
           if seekeof(f1) then err('0  Blocuri insuficiente!');
           readln(f1,p1,p2);
           if ioresult<>0 then err('0  Format de date incorect la linia '+ cts(k)+'!');
           if (p1<>c1)or(p2<>c2) then err('0  Bloc ('+cts(p1)+','+cts(p2)+') in loc de ('+cts(c1)+','+cts(c2)+'!');
     end;
     if not seekeof(f1) then err('0  Prea multe blocuri!');
     err('1  CORECT!!! (10p)');
end.