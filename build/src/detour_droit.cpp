#include "gui/shape/circle.h"
#include "core/tree/component.h"
#include "base/connector.h"
#include "base/fsm.h"
#include "base/fsm.h"
#include "gui/style/color.h"
#include "gui/shape/line.h"
#include "gui/style/color.h"
#include "gui/style/gen/outline_width.h"
#include "core/tree/spike.h"

#include "core/utils/error.h" // for Context class
#undef error // avoid name clash with error macro and possible following #include
#undef warning // avoid name clash with error macro and possible following #include

using namespace djnn;

#include "core/core-dev.h"
#include "display/display-dev.h"
#include "gui/gui-dev.h"
#include "base/base-dev.h"
ParentProcess*
detour_droit (ParentProcess *p, const string &n, djnn::CoreProcess* cpnt_0, double d_var_0, double d_var_1, double d_var_2, double d_var_3, double d_var_4, double d_var_5, double d_var_6, double d_var_7)
{
	auto* cpnt_1 = new Component (p, n);
	auto* cpnt_2 = new Spike (cpnt_1, "pressed");
	auto* cpnt_3 = new FillColor (cpnt_1, "fill", 0, 0, 255);
	auto* cpnt_4 = new Circle (cpnt_1, "cercle_1", d_var_0, d_var_1, 15);
	auto* cpnt_5 = new Circle (cpnt_1, "cercle_2", d_var_2, d_var_3, 15);
	auto* cpnt_6 = new Circle (cpnt_1, "cercle_3", d_var_4, d_var_5, 15);
	auto* cpnt_7 = new Circle (cpnt_1, "cercle_4", d_var_6, d_var_7, 15);
	auto* cpnt_8 = new OutlineWidth (cpnt_1, "_", 5);
	auto* cpnt_9 = new OutlineColor (cpnt_1, "_", 255, 0, 0);
	auto* cpnt_10 = new Line (cpnt_1, "myline_1", 0, 0, 0, 0);
	auto* cpnt_11 = new Line (cpnt_1, "myline_2", 0, 0, 0, 0);
	auto* cpnt_12 = new Line (cpnt_1, "myline_3", 0, 0, 0, 0);
	new Connector (cpnt_1, "", cpnt_4->find_child ("cx"), cpnt_10->find_child ("x1"), 1);
	new Connector (cpnt_1, "", cpnt_4->find_child ("cy"), cpnt_10->find_child ("y1"), 1);
	new Connector (cpnt_1, "", cpnt_5->find_child ("cx"), cpnt_10->find_child ("x2"), 1);
	new Connector (cpnt_1, "", cpnt_5->find_child ("cy"), cpnt_10->find_child ("y2"), 1);
	new Connector (cpnt_1, "", cpnt_5->find_child ("cx"), cpnt_11->find_child ("x1"), 1);
	new Connector (cpnt_1, "", cpnt_5->find_child ("cy"), cpnt_11->find_child ("y1"), 1);
	new Connector (cpnt_1, "", cpnt_6->find_child ("cx"), cpnt_11->find_child ("x2"), 1);
	new Connector (cpnt_1, "", cpnt_6->find_child ("cy"), cpnt_11->find_child ("y2"), 1);
	new Connector (cpnt_1, "", cpnt_6->find_child ("cx"), cpnt_12->find_child ("x1"), 1);
	new Connector (cpnt_1, "", cpnt_6->find_child ("cy"), cpnt_12->find_child ("y1"), 1);
	new Connector (cpnt_1, "", cpnt_7->find_child ("cx"), cpnt_12->find_child ("x2"), 1);
	new Connector (cpnt_1, "", cpnt_7->find_child ("cy"), cpnt_12->find_child ("y2"), 1);
	auto* cpnt_13 = new Spike (cpnt_1, "touch");
	auto* cpnt_14 = new FSM (nullptr, "touch_detour");
	auto* cpnt_15 = new FSMState (cpnt_14, "idle");
	auto* cpnt_16 = new FSMState (cpnt_14, "active");
	new FSMTransition (cpnt_14, "", cpnt_15, cpnt_16, cpnt_4->find_child ("press"), "", cpnt_2, "");
	new FSMTransition (cpnt_14, "", cpnt_16, cpnt_15, cpnt_4->find_child ("release"), "", nullptr, "");
	new FSMTransition (cpnt_14, "", cpnt_15, cpnt_16, cpnt_5->find_child ("press"), "", nullptr, "");
	new FSMTransition (cpnt_14, "", cpnt_16, cpnt_15, cpnt_5->find_child ("release"), "", nullptr, "");
	new FSMTransition (cpnt_14, "", cpnt_15, cpnt_16, cpnt_6->find_child ("press"), "", nullptr, "");
	new FSMTransition (cpnt_14, "", cpnt_16, cpnt_15, cpnt_6->find_child ("release"), "", nullptr, "");
	new FSMTransition (cpnt_14, "", cpnt_15, cpnt_16, cpnt_7->find_child ("press"), "", nullptr, "");
	new FSMTransition (cpnt_14, "", cpnt_16, cpnt_15, cpnt_7->find_child ("release"), "", nullptr, "");
	new FSMTransition (cpnt_14, "", cpnt_15, cpnt_16, cpnt_10->find_child ("press"), "", nullptr, "");
	new FSMTransition (cpnt_14, "", cpnt_16, cpnt_15, cpnt_10->find_child ("release"), "", nullptr, "");
	new FSMTransition (cpnt_14, "", cpnt_15, cpnt_16, cpnt_11->find_child ("press"), "", nullptr, "");
	new FSMTransition (cpnt_14, "", cpnt_16, cpnt_15, cpnt_11->find_child ("release"), "", nullptr, "");
	new FSMTransition (cpnt_14, "", cpnt_15, cpnt_16, cpnt_12->find_child ("press"), "", nullptr, "");
	new FSMTransition (cpnt_14, "", cpnt_16, cpnt_15, cpnt_12->find_child ("release"), "", nullptr, "");
	cpnt_1->add_child (dynamic_cast<FatChildProcess*>(cpnt_14), "touch_detour");
	return cpnt_1;
}
