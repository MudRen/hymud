// Room: /open/stst/sazai/da.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short","Ұ��կկ����");
        set("long", @LONG
        ������Ұ��կ��կ������Ϣ�ң���կ������˫ȫ����˵�ǵ���ŷ��
��������֣������ĺ��������ƻ���ˣ�����ٸ��ͽ����ú�����Χ������
��ɱ����Χ������������˱�����һ���կ�е��Ӷ����õ��������š�����
���Ǵ����ˡ�

LONG

        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dating",
]));
	set("objects",([
		__DIR__"npc/ouyangye":1,
]));

        setup();
        replace_program(ROOM);
}

