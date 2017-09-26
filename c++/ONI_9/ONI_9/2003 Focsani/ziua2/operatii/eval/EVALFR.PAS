{$A+,B-,D+,E+,F-,G-,I-,L+,N-,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 65384,0,655360}

program evaluareFractii;

var f,g:text;
    intrare,corect,iesire,nrtest,rezultat:string;
    ncorect,nconcurent:longint;

begin
 if paramcount<>5 then
  begin
   writeln('nu au fost pasati 5 parametri...');
   exit;
  end;
 intrare:=paramstr(1);
 corect:=paramstr(2);
 iesire:=paramstr(3);
 nrtest:=paramstr(4);
 rezultat:=paramstr(5);
 assign(g,rezultat);
 rewrite(g);
 if ioresult<>0 then
  begin
   writeln('Nu pot crea fisierul ',rezultat, '! Sfarsit anormal de excutie');
   halt;                   0
  end;
 assign(f,corect);
 reset(f);
 if ioresult<>0 then
  begin
   writeln('Nu pot citi fiserul ',corect,' ce contine rezultatul corect ! Sfarsit anormal de excutie');
   close(g);
   halt;
  end;
 readln(f,ncorect);
 if ioresult<>0 then
  begin
   writeln('Nu pot citi din fiserul ',corect,' ce contine rezultatul corect ! Sfarsit anormal de excutie');
   close(g);
   halt;
  end;
 close(f);
 assign(f,iesire);
 reset(f);
 if ioresult<>0 then
  begin
   writeln(g,'PCT=0 Fisierul de iesire nu exista');
   close(g);
   halt;
  end;
 readln(f,nconcurent);
 if ioresult<>0 then
  begin
   writeln(g,'PCT=0 Fisierul nu contine un numar valid');
   close(g);
   halt;
  end;
 close(f);
 if nconcurent=ncorect then
  begin
   writeln(g,'PCT=5 Raspuns corect');
   close(g);
   halt;
  end
 else
  begin
   writeln(g,'PCT=0 Raspuns incorect');
   close(g);
   halt;
  end;
end.