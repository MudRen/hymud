 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�����콾��");
        set("long", @LONG
����һ�����϶���ʥ�Ĵ���ʯ�ţ���Լ���ڰ���ǰ�����ϰ߰ߵ�㣬�绯������
��˵������ʴ���ٷ��ν����¶�ŮӢ�۵ĵط������Ǳ��ν���Ӣ�۶���Ϊ����֮
�����ǵ��¼�ǧ����Ϊ���˴��̡�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"ecloud5",
  "north" : __DIR__"jinshuihe",
]));
        set("outdoors", "fengyun");
        set("coor/x",50);
        set("coor/y",10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
