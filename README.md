# gdextension-uBASIC-Godot
gdextension uBASIC-Godot

a first picture:    
![Pic1](gdextension-uBASIC-Godot/blob/main/firstpic.JPG)

yet another example for gdextension. imho i think theres still not enough documentation for gdextension.    
im interested in interpreters and i found Adam Dunkels uBASIC (you can find on github, too).   
a cool oldschool basicinterpreter. for example variables have only one letter lowercase a-z, means only 26 variables.    
i inject uBASIC with gdextension to godot as a node. i pimped some things for godot like change from printf to godots print.    
programmed for windows with godot 4.2.1 godot-cpp. if build in for example linux you have to expand some files like UBASICGODOT.gdextension...    


# usage:   
with the dll in bin, godot should know the new node, you can find if you search for UBASICGODOT.    
Godot generates also a helppage.    
in inspector select the UBASICGODOT-node and type in the name of the basic-program.   
in this test it is test.bas   
you can write own programs with texteditor of your choice.    


# build:   
for build, you have to insert godot-cpp, follow the gdextension-example in godot-docs      


# contact:    
sys_temerror@web.de    
before pullrequest/merging please contact me and talk with me...    
