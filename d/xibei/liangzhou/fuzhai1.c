//fuzhai1.c ����
//Hydra

inherit ROOM;

void create()
{
    set("short","����");
    set("long", @LONG
һ��שʯ�̳ɵ�С�������ſ�һֱͨ�������������������Ÿ��ֻ��ݣ���Щ
������������˴ӱ������ֵģ���Ȼ���ݷ�ɳ�ܴ󣬵������ھ��Ļ�������
�Ĳݶ����Ĳ��������Ǵ�����
LONG
    );
    set("outdoors","liangzhou");
    set("exits", ([ 
        "south"         :       __DIR__"door",
        "north"         :       __DIR__"fuzhai_dating",
    ]) );

        setup();
}

