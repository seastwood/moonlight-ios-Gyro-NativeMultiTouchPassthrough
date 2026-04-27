//
//  KeyboardSupport.h
//  Moonlight
//
//  Created by Diego Waxemberg on 8/25/18.
//  Copyright © 2018 Moonlight Game Streaming Project. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MOUSE_BUTTON_LEFT BUTTON_LEFT
#define MOUSE_BUTTON_RIGHT BUTTON_RIGHT
#define MOUSE_BUTTON_MIDDLE BUTTON_MIDDLE
#define MOUSE_BUTTON_X1 BUTTON_X1
#define MOUSE_BUTTON_X2 BUTTON_X2

#define TOUCH_EVENT_HOVER 0x00
#define TOUCH_EVENT_DOWN 0x01
#define TOUCH_EVENT_UP 0x02
#define TOUCH_EVENT_MOVE 0x03
#define TOUCH_EVENT_CANCEL 0x04
#define TOUCH_EVENT_BUTTON_ONLY 0x05

@interface KeyboardSupport : NSObject

struct KeyEvent {
    u_short keycode;
    u_short modifierKeycode;
    u_char modifier;
};

+ (BOOL)sendKeyEventForPress:(UIPress*)press down:(BOOL)down API_AVAILABLE(ios(13.4));
+ (BOOL)sendKeyEvent:(UIKey*)key down:(BOOL)down API_AVAILABLE(ios(13.4));
+ (struct KeyEvent) translateKeyEvent:(unichar) inputChar withModifierFlags:(UIKeyModifierFlags)modifierFlags;
+ (void)sendMouseButtonEvent:(int)button down:(BOOL)down;
+ (void)sendMouseWheelEvent:(short)deltaY deltaX:(short)deltaX;
+ (void)sendMousePositionEvent:(short)x y:(short)y width:(short)width height:(short)height;
+ (void)sendTouchEvent:(int)eventType x:(short)x y:(short)y pointerId:(int)pointerId pressure:(float)pressure contactAreaMajor:(float)contactAreaMajor contactAreaMinor:(float)contactAreaMinor rotation:(float)rotation;

@end
