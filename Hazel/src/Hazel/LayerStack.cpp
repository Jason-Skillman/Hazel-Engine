#include "hzpch.h"
#include "LayerStack.h"

namespace Hazel {
	LayerStack::LayerStack() = default;
	
	LayerStack::~LayerStack() {
		for(Layer* layer : layers)
			delete layer;
	}
	
	void LayerStack::PushLayer(Layer* layer) {
		layers.emplace(layers.begin() + layerInsertIndex, layer);
		layerInsertIndex++;
	}
	
	void LayerStack::PushOverlay(Layer* overlay) {
		layers.emplace_back(overlay);
	}
	
	void LayerStack::PopLayer(Layer* layer) {
		auto it = std::find(layers.begin(), layers.end(), layer);
		if(it != layers.end()) {
			layers.erase(it);
			layerInsertIndex--;
		}
	}
	
	void LayerStack::PopOverlay(Layer* overlay) {
		auto it = std::find(layers.begin(), layers.end(), overlay);
		if(it != layers.end()) {
			layers.erase(it);
		}
	}
	
	std::vector<Layer*>::iterator LayerStack::begin() {
		return layers.begin();
	}
	
	std::vector<Layer*>::iterator LayerStack::end() {
		return layers.end();
	}
}
