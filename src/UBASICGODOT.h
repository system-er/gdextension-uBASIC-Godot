#ifndef UBASICGODOT_H
#define UBASICGODOT_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <vector>


namespace godot {
    class UBASICGODOT : public Node2D {
        GDCLASS(UBASICGODOT, Node2D)

        private:

        protected:
            static void _bind_methods();
        
        public:
            UBASICGODOT();
            ~UBASICGODOT();
            
            void _ready();
            void _process(double delta);
            void _draw();
            
            godot::String programname;
            void set_programname(const godot::String &progname);
            godot::String get_programname() const;

    };
};

#endif