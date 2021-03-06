// 楚州东市 /d/city/chuzhou/dongshi.c
// by lala, 1997-12-04

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", GRN"东市"NOR);
    set("long", @LONG
东市的热闹程度不但不能同西市和北市相比，就是比起南市来也略逊一筹，
主要是因为本来东城就不是交通要路，而且离州府衙门太近——就在东面的炎兴
街上——大家都不敢太过放纵，那些贩卖违禁商品的商人就更不敢到这里来了。
北面是一家客店，名叫“燕归客店”，不少旅客都喜欢住在这里。南面是家卖针
头线脑的杂货铺。西面是通向南市的胯下桥。
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "north"     : __DIR__"kedian",
        "west"      : __DIR__"kuaxiaqiao", 
        "east"      : __DIR__"yanxing_jie",
        "south"     : __DIR__"zahuopu",
        "northwest" : __DIR__"jiulou",
        ]));
    set("objects", ([
        __DIR__"npc/xunbu"  :   1,
        __DIR__"npc/east_seller0"  :  1,
    ]));        
    set( "outdoors", "chuzhou" );       
    setup();
}
