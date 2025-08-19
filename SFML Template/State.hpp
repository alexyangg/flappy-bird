#pragma once

namespace MySFMLEngine {
	class State {
	public:
		virtual void Init() = 0; // = 0 means pure virtual function

		virtual void HandleInput() = 0;
		virtual void Update() = 0;
		virtual void Draw(float dt) = 0;

		virtual void Pause() {} // not pure virtual, has default implementation {}, can be overridden if needed
		virtual void Resume() {}
	};
}