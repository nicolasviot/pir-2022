#include "gui/shape/circle.h"
#include "core/tree/component.h"
#include "base/connector.h"
#include "base/fsm.h"
#include "base/fsm.h"
#include "gui/style/color.h"

#include "core/utils/error.h" // for Context class
#undef error // avoid name clash with error macro and possible following #include
#undef warning // avoid name clash with error macro and possible following #include

using namespace djnn;

#include "core/core-dev.h"
#include "display/display-dev.h"
#include "gui/gui-dev.h"
#include "base/base-dev.h"
ParentProcess*
Bombe (ParentProcess *p, const string &n, djnn::CoreProcess* cpnt_0, double d_var_0, double d_var_1)
{
	auto* cpnt_1 = new Component (p, n);
	auto* cpnt_2 = new FillColor (cpnt_1, "fill", 255, 0, 0);
	auto* cpnt_3 = new Circle (cpnt_1, "cercle", d_var_0, d_var_1, 20);
	alias (cpnt_1, "x", dynamic_cast<FatChildProcess*>(cpnt_3->find_child ("cx")));
	auto *cpnt_4 = cpnt_1->find_child ( "x");
	alias (cpnt_1, "y", dynamic_cast<FatChildProcess*>(cpnt_3->find_child ("cy")));
	auto *cpnt_5 = cpnt_1->find_child ( "y");
	auto* cpnt_6 = new FSM (nullptr, "drag_Bombe");
	auto* cpnt_7 = new FSMState (cpnt_6, "idle");
	auto* cpnt_8 = new FSMState (cpnt_6, "moving");
	new Connector (cpnt_8, "", cpnt_0->find_child ("move/x"), cpnt_3->find_child ("cx"), 1);
	new Connector (cpnt_8, "", cpnt_0->find_child ("move/y"), cpnt_3->find_child ("cy"), 1);
	new FSMTransition (cpnt_6, "", cpnt_7, cpnt_8, cpnt_3->find_child ("press"), "", nullptr, "");
	new FSMTransition (cpnt_6, "", cpnt_8, cpnt_7, cpnt_3->find_child ("release"), "", nullptr, "");
	cpnt_1->add_child (dynamic_cast<FatChildProcess*>(cpnt_6), "drag_Bombe");
	return cpnt_1;
}
