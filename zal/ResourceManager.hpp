#pragma once

#include "Resource.hpp"

class ResourceManager
{
    private:
    Resource* resource;
    
    public:
    ResourceManager(){
    this->resource=new Resource{};
    }
    ~ResourceManager(){
    delete resource;
    }
    double get(){
    return resource->get();
    }
};
