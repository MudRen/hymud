
// Room: /u/cloud/dukou.c

inherit ROOM;

void create()
{
        set("coor",({2100,3700,0}));
	set("short", "�����ɿ�");
        set("long",
"���Ǹ���˵����ȴ��������Ķɿڡ�����ȥ��ͨ������������ʯ������������޷�������\n"
"����ˮ�ˡ�������ȥ����Լ�ɼ��԰�����ɽ��������ɽ����������������\n"
);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sroad1",

]));



        set("outdoors", "cloud");

        setup();
}
