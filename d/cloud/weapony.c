
// weapony.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2120,3900,0}));
	set("short", "������");
        set("long",
"��������վ�ڱ������￿���ſڵĵط���һ����ľ��ɵ�����(sign)��\n"
);
        set("exits", ([
               	"west"          : __DIR__"nroad1",
			])  );

        set("objects", ([
                __DIR__"npc/weaponor" : 1,
 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д����ר����ʽ����\n";
}

