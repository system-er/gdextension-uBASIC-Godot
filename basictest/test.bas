5 print "hello world from uBASIC-Godot"
10 gosub 100
20 for i = 1 to 3
30 print i;
40 next i
45 print "3*2+4="
46 print 3*2+4
48 setcolor 0 0 255
49 setwidth 3
52 drawline 50 50 450 250
48 setcolor 0 255 0
49 setwidth 6
52 drawline 20 500 600 20
54 setcolor 255 0 0
56 setwidth 12
58 drawline 20 250 600 250
80 print "end"
90 end
100 print "subroutine"
110 return;