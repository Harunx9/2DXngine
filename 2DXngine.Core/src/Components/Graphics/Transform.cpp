#include "Transform.h"

Transform::Transform() :
    Component("TransformComponent"),
    _position(glm::vec2(0.f, 0.f)),
    _width(0.f),
    _height(0.f),
    _scale(1.f),
    _worldScale(1.f),
    _rotation(0.f),
    _worldRotation(0.f),
    _drawOrder(0)
{
}

Transform::Transform(glm::vec2 position, float width, float height) :
    Component("TransformComponent"),
    _position(position),
    _width(width),
    _height(height),
    _scale(1.f),
    _worldScale(1.f),
    _rotation(0.f),
    _worldRotation(0.f),
    _drawOrder(0)
{
}


Transform::~Transform()
{
}

void Transform::initialize(bool force)
{
    _flag = DirtyFlag::All;
}

void Transform::terminate()
{
    this->_parentTransform = nullptr;
}

void Transform::resolveDependencies(bool force)
{
    if (force == false && this->_parentTransform) return;

    if (this->_owner->get_parent())
    {
        this->_parentTransform =
            this->_owner
            ->get_parent()
            ->findFirstComponentOfType<Transform>();
    }
}

float Transform::get_x() const
{
    return this->_position.x;
}

float Transform::get_y() const
{
    return this->_position.y;
}

void Transform::set_x(float x)
{
    this->_position.x = x;
    localTransformBecomeDirty();
    worldTransformBecomeDirty();
}

void Transform::set_y(float y)
{
    this->_position.y = y;
    localTransformBecomeDirty();
    worldTransformBecomeDirty();
}

glm::vec2 Transform::get_position() const
{
    return this->_position;
}

void Transform::set_position(glm::vec2 position)
{
    this->_position = position;
    localTransformBecomeDirty();
    worldTransformBecomeDirty();
}

glm::vec2 Transform::get_worldPosition() const
{

    return glm::vec2(this->_worldTranslation.x, this->_worldTranslation.y);
}

glm::vec2 Transform::get_worldScale() const
{
    return glm::vec2(this->_worldTranslation.x, this->_worldTranslation.y);;
}

float Transform::get_worldRotation() const
{
    return this->_worldRotation;
}

float Transform::get_width() const
{
    return this->_width;
}

float Transform::get_heihgt() const
{
    return this->_height;
}

void Transform::set_width(float width)
{
    this->_width = width;
}

void Transform::set_height(float height)
{
    this->_height = height;
}

float Transform::get_rotation() const
{
    return this->_rotation;
}

void Transform::set_rotation(float rotation)
{
    this->_rotation = rotation;
    localTransformBecomeDirty();
    worldTransformBecomeDirty();
}

float Transform::get_drawOrder() const
{
    return this->_drawOrder;
}

void Transform::set_drawOrder(float drawOrder)
{
    this->_drawOrder = drawOrder;
    auto handler = DrawOrderChanged;
    if (handler.isUsed())
    {
        handler(EventArgs());
    }
}

glm::vec2 Transform::get_origin() const
{
    return this->_origin;
}

void Transform::set_origin(glm::vec2 origin)
{
    this->_origin = origin;
    localTransformBecomeDirty();
    worldTransformBecomeDirty();
}

float Transform::get_scale() const
{
    return this->_scale;
}

void Transform::set_scale(float scale)
{
    this->_scale = scale;
    localTransformBecomeDirty();
    worldTransformBecomeDirty();
}

glm::mat4 Transform::get_worldMatrix() const
{
    return this->_worldMatrix;
}

glm::mat4 Transform::get_localMatrix() const
{
    return this->_localMatrix;
}

void Transform::recalculateWorldMatrixIfDirty()
{
    if ((static_cast<int>(this->_flag) & static_cast<int>(DirtyFlag::World)) == 0)
        return;

    recalculateLocalMatrixIfDirty();

    if (this->_parentTransform)
    {
        auto parentWorld = _parentTransform->get_worldMatrix();
        this->_worldMatrix = parentWorld * this->_localMatrix;
    }
    else
    {
        this->_worldMatrix = this->_localMatrix;
    }

    this->_flag = (DirtyFlag)(static_cast<int>(this->_flag) & ~static_cast<int>(DirtyFlag::World));
    auto handler = TransformUpdated;

    glm::quat rot;
    glm::vec3 skew;
    glm::vec4 perspective;

    glm::decompose(this->_worldMatrix, this->_worldScale, rot, this->_worldTranslation, skew, perspective);
    this->_worldRotation = glm::length(rot);

    if (handler.isUsed())
    {
        handler(EventArgs());
    }

}

void Transform::recalculateLocalMatrixIfDirty()
{

    if ((static_cast<int>(this->_flag) & static_cast<int>(DirtyFlag::Local)) == 0)
        return;

    if (this->_parentTransform)
    {
        auto parentPos = this->_parentTransform->get_position();

        this->_localMatrix = glm::translate(glm::mat4(), -glm::vec3(parentPos, 0))*
            glm::scale(glm::mat4(), glm::vec3(this->_scale, this->_scale, this->_scale))*
            glm::rotate(glm::mat4(), -this->_rotation, glm::vec3(0.f, 0.f, 1.f))*
            glm::translate(glm::mat4(), glm::vec3(parentPos, 0))*
            glm::translate(glm::mat4(), glm::vec3(this->_position, 0));
    }
    else
    {
        this->_localMatrix = glm::scale(glm::mat4(), glm::vec3(this->_scale, this->_scale, this->_scale))*
            glm::rotate(glm::mat4(), -this->_rotation, glm::vec3(0.f, 0.f, 1.f))*
            glm::translate(glm::mat4(), glm::vec3(this->_position, 0));
    }

    this->_flag = (DirtyFlag)(static_cast<int>(this->_flag) & ~static_cast<int>(DirtyFlag::Local));
    worldTransformBecomeDirty();
}

void Transform::worldTransformBecomeDirty()
{
    this->_flag = (DirtyFlag)(static_cast<int>(this->_flag) | static_cast<int>(DirtyFlag::World));
    auto handler = TransformBecomeDirty;
    if (handler.isUsed())
    {
        handler(EventArgs());
    }
}

void Transform::localTransformBecomeDirty()
{
    this->_flag = (DirtyFlag)(static_cast<int>(this->_flag) | static_cast<int>(DirtyFlag::Local));
}


