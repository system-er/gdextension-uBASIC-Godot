# gdextension-uBASIC-Godot
gdextension uBASIC-Godot

a first picture:    
![Pic1](firstpic.JPG)

yet another example for gdextension. imho i think theres still not enough documentation for gdextension.    
im interested in interpreters and i found [Adam Dunkels uBASIC](https://github.com/adamdunkels/ubasic). a cool oldschool basicinterpreter.       
i inject uBASIC with gdextension to godot as a node. programmed in c++ for windows, tested with 4.3.dev4.      
the basic-program test.bas produces the output you see in the pic:   

5 print "hello world from uBASIC-Godot"    
10 gosub 100    
20 for i = 1 to 3    
30 print i;    
40 next i    
45 print "3\*2+4="    
46 print 3\*2+4    
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


# godot-specific-commands:   
some first godot-specific-commands, i extended (look basictest/test.bas exampleprogram).    

drawing lines:    
setwidth number - set the linewidth for example 1    
setcolor number number number - set the drawcolor for examle blue 0 0 255    
drawline number number number number - draw a line from startx, starty to endx, endy    



# usage:   
with the dll in bin, godot should know the new node, you can find if you search for UBASICGODOT.    
Godot generates also a helppage.    
in inspector select the UBASICGODOT-node and type in the name of the basic-program.   
in this test it is test.bas   
you can write own programs with texteditor of your choice.    


# build:   
for build, you have to insert godot-cpp, follow the gdextension-example in godot-docs    
if you build it for example for linux you have to expand some files like UBASICGODOT.gdextension...    

