#include <room.h>
inherit ROOM;


void create()
{
        set("short", "�������");
        set("long", @LONG
��������Ƕ��Ⱥɽ֮�е�һ�����顣���ı����ǿ���ļ���ɽ��������ɽ��
��ѩ�ĵ��ɽ�������ʹ�����Ⱥɽ����֮�У���ˮտ����ˮ��ƽ���羵��ӳ����
���ϵĶ����ƣ�ˮ��ɽ�������Ÿ��ָ�������Ļ��ݣ�������һֻֻҰѼ�ʹ�
�������е��ε���
    �������Ǳ�����ԣ����ٶ������Ǵ�������ڵĹ�����������ɵ��ϵ��
ɽ��
LONG
        );
        set("exits", ([
                "south"     : __DIR__"taihe_cun",
                "east"      : __DIR__"nongtian1",
	                "northeast" : "/d/dali/road4",
                "west" : "/d/dali/xiaguan",
        ]));
        set("outdoors","xinan");
	set("objects",([
		__DIR__"npc/xiang" : 1,
		__DIR__"npc/yan"   : 1,
		]) );
        setup();
}
