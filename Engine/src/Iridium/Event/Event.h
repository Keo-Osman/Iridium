#pragma once
#include "irpch.h"
#include "EventDefines.h"
namespace Ird{
        class Event{
        public:
            //Empty Initailize
            Event() = default;

            //Window Close
            Event(u16 ptype, u16 pcategory) :type(ptype), category(pcategory) {}
             //Window Resize
            Event(u16 ptype, u16 pcategory, u16 pwidth, u16 pheight) :type(ptype), category(pcategory) {
                data.windowResize.width = pwidth;
                data.windowResize.height = pheight;
            }
            //Key Press
            Event(u16 ptype, u16 pcategory, u16 pkeycode, bool pisrepeat) :type(ptype), category(pcategory) {
                data.keyPress.keyCode = pkeycode;
                data.keyPress.isRepeat = pisrepeat;
            }
            //Key Release and Mouse Press/Release
            //Will change this in futre probably
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

                //Window Events
                struct{
                    u16 width;
                    u16 height;
                } windowResize;

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
            //Window
            void AddWindowCloseEvent();
            void AddWindowResizeEvent(u16 width, u16 height);


            //Debug function
            void Flush();
        }

}
