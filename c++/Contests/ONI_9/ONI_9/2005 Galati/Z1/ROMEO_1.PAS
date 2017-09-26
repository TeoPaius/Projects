var v,o,x,y,l1,ev,eo:longint;

procedure citire;
var f:text;
begin
   assign(f,'romeo.in');
   reset(f);
   readln(f,v,o); { v=nr strazii verticale si o=nr strazii orizontale de destinatie }
   close(f);
end;

procedure afisare;
var f:text;
begin
   assign(f,'romeo.out');
   rewrite(f);
   writeln(f,eo+ev);
   close(f);
end;

procedure calcul;
begin
   eo:=v;
   if o<=v+1
      then
         ev:=o
      else
         begin
            l1:=o div (v+1);
            x:=(v+1)*(l1+1)-o;
            y:=v+1-x;
            ev:=(l1+1) * (x*l1 + y*(l1+2)) div 2;
            { atentie la ordinea evaluarii lui ev !!! Impartirea sa fie ultima !}
         end;
   {writeln(ev);}
end;

begin
   citire;
   calcul;
   afisare;
end.



