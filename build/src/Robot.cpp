#include "core/tree/abstract_property.h"
#include "core/control/binding.h"
#include "core/tree/bool_property.h"
#include "base/clock.h"
#include "core/tree/component.h"
#include "base/connector.h"
#include "core/tree/double_property.h"
#include "base/fsm.h"
#include "base/fsm.h"
#include "gui/shape/image.h"
#include "core/tree/int_property.h"
#include "gui/shape/line.h"
#include "base/log.h"
#include "core/control/native_action.h"
#include "core/control/native_expression_action.h"
#include "gui/style/color.h"
#include "gui/style/gen/outline_width.h"
#include "base/math_functions.h"
#include "core/tree/spike.h"
#include "base/math_functions.h"
#include "core/control/synchronizer.h"

#include "core/utils/error.h" // for Context class
#undef error // avoid name clash with error macro and possible following #include
#undef warning // avoid name clash with error macro and possible following #include

using namespace djnn;

#include "core/core-dev.h"
#include "base/base-dev.h"
#include "display/display-dev.h"
#include "gui/gui-dev.h"

struct nat_src_Robot_cpp_0_struct : public NativeExpressionAction {
	nat_src_Robot_cpp_0_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * left_pow_base;
	AbstractProperty * robot_x;
	AbstractProperty * targetX;
};

void
nat_src_Robot_cpp_0_struct::impl_activate ()
{
	left_pow_base->set_value(((AbstractProperty*)robot_x)->get_double_value () - ((AbstractProperty*)targetX)->get_double_value (), 1);
};


struct nat_src_Robot_cpp_1_struct : public NativeExpressionAction {
	nat_src_Robot_cpp_1_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * right_pow_base;
	AbstractProperty * robot_y;
	AbstractProperty * targetY;
};

void
nat_src_Robot_cpp_1_struct::impl_activate ()
{
	right_pow_base->set_value(((AbstractProperty*)robot_y)->get_double_value () - ((AbstractProperty*)targetY)->get_double_value (), 1);
};


struct nat_src_Robot_cpp_2_struct : public NativeExpressionAction {
	nat_src_Robot_cpp_2_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * to_be_squared;
	AbstractProperty * left_pow_result;
	AbstractProperty * right_pow_result;
};

void
nat_src_Robot_cpp_2_struct::impl_activate ()
{
	to_be_squared->set_value(((AbstractProperty*)left_pow_result)->get_double_value () + ((AbstractProperty*)right_pow_result)->get_double_value (), 1);
};


struct nat_src_Robot_cpp_3_struct : public NativeExpressionAction {
	nat_src_Robot_cpp_3_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * myline_x1;
	AbstractProperty * robot_x;
};

void
nat_src_Robot_cpp_3_struct::impl_activate ()
{
	myline_x1->set_value((((AbstractProperty*)robot_x)->get_double_value () + 70), 1);
};


struct nat_src_Robot_cpp_4_struct : public NativeExpressionAction {
	nat_src_Robot_cpp_4_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * myline_y1;
	AbstractProperty * robot_y;
};

void
nat_src_Robot_cpp_4_struct::impl_activate ()
{
	myline_y1->set_value((((AbstractProperty*)robot_y)->get_double_value () + 70), 1);
};


struct nat_src_Robot_cpp_5_struct : public NativeExpressionAction {
	nat_src_Robot_cpp_5_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * distance_to_target;
};

void
nat_src_Robot_cpp_5_struct::impl_activate ()
{
	loc_bool0->set_value(((((AbstractProperty*)distance_to_target)->get_double_value ()) < 50), 1);
};


struct nat_src_Robot_cpp_6_struct : public NativeExpressionAction {
	nat_src_Robot_cpp_6_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * nb_step;
	AbstractProperty * distance_to_target;
	AbstractProperty * vitesse;
};

void
nat_src_Robot_cpp_6_struct::impl_activate ()
{
	nb_step->set_value(((AbstractProperty*)distance_to_target)->get_double_value () / ((AbstractProperty*)vitesse)->get_double_value (), 1);
};


struct nat_src_Robot_cpp_7_struct : public NativeExpressionAction {
	nat_src_Robot_cpp_7_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * loc_bool1;
	AbstractProperty * distance_to_target;
	AbstractProperty * robot_width;
};

void
nat_src_Robot_cpp_7_struct::impl_activate ()
{
	loc_bool1->set_value((((AbstractProperty*)distance_to_target)->get_double_value () < ((AbstractProperty*)robot_width)->get_double_value () + 100), 1);
};


static void
func_0 (CoreProcess* c) {
	auto *cpnt_0 = c->get_activation_source ();
	Process *cpnt_1 = (Process *) get_native_user_data (c);
	((AbstractProperty*) cpnt_1->find_child ("robot_fsm/start_moving/x0"))->set_value (((AbstractProperty*)cpnt_1->find_child ("robot/x"))->get_double_value (), true);
	((AbstractProperty*) cpnt_1->find_child ("robot_fsm/start_moving/y0"))->set_value (((AbstractProperty*)cpnt_1->find_child ("robot/y"))->get_double_value (), true);
}


static void
func_1 (CoreProcess* c) {
	auto *cpnt_2 = c->get_activation_source ();
	Process *cpnt_3 = (Process *) get_native_user_data (c);
	((AbstractProperty*) cpnt_3->find_child ("robot_fsm/start_moving/x0"))->set_value (((AbstractProperty*)cpnt_3->find_child ("robot/x"))->get_double_value (), true);
	((AbstractProperty*) cpnt_3->find_child ("robot_fsm/start_moving/y0"))->set_value (((AbstractProperty*)cpnt_3->find_child ("robot/y"))->get_double_value (), true);
}


static void
func_2 (CoreProcess* c) {
	auto *cpnt_4 = c->get_activation_source ();
	Process *cpnt_5 = (Process *) get_native_user_data (c);
	((AbstractProperty*) cpnt_5->find_child ("robot/x"))->set_value (((AbstractProperty*)cpnt_5->find_child ("robot/x"))->get_double_value () + (((AbstractProperty*)cpnt_5->find_child ("targetX"))->get_double_value () - ((AbstractProperty*)cpnt_5->find_child ("robot_fsm/start_moving/x0"))->get_double_value ()) / ((AbstractProperty*)cpnt_5->find_child ("robot_fsm/start_moving/nb_step"))->get_double_value (), true);
	((AbstractProperty*) cpnt_5->find_child ("robot/y"))->set_value (((AbstractProperty*)cpnt_5->find_child ("robot/y"))->get_double_value () + (((AbstractProperty*)cpnt_5->find_child ("targetY"))->get_double_value () - ((AbstractProperty*)cpnt_5->find_child ("robot_fsm/start_moving/y0"))->get_double_value ()) / ((AbstractProperty*)cpnt_5->find_child ("robot_fsm/start_moving/nb_step"))->get_double_value (), true);
}

ParentProcess*
Robot (ParentProcess *p, const string &n, djnn::CoreProcess* cpnt_6, const djnn::string& s_var_0, double d_var_1, double d_var_2)
{
		auto* cpnt_7 = new Component (p, n);
		auto* cpnt_8 = new DoubleProperty (cpnt_7, "vitesse", 10);
		auto* cpnt_9 = new DoubleProperty (cpnt_7, "step_to_arrival", 0);
		auto* cpnt_10 = new DoubleProperty (cpnt_7, "distance_to_target", 0);
		auto* cpnt_11 = new Image (cpnt_7, "robot", s_var_0, 1200, 600, 150, 150);
		alias (cpnt_7, "x", dynamic_cast<FatChildProcess*>(cpnt_11->find_child ("x")));
		auto *cpnt_12 = cpnt_7->find_child ( "x");
		alias (cpnt_7, "y", dynamic_cast<FatChildProcess*>(cpnt_11->find_child ("y")));
		auto *cpnt_13 = cpnt_7->find_child ( "y");
		auto* cpnt_14 = new DoubleProperty (cpnt_7, "targetX", 600);
		auto* cpnt_15 = new DoubleProperty (cpnt_7, "targetY", 600);
		auto* cpnt_16 = new Sqrt (cpnt_7, "mysqrt", 0);
		auto* cpnt_17 = new Pow (cpnt_7, "left_pow", 0, 2);
		auto* cpnt_18 = new Pow (cpnt_7, "right_pow", 0, 2);
		auto* cpnt_19 = new DoubleProperty (cpnt_7, "to_be_squared", 0);
		auto *cpnt_20 = new nat_src_Robot_cpp_0_struct (cpnt_7, "", true, 0);
		AbstractProperty* cpnt_21 = dynamic_cast<AbstractProperty*> (cpnt_11->find_child ("x"));
		if (cpnt_11->find_child ("x")->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_11->find_child ("x"), "is not a property\n");
			exit(0);
		}
				cpnt_20->robot_x= cpnt_21;
		if (cpnt_14->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_14, "is not a property\n");
			exit(0);
		}
				cpnt_20->targetX = dynamic_cast<AbstractProperty*>(cpnt_14);
		AbstractProperty* cpnt_22 = dynamic_cast<AbstractProperty*> (cpnt_17->find_child ("base"));
		if (cpnt_22->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_22, "is not a property\n");
			exit(0);
		}
				cpnt_20->left_pow_base = cpnt_22;
		cpnt_20->finalize_construction (cpnt_7, "");
		Synchronizer* cpnt_23 = new Synchronizer (cpnt_7, "sync_cpnt_23", cpnt_20, ""); //FIXME remove Synchronizer
		cpnt_23->add_source (cpnt_21, "");
		cpnt_23->add_source (cpnt_14, "");
		cpnt_23->add_native_edge (cpnt_20,cpnt_17->find_child ("base"));
		auto *cpnt_24 = new nat_src_Robot_cpp_1_struct (cpnt_7, "", true, 0);
		AbstractProperty* cpnt_25 = dynamic_cast<AbstractProperty*> (cpnt_11->find_child ("y"));
		if (cpnt_11->find_child ("y")->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_11->find_child ("y"), "is not a property\n");
			exit(0);
		}
				cpnt_24->robot_y= cpnt_25;
		if (cpnt_15->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_15, "is not a property\n");
			exit(0);
		}
				cpnt_24->targetY = dynamic_cast<AbstractProperty*>(cpnt_15);
		AbstractProperty* cpnt_26 = dynamic_cast<AbstractProperty*> (cpnt_18->find_child ("base"));
		if (cpnt_26->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_26, "is not a property\n");
			exit(0);
		}
				cpnt_24->right_pow_base = cpnt_26;
		cpnt_24->finalize_construction (cpnt_7, "");
		Synchronizer* cpnt_27 = new Synchronizer (cpnt_7, "sync_cpnt_27", cpnt_24, ""); //FIXME remove Synchronizer
		cpnt_27->add_source (cpnt_25, "");
		cpnt_27->add_source (cpnt_15, "");
		cpnt_27->add_native_edge (cpnt_24,cpnt_18->find_child ("base"));
		auto *cpnt_28 = new nat_src_Robot_cpp_2_struct (cpnt_7, "", true, 0);
		AbstractProperty* cpnt_29 = dynamic_cast<AbstractProperty*> (cpnt_17->find_child ("result"));
		if (cpnt_17->find_child ("result")->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_17->find_child ("result"), "is not a property\n");
			exit(0);
		}
				cpnt_28->left_pow_result= cpnt_29;
		AbstractProperty* cpnt_30 = dynamic_cast<AbstractProperty*> (cpnt_18->find_child ("result"));
		if (cpnt_18->find_child ("result")->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_18->find_child ("result"), "is not a property\n");
			exit(0);
		}
				cpnt_28->right_pow_result= cpnt_30;
		if (cpnt_19->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_19, "is not a property\n");
			exit(0);
		}
				cpnt_28->to_be_squared = dynamic_cast<AbstractProperty*>(cpnt_19);
		cpnt_28->finalize_construction (cpnt_7, "");
		Synchronizer* cpnt_31 = new Synchronizer (cpnt_7, "sync_cpnt_31", cpnt_28, ""); //FIXME remove Synchronizer
		cpnt_31->add_source (cpnt_29, "");
		cpnt_31->add_source (cpnt_30, "");
		cpnt_31->add_native_edge (cpnt_28,cpnt_19);
		new Connector (cpnt_7, "", cpnt_19, cpnt_16->find_child ("input"), 1);
		new Connector (cpnt_7, "", cpnt_16->find_child ("output"), cpnt_10, 0);
		auto* cpnt_32 = new Spike (cpnt_7, "goto");
		auto* cpnt_33 = new Spike (cpnt_7, "arrived");
		auto* cpnt_34 = new Spike (cpnt_7, "left");
		auto* cpnt_35 = new Spike (cpnt_7, "_stop");
		auto* cpnt_36 = new OutlineWidth (cpnt_7, "_", 5);
		auto* cpnt_37 = new OutlineColor (cpnt_7, "_", 255, 0, 0);
		auto* cpnt_38 = new Line (cpnt_7, "myline", 0, 0, 0, 0);
		auto *cpnt_39 = new nat_src_Robot_cpp_3_struct (cpnt_7, "", true, 0);
		AbstractProperty* cpnt_40 = dynamic_cast<AbstractProperty*> (cpnt_11->find_child ("x"));
		if (cpnt_11->find_child ("x")->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_11->find_child ("x"), "is not a property\n");
			exit(0);
		}
				cpnt_39->robot_x= cpnt_40;
		AbstractProperty* cpnt_41 = dynamic_cast<AbstractProperty*> (cpnt_38->find_child ("x1"));
		if (cpnt_41->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_41, "is not a property\n");
			exit(0);
		}
				cpnt_39->myline_x1 = cpnt_41;
		cpnt_39->finalize_construction (cpnt_7, "");
		Synchronizer* cpnt_42 = new Synchronizer (cpnt_7, "sync_cpnt_42", cpnt_39, ""); //FIXME remove Synchronizer
		cpnt_42->add_source (cpnt_40, "");
		cpnt_42->add_native_edge (cpnt_39,cpnt_38->find_child ("x1"));
		auto *cpnt_43 = new nat_src_Robot_cpp_4_struct (cpnt_7, "", true, 0);
		AbstractProperty* cpnt_44 = dynamic_cast<AbstractProperty*> (cpnt_11->find_child ("y"));
		if (cpnt_11->find_child ("y")->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_11->find_child ("y"), "is not a property\n");
			exit(0);
		}
				cpnt_43->robot_y= cpnt_44;
		AbstractProperty* cpnt_45 = dynamic_cast<AbstractProperty*> (cpnt_38->find_child ("y1"));
		if (cpnt_45->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_45, "is not a property\n");
			exit(0);
		}
				cpnt_43->myline_y1 = cpnt_45;
		cpnt_43->finalize_construction (cpnt_7, "");
		Synchronizer* cpnt_46 = new Synchronizer (cpnt_7, "sync_cpnt_46", cpnt_43, ""); //FIXME remove Synchronizer
		cpnt_46->add_source (cpnt_44, "");
		cpnt_46->add_native_edge (cpnt_43,cpnt_38->find_child ("y1"));
		new Connector (cpnt_7, "", cpnt_14, cpnt_38->find_child ("x2"), 1);
		new Connector (cpnt_7, "", cpnt_15, cpnt_38->find_child ("y2"), 1);
		auto* cpnt_47 = new BoolProperty (cpnt_7, "loc_bool0", 0);
		auto *cpnt_48 = new nat_src_Robot_cpp_5_struct (cpnt_7, "", true, 0);
		if (cpnt_10->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_10, "is not a property\n");
			exit(0);
		}
				cpnt_48->distance_to_target = dynamic_cast<AbstractProperty*>(cpnt_10);
		if (cpnt_47->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_47, "is not a property\n");
			exit(0);
		}
				cpnt_48->loc_bool0 = dynamic_cast<AbstractProperty*>(cpnt_47);
		cpnt_48->finalize_construction (cpnt_7, "");
		Synchronizer* cpnt_49 = new Synchronizer (cpnt_7, "sync_cpnt_49", cpnt_48, ""); //FIXME remove Synchronizer
		cpnt_49->add_source (cpnt_10, "");
		cpnt_49->add_native_edge (cpnt_48,cpnt_47);
		new Binding (cpnt_7, "", cpnt_47->find_child ("true"), ACTIVATION, cpnt_33, ACTIVATION);
		auto* cpnt_50 = new FSM (nullptr, "robot_fsm");
		auto* cpnt_51 = new FSMState (cpnt_50, "idle");
		auto* cpnt_52 = new FSMState (cpnt_50, "start_moving");
		auto* cpnt_53 = new LogPrinter (cpnt_52, "lp2", "debug in fsm");
		auto* cpnt_54 = new DoubleProperty (cpnt_52, "x0", ((AbstractProperty*)cpnt_11->find_child ("x"))->get_double_value ());
		auto* cpnt_55 = new DoubleProperty (cpnt_52, "y0", ((AbstractProperty*)cpnt_11->find_child ("y"))->get_double_value ());
		auto* cpnt_56 = new IntProperty (cpnt_52, "nb_step", 10);
		auto *cpnt_57 = new nat_src_Robot_cpp_6_struct (cpnt_52, "", true, 0);
		if (cpnt_10->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_10, "is not a property\n");
			exit(0);
		}
				cpnt_57->distance_to_target = dynamic_cast<AbstractProperty*>(cpnt_10);
		if (cpnt_8->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_8, "is not a property\n");
			exit(0);
		}
				cpnt_57->vitesse = dynamic_cast<AbstractProperty*>(cpnt_8);
		if (cpnt_56->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_56, "is not a property\n");
			exit(0);
		}
				cpnt_57->nb_step = dynamic_cast<AbstractProperty*>(cpnt_56);
		cpnt_57->finalize_construction (cpnt_52, "");
		Synchronizer* cpnt_58 = new Synchronizer (cpnt_52, "sync_cpnt_58", cpnt_57, ""); //FIXME remove Synchronizer
		cpnt_58->add_source (cpnt_10, "");
		cpnt_58->add_source (cpnt_8, "");
		cpnt_58->add_native_edge (cpnt_57,cpnt_56);
		auto* cpnt_59 = new Clock (cpnt_52, "myclock", 50);
		new Connector (cpnt_52, "", cpnt_56, cpnt_53->find_child ("input"), 1);
		auto* cpnt_60 = new NativeAction (cpnt_52, "", func_0, cpnt_7, 1);
 		new Binding (cpnt_52, "", cpnt_14, ACTIVATION, cpnt_60, ACTIVATION);
		auto* cpnt_61 = new NativeAction (cpnt_52, "", func_1, cpnt_7, 1);
 		new Binding (cpnt_52, "", cpnt_15, ACTIVATION, cpnt_61, ACTIVATION);
		auto* cpnt_62 = new NativeAction (cpnt_52, "", func_2, cpnt_7, 1);
 		new Binding (cpnt_52, "", cpnt_59->find_child ("tick"), ACTIVATION, cpnt_62, ACTIVATION);
		new FSMTransition (cpnt_50, "", cpnt_51, cpnt_52, cpnt_32, "", nullptr, "");
		new FSMTransition (cpnt_50, "", cpnt_52, cpnt_51, cpnt_33, "", nullptr, "");
		new FSMTransition (cpnt_50, "", cpnt_52, cpnt_52, cpnt_14, "", nullptr, "");
		new FSMTransition (cpnt_50, "", cpnt_52, cpnt_52, cpnt_15, "", nullptr, "");
		new FSMTransition (cpnt_50, "", cpnt_51, cpnt_52, cpnt_11->find_child ("press"), "", nullptr, "");
		new FSMTransition (cpnt_50, "", cpnt_52, cpnt_51, cpnt_11->find_child ("press"), "", nullptr, "");
		new FSMTransition (cpnt_50, "", cpnt_52, cpnt_51, cpnt_35, "", nullptr, "");
		cpnt_7->add_child (dynamic_cast<FatChildProcess*>(cpnt_50), "robot_fsm");
		auto* cpnt_63 = new BoolProperty (cpnt_7, "loc_bool1", 0);
		auto *cpnt_64 = new nat_src_Robot_cpp_7_struct (cpnt_7, "", true, 0);
		if (cpnt_10->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_10, "is not a property\n");
			exit(0);
		}
				cpnt_64->distance_to_target = dynamic_cast<AbstractProperty*>(cpnt_10);
		AbstractProperty* cpnt_65 = dynamic_cast<AbstractProperty*> (cpnt_11->find_child ("width"));
		if (cpnt_11->find_child ("width")->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_11->find_child ("width"), "is not a property\n");
			exit(0);
		}
				cpnt_64->robot_width= cpnt_65;
		if (cpnt_63->get_process_type() != PROPERTY_T) {
			djnn__error (cpnt_63, "is not a property\n");
			exit(0);
		}
				cpnt_64->loc_bool1 = dynamic_cast<AbstractProperty*>(cpnt_63);
		cpnt_64->finalize_construction (cpnt_7, "");
		Synchronizer* cpnt_66 = new Synchronizer (cpnt_7, "sync_cpnt_66", cpnt_64, ""); //FIXME remove Synchronizer
		cpnt_66->add_source (cpnt_10, "");
		cpnt_66->add_source (cpnt_65, "");
		cpnt_66->add_native_edge (cpnt_64,cpnt_63);
		new Binding (cpnt_7, "", cpnt_63->find_child ("true"), ACTIVATION, cpnt_33, ACTIVATION);
		auto* cpnt_67 = new LogPrinter (cpnt_7, "lp", "debug : ");
		return cpnt_7;
}
