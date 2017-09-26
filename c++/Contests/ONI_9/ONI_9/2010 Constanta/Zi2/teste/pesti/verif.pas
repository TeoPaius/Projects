var fin,fout,fok : text;
    i,j,k : integer;
    pct,v1ok,v2ok,v3ok, v1,v2,v3 : longint;
    buf : string;
    p : integer;

procedure stop(pct:integer; msg:string);
begin
  write(pct,' ',msg);
  halt
end;


begin
  {$i-}

  assign(fout,'pesti.out');  reset(fout);
  if ioresult<> 0 then
    stop(0,'fisier de iesire lipsa');

  assign(fok,'pesti.ok'); reset(fok);
  if ioresult <> 0 then
    stop(-2,'fisier ok lipsa');
    
  readln(fok,v1ok,v2ok,v3ok);
     if ioresult<>0 then
         stop(-3,'eroare de citire din ok  ');

  read(fout,v1);
      if ioresult<>0 then
          stop(0,'eroare de citire la primul numar');
      //writeln(buf);

    if v1 <> v1ok then
      stop(0,'prima valoare eronata');
       
     if seekeof(fout) then
        stop(2,'prima valoare corecta, urmatoarele lipsesc');
     
     read(fout,v2);
     if ioresult<>0 then
       stop(0,'eroare de format'); 

     if v2<>v2ok then
       stop(2,'prima valore ok, a doua eronata');
       
     if seekeof(fout) then
      stop(6,'primele doua valori corecte, a treia lipseste' );
   
     read(fout,v3);
     
     if ioresult <> 0 then
        stop(0,'eroare de format');
	
     if not seekeof(fout) then
        stop(0,'eroare de format');

     if v3 = v3ok then
        stop(10,'ok')
     else
        stop(6,'primele doua valori corecte, a treia eronata'); 

end.
