#include "UBASICGODOT.h"
#include "ubasic.h"
#include <fstream>
#include <string>
 

//using namespace std;
using namespace godot;


void UBASICGODOT::_bind_methods(){
    ClassDB::bind_method(D_METHOD("set_programname", "programname"), &UBASICGODOT::set_programname);
    ClassDB::bind_method(D_METHOD("get_programname"), &UBASICGODOT::get_programname);
    ADD_GROUP("Basicprogram", "programname_");
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "programname"), "set_programname", "get_programname");
}


UBASICGODOT::UBASICGODOT(){
    if(Engine::get_singleton()->is_editor_hint()){
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
    }
    //UtilityFunctions::print("hello world from constructor\n");
}


UBASICGODOT::~UBASICGODOT(){
    //UtilityFunctions::print("hello world from destructor\n");  
}


void UBASICGODOT::_ready(){

    UtilityFunctions::print("uBasic-Godot v0.01\n"); 
    UtilityFunctions::print("programname: ", programname, "\n"); 
/*
    static const char program[] =
    "10 gosub 100\n\
20 for i = 1 to 5\n\
30 print i;\n\
40 next i\n\
45 print 3*2+4\n\
50 print \"end\"\n\
55 print A\n\
55 print B\n\
60 end\n\
100 print \"subroutine\"\n\
110 return\n";
*/

    std::string line, text;
    std::ifstream in(programname.utf8().get_data());
    while(std::getline(in, line))
    {
        text += line + "\n";
    }
    const char *program = text.c_str();
    UtilityFunctions::print("length: ", strlen(program), "\n");
    
    ubasic_init(program, *this, *this->get_parent());
    do {
        ubasic_run();
    } while (!ubasic_finished());

}


void UBASICGODOT::_process(double delta){

}


void UBASICGODOT::set_programname(godot::String progname) {
	programname = progname;
}


godot::String UBASICGODOT::get_programname() {
	return programname;
}


