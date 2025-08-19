#pragma once

#include <memory>
#include <stack>

// Use quotes for local headers instead of angle brackets
#include "State.hpp"

namespace MySFMLEngine {
	typedef std::unique_ptr<State> StateRef;

	class StateMachine {
	public:
		StateMachine() {}
		~StateMachine() {}

		void AddState(StateRef newState, bool isReplacing=true);
		void RemoveState(); // remove top state on stack

		void ProcessStateChanges(); // runs at start of game loop

		StateRef& GetActiveState();

	private:
		std::stack<StateRef> _states; // all states currently on the stack
		StateRef _newState;

		bool _isAdding;
		bool _isRemoving;
		bool _isReplacing;
	};
}
