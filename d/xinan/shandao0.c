#include <room.h>
inherit ROOM;


void create()
{
        set("short", "ɽ��");
        set("long", @LONG
��������ڶ�ɽ��ȫ��ʮ�ɵ��оųɶ���ɽ�֣���������̤����С�����߶�
�ǻ���һ��Ĳ������������ͬ���ߴ�Ĺ��١����ϵ������ģ���ʪ�ĺܣ�̤
��ȥ��������ˮ����һȺȺ�ó�������߷��裬�����ˡ��������������ķ���
    �ϱ߳�ɽ��һ��ƽ�أ�����С�����ֶ�����
LONG
        );
        set("exits", ([
                "southdown"     : __DIR__"xiao_shancun",
                "northup"      : __DIR__"baicao_ling1",
        ]));
        set("outdoors","xinan");
        setup();
}
