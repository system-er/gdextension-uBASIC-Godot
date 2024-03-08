#ifndef UBASICGODOT_H
#define UBASICGODOT_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node2d.hpp>


namespace godot {
    class UBASICGODOT : public Node {
        GDCLASS(UBASICGODOT, Node)

        private:

        protected:
            static void _bind_methods();
        
        public:
            UBASICGODOT();
            ~UBASICGODOT();
            
            void _ready();
            void _process(double delta);
            
            godot::String programname;
            void set_programname(godot::String progname);
            godot::String get_programname();
    };
};

#endif