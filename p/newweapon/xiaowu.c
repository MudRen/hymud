// xiaoyuan.c

inherit ROOM;

#define GANJIANG        "/adm/npc/ganjiang"
#define MOYE            "/adm/npc/moye"

void create()
{
        object ob;

	set("short", "������");
	set("long", @LONG
��һ�߽�������ӣ��͸о�����һ����������������ݽ���һ��¯�ӣ�
����ȼ�����ܻ�⣬�ƺ������Ľ���������ǰ�ζ����ݽǶѷ���һ�ѶѺ�
�����Ķ�������֪����ʲô��
LONG );


        set("objects", ([
                __DIR__"npc/ganjiang" : 1,
               __DIR__"npc/moye" : 1,
        ]));

        set("no_fight", 1);
        set("no_sleep_room", 1);

	set("exits", ([
                "out" : __DIR__"road5",
	]));
	setup();
}
