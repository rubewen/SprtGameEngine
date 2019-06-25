#pragma once

class BaseSystem {

public:
    // virtuelle funksjoner KAN overskrives i klasser som arver av denne.
    // Hvis ikke bruker de denne som default:
    virtual void Update() {

    }
};