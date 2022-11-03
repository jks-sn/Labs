//
// Created by User on 24.10.2022.
//
#pragma once
#include "Life_Core.h"
class interface {
public:
    virtual void interface_() = 0;
};

class interface_online : public interface {
public:
    void interface_() override;
};

class interface_offline : public interface {
public:;
    void interface_() override;
};