
// Room: /u/cloud/eroad2.c

inherit ROOM;

void create()
{
        set("coor",({2200,3800,0}));
	set("short", "�����ֵ�");
        set("long",
"����������򶫣�ͨ���賡��·���ϱ���һ�������Ĵ��ھ�--��Զ�ھ֡�����������żҵ�\n"
"լԺ��\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"eroad1",
  "north" : __DIR__"park",
  "south" : __DIR__"biaoju",
  "northeast" : __DIR__"eroad3",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

