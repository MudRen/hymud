
// marry_room.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("coor",({2000,3820,0}));
	set("short", "����ׯ");
        set("long",
"��������վ�ں���ׯ�������ר�����˵޽��Լ�ͽ����Լ�ĵط����������еķ򸾶���\n"
"������ϲ����Ե�ģ�������������Ҳ�����Ľ�������Ŀ����ſڵĵط���һ����ľ��ɵ���\n"
"��(sign)��\n"
);
        set("exits", ([
                "south"          : __DIR__"wroad1", 
         ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("objects", ([
//                __DIR__"npc/mei_po" : 1,
        ]) );
 
        setup();

}

string look_sign(object me)
{
        return "�޽������Լ��\n";
}

