 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "���Ͻ�");
        set("long", @LONG
�����ܵͣ�����ʯ�൱�Ķ࣬�γ�һƬʯ�֡�ʯ���л��м�
����Ģ����Ģ�Ա߾�Ȼ�м���ʯ�ʺ�һ��ʯ̨�����Թ�����Ϣ��
����һֱ�ڵ�ˮ��Ū�������ƺ����������ꡣ
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"ntdm",
                "west" : __DIR__"tdnd",
        ]));
    set("objects", ([
        __DIR__"npc/dinggan": 1,
    ]) );
        set("indoors", "cave");
        set("coor/x",-30);
        set("coor/y",-24);
        set("coor/z",-20);
        setup();
} 
int valid_leave(object obj, string dir){
        object ma;
        if(dir == "west"){
                if(obj->query_temp("marks/underground_gao")){
                        return 1;
                }
                if(!obj->query("vendetta/authority") && present("ding gan", this_object())){
                        ma = present("ding gan", this_object());
                        return notify_fail("��û����"+ma->name()+"�����ƶ���Ȼ����ȴվ������ǰ��ס�����·��\n");
                }
        }       
        return 1;
} 
