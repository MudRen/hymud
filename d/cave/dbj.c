 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
һ������ʯ���������������һ�˶�֣��ͺ�����һ��
���������ӡ������ϸ���Ļ��������Է���һ����ϸϸ����
ˮ�������������£�û�����Ͳ����ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"dbm",
                "south" : __DIR__"btdm",
        ]));
    set("objects", ([
        __DIR__"npc/tangye": 1,
    ]) );
        set("indoors", "cave");
        set("coor/x",-30);
        set("coor/y",0);
        set("coor/z",-20);
        setup(); 
}  
int valid_leave(object obj, string dir){
        object ma;
        if(dir == "west"){
                if(!obj->query("vendetta/authority") && present("tang ye", this_object())){
                        ma = present("tang ye", this_object());
                        return notify_fail(ma->name()+"�Ӷ�����ĵ�������ס�����·��\n");
                }
        }       
        return 1;
} 
