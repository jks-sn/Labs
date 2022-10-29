//
// Created by User on 24.10.2022.
//
#pragma once
class interface
{
public:
    //virtual bool type_interface(int&) = 0;
    virtual void interface_(int&, char **) = 0;
};
class interface_online : public interface
{
public:
    //bool type_interface(int &argc) override;
    void interface_(int &argc, char *argv[]) override;
};
class interface_offline : public interface
{
public:
    //bool type_interface(int &argc) override;
    void interface_(int &argc, char *argv[]) override;
};