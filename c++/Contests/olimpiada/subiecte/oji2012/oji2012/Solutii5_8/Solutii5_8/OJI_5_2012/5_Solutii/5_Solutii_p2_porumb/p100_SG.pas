{prof. Septimiu Groza}
var f,g:text;n,x,p,numar, trecere:longint;
begin
        assign(f,'porumb.in');reset(f);
        assign(g,'porumb.out');rewrite(g);
        read(f,n,x);
	writeln(g,(n+1)div 2);
        p:=1;numar:=0;
        while p*2<=n do begin
                p:=p*2;
                inc(numar);
        end;
        writeln(g,numar+1);
        trecere:=0;
        while x mod 2=0 do begin
                inc(trecere);
                x:=x div 2
        end;
        writeln(g,trecere+1);
        writeln(g,p);
        close(g);
end.
