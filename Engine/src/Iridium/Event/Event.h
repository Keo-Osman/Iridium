#pragma once
#include "irpch.h"
#include "EventDefines.h"
namespace Ird{
        class Event{
        public:
            Event() :type(EVENT_TYPE::_None), category(EVENT_CATEGORY::_EventCategoryNone), handled(false){}
            Event(EVENT_TYPE ptype, EVENT_CATEGORY pcategory, u16 pkeycode) :type(ptype), category(pcategory) {
                data.keyRelease.keyCode = pkeycode;
                //exists = true;
            }
            Event(EVENT_TYPE ptype, EVENT_CATEGORY pcategory, u16 pkeycode, bool pisrepeat) :type(ptype), category(pcategory) {
                data.keyPress.keyCode = pkeycode;
                data.keyPress.isRepeat = pisrepeat;
                //exists = true;
            }
            EVENT_TYPE type = EVENT_TYPE::_None;
            EVENT_CATEGORY category = EVENT_CATEGORY::_EventCategoryNone;
            //bool exists = false;
            bool handled = false;
            union 
            {
                struct {
                    u16 keyCode;
                } keyRelease;
                struct {
                    u16 keyCode;
                    bool isRepeat;
                } keyPress;
            } data;

        };


        namespace Queue{
            //Events will be inserted at the tail and handled at the head
            constexpr u8 SIZE = 255;
            extern Event evQueue[SIZE];
            extern u8 head;
            extern u8 tail;
            extern Event emptyEvent;
            //returns true if there are unhandled events
            //bool UnhandledEvents();
            Event* GetNextEvent();
            void ResetEvent(Event*);
            //void init();
            //Add Events
            void AddKeyPressEvent(u16 keycode, bool repeat);
            void AddKeyReleaseEvent(u16 keycode);

            //Debug function
            void Flush();
        }

}
