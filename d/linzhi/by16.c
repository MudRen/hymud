// Room: /d/linzhi/by16.c

inherit ROOM;

void create()
{
	set("short", "��·��");
	set("long", @LONG
������С��Ĳ�·�ڣ�����������˺ܶ࣬�㿴�Ż�������
�ķ��Σ�Խ��Խ����������һ������ȥ���������Ĺ��ﲻС��
������һ�£����������˵�һЦ��Ȼ���߿��ˡ��㲻�����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"by15",
  "west" : __DIR__"by17",
  "east" : __DIR__"by04",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/man" : 1,  	
"/clone/npc/man" : 1, 	
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
