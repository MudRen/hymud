/* suzhou.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

inherit ROOM;

void create()
{
    set( "short","肃州" );
    set( "long",@LONG
肃州，又称酒泉，地处河西走廊西部，在祁连山主峰之下，是嘉峪关西来的
第一个重镇，也是丝绸之路入玉门关后的第二大商业和贸易点，也是吐蕃、蒙古
等民族地区的交通要口，为历代兵家比争之地。据传西汉是大将霍去病把汉武帝
为表彰他的战功和赐给他的美酒倒在泉中与将士共享和得名“酒泉”。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : __DIR__"silk9",
        "east" : __DIR__"silk8",
    ]) );
    set( "outdoors","silk");
    setup();
}


