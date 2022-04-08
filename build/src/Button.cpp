#include "core/tree/abstract_property.h"
#include "core/control/assignment.h"
#include "core/tree/component.h"
#include "core/tree/double_property.h"
#include "base/fsm.h"
#include "base/fsm.h"
#include "gui/style/color.h"
#include "core/control/native_expression_action.h"
#include "gui/shape/rectangle.h"
#include "core/tree/spike.h"
#include "core/control/synchronizer.h"
#include "gui/shape/text.h"
#include "gui/transformation/translation.h"

#include "core/utils/error.h" // for Context class
#undef error // avoid name clash with error macro and possible following #include
#undef warning // avoid name clash with error macro and possible following #include

using namespace djnn;

#include "core/core-dev.h"
#include "base/base-dev.h"
#include "display/display-dev.h"
#include "gui/gui-dev.h"

struct nat_src_Button_cpp_0_struct : public NativeExpressionAction {
	nat_src_Button_cpp_0_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
      : NativeExpressionAction (p, n, isModel), _string_setter (string_setter)
    {
      set_is_model (isModel);

      // note: finalize_construction will call impl_activate before proper properties are fully built, leading to a crash
      // so delay finalize_construction after building properties
      // finalize_construction (p, n);
    }

    bool _string_setter;
    void impl_deactivate () override {}
    void impl_activate () override;
	AbstractProperty * thisLabel_y;
	AbstractProperty * r_height;
};

void
nat_src_Button_cpp_0_struct::impl_activate ()
{
	thisLabel_y->set_value(((AbstractProperty*)r_height)->get_double_value () / 2, 1);
};


struct nat_src_Button_cpp_1_struct : public NativeExpressionAction {
	nat_src_Button_cpp_1_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
      : NativeExpressionAction (p, n, isModel), _string_setter (string_setter)
    {
      set_is_model (isModel);

      // note: finalize_construction will call impl_activate before proper properties are fully built, leading to a crash
      // so delay finalize_construction after building properties
      // finalize_construction (p, n);
    }

    bool _string_setter;
    void impl_deactivate () override {}
    void impl_activate () override;
	AbstractProperty * r_width;
	AbstractProperty * thisLabel_width;
};

void
nat_src_Button_cpp_1_struct::impl_activate ()
{
	r_width->set_value(((AbstractProperty*)thisLabel_width)->get_double_value () + 20, 1);
};


struct nat_src_Button_cpp_2_struct : public NativeExpressionAction {
	nat_src_Button_cpp_2_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
      : NativeExpressionAction (p, n, isModel), _string_setter (string_setter)
    {
      set_is_model (isModel);

      // note: finalize_construction will call impl_activate before proper properties are fully built, leading to a crash
      // so delay finalize_construction after building properties
      // finalize_construction (p, n);
    }

    bool _string_setter;
    void impl_deactivate () override {}
    void impl_activate () override;
	AbstractProperty * r_width;
	AbstractProperty * thisLabel_width;
};

void
nat_src_Button_cpp_2_struct::impl_activate ()
{
	r_width->set_value(((AbstractProperty*)thisLabel_width)->get_double_value () + 20, 1);
};

ParentProcess*
Button (ParentProcess *p, const string &n, djnn::CoreProcess* cpnt_0, const djnn::string& s_var_0, double d_var_1, double d_var_2)
{
	auto* cpnt_1 = new Component (p, n);
	auto* cpnt_2 = new Translation (cpnt_1, "t", d_var_1, d_var_2);
	alias (cpnt_1, "x", dynamic_cast<FatChildProcess*>(cpnt_2->find_child ("tx")));
	auto *cpnt_3 = cpnt_1->find_child ( "x");
	alias (cpnt_1, "y", dynamic_cast<FatChildProcess*>(cpnt_2->find_child ("ty")));
	auto *cpnt_4 = cpnt_1->find_child ( "y");
	auto* cpnt_5 = new Spike (cpnt_1, "click");
	auto* cpnt_6 = new FillColor (cpnt_1, "fc", 50, 50, 50);
	auto* cpnt_7 = new Rectangle (cpnt_1, "r", 0, 0, 100, 70, 10, 10);
	auto* cpnt_8 = new FSM (nullptr, "fsm");
	auto* cpnt_9 = new FSMState (cpnt_8, "idle");
	DoubleProperty *cpnt_10 = new DoubleProperty (cpnt_9, "", 50);
	new Assignment (cpnt_9, "", cpnt_10, cpnt_6->find_child ("r"), 0);
	auto* cpnt_11 = new FSMState (cpnt_8, "pressed");
	DoubleProperty *cpnt_12 = new DoubleProperty (cpnt_11, "", 150);
	new Assignment (cpnt_11, "", cpnt_12, cpnt_6->find_child ("r"), 0);
	new FSMTransition (cpnt_8, "", cpnt_9, cpnt_11, cpnt_7->find_child ("press"), "", nullptr, "");
	new FSMTransition (cpnt_8, "", cpnt_11, cpnt_9, cpnt_7->find_child ("release"), "", cpnt_5, "");
	new FSMTransition (cpnt_8, "", cpnt_11, cpnt_9, cpnt_0->find_child ("release"), "", nullptr, "");
	cpnt_1->add_child (dynamic_cast<FatChildProcess*>(cpnt_8), "fsm");
	auto* cpnt_13 = new FillColor (cpnt_1, "w", 255, 255, 255);
	auto* cpnt_14 = new Text (cpnt_1, "thisLabel", 10, 10, s_var_0);
	auto *cpnt_15 = new nat_src_Button_cpp_0_struct (cpnt_1, "", true, 0);
	AbstractProperty* cpnt_16 = dynamic_cast<AbstractProperty*> (cpnt_7->find_child ("height"));
	if (cpnt_7->find_child ("height")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_7->find_child ("height"), "is not a property\n");
		exit(0);
	}
		cpnt_15->r_height= cpnt_16;
	AbstractProperty* cpnt_17 = dynamic_cast<AbstractProperty*> (cpnt_14->find_child ("y"));
	if (cpnt_17->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_17, "is not a property\n");
		exit(0);
	}
		cpnt_15->thisLabel_y = cpnt_17;
	cpnt_15->finalize_construction (cpnt_1, "");
	cpnt_15->add_native_edge (cpnt_15,cpnt_14->find_child ("y"));
	auto *cpnt_18 = new nat_src_Button_cpp_1_struct (cpnt_1, "", true, 0);
	AbstractProperty* cpnt_19 = dynamic_cast<AbstractProperty*> (cpnt_14->find_child ("width"));
	if (cpnt_14->find_child ("width")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_14->find_child ("width"), "is not a property\n");
		exit(0);
	}
		cpnt_18->thisLabel_width= cpnt_19;
	AbstractProperty* cpnt_20 = dynamic_cast<AbstractProperty*> (cpnt_7->find_child ("width"));
	if (cpnt_20->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_20, "is not a property\n");
		exit(0);
	}
		cpnt_18->r_width = cpnt_20;
	cpnt_18->finalize_construction (cpnt_1, "");
	Synchronizer* cpnt_21 = new Synchronizer (cpnt_1, "sync_cpnt_21", cpnt_18, ""); //FIXME remove Synchronizer
	cpnt_21->add_source (cpnt_19, "");
	cpnt_21->add_native_edge (cpnt_18,cpnt_7->find_child ("width"));
	auto *cpnt_22 = new nat_src_Button_cpp_2_struct (cpnt_1, "", true, 0);
	AbstractProperty* cpnt_23 = dynamic_cast<AbstractProperty*> (cpnt_14->find_child ("width"));
	if (cpnt_14->find_child ("width")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_14->find_child ("width"), "is not a property\n");
		exit(0);
	}
		cpnt_22->thisLabel_width= cpnt_23;
	AbstractProperty* cpnt_24 = dynamic_cast<AbstractProperty*> (cpnt_7->find_child ("width"));
	if (cpnt_24->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_24, "is not a property\n");
		exit(0);
	}
		cpnt_22->r_width = cpnt_24;
	cpnt_22->finalize_construction (cpnt_1, "");
	Synchronizer* cpnt_25 = new Synchronizer (cpnt_1, "sync_cpnt_25", cpnt_22, ""); //FIXME remove Synchronizer
	cpnt_25->add_source (cpnt_23, "");
	cpnt_25->add_native_edge (cpnt_22,cpnt_7->find_child ("width"));
	return cpnt_1;
}
