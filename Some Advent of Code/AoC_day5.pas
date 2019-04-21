Program AoC_day5;
{$MODE OBJFPC}
uses
 Sysutils,
 RegExpr,
 Crt;
const
     fname = 'input.txt';
var
    histogram: array[65..90] of integer;
    tfOut: Text;
    s1:ansistring;
    s2:ansistring;
    i:integer;
    min:integer;
    pos:integer;
    len:integer;
    len2:integer;
    re:TRegExpr;
function annihilate(s:ansistring; c:char):ansistring;
         var l:integer;
             it:integer;
             outs:ansistring;
         Begin
              l:=Length(s);
              it:=1;
              outs:=s;
              while it < l do
                    begin
                         if char(lowercase(outs[it])) = lowercase(c) then
                            begin
                                 outs:=(LeftStr(outs, (it-1)) + RightStr(outs, (l-it)));
                                 l:=l-1;
                            end
                         else
                             it:=it+1;
                    end;
              annihilate:=outs;     
         end;
function purity(s:ansistring):integer;
         var l:integer;
             it:integer;
             copy:ansistring;
         Begin
              l:=Length(s);
              it:=2;
              copy:=s;
              while it < l do
                Begin
                     if (lowercase(copy[it]) = lowercase(copy[it-1])) and (copy[it] <> copy[it-1]) then
                        Begin
                             copy:= (LeftStr(copy, it-2) + RightStr(copy, l-it));
                             l:=l-2;
                             it:=it-1;
                        end
                     else
                         it:=it+1;
                end;
              purity:=l;
         end;
         
Begin
     Assign(tfOut, fname);
     try                
          reset(tfOut);
          readln(tfOut,s1);
          CloseFile(tfOut);
          i:= 2;
          s2:='dabAcCaCBAcCcaDA';
          s2:=annihilate(s2, 'D');
          writeln(purity(s2));
          s2:= s1;            
          writeln(purity(s1));
          min:=50000;
          for pos:=65 to 91 do
                begin
                     s1:= annihilate(s2, char(pos));
                     len:=purity(s1);
                     if len < min then
                        min:= len;
                end;
          writeln(min);
          ReadKey;
     except on E:EInOutError do
            begin 
                        writeln(E.ClassName, '/ ',E.Message);
                        ReadKey;
            end;
     end;
end.