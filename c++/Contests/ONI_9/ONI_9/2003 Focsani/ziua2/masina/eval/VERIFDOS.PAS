Program VerifMasina;

Type Vector = Array[1..30000] Of Word;
     PVector=^Vector;

Var f, g, h: Text;
    a, b: PVector;
    N, K, i, Plecare: Word;
    Rezervor: LongInt;

Procedure Error(p: Byte; Mesaj: String);
Begin
   {$I-}
     Assign(h, 'punctaj.txt'); Append(h);
   {$I+}
   If IOResult<>0 Then ReWrite(h);
   WriteLn(p, ' ', Mesaj);
   WriteLn(h, p); Close(h);
   Halt
End;

Begin
  New(a); New(b);
  Assign(f, 'masina.in'); Reset(f);
  {$I-}
    Assign(g, 'masina.out'); Reset(g);
  {$I+}
  If IOResult<>0 Then Error(0, 'Fisier de iesire absent');
  ReadLn(g, Plecare);

  ReadLn(f, N);
  For i := 1 To N Do Read(f, a^[i]);
  For i := 1 To N Do Read(f, b^[i]);
  Rezervor := 0;
  i := Plecare;
  Rezervor := Rezervor + a^[i];
  Rezervor := Rezervor - b^[i];
  Inc(i);
  If i=N+1 Then i := 1;
  While (i<>Plecare) And (Rezervor>=0) Do
    Begin
      Rezervor := Rezervor + a^[i];
      Rezervor := Rezervor - b^[i];
      Inc(i);
      If i=N+1 Then i := 1
    End;
  If Rezervor<0 Then
    Error(0, 'Solutie gresita')
  Else
    Error(10, 'OK');
  Dispose(a);Dispose(b);
  Close(f); Close(g)
End.