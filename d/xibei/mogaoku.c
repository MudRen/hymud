/* mogaoku.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

inherit ROOM;

void create()
{
    set( "short","莫高窟" );
    set( "long",@LONG
这里是位于敦煌东南的莫高窟，这里是飞天的宫阙，菩萨的殿堂。在一座座
洞窟里，那些精美的塑像，面容慈祥的大佛、菩萨，仿佛对人微笑相迎；面目狰
狞的金刚、力士，又令人望而生畏。环顾四壁、窟顶，到处画的是佛像，以及飞
天、仙女，还有变幻出奇的怪兽。每一幅画，都展示给人们一个生动的故事。
LONG
    );

    set( "exits",([ /* sizeof() ==1 */
        "northwest" : __DIR__"dunhuang",
    ]) );
    set( "outdoors","silk");
    setup();
}


