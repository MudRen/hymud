// jiulou2.c

inherit ROOM;
inherit F_DEALER;
#include <ansi.h>;

void create()
{
	set("short", "��¥��¥");
        set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ�������
�Ժȱ������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������
ֻ�����Ļ�̹��������ȫ�������Ļ�ɳ����֮���ϵĻ���������Ƹ�
�ǺƵ�����¥��ǽ�Ϲ���һ������(paizi)��
LONG
        );
        set("item_desc", ([
                "paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
        ]));
    	set("objects", ([
            "/d/quanzhen/npc/zhanggui" : 1,
	    __DIR__"npc/hongrenxiong" : 1,
	    __DIR__"npc/linghu" : 1,
    	]));

        set("exits", ([
                "down" : "/d/quanzhen/jiulou1",
        ]));

        setup();
        replace_program(ROOM);
}