var i, j, w ,h:integer;
t:text;
a: array[1..1000,1..1000] of integer;
begin
	assign(t,'turtle.in');
	reset(t);
	
	
	readln(t, h, w);


  for i:=1 to h do
  begin
  	for j:=1 to w-1 do
  		read(t, a[i,j]);
  	readln(t, a[i, w]);
  end;
  
  
	for i:=h-1 downto 1 do   //filling first ranges
  	a[i,1]+=a[i+1,1];
	for j:=2 to w do
  	a[h,j]+=a[h,j-1];
  	
  for j:=2 to w do   //filling last elements
  	for i:=h-1 downto 1 do
  	begin
  		if (a[i+1,j]>a[i,j-1]) then
  			a[i][j]+=a[i+1][j]
  		else
  			a[i,j]+=a[i,j-1];
  	end;
	close(t);
	
	assign(t,'turtle.out');
	rewrite(t);
	writeln (t, a[1,w]);
	close(t);
end.
