
// tearoom.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
        
	set("coor",({2050,3950,0}));
	set("short", "������");
        set("long",
"��������������ߵ�һ�Ҳ跻��,������ʷ�Ѳ��°���,����򱾾�����ʢ����Ҷ����������\n"
",��˲�¥���������ĺá��߸�����Ľ���(sign)�������һ��ѣ�εĸо�,�Һ��������\n"
"ʹ����������ࡣվ���ſ�,����Կ���������һ�Ȳ�̫���۵�ľ����(door)�������¥��\n"
"ͨ��¥�ϵ�����,��ʱ���������洫��˿��֮��������Ц��...\n"
);

        set("item_desc", ([
                "sign": (: look_sign :),
                "door": (: look_door, "north" :),
        ]) );

        set("exits", ([
                "south"          : __DIR__"nwroad3",
                "west"           : __DIR__"nwroad1",
                "north"          : __DIR__"tea_corridor",
                "up"             : __DIR__"tearoom2" ]) );

        set("objects", ([
                __DIR__"npc/tea_waiter" : 1,

 ]) );


       set("valid_startroom", 1);

        setup();

}

string look_sign()
{
        return "����д��: ������ �� �Ա�һ��С��: �����ױʡ� \n";
}


