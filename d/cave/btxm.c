 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "��������");
        set("long", @LONG
����ĵ��Ʊ������ǵͶ��ˣ�·���ϵ��ѷ��ж���һ����
Сˮ���ڼ������������š�ˮ�����������Ƶ���̦��ʹ����·
��ʪ���ޱȡ�һ��С�ľͻỬһ�ӡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sbj",
  "south" : __DIR__"btxl",
]));
        set("objects", ([
        __DIR__"obj/lichen": 1,
                        ]) );
        set("indoors", "cave");
        set("coor/x",-60);
        set("coor/y",-10);
        set("coor/z",-20);
        setup(); 
}  
