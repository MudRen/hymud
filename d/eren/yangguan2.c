 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��Į");
        set("long", @LONG
ããһƬѩ�ף�ʲôҲû�У���һ������Ҳ�Ҳ�����û�бߣ�û�мʡ���߽�
��Ʈ�������̼�����������ȴ�ڼ���ɻ���Σ��ŷ��֣����Ǹոջ�ѩ��ɽ����
ż����ƽ���ϻ��м�����Ӱ�����ǰ�������á�
LONG
        );
        set("exits", ([ 
        "northwest" : __DIR__"kunlun1",
        "southeast" : __DIR__"yangguan1",
        ]));
        set("objects", ([
                        __DIR__"npc/traveler" : 2,
        ]) );
        set("outdoors", "eren");
        set("coor/x",-980);
        set("coor/y",130);
        set("coor/z",0);
        setup();
} 
int valid_leave(object obj, string dir){
        if (userp(obj) && random(3)) {
                obj->move(this_object());
                return notify_fail("");
                }
        return 1;
}   
