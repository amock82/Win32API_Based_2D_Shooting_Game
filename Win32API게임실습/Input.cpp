#include "framework.h"

//키입력 테스트하기
string Input::name[MAX_KEY] = { "left",   "right",  "up",   "down",  "space",   "z" , "F1", "", "", "" };
int Input::key[MAX_KEY]     = { VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_SPACE, 'Z', VK_F1, VK_LBUTTON, VK_RBUTTON, VK_MBUTTON };
int Input::state[MAX_KEY] = { keyUpRep, keyUpRep, keyUpRep,keyUpRep,keyUpRep ,keyUpRep, keyUpRep, keyUpRep, keyUpRep, keyUpRep };

MousePosition Input::mousePosition = { 0, 0 };

void Input::init()
{
}

void Input::update()
{
    //키입력 스테이트 머신//
    for (int i = 0; i < MAX_KEY ; i++)
    {
        if (state[i] == keyUpRep)
        {
            if (GetAsyncKeyState(key[i]) != 0)
            {
                state[i] = keyDown;
            }
            else {
                state[i] = keyUpRep;
            }
        }
        else if (state[i] == keyDown)
        {

            if (GetAsyncKeyState(key[i]) != 0)
            {
                state[i] = keyDownRep;
            }
            else {
                state[i] = keyUp;
            }
        }
        else if (state[i] == keyDownRep)
        {
            //cout << "키를  계속 누름" << endl;

            if (GetAsyncKeyState(key[i]) == 0)
            {
                state[i] = keyUp;
            }
            else {
                state[i] = keyDownRep;
            }
        }
        else if (state[i] == keyUp)
        {

            if (GetAsyncKeyState(key[i]) == 0)
            {
                state[i] = keyUpRep;
            }
            else {
                state[i] = keyDown;
            }
        }
    }
}

bool Input::getKey(string keyCode)
{
    for (int i = 0; i < MAX_KEY ; i++)
    {
        if (name[i] == keyCode)
        {
            if (state[i] == keyDownRep || state[i] == keyDown)
            {
                return true;
            }
            else {
                return false;
            }
        }
    }   
    
    return false;
}

bool Input::getKeyDown(string keyCode)
{
    for (int i = 0; i < MAX_KEY ; i++)
    {
        if (name[i] == keyCode)
        {
            if (state[i] == keyDown)
            {
                return true;
            }
            else {
                return false;
            }
        }
    }

    return false;
}

bool Input::getKeyUp(string keyCode)
{
    for (int i = 0; i < MAX_KEY ; i++)
    {
        if (name[i] == keyCode)
        {
            if (state[i] == keyUp)
            {
                return true;
            }
            else {
                return false;
            }
        }
    }

    return false;
}

bool Input::getMouseButton(int button)
{
    if (state[button + 7] == keyDownRep || state[button + 7] == keyDown)
        return true;
    else
        return false;
}

bool Input::getMouseButtonDown(int button)
{
    if (state[button + 7] == keyDown)
        return true;
    else
        return false;
}

bool Input::getMouseButtonUp(int button)
{
    if (state[button + 7] == keyUp)
        return true;
    else
        return false;
}