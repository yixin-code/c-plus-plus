#pragma once

class ID
{
private:
    int m_id;
public:
    ID();
    ID(int id);
    int getId() const;
    ~ID();
};