// Room: /d/linzhi/yg04.c

inherit ROOM;

void create()
{
	set("short", "�׹��賡");
	set("long", @LONG
��������׹��賡����������ïʢ�Ĳ���������Ĳ���ϵ��
Ȼ��ѩ��ˮ�ཽ��Ʒ��ʮ�ָߡ�һЩ�ع����ڲ���Ⱥ��æµ�ţ�
���������ڲ�ժ��Ҷ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yg03",
//  "east" : __DIR__"yg03",
  "west" : __DIR__"yg05",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 1900);
	setup();
	replace_program(ROOM);
}
