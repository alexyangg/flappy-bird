#include "StateMachine.hpp"

namespace MySFMLEngine {
	void StateMachine::AddState(StateRef newState, bool isReplacing) {
		this->_isAdding = true;
		this->_isReplacing = isReplacing;

		// Transfer ownership of newState to _newState
		// Since StateRef is a unique_ptr, we have to use std::move
		this->_newState = std::move(newState);
	}

	void StateMachine::RemoveState() {
		this->_isRemoving = true;
	}

	void StateMachine::ProcessStateChanges() {
		if (this->_isRemoving && !this->_states.empty()) {
			this->_states.pop();
			
			// if there are still states left, resume the next one
			if (!this->_states.empty()) {
				this->_states.top()->Resume();
			}
			this->_isRemoving = false; // stop removing states
		}

		if (this->_isAdding) {
			if (this->_isReplacing && !this->_states.empty()) {
				this->_states.pop(); // remove the current state
			}
			if (!this->_states.empty()) {
				this->_states.top()->Pause();
			}

			// Add the new state to the stack
			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();
			this->_isAdding = false;
		}
	}

	StateRef& StateMachine::GetActiveState() {
		return this->_states.top();
	}
}
