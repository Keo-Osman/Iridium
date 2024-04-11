#pragma once
#include "irpch.h"
#include "EventDefines.h"
namespace Ird{
        class Event{
        public:
            //Empty Initailize
            Event() :type(EVENT_TYPE::None), category(EVENT_CATEGORY::None), handled(false){}

            //Key Press
            Event(u16 ptype, u16 pcategory, u16 pkeycode, bool pisrepeat) :type(ptype), category(pcategory) {
                data.keyPress.keyCode = pkeycode;
                data.keyPress.isRepeat = pisrepeat;
            }
            //Key Release and Mouse Press/Release
            Event(u16 ptype, u16 pcategory, u16 pcode) :type(ptype), category(pcategory) {
                switch(ptype){
                    case EVENT_TYPE::KeyReleased:
                        data.keyRelease.keyCode = pcode;
                        break;
                    //Defalut will be a mouse event
                    default:
                        data.mouseButton.mouseCode = pcode;
                }
            }

            //Mouse Move/Scroll
            Event(u16 ptype, u16 pcategory, f32 px, f32 py) :type(ptype), category(pcategory) {
                data.mousePos.x = px;
                data.mousePos.y = py;
            }
            u16 type = EVENT_TYPE::None;
            u16 category = EVENT_CATEGORY::None;
            bool handled = false;


            //TODO - make union events same size to get more info for smaller events as the space is taken up anyway
            //Possibly optimise mouseScroll fo f16? not sure
            //Data size: 64 bits / 8 bytes
            union 
            {
                //Key Events
                struct {
                    u16 keyCode;
                } keyRelease;
                struct {
                    u16 keyCode;
                    bool isRepeat;
                } keyPress;

                //Mouse Events
                //Scroll or move
                struct{
                    f32 x;
                    f32 y;
                } mousePos;
                //Don't need seperate release or press events as there is no repeat
                //Can distinguish by event type
                struct {
                    u16 mouseCode;
                } mouseButton;
            } data;
        };


        namespace evQueue{
            //Events will be inserted at the tail and handled at the head
            constexpr u8 SIZE = 255;
            extern Event queue[SIZE];
            extern u8 head;
            extern u8 tail;
            //Reciever of Handle can directly access Event queue with head and then go on for the number of Events
            struct Handle{
                u8 numOfEvents;
                u8 head;
            };
            Handle GetNextEvents();

            //Add Events
            //Key
            void AddKeyPressEvent(u16 keycode, bool repeat);
            void AddKeyReleaseEvent(u16 keycode);
            //Mouse
            void AddMousePressEvent(u16 mousecode);
            void AddMouseReleaseEvent(u16 mousecode);
            void AddMouseMoveEvent(f32 x, f32 y);
            void AddMouseScrollEvent(f32 x, f32 y);


            //Debug function
            void Flush();
        }

}
