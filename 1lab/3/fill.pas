var i, j, size:longint;
t: text;
begin
assign(t,'turtle.in');
rewrite(t);
size:=12;
writeln(t, size,' ',size);
for i:=1 to size do
	write(t, 100, ' ');
writeln(t, '');
for i:=2 to size do
	begin
		write (t, 100, ' ');
		for j:=2 to size do
		write(t, 3, ' ');
		writeln(t, '');
	end;
	
		
			
	

close(t);
end.
