// Room: /d/linzhi/by08.c

inherit ROOM;

void create()
{
	set("short", "��С·");
	set("long", @LONG
�������򱱵�һ��С·��·��ӿ����ݣ���̫���ߡ���һ��
С�ģ��ŲȽ���һ��ˮ�ݣ��㼱æ�ѽ����˻�����С��������һ
�䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by07",
  "north" : __DIR__"by09",
]));
        set("outdoors", "linzhi");
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/sheepgirl" : 2,  	
"/clone/npc/man" : 3, 	
]));
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
