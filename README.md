# hub
Smart Home Hub; final project for training in Experis Academy

Smart Home Hub - instructions

- Agents will inherit from AgentInterfaceForHub, defined in inc/agent_interface_for_hub.hpp. For convenience, an abstract base class "Agent" is provided, defined in inc/agent.hpp.
- Agents will be compiled individually as dynamic libraries (.SO) and the .out file will be linked with them.
- The libraries will be named "< Agent type >.SO".
- A library will include a function named "Create< Agent type >" that receives the CtorArgs class (defined in inc/ctorArgs.hpp) as its parameter and returns a pointer to a new AgentInterfaceForHub object.
This function will be declared under 'extern "C" '.
- Subscribing to channels can be done in the construction stage, either hard coded or by utilizing the "config" field in the .ini file, or during runtime in response to an Event.
- The .ini file has a blank row with just a single space at the end. Please keep it there.

Use the demo files as examples of how you can implement your own Agents. In the demo directory, you will find header and source files for three concrete Agent classes:
- Thermostat - simulates a sensor, i.e. an agent that only generates and sends events and never receives any.
- Light - simulates a controller, i.e. an agent that only receives events and never generates any.
- AC - simulates both, i.e. an agent that generates and sends, as well as receives, events.

The demo_test shows system start-up, followed by an Event being sent by a Thermostat agent.
In response to receiving the Event, the AC agent generates its own event, which is ultimately received by the Light agent.
To exit the demo, use ctrl+C.
