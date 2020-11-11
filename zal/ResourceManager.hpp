#pragma once

#include "Resource.hpp"

class ResourceManager
{
    private:
    Resource* resource;
    
public:
    ResourceManager(){
        this->resource = new Resource{};
    }
    
    ResourceManager(ResourceManager &rm2){
        this->resource = new Resource{*rm2.getResource()};
    }
    
    ResourceManager(ResourceManager &&rm2){
        this->resource = rm2.getResource();
        rm2.resource = nullptr;
    }
    
    ~ResourceManager(){
        delete resource;
    }
    
    ResourceManager& operator=( ResourceManager &rm2){
      
        if (this == &rm2) {
            return *this;
        }
        delete resource;
        this->resource = new Resource{*rm2.getResource()};

        return *this;
    }
    
    ResourceManager& operator=( ResourceManager &&rm2){
      
        if (this == &rm2) {
            return *this;
        }
        
        delete resource;
        this->resource = rm2.getResource();
        
        rm2.resource = nullptr;

        return *this;
    }
    
    double get(){
        return resource->get();
    }
    
    Resource* getResource(){
        return resource;
    }
};
