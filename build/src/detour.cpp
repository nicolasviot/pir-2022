#include "core/tree/abstract_property.h"
#include "gui/shape/circle.h"
#include "core/tree/component.h"
#include "base/connector.h"
#include "base/fsm.h"
#include "base/fsm.h"
#include "gui/style/color.h"
#include "gui/shape/line.h"
#include "core/control/native_expression_action.h"
#include "gui/style/color.h"
#include "gui/style/gen/outline_width.h"
#include "gui/transformation/transformations.h"
#include "core/tree/spike.h"
#include "base/switch.h"
#include "core/control/synchronizer.h"
#include "core/tree/text_property.h"
#include "gui/transformation/translation.h"

#include "core/utils/error.h" // for Context class
#undef error // avoid name clash with error macro and possible following #include
#undef warning // avoid name clash with error macro and possible following #include

using namespace djnn;

#include "core/core-dev.h"
#include "display/display-dev.h"
#include "gui/gui-dev.h"
#include "base/base-dev.h"
#include "side.h"
#include "side_bas.h"
#include "side_bas_cycle.h"
#include "side_cycle.h"

struct nat_src_detour_cpp_0_struct : public NativeExpressionAction {
	nat_src_detour_cpp_0_struct (ParentProcess *p, const djnn::string &n, bool string_setter, bool isModel)
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
	AbstractProperty * anti_rot_a;
	AbstractProperty * rot_a;
};

void
nat_src_detour_cpp_0_struct::impl_activate ()
{
	anti_rot_a->set_value(- ((AbstractProperty*)rot_a)->get_double_value (), 1);
};

ParentProcess*
detour (ParentProcess *p, const string &n, const djnn::string& s_var_0)
{
	auto* cpnt_0 = new Component (p, n);
	auto* cpnt_1 = new Translation (cpnt_0, "t", 0, 0);
	auto* cpnt_2 = new Rotation (cpnt_0, "rot", 0, 0, 0);
	auto* cpnt_3 = new Spike (cpnt_0, "pressed");
	auto* cpnt_4 = new FillColor (cpnt_0, "fill", 0, 0, 255);
	auto* cpnt_5 = new Circle (cpnt_0, "cercle_1", 70, 0, 15);
	auto* cpnt_6 = new Circle (cpnt_0, "cercle_2", 30, - 40, 15);
	auto* cpnt_7 = new Circle (cpnt_0, "cercle_3", - 30, - 40, 15);
	auto* cpnt_8 = new Circle (cpnt_0, "cercle_4", - 70, 0, 15);
	auto* cpnt_9 = new OutlineWidth (cpnt_0, "_", 5);
	auto* cpnt_10 = new OutlineColor (cpnt_0, "_", 255, 0, 0);
	auto* cpnt_11 = new Line (cpnt_0, "myline_1", 0, 0, 0, 0);
	auto* cpnt_12 = new Line (cpnt_0, "myline_2", 0, 0, 0, 0);
	auto* cpnt_13 = new Line (cpnt_0, "myline_3", 0, 0, 0, 0);
	new Connector (cpnt_0, "", cpnt_5->find_child ("cx"), cpnt_11->find_child ("x1"), 1);
	new Connector (cpnt_0, "", cpnt_5->find_child ("cy"), cpnt_11->find_child ("y1"), 1);
	new Connector (cpnt_0, "", cpnt_6->find_child ("cx"), cpnt_11->find_child ("x2"), 1);
	new Connector (cpnt_0, "", cpnt_6->find_child ("cy"), cpnt_11->find_child ("y2"), 1);
	new Connector (cpnt_0, "", cpnt_6->find_child ("cx"), cpnt_12->find_child ("x1"), 1);
	new Connector (cpnt_0, "", cpnt_6->find_child ("cy"), cpnt_12->find_child ("y1"), 1);
	new Connector (cpnt_0, "", cpnt_7->find_child ("cx"), cpnt_12->find_child ("x2"), 1);
	new Connector (cpnt_0, "", cpnt_7->find_child ("cy"), cpnt_12->find_child ("y2"), 1);
	new Connector (cpnt_0, "", cpnt_7->find_child ("cx"), cpnt_13->find_child ("x1"), 1);
	new Connector (cpnt_0, "", cpnt_7->find_child ("cy"), cpnt_13->find_child ("y1"), 1);
	new Connector (cpnt_0, "", cpnt_8->find_child ("cx"), cpnt_13->find_child ("x2"), 1);
	new Connector (cpnt_0, "", cpnt_8->find_child ("cy"), cpnt_13->find_child ("y2"), 1);
	auto* cpnt_14 = new Rotation (cpnt_0, "anti_rot", 0, 0, 0);
	new Connector (cpnt_0, "", cpnt_2->find_child ("cx"), cpnt_14->find_child ("cx"), 1);
	new Connector (cpnt_0, "", cpnt_2->find_child ("cy"), cpnt_14->find_child ("cy"), 1);
	auto *cpnt_15 = new nat_src_detour_cpp_0_struct (cpnt_0, "", true, 0);
	AbstractProperty* cpnt_16 = dynamic_cast<AbstractProperty*> (cpnt_2->find_child ("a"));
	if (cpnt_2->find_child ("a")->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_2->find_child ("a"), "is not a property\n");
		exit(0);
	}
		cpnt_15->rot_a= cpnt_16;
	AbstractProperty* cpnt_17 = dynamic_cast<AbstractProperty*> (cpnt_14->find_child ("a"));
	if (cpnt_17->get_process_type() != PROPERTY_T) {
		djnn__error (cpnt_17, "is not a property\n");
		exit(0);
	}
		cpnt_15->anti_rot_a = cpnt_17;
	cpnt_15->finalize_construction (cpnt_0, "");
	Synchronizer* cpnt_18 = new Synchronizer (cpnt_0, "sync_cpnt_18", cpnt_15, ""); //FIXME remove Synchronizer
	cpnt_18->add_source (cpnt_16, "");
	cpnt_18->add_native_edge (cpnt_15,cpnt_14->find_child ("a"));
	auto* cpnt_19 = new Switch (nullptr, "which_side", "bas");
	auto* cpnt_20 = new Component (cpnt_19, "bas");
	auto* cpnt_21 = side_bas (cpnt_20, "myside", - 50, - 150);
	auto* cpnt_22 = side_bas_cycle (cpnt_20, "myside", 0, - 300);
	auto* cpnt_23 = new Component (cpnt_19, "haut");
	auto* cpnt_24 = side (cpnt_23, "myside", - 50, 100);
	auto* cpnt_25 = side_cycle (cpnt_23, "myside", 0, 250);
	cpnt_0->add_child (dynamic_cast<FatChildProcess*>(cpnt_19), "which_side");
	auto* cpnt_26 = new TextProperty (cpnt_0, "switch_status", s_var_0);
	new Connector (cpnt_0, "", cpnt_26, cpnt_19->find_child ("state"), 1);
	auto* cpnt_27 = new Spike (cpnt_0, "touch");
	auto* cpnt_28 = new FSM (nullptr, "touch_detour");
	auto* cpnt_29 = new FSMState (cpnt_28, "idle");
	auto* cpnt_30 = new FSMState (cpnt_28, "active");
	new FSMTransition (cpnt_28, "", cpnt_29, cpnt_30, cpnt_5->find_child ("press"), "", cpnt_3, "");
	new FSMTransition (cpnt_28, "", cpnt_30, cpnt_29, cpnt_5->find_child ("release"), "", nullptr, "");
	new FSMTransition (cpnt_28, "", cpnt_29, cpnt_30, cpnt_6->find_child ("press"), "", nullptr, "");
	new FSMTransition (cpnt_28, "", cpnt_30, cpnt_29, cpnt_6->find_child ("release"), "", nullptr, "");
	new FSMTransition (cpnt_28, "", cpnt_29, cpnt_30, cpnt_7->find_child ("press"), "", nullptr, "");
	new FSMTransition (cpnt_28, "", cpnt_30, cpnt_29, cpnt_7->find_child ("release"), "", nullptr, "");
	new FSMTransition (cpnt_28, "", cpnt_29, cpnt_30, cpnt_11->find_child ("press"), "", nullptr, "");
	new FSMTransition (cpnt_28, "", cpnt_30, cpnt_29, cpnt_11->find_child ("release"), "", nullptr, "");
	new FSMTransition (cpnt_28, "", cpnt_29, cpnt_30, cpnt_12->find_child ("press"), "", nullptr, "");
	new FSMTransition (cpnt_28, "", cpnt_30, cpnt_29, cpnt_12->find_child ("release"), "", nullptr, "");
	cpnt_0->add_child (dynamic_cast<FatChildProcess*>(cpnt_28), "touch_detour");
	return cpnt_0;
}
