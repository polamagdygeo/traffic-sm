
typedef enum{
    STATE_RED,
    STATE_YELLOW,
    STATE_GREEN,
    STATE_NO
}tState;

typedef enum{
    TRANSITION_RED_TIMEOUT,
    TRANSITION_YELLOW_TIMEOUT,
    TRANSITION_GREEN_TIMEOUT,
    TRANSITION_NO
}tTransition;

typedef enum{
    COMMAND_DO,
    //entry and exit to avoid calling them in all related transitions (a state can be entered from more than on transition)
    COMMAND_ENTRY,
    COMMAND_EXIT
}tCommand;

static tState current_state = STATE_RED;
static tState next_state = STATE_NO;
static tTransition current_transition = TRANSITION_NO;
static void redState(tCommand command);
static void yellowState(tCommand command);
static void greenState(tCommand command);
static void procState(tState state,tCommand command);
static void procTransition(void);

void redState(tCommand command)
{
    switch(command)
    {
        case COMMAND_DO:
        /*if timeout set next state and transition*/
        break;
        case COMMAND_ENTRY:
        break;
        case COMMAND_EXIT:
        break;
        default:
        break;
    }
}

void yellowState(tCommand command)
{
    switch(command)
    {
        case COMMAND_DO:
        /*if timeout set next state and transition*/
        break;
        case COMMAND_ENTRY:
        break;
        case COMMAND_EXIT:
        break;
        default:
        break;
    }
}

void greenState(tCommand command)
{
    switch(command)
    {
        case COMMAND_DO:
        /*if timeout set next state and transition*/
        break;
        case COMMAND_ENTRY:
        break;
        case COMMAND_EXIT:
        break;
        default:
        break;
    }
}

void procState(tState state,tCommand command)
{
    switch(state)
    {
        case STATE_RED:
        redState(command);
        break;
        case STATE_YELLOW:
        yellowState(command);
        break;
        case STATE_GREEN:
        greenState(command);
        break;
        default:
        break;
    }
}

void procTransition(void)
{
    switch(current_transition)
    {
        case TRANSITION_RED_TIMEOUT:
        /*red off yellow on*/
        break;
        case TRANSITION_YELLOW_TIMEOUT:
        /*yellow off green on*/
        break;
        case TRANSITION_GREEN_TIMEOUT:
        /*green off red on*/
        break;
        default:
        break;
    }
}

void run_traffic_light_sm(void)
{
    current_transition = TRANSITION_NO;
    next_state = STATE_NO;

    //call do behavior of the current state
    procState(current_state,COMMAND_DO);

    //check if there's transition and do associated action
    //transitions not always come with state change (same state transition)
    if(current_transition != TRANSITION_NO)
    {
        procTransition();
    }

    //check if there's new state and call exit and entry behaviors and change to new state
    if(next_state != STATE_NO)
    {
        procState(current_state,COMMAND_EXIT);
        procState(next_state,COMMAND_ENTRY);
        current_state = next_state;
    }
}
