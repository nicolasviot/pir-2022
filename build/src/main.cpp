#include "core/tree/abstract_property.h"
#include "core/control/binding.h"
#include "core/tree/bool_property.h"
#include "core/tree/component.h"
#include "base/connector.h"
#include "exec_env/exit.h"
#include "base/fsm.h"
#include "base/fsm.h"
#include "gui/style/color.h"
#include "base/log.h"
#include "exec_env/main_loop.h"
#include "core/control/native_expression_action.h"
#include "gui/shape/rectangle.h"
#include "core/control/synchronizer.h"
#include "base/trigonometry.h"
#include "display/window.h"

#include "exec_env/exec_env-dev.h"
#include "core/utils/error.h" // for Context class
#undef error // avoid name clash with error macro and possible following #include
#undef warning // avoid name clash with error macro and possible following #include

using namespace djnn;

#include "core/core-dev.h"
#include "display/display-dev.h"
#include "gui/gui-dev.h"
#include "base/base-dev.h"
#include "Button.h"
#include "Robot.h"
#include "Waypoint.h"
#include "detour.h"
#include "Bombe.h"
#include "side.h"
#include "side_bas.h"

struct nat_src_main_cpp_0_struct : public NativeExpressionAction {
	nat_src_main_cpp_0_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * loc_bool0;
	AbstractProperty * myBombe_y;
	AbstractProperty * myrobot_y;
};

void
nat_src_main_cpp_0_struct::impl_activate ()
{
	loc_bool0->set_value((((((AbstractProperty*)myBombe_y)->get_double_value () - ((AbstractProperty*)myrobot_y)->get_double_value ()) * (((AbstractProperty*)myBombe_y)->get_double_value () - ((AbstractProperty*)myrobot_y)->get_double_value ())) < 50) && (((((AbstractProperty*)myBombe_y)->get_double_value () - ((AbstractProperty*)myrobot_y)->get_double_value ()) * (((AbstractProperty*)myBombe_y)->get_double_value () - ((AbstractProperty*)myrobot_y)->get_double_value ())) < 50), 1);
};


struct nat_src_main_cpp_1_struct : public NativeExpressionAction {
	nat_src_main_cpp_1_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * tan_input;
	AbstractProperty * myWaypoint_x;
	AbstractProperty * myrobot_x;
	AbstractProperty * myWaypoint_y;
	AbstractProperty * myrobot_y;
};

void
nat_src_main_cpp_1_struct::impl_activate ()
{
	tan_input->set_value((((AbstractProperty*)myWaypoint_x)->get_double_value () - ((AbstractProperty*)myrobot_x)->get_double_value ()) / (((AbstractProperty*)myWaypoint_y)->get_double_value () - ((AbstractProperty*)myrobot_y)->get_double_value ()), 1);
};


struct nat_src_main_cpp_2_struct : public NativeExpressionAction {
	nat_src_main_cpp_2_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * detour1_rot_a;
	AbstractProperty * tan_output;
};

void
nat_src_main_cpp_2_struct::impl_activate ()
{
	detour1_rot_a->set_value(((AbstractProperty*)tan_output)->get_double_value () * 180 / 3.14, 1);
};


struct nat_src_main_cpp_3_struct : public NativeExpressionAction {
	nat_src_main_cpp_3_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * detour2_rot_a;
	AbstractProperty * tan_output;
};

void
nat_src_main_cpp_3_struct::impl_activate ()
{
	detour2_rot_a->set_value(((AbstractProperty*)tan_output)->get_double_value () * 180 / 3.14 + 180, 1);
};

int
main (int argc, char* argv[]) {
	init_core ();
	init_exec_env ();
	init_display ();
	init_gui ();
	init_base ();
	auto* cpnt_0 = new Component (nullptr, "root");
	auto* cpnt_1 = new Window (cpnt_0, "f", "robot", 0, 0, 1920, 1080);
	auto* cpnt_2 = new Exit (cpnt_0, "quit", 0, 1);
	new Binding (cpnt_0, "", cpnt_1->find_child ("close"), ACTIVATION, cpnt_2, ACTIVATION);
	auto* cpnt_3 = new FillColor (cpnt_0, "reed", 250, 250, 255);
	auto* cpnt_4 = new Rectangle (cpnt_0, "ree", 0, 0, 1900, 1000, 0, 0);
	auto* cpnt_5 = Bombe (cpnt_0, "myBombe", cpnt_1, 700, 700);
	auto* cpnt_6 = Robot (cpnt_0, "myrobot", cpnt_1, "src/Robot.png", 0, 0);
	auto* cpnt_7 = Waypoint (cpnt_0, "myWaypoint", cpnt_1, 500, 500);
	new Connector (cpnt_0, "", cpnt_7->find_child ("x"), cpnt_6->find_child ("targetX"), 1);
	new Connector (cpnt_0, "", cpnt_7->find_child ("y"), cpnt_6->find_child ("targetY"), 1);
	auto* cpnt_8 = new BoolProperty (cpnt_0, "loc_bool0", 0);
	auto *cpnt_9 = new nat_src_main_cpp_0_struct (cpnt_0, "", true, 0);
	AbstractProperty* cpnt_10 = dynamic_cast<AbstractProperty*> (cpnt_5->find_child ("y"));
	if (cpnt_5->find_child ("y")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_5->find_child ("y"), "is not a property\n");
		exit(0);
	}
		cpnt_9->myBombe_y= cpnt_10;
	AbstractProperty* cpnt_11 = dynamic_cast<AbstractProperty*> (cpnt_6->find_child ("y"));
	if (cpnt_6->find_child ("y")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_6->find_child ("y"), "is not a property\n");
		exit(0);
	}
		cpnt_9->myrobot_y= cpnt_11;
	AbstractProperty* cpnt_12 = dynamic_cast<AbstractProperty*> (cpnt_5->find_child ("y"));
	if (cpnt_5->find_child ("y")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_5->find_child ("y"), "is not a property\n");
		exit(0);
	}
		cpnt_9->myBombe_y= cpnt_12;
	AbstractProperty* cpnt_13 = dynamic_cast<AbstractProperty*> (cpnt_6->find_child ("y"));
	if (cpnt_6->find_child ("y")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_6->find_child ("y"), "is not a property\n");
		exit(0);
	}
		cpnt_9->myrobot_y= cpnt_13;
	AbstractProperty* cpnt_14 = dynamic_cast<AbstractProperty*> (cpnt_5->find_child ("y"));
	if (cpnt_5->find_child ("y")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_5->find_child ("y"), "is not a property\n");
		exit(0);
	}
		cpnt_9->myBombe_y= cpnt_14;
	AbstractProperty* cpnt_15 = dynamic_cast<AbstractProperty*> (cpnt_6->find_child ("y"));
	if (cpnt_6->find_child ("y")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_6->find_child ("y"), "is not a property\n");
		exit(0);
	}
		cpnt_9->myrobot_y= cpnt_15;
	AbstractProperty* cpnt_16 = dynamic_cast<AbstractProperty*> (cpnt_5->find_child ("y"));
	if (cpnt_5->find_child ("y")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_5->find_child ("y"), "is not a property\n");
		exit(0);
	}
		cpnt_9->myBombe_y= cpnt_16;
	AbstractProperty* cpnt_17 = dynamic_cast<AbstractProperty*> (cpnt_6->find_child ("y"));
	if (cpnt_6->find_child ("y")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_6->find_child ("y"), "is not a property\n");
		exit(0);
	}
		cpnt_9->myrobot_y= cpnt_17;
	if (cpnt_8->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_8, "is not a property\n");
		exit(0);
	}
		cpnt_9->loc_bool0 = dynamic_cast<AbstractProperty*>(cpnt_8);
	cpnt_9->finalize_construction (cpnt_0, "");
	Synchronizer* cpnt_18 = new Synchronizer (cpnt_0, "sync_cpnt_18", cpnt_9, ""); //FIXME remove Synchronizer
	cpnt_18->add_source (cpnt_10, "");
	cpnt_18->add_source (cpnt_11, "");
	cpnt_18->add_source (cpnt_12, "");
	cpnt_18->add_source (cpnt_13, "");
	cpnt_18->add_source (cpnt_14, "");
	cpnt_18->add_source (cpnt_15, "");
	cpnt_18->add_source (cpnt_16, "");
	cpnt_18->add_source (cpnt_17, "");
	cpnt_18->add_native_edge (cpnt_9,cpnt_8);
	new Binding (cpnt_0, "", cpnt_8->find_child ("true"), ACTIVATION, cpnt_6->find_child ("_stop"), ACTIVATION);
	new Binding (cpnt_0, "", cpnt_7->find_child ("drag_Waypoint/moving"), ACTIVATION, cpnt_6->find_child ("arrived"), ACTIVATION);
	auto* cpnt_19 = new LogPrinter (cpnt_0, "lp", "debug tangent : ");
	auto* cpnt_20 = new FSM (nullptr, "show_detour");
	auto* cpnt_21 = new FSMState (cpnt_20, "no_show");
	auto* cpnt_22 = new FSMState (cpnt_20, "show");
	auto* cpnt_23 = detour (cpnt_22, "detour1", "bas");
	auto* cpnt_24 = detour (cpnt_22, "detour2", "haut");
	new Connector (cpnt_22, "", cpnt_5->find_child ("x"), cpnt_23->find_child ("t/tx"), 1);
	new Connector (cpnt_22, "", cpnt_5->find_child ("y"), cpnt_23->find_child ("t/ty"), 1);
	new Connector (cpnt_22, "", cpnt_5->find_child ("x"), cpnt_24->find_child ("t/tx"), 1);
	new Connector (cpnt_22, "", cpnt_5->find_child ("y"), cpnt_24->find_child ("t/ty"), 1);
	auto* cpnt_25 = new Tangent (cpnt_22, "tan", 0);
	auto *cpnt_26 = new nat_src_main_cpp_1_struct (cpnt_22, "", true, 0);
	AbstractProperty* cpnt_27 = dynamic_cast<AbstractProperty*> (cpnt_7->find_child ("x"));
	if (cpnt_7->find_child ("x")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_7->find_child ("x"), "is not a property\n");
		exit(0);
	}
		cpnt_26->myWaypoint_x= cpnt_27;
	AbstractProperty* cpnt_28 = dynamic_cast<AbstractProperty*> (cpnt_6->find_child ("x"));
	if (cpnt_6->find_child ("x")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_6->find_child ("x"), "is not a property\n");
		exit(0);
	}
		cpnt_26->myrobot_x= cpnt_28;
	AbstractProperty* cpnt_29 = dynamic_cast<AbstractProperty*> (cpnt_7->find_child ("y"));
	if (cpnt_7->find_child ("y")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_7->find_child ("y"), "is not a property\n");
		exit(0);
	}
		cpnt_26->myWaypoint_y= cpnt_29;
	AbstractProperty* cpnt_30 = dynamic_cast<AbstractProperty*> (cpnt_6->find_child ("y"));
	if (cpnt_6->find_child ("y")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_6->find_child ("y"), "is not a property\n");
		exit(0);
	}
		cpnt_26->myrobot_y= cpnt_30;
	AbstractProperty* cpnt_31 = dynamic_cast<AbstractProperty*> (cpnt_25->find_child ("input"));
	if (cpnt_31->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_31, "is not a property\n");
		exit(0);
	}
		cpnt_26->tan_input = cpnt_31;
	cpnt_26->finalize_construction (cpnt_22, "");
	Synchronizer* cpnt_32 = new Synchronizer (cpnt_22, "sync_cpnt_32", cpnt_26, ""); //FIXME remove Synchronizer
	cpnt_32->add_source (cpnt_27, "");
	cpnt_32->add_source (cpnt_28, "");
	cpnt_32->add_source (cpnt_29, "");
	cpnt_32->add_source (cpnt_30, "");
	cpnt_32->add_native_edge (cpnt_26,cpnt_25->find_child ("input"));
	auto *cpnt_33 = new nat_src_main_cpp_2_struct (cpnt_22, "", true, 0);
	AbstractProperty* cpnt_34 = dynamic_cast<AbstractProperty*> (cpnt_25->find_child ("output"));
	if (cpnt_25->find_child ("output")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_25->find_child ("output"), "is not a property\n");
		exit(0);
	}
		cpnt_33->tan_output= cpnt_34;
	AbstractProperty* cpnt_35 = dynamic_cast<AbstractProperty*> (cpnt_23->find_child ("rot/a"));
	if (cpnt_35->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_35, "is not a property\n");
		exit(0);
	}
		cpnt_33->detour1_rot_a = cpnt_35;
	cpnt_33->finalize_construction (cpnt_22, "");
	Synchronizer* cpnt_36 = new Synchronizer (cpnt_22, "sync_cpnt_36", cpnt_33, ""); //FIXME remove Synchronizer
	cpnt_36->add_source (cpnt_34, "");
	cpnt_36->add_native_edge (cpnt_33,cpnt_23->find_child ("rot/a"));
	auto *cpnt_37 = new nat_src_main_cpp_3_struct (cpnt_22, "", true, 0);
	AbstractProperty* cpnt_38 = dynamic_cast<AbstractProperty*> (cpnt_25->find_child ("output"));
	if (cpnt_25->find_child ("output")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_25->find_child ("output"), "is not a property\n");
		exit(0);
	}
		cpnt_37->tan_output= cpnt_38;
	AbstractProperty* cpnt_39 = dynamic_cast<AbstractProperty*> (cpnt_24->find_child ("rot/a"));
	if (cpnt_39->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_39, "is not a property\n");
		exit(0);
	}
		cpnt_37->detour2_rot_a = cpnt_39;
	cpnt_37->finalize_construction (cpnt_22, "");
	Synchronizer* cpnt_40 = new Synchronizer (cpnt_22, "sync_cpnt_40", cpnt_37, ""); //FIXME remove Synchronizer
	cpnt_40->add_source (cpnt_38, "");
	cpnt_40->add_native_edge (cpnt_37,cpnt_24->find_child ("rot/a"));
	new Connector (cpnt_22, "", cpnt_25->find_child ("output"), cpnt_19->find_child ("input"), 1);
	new FSMTransition (cpnt_20, "", cpnt_21, cpnt_22, cpnt_6->find_child ("_stop"), "", nullptr, "");
	cpnt_0->add_child (dynamic_cast<FatChildProcess*>(cpnt_20), "show_detour");
	cpnt_0->activate ();
	MainLoop::instance ().activate ();
}
