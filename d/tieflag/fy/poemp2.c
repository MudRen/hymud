 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", HIG"̽�����¥"NOR);
        set("long", 
"���������ٷ��ƥ�������ݡ��غ��ζϺδ������������á���δ������
������������˭�ϣ�������ɽ�����ϲ��ޣ�\n"                                   
        );
        set("exits", ([ 
        "down" : __DIR__"poemp",
        "up" : __DIR__"poemp3",
        "west" : __DIR__"poemp2a",
]));
        set("objects", ([
        __DIR__"npc/mother1" : 1,
        ]) );
        set("no_death_penalty",1);
        set("NONPC", 1);
        set("coor/x",-10);
        set("coor/y",1);
        set("coor/z",10);
        setup();
} 
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(dir == "west"){
                if (obj->query("combat_exp")<500000)
                        return notify_fail("���ֻ�д�����ݵĿ��ˡ�\n");
        }       
        return 1;
}   
