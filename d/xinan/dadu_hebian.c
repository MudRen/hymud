#include <room.h>
inherit ROOM;


void create()
{
        set("short", "��ɺӱ�");
        set("long", @LONG
�����Ѿ��Ǵ���ƽԭ�ı�Ե��������ֱ�������ĸߴ�ɽ����ɽ���϶�������
��ѩ�������˼�������������һ���޼ʵĳ�ɽ���룬���ֱ��գ�ɽ�߹��ģ����
�Ӵ�����ѩɽ֮��������������ẽ����������ȥ������Խ�����ߺ��еĴ�ɭ
�־��Ǵ�������ˡ�
LONG
        );
        set("exits", ([
                "southwest"     : __DIR__"shanlu11",
                "northeast"     : __DIR__"leshan",
        ]));
        setup();
        set("outdoors","xinan");
}

