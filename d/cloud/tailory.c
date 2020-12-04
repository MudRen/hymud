
// tailory.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2000,3880,0}));
	set("short", "��ﲼׯ");
	set("long",
"��������վ����ﲼׯ�������Ϊ�������·�������˫������ ��һ��ׯ ��������������\n"
"����ʮ����¡�������ſڵ�ǽ���Ϲ���(sign)��\n"
);
        set("exits", ([
                "north"          : __DIR__"nwroad2" ]) );

        set("objects", ([
                __DIR__"npc/tailor" : 1,
 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д���������·���\n��������ʷ￨(apply card).\n";
}

