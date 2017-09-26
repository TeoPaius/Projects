{
   autor: Alin Burtza
}
program cifru;
var  N:longint;
     Apar:array[0..9] of longint;
     MAX, NrMin, Cif, Cate:longint;
     i,j, Nr, x:longint;
     fin, fou:text;

begin
        assign(fin,'cifru.in');
        assign(fou,'cifru.out');
        reset(fin);rewrite(fou);
	//initializari
	for i:=0 to 9 do Apar[i] := 0;

	//citesc datele de intrare si
	//determin cifrele care apar initial si cifra maxima
	readln(fin,N); MAX := 0;
	for i:=1 to N do begin
          readln(fin,x);
	  inc(Apar[x]);
	  if MAX < x then MAX := x;
	end;
	//calculez numarul de mutari pentru fiecare cifra care apare
	NrMin := 10 * N + 1;
	for i:=0 to 9 do begin
          Nr := 0;
          for j:=0 to 9 do
	    if (Apar[j]>0) and (j<>i) then
	       if  abs(j-i) <= 10 - abs(j-i) then Nr := Nr+ Apar[j]*abs(j-i)
               else Nr := Nr + Apar[j]*(10 - abs(j-i));
	  if Nr<NrMin then begin NrMin := Nr; Cif := i; Cate := 1; end
			else if Nr=NrMin then inc(Cate);
	end;
 	writeln(fou,MAX);
        writeln(fou,NrMin);
        writeln(fou,Cif);
        writeln(fou,Cate);
	close(fin);
	close(fou);
 end.

