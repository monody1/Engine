/**
 * Copyright (c) 2020, chen.zr. All rights reserved.
 *
 * @author chen.zr
 * @date 2020-09-22
 */

#ifndef __SCENEOBJECT_HPP__
#define __SCENEOBJECT_HPP__

#include <crossguid/guid.hpp>
#include <iostream>
#include <vector>
#include "Portable.hpp"

namespace engine
{
    namespace details
    {
        constexpr int32_t i32(const char *s, int32_t v)
        {
            return *s ? i32(s + 1, v * 256 + *s) : v;
        }
    } // namespace details

    constexpr int32_t operator"" _i32(const char *s, size_t)
    {
        return details::i32(s, 0);
    }

    ENUM(SceneObjectType){
        kSceneObjectTypeMesh = "MESH"_i32,
        kSceneObjectTypeMaterial = "MATL"_i32,
        kSceneObjectTypeTexture = "TXTU"_i32,
        kSceneObjectTypeLight = "LGHT"_i32,
        kSceneObjectTypeCamera = "CAMR"_i32,
        kSceneObjectTypeAnimator = "ANIM"_i32,
        kSceneObjectTypeClip = "CLIP"_i32,
    };

    std::ostream& operator<<(std::ostream& out, SceneObjectType type)
    {
        int32_t n = static_cast<int32_t>(type);
        n = endian_net_unsigned_int<int32_t>(n);
        char* c = reinterpret_cast<char*>(&n);
        for (int i = 0; i < sizeof(int32_t); i++) {
            out << *c++;
        }
        return out;
    }

    using namespace xg;

    class BaseSceneObject
    {

    private:
        // no default constructor
        BaseSceneObject() = delete;
        // can not be copied
        BaseSceneObject(BaseSceneObject &obj) = delete;
        BaseSceneObject &operator=(BaseSceneObject &obj) = delete;

    protected:
        Guid m_guid;
        SceneObjectType m_type;

        BaseSceneObject(SceneObjectType type): m_type(type){
            m_guid = newGuid(); 
        };

        BaseSceneObject(Guid &guid, SceneObjectType type):
        m_guid(guid), m_type(type){};
        //guid move constructor
        BaseSceneObject(Guid &&guid, SceneObjectType type):
        m_guid(std::move(guid)), m_type(type){};
        //obj move constructor
        BaseSceneObject(BaseSceneObject &&obj):
        m_guid(std::move(obj.m_guid)), m_type(obj.m_type){};

        BaseSceneObject &operator=(BaseSceneObject &&obj){
            this -> m_guid = std::move(obj.m_guid);
            this -> m_type = obj.m_type;
            return *this;
        }

    public:
        const Guid& GetGuid() const{
            return m_guid;
        };
        ~BaseSceneObject();


        friend std::ostream &operator<<(
            std::ostream &out,
            const BaseSceneObject &obj
        ){
            out << "SceneObject" << std::endl;
            out << "-----------" << std::endl;
            out << "GUID: " << obj.m_guid << std::endl;
            out << "Type: " << obj.m_type << std::endl;
            return out;
        };
    };

    ENUM(VertexDataType){
        kVertexDataTypeFloat = "FLOT"_i32,
        kVertexDataTypeDouble = "DOUB"_i32
    };

    class SenceObjectVertexArray: public BaseSceneObject{
        protected:
            VertexDataType m_dataType;
            std::string    m_attribute;
            uint32_t       m_morphTargetIndex;

            union{
                float* m_pDataFloat;
                double* m_pDataDouble;
            };
            size_t m_szData;
    };
    //Generally, vertex is a structor include a few of attributes data, such as,
    //position, normal, tangent, color, uv.

    //AOS 
    //SOA //28

    ENUM(IndexDataType){
        kIndexDataTypeInt16 = "_I16"_i32,
        kIndexDataTypeInt32 = "_I32"_i32
    };

    class SenceObjectIndexArray: public BaseSceneObject{
        protected:
            uint32_t m_materialsIndex;
            size_t m_restartIndex;
            IndexDataType m_dataType;

            union{
                uint16_t* m_pDataI16;
                uint32_t* m_pDataI32;
            };
    };

    class SenceObjectMesh: public BaseSceneObject{
        protected:
            std::vector<SenceObjectVertexArray> m_vertexArray;
            std::vector<SenceObjectIndexArray> m_indexArray;

            bool m_bVisiable = true;
            bool m_bShadow = false;
            bool m_bMotionBlur = false;
        public:
            SenceObjectMesh(): 
            BaseSceneObject(SceneObjectType::kSceneObjectTypeMesh){};
    };

    class SenceObjectMaterials: public BaseSceneObject{
        protected:
            
        public:
    };
} // namespace engine

#endif