#include "UBASICGODOT.h"
#include "ubasic.h"
#include <fstream>
#include <string>
 
//using namespace std;
using namespace godot;


void UBASICGODOT::_bind_methods(){
    ClassDB::bind_method(D_METHOD("get_programname"), &UBASICGODOT::get_programname);
	ClassDB::bind_method(D_METHOD("set_programname", "programname"), &UBASICGODOT::set_programname);
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
    UtilityFunctions::print("uBASIC-Godot v0.01\n"); 
    UtilityFunctions::print("programname: ", programname, "\n"); 


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
    //UtilityFunctions::print("hello world from _process\n");  
}

void UBASICGODOT::_draw(){
    //UtilityFunctions::print("color:", ubasic_get_color(), "\n");
    godot::Color c;
    int width;
    std::vector<lines> l = ubasic_get_lines();
    godot::PackedVector2Array points;
    for (int i=0; i<l.size(); i++){
        points.append(Vector2(l[i].startx, l[i].starty));
        points.append(Vector2(l[i].endx, l[i].endy));
        c = l[i].color;
        width = l[i].width;
        draw_polyline(points, c, (double)width);
        points.clear();
    }
}

void UBASICGODOT::set_programname(const godot::String &progname) {
	programname = progname;
}

godot::String UBASICGODOT::get_programname() const {
	return programname;
}




