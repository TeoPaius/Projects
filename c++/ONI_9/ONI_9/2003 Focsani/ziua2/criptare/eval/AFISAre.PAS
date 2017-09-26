Program Afiseaza_Rezultate;
Var FPunct,fc       : Text;
    Suma, Puncte : Byte;
    Elev         : String;
    NrTest       : Integer;
Begin
    Elev := Paramstr(1);
    Assign(FPunct, 'criptare.pct'); Reset(FPunct);
    assign(fc,'central.dat'); append(fc);
    Suma := 0; NrTest := -1;
    WriteLn('PROGRAM: ', Elev);
    write(fc,Elev,#9);
    While Not SeekEOF(FPunct) Do
        Begin
            ReadLn(FPunct, Puncte);
            Inc(NrTest);
            WriteLn('TEST:', NrTest:2, Puncte:15, ' puncte');
            write(fc,Puncte,#9);
            Suma := Suma + Puncte;
        End;
{    writeln ('Pentru compilare:   10 puncte');}
    Close(FPunct);
    WriteLn('===================================');
    WriteLn('Programul ', Elev, ' a obtinut ', Suma, ' PUNCTE');
    writeln(fc,suma);
    close(fc);
End.
