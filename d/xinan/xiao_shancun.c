#include <room.h>
inherit ROOM;


void create()
{
        set("short", "Сɽ��");
        set("long", @LONG
ɽ��ش�Ⱥɽ��Ĺȵ�ƽԭ����Բ������ƽ���ϵ�������ˮ����Ŵ���
������������ӱ���һƬ���ᣬ����������Ӵ����С¥���ݵ��þ���֧�ڰ�
�գ��Է����߶����ȥ��
    ���ߵ����ӷǳ�ï�ܡ�����Զɽ���ߣ��ƺ���һ��·ͨ��ɽ��֮�С�
LONG
        );
        set("exits", ([
                "west"     : __DIR__"milin3",
                "northup"      : __DIR__"shandao0",
        ]));
        set("outdoors","xinan");
        setup();
}
