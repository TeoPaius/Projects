//sursa oficiala - liste implementate cu pointeri
//100 puncte

type pnod = ^nod;
	  nod = record
				val,lg:longint;
				urm:pnod;
			end;

const oo=2000000000;

var paux:pnod;
	k,n,i,v,j,km,st,dr,mi,lmax,sol:longint;
	p:array[0..100010] of pnod;
	bst:array[0..100010] of longint;
	b:array[0..100010] of char;
	fin,fout:text;

begin
    assign(fin,'blis.in');
	reset(fin);
	
	readln(fin,k);

	n:=0;
	while (not eof(fin)) do
		begin
			n:=n+1;
			read(fin,b[n]);
		end;
		
	close(fin);
  
    for i:=1 to n+1 do bst[i]:=oo;
	bst[0]:=-oo;
	lmax:=0;
	sol:=0;
    
	for i:=1 to n do
		begin
			v:=0;
			if i+k-1<n then km:=i+k-1
			else km:=n;
        
			for j:=i to km do
				begin
					v:=v shl 1;
					v:= v or (ord(b[j])-ord('0'));
					if v>sol then sol:=v;
					
					st:=0;
					dr:=lmax+1;
					while dr-st-1<>0 do
						begin
							mi:=(st+dr) shr 1;
							if bst[mi]<v then st:=mi
							else dr:=mi;
						end;
					if v<bst[dr] then
						begin
							new(paux);
							paux^.val:=v;
							paux^.lg:=dr;
							paux^.urm:=p[j];
							p[j]:=paux;
						end;
				end;
        while p[i]<>nil do
			begin
				paux:=p[i];
				p[i]:=p[i]^.urm;
				if bst[paux^.lg]>paux^.val then bst[paux^.lg]:=paux^.val;
				dispose(paux);
			end;
        
		while bst[lmax+1]<oo do lmax:=lmax+1;
    end;
	
	assign(fout,'blis.out');
	rewrite(fout);
	
	writeln(fout,sol);
	write(fout,lmax);
	
	close(fout);

end.
