#pragma once
#include "../../ComponentModel/GameObject.h"
#include "../../ComponentModel/Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include "../../Utils/Math/RectangleI.h"
#include "../../Utils/Events/EventHandler.h"

class Transform : public Component
{
public:
    ADD_TYPE_META_INFO()
        Transform();
    Transform(glm::vec2 position, float width, float height);
    ~Transform();

    // Inherited via Component
    virtual void initialize(bool force = false) override;
    virtual void terminate() override;
    virtual void resolveDependencies(bool force = false) override;

    float get_x() const;
    float get_y() const;
    void set_x(float x);
    void set_y(float y);

    glm::vec2 get_position() const;
    void set_position(glm::vec2 position);

    glm::vec2 get_worldPosition() const;
    glm::vec2 get_worldScale() const;
    float get_worldRotation() const;

    float get_width() const;
    float get_heihgt() const;
    void set_width(float width);
    void set_height(float height);

    float get_rotation()const;
    void set_rotation(float rotation);

    float get_drawOrder() const;
    void set_drawOrder(float drawOrder);

    glm::vec2 get_origin() const;
    void set_origin(glm::vec2 origin);

    float get_scale() const;
    void set_scale(float scale);

    glm::mat4 get_worldMatrix() const;
    glm::mat4 get_localMatrix() const;

    EventHandler DrawOrderChanged;
    EventHandler TransformBecomeDirty;
    EventHandler TransformUpdated;
private:
    enum DirtyFlag
    {
        World = 1 << 0,
        Local = 1 << 1,
        All = World | Local
    };

    DirtyFlag _flag;
    void recalculateWorldMatrixIfDirty();
    void recalculateLocalMatrixIfDirty();
    void worldTransformBecomeDirty();
    void localTransformBecomeDirty();

    glm::vec3 _worldScale;
    float _worldRotation;
    glm::vec3 _worldTranslation;
    glm::mat4 _localMatrix;
    glm::mat4 _worldMatrix;
    glm::vec2 _position;
    glm::vec2 _origin;
    float _rotation;
    float _width, _height;
    float _drawOrder;
    float _scale;
    Transform * _parentTransform;
};

