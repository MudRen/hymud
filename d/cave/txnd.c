 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "�����ϵ�");
        set("long", @LONG
�ϱ߾��Ƕ��ڣ�ʯ�ڿ��ݲ�ƽ���൱�Ķ��ͣ�������������
�ǡ��������м�ֻ��Ѻ����򣬰������յ�ͨ����������Χ�ƺ�
�и���ׯ����ÿ��Ʈ����ȴ����������Ż��Ѫ��֮������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xnj",
  "east" : __DIR__"xnm",
]));
        set("objects", ([
        __DIR__"npc/devilwaiter": 1,
        __DIR__"obj/slayedman": 2,
                        ]) );
        set("indoors", "cave");
        set("coor/x",-38);
        set("coor/y",-24);
        set("coor/z",-20); 
        set("refresh_all_items", 1);
        setup(); 
}  
