// /d/heifeng/weaponrm.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǵ�ű����ĵط���һЩ���õı�������ط���
����ļܹ��ϡ�����ǿ���ո�ȡ��Щ������ɽȥ�ˣ�����
���ѵ�ǹɢ���ڵ��ϡ�
LONG
        );
        set("exits", ([ 
            "east"   : __DIR__"corr02",
]));
        set("objects",([
        __DIR__"npc/obj/spear" : 2,
        __DIR__"npc/obj/blade" : 2,
]));
        setup();
        replace_program(ROOM);
}

