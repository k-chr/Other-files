var s:string;
    len:Longint;
begin
  Randomize;
  s:='';
  for len:=Random(249)+8 downto 0 do
      s:=s+chr(Random(94)+33);
  writeln(s);
end.