// Room: /d/linzhi/lin60.c
// Room: /d/linzhi/lin61.c

inherit ROOM;

void create()
{
	set("short", "��ԭ�ް�����");
	set("long", @LONG
���������֥�����ĹŰ����ˣ����г����˸ߴ�ĹŰ�����
�Ű����ǵ��ز���������Ŀ�е�ʥ�أ���˵���̿�ɽ��ʦ������
�������������ǹŰ��������������е���������ѣ���Щ�����
���ϵ����ϻ������ŷ������ɵ������г������⣬���߱�ע��
�ŷ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin59",
  "south" : __DIR__"lin61",	
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}


