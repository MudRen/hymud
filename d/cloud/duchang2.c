
// duchang2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "�ĳ�");
	set("long", @LONG
�����Ƕĳ��Ķ�¥���ܶ�����Χ�ż������Ӹ������£�ɷ�����֡�
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "north"          : __DIR__"eroad1", 
		"up"		 : __DIR__"duchang2",
	 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д������(bet)��Ӯһ������������ʮ�ġ�\n";
}

