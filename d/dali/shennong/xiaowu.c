// С���� /d/menpai/shennong/xiaowu.c

inherit ROOM;



void create()
{   
    set("short",    "С����");
    set("long", @LONG
��վ��С���ڣ����촰�����̫����͵Ĺ�â����С���յĺ������������
��ľ���Ӻͼ�����ʣ�������ż�ֻ�����һЩʳ�������ר��������·��Ъ
��׼���ġ�ǽ����һ��é���̳ɵĴ���ʹ��һ��������һ�ֻص��ҵĸо���
LONG
    );
    set("exits",    ([
            "out"   :   __DIR__"wuqian"   
    ]) );
    set("sleep_room", 1);
    set("objects",  ([
        "/d/city/npc/obj/baozi" : 5,
		"/d/city/npc/obj/jitui" : 2,
		"/d/city/npc/obj/jiudai" : 2,

    ]) );
    setup();
}

