/* silk11.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980426
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980426
 */

inherit ROOM;

void create()
{
    set( "short","丝绸之路" );
    set( "long",@LONG
这里一条连接中原和西域，乃至欧洲的交通要道。来于亚欧大陆之间的商队
不是从这里经过，他们把中国美丽的丝绸以及纸张带到了欧洲，同时带去的还有
中国人民的友谊；而来自西方的传教士门把佛教、伊斯兰教带到了中国。你在这
里不是可以看到满载货物的驼队经过。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : __DIR__"dunhuang",
        "southeast" : __DIR__"silk10",
    ]) );
    set( "outdoors","silk");
    setup();
}


