
// Room: /d/snow/schoolhall.c

inherit ROOM;

void create()
{
	set("coor",({-15,-50,0}));
	set("short", "������ݴ���");
	set("long",
"�����Ǵ�����ݵ�����������̫ʦ��һ���ſ�������ſڣ������������λ��ʦ���������\n"
"�������λ����һ����ݲ�ͬ���ǣ�ǽ�Ͼ�Ȼ�������������Ϊ���׵��黭����ʾ�������\n"
"�˲��Ǵ��ֲ�ʶ�Ĵֺ�����������˫ȫ�ĸ��ˡ�\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"school2",
  "west" : __DIR__"inneryard",
]));
	set("valid_startroom", 1);
        set_temp("light",1);
	setup();
}

