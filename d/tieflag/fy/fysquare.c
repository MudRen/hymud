#include <room.h>
inherit ROOM; 
void midnight_event();
void sunrise_event(); 
void create()
{       object con,item;
        set("short", "��������");
        set("long", @LONG
������꣬���Ƴǵ����Ĺ㳡�����������¡���ֺ���·�����ｻ�ᣬ������
�ֵ�Χ��һ���޴�Ĺ㳡���㳡�����ˮ���Ѿ��ɺԣ�������̵ĳ�ˮ��ββ����
�������ڣ����µ��Ǹ����ɷ�Բ������׵Ĵ󶴡�ˮ���Ե����Ħ��ʯ��������
�²�ɣ����Ȼ�������ӵ�������ʯ���Ͼ�������������צ��ֱ�������ȥ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nwind1",
  "south" : __DIR__"swind1",
  "east" : __DIR__"ecloud1",
  "west" : __DIR__"wcloud1",
//  "down" : AREA_CAVE"tt", //temp. link for coordinate expandsion
]));
        set("outdoors", "fengyun"); 
        set("objects", ([
                __DIR__"npc/center_soldier" : 1,
                __DIR__"npc/half_god" : 1,
                __DIR__"obj/gui1" : 1,
                "/d/cave/obj/slayedman" : 1,
       ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        set("no_dazuo",1);
        set("no_study",1);
        setup();
        con = present("mugui",this_object());
        item = present("slayed corpse",this_object());
        item->set_amount(1+random(1));
        item->move(con);

        // To "load" the board, don't ever "clone" a bulletin board.
//         call_other( "/obj/board/fysquare_b", "???" );
//      NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
}
