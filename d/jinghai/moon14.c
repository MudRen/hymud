// Room: /d/jinghai/moon14.c

inherit ROOM;

void create()
{
	set("short", "������Ϣ��");
	set("long", @LONG
��������ˮկ�ĵ�������Ϣ�ĵط�����϶��Ա�Ӫ���Ļ���
Ҫ�õĶ��ˣ���Ȼ��һ���ס��һ������������ÿ���˶���
�Եõ�һ���̶���λ��ÿ�Ŵ��߶���һ��СС�ĳ�������ʢ��
�������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"moon11",
]));

	
        set("sleep_room", 1);
        set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
