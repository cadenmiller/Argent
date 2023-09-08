#ifndef ARGENT_WINDOW_H
#define ARGENT_WINDOW_H

namespace Ar {

class Window {
public:

    virtual void SetTitle(const std::string& title);
    virtual void SetSize(glm::vec2 extent);

};

}; // namespace Ar

#endif // ARGENT_WINDOW_H