 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "Сɽ������");
        set("long", @LONG
�����Ƿ��Ƴǣ�������ʱ����ԼԼ�ػ����Կ������Ƴǵĺ�ɫ������
��������һ����ͺͺ��Сɽ�£������ѱ�·��������̤����һ������
·��·�����߻�����һЩ���˸ߵĽ���é�ݡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "eastup" : __DIR__"sroad2",
//  "west" : "/d/sharen/zmen",
  "north" : __DIR__"road0",
  "south" : "/d/xinjiang/zhenlong",
]));
        set("objects", ([
        __DIR__"obj/grass" : 1,
                        ]) );
        set("outdoors", "fengyun");
        set("coor/x",10);
        set("coor/y",-430);
        set("coor/z",10);
        set("coor/x",10);
        set("coor/y",-430);
        set("coor/z",10);
        setup();
} 
void reset()
{
object con, item, *inv;
::reset();
if( con = present("grass",this_object()))
if( inv = all_inventory(con))
if( !sizeof(inv))
        {
        item = new(__DIR__"obj/9whip");
        item->move(con);
        item = new(__DIR__"obj/9whip");
        item->move(con);
        item = new(__DIR__"obj/9whip");
        item->move(con);
        item = new(__DIR__"npc/obj/killersword1");
        item->move(con);
        item = new(__DIR__"npc/obj/killersword1");
        item->move(con);
        item = new(__DIR__"npc/obj/killersword1");
        item->move(con);

   }       
}     
