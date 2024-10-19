#pragma once
#include <vector>
#include <string>

using std::string;

class Charset
{
public:
    using listener = void(*)(int, int);
    void setListener(listener l);
    void processCharset(int pX, int pY, int padding, std::vector<std::vector<int>> &arr);
    void drawText(int pX, int pY, string text);
private:
    listener listenerFunc = nullptr;
    std::vector<std::vector<int>> char_double_points = { 
        {0, 1, 0},
        {0, 0, 0}, 
        {0, 0, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    std::vector<std::vector<int>> char_point = { 
        {0, 1, 0},
        {0, 0, 0}, 
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    std::vector<std::vector<int>> char_y = { 
        {0, 1, 0},
        {0, 1, 0}, 
        {0, 1, 0},
        {1, 0, 1},
        {1, 0, 1}
    };
    std::vector<std::vector<int>> char_x = { 
        {1, 0, 1},
        {1, 0, 1}, 
        {0, 1, 0},
        {1, 0, 1},
        {1, 0, 1}
    };
    std::vector<std::vector<int>> char_i = { 
        {0, 1, 0},
        {0, 1, 0}, 
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    std::vector<std::vector<int>> zero = { 
        {1, 1, 1},
        {1, 0, 1}, 
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    std::vector<std::vector<int>> one =
    { 
        {0, 1, 0},
        {0, 1, 0}, 
        {0, 1, 0},
        {1, 1, 0},
        {0, 1, 0},
    };
    std::vector<std::vector<int>> two =
    { 
        {1, 1, 1},
        {1, 0, 0}, 
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 0},
    };
    std::vector<std::vector<int>> three =
    { 
        {1, 1, 1},
        {0, 0, 1}, 
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
    };
    std::vector<std::vector<int>> four =
    { 
        {0, 0, 1},
        {0, 0, 1}, 
        {1, 1, 1},
        {1, 0, 1},
        {1, 0, 1},
    };
    std::vector<std::vector<int>> five =
    { 
        {1, 1, 1},
        {0, 0, 1}, 
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
    };
    std::vector<std::vector<int>> six =
    { 
        {1, 1, 1},
        {1, 0, 1}, 
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
    };
    std::vector<std::vector<int>> seven =
    { 
        {0, 1, 0},
        {0, 1, 0}, 
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
    };
    std::vector<std::vector<int>> eight =
    { 
        {1, 1, 1},
        {1, 0, 1}, 
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    };
    std::vector<std::vector<int>> nine =
    { 
        {1, 1, 1},
        {0, 0, 1}, 
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    };
};