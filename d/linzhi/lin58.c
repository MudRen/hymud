// Room: /d/linzhi/lin58.c
// Room: /d/linzhi/lin56.c

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
  "north" : __DIR__"lin57",
  "south" : __DIR__"lin59",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}

