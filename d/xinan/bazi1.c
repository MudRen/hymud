#include <room.h>
inherit ROOM;


void create()
{
        set("short", "����");
        set("long", @LONG
������Ⱥɽ������һ�����أ������˳���Ϊ�����ӡ�������ɽ��ƽ�أ��ȵ�
����˼���󲿷��ϰ��ն��۾���һ����ɢ�ġ����ӡ��ϡ��������ط��֣�ˮԴ
��֣�����ƽ̹���˸��֡���������һ������ɽ��ɽ���ֲݴ�����������һ��С
���ӡ������������������ɽ���İ�����ѩ��
LONG
        );
        set("exits", ([
                "southup"     : __DIR__"shangu1",
                "northeast"  : __DIR__"taihe_cun",
        ]));
        set("outdoors","xinan");
	set("objects", ([
		__DIR__"npc/chashang" : 2,
		]) );
        setup();
}
