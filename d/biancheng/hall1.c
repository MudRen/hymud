inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "ǰ��");
        set("long", @LONG
ǰ�����Ȱ�ľ���ľ�ţ��ű������������´󺺡��ź����Ǹ�����İ�ľ���
���������ɶ�ߣ������û��ͼ����Ҳû���֣���ȴϴ�øɸɾ�����һ����Ⱦ����
���������õ�ǰ���������ܹ���ϽӴ�һ�����͵ĵط���
LONG
        );
        set("exits", ([ 
        "north" : __DIR__"hall2",
        "south": __DIR__"yard2",
        "east" : __DIR__"pianting",
        ]));
        set("objects", ([
                __DIR__"npc/gongsun": 1,
        ]) );
        set("coor/x",-1110);
        set("coor/y",290);
        set("coor/z",0);
        setup(); 
}  
int valid_leave(object me, string arg) {
        object ob;
        
        ob=present("gongsun duan",this_object());
        
        if (!ob || me->query("wanma/ӭ��")) 
                return 1;
        
        if (userp(me))
        if (arg== "north" || arg=="east") {
                message_vision("$N˵����û�������������룬˭����׼���ڡ���\n",ob);
                return notify_fail("");
        }
        
        return 1;
}
