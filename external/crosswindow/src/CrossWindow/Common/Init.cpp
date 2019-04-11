#include "Init.h"
#include "State.h"

namespace xwin
{

    XWinState xWinState;

    bool init(MainArgs)
    {
        xWinState = XWinState(MainArgsVars);
        return true;
    }

    const xwin::XWinState& getXWinState()
    {
        return xWinState;
    }
}
