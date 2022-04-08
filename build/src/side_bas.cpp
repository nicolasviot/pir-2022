#include "core/tree/abstract_property.h"
#include "core/control/binding.h"
#include "base/clock.h"
#include "core/tree/component.h"
#include "base/connector.h"
#include "base/fsm.h"
#include "base/fsm.h"
#include "gui/style/color.h"
#include "gui/style/opacity.h"
#include "base/arithmetic.h"
#include "base/log.h"
#include "core/control/native_expression_action.h"
#include "gui/shape/rectangle.h"
#include "core/control/synchronizer.h"
#include "exec_env/timer.h"

#include "core/utils/error.h" // for Context class
#undef error // avoid name clash with error macro and possible following #include
#undef warning // avoid name clash with error macro and possible following #include

using namespace djnn;

#include "core/core-dev.h"
#include "display/display-dev.h"
#include "gui/gui-dev.h"
#include "base/base-dev.h"

struct nat_src_side_bas_cpp_0_struct : public NativeExpressionAction {
	nat_src_side_bas_cpp_0_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * col;
	AbstractProperty * x_state;
};

void
nat_src_side_bas_cpp_0_struct::impl_activate ()
{
	col->set_value(((AbstractProperty*)col)->get_double_value () - ((AbstractProperty*)x_state)->get_double_value () / 300, 1);
};


struct nat_src_side_bas_cpp_1_struct : public NativeExpressionAction {
	nat_src_side_bas_cpp_1_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * wi1;
	AbstractProperty * x_state;
};

void
nat_src_side_bas_cpp_1_struct::impl_activate ()
{
	wi1->set_value(((AbstractProperty*)wi1)->get_double_value () + (((AbstractProperty*)x_state)->get_double_value ()), 1);
};


struct nat_src_side_bas_cpp_2_struct : public NativeExpressionAction {
	nat_src_side_bas_cpp_2_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * fc_r;
	AbstractProperty * fc_g;
	AbstractProperty * x_state;
};

void
nat_src_side_bas_cpp_2_struct::impl_activate ()
{
	fc_r->set_value(((AbstractProperty*)fc_g)->get_double_value () + (((AbstractProperty*)x_state)->get_double_value () * 4), 1);
};

ParentProcess*
side_bas (ParentProcess *p, const string &n, double d_var_0, double d_var_1)
{
	auto* cpnt_0 = new Component (p, n);
	auto* cpnt_1 = new FillColor (cpnt_0, "fill", 0, 255, 0);
	auto* cpnt_2 = new FillOpacity (cpnt_0, "fo", 1);
	auto* cpnt_3 = new FillColor (cpnt_0, "fc", 100, 100, 100);
	auto* cpnt_4 = new Rectangle (cpnt_0, "r", d_var_0, d_var_1, 100, 50, 0, 0);
	auto* cpnt_5 = new LogPrinter (cpnt_0, "lp", "valeur de l'incrément : ");
	alias (cpnt_0, "col", dynamic_cast<FatChildProcess*>(cpnt_2->find_child ("a")));
	auto *cpnt_6 = cpnt_0->find_child ( "col");
	alias (cpnt_0, "wi1", dynamic_cast<FatChildProcess*>(cpnt_4->find_child ("width")));
	auto *cpnt_7 = cpnt_0->find_child ( "wi1");
	auto* cpnt_8 = new FSM (nullptr, "rect");
	auto* cpnt_9 = new FSMState (cpnt_8, "idle");
	auto* cpnt_10 = new FSMState (cpnt_8, "level1");
	auto* cpnt_11 = new Timer (cpnt_10, "t", 5000);
	auto* cpnt_12 = new Clock (cpnt_10, "sec", 500);
	auto* cpnt_13 = new Incr (cpnt_10, "x", 1);
	new Binding (cpnt_10, "", cpnt_12->find_child ("tick"), ACTIVATION, cpnt_13, ACTIVATION);
	auto *cpnt_14 = new nat_src_side_bas_cpp_0_struct (cpnt_10, "", true, 0);
	if (cpnt_6->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_6, "is not a property\n");
		exit(0);
	}
		cpnt_14->col = dynamic_cast<AbstractProperty*>(cpnt_6);
	AbstractProperty* cpnt_15 = dynamic_cast<AbstractProperty*> (cpnt_13->find_child ("state"));
	if (cpnt_13->find_child ("state")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_13->find_child ("state"), "is not a property\n");
		exit(0);
	}
		cpnt_14->x_state= cpnt_15;
	cpnt_14->finalize_construction (cpnt_10, "");
	Synchronizer* cpnt_16 = new Synchronizer (cpnt_10, "sync_cpnt_16", cpnt_14, ""); //FIXME remove Synchronizer
	cpnt_16->add_source (cpnt_6, "");
	cpnt_16->add_source (cpnt_15, "");
	cpnt_16->add_native_edge (cpnt_14,cpnt_6);
	auto *cpnt_17 = new nat_src_side_bas_cpp_1_struct (cpnt_10, "", true, 0);
	if (cpnt_7->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_7, "is not a property\n");
		exit(0);
	}
		cpnt_17->wi1 = dynamic_cast<AbstractProperty*>(cpnt_7);
	AbstractProperty* cpnt_18 = dynamic_cast<AbstractProperty*> (cpnt_13->find_child ("state"));
	if (cpnt_13->find_child ("state")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_13->find_child ("state"), "is not a property\n");
		exit(0);
	}
		cpnt_17->x_state= cpnt_18;
	cpnt_17->finalize_construction (cpnt_10, "");
	Synchronizer* cpnt_19 = new Synchronizer (cpnt_10, "sync_cpnt_19", cpnt_17, ""); //FIXME remove Synchronizer
	cpnt_19->add_source (cpnt_7, "");
	cpnt_19->add_source (cpnt_18, "");
	cpnt_19->add_native_edge (cpnt_17,cpnt_7);
	auto *cpnt_20 = new nat_src_side_bas_cpp_2_struct (cpnt_10, "", true, 0);
	AbstractProperty* cpnt_21 = dynamic_cast<AbstractProperty*> (cpnt_3->find_child ("g"));
	if (cpnt_3->find_child ("g")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_3->find_child ("g"), "is not a property\n");
		exit(0);
	}
		cpnt_20->fc_g= cpnt_21;
	AbstractProperty* cpnt_22 = dynamic_cast<AbstractProperty*> (cpnt_13->find_child ("state"));
	if (cpnt_13->find_child ("state")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_13->find_child ("state"), "is not a property\n");
		exit(0);
	}
		cpnt_20->x_state= cpnt_22;
	AbstractProperty* cpnt_23 = dynamic_cast<AbstractProperty*> (cpnt_3->find_child ("r"));
	if (cpnt_23->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_23, "is not a property\n");
		exit(0);
	}
		cpnt_20->fc_r = cpnt_23;
	cpnt_20->finalize_construction (cpnt_10, "");
	Synchronizer* cpnt_24 = new Synchronizer (cpnt_10, "sync_cpnt_24", cpnt_20, ""); //FIXME remove Synchronizer
	cpnt_24->add_source (cpnt_21, "");
	cpnt_24->add_source (cpnt_22, "");
	cpnt_24->add_native_edge (cpnt_20,cpnt_3->find_child ("r"));
	new Connector (cpnt_10, "", cpnt_13->find_child ("state"), cpnt_5->find_child ("input"), 1);
	new FSMTransition (cpnt_8, "", cpnt_9, cpnt_10, cpnt_4->find_child ("press"), "", nullptr, "");
	new FSMTransition (cpnt_8, "", cpnt_10, cpnt_9, cpnt_10->find_child ("t/end"), "", nullptr, "");
	cpnt_0->add_child (dynamic_cast<FatChildProcess*>(cpnt_8), "rect");
	return cpnt_0;
}
