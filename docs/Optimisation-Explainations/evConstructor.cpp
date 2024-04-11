class Event{
        public:
            Event() :type(0), category(0), handled(false){}
            Event(int ptype, int pcategory, int pkeycode) :type(ptype), category(pcategory) {
                data.keyRelease.keyCode = pkeycode;
                //exists = true;
            }
            Event(int ptype, int pcategory, int pkeycode, bool pisrepeat) :type(ptype), category(pcategory) {
                data.keyPress.keyCode = pkeycode;
                data.keyPress.isRepeat = pisrepeat;
                //exists = true;
            }
            int type;
            int category;
            //bool exists = false;
            bool handled = false;
            union 
            {
                struct {
                    int keyCode;
                } keyRelease;
                struct {
                    int keyCode;
                    bool isRepeat;
                } keyPress;
            } data;

};


//DAddKeyPressEvent modifies the 

void DAddKeyPressEvent(Event queue[], int keycode, bool repeat, int& tail){
    queue[tail].data.keyPress.keyCode = keycode;
    queue[tail].category = 4;
    queue[tail].data.keyPress.isRepeat = repeat;
    queue[tail].type = 0;
    tail = (tail +1 ) % 255;
}
void CAddKeyPressEvent(Event queue[], int keycode, bool repeat, int& tail){
    queue[tail] = Event(0, 4, keycode, repeat);
    tail = (tail +1 ) % 255;
}

int main(){
    Event queue[255];
    int tail = 0;
    CAddKeyPressEvent(queue, 4, false, tail);
    DAddKeyPressEvent(queue, 4, false, tail);
    return 0;
}