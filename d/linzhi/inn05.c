// Room: /d/linzhi/inn05.c

inherit ROOM;

void create()
{
	set("short", "�͵�ͷ�");
	set("long", @LONG
�����ǿ͵���¥�Ŀͷ���������·�Ŀ���������Ϣ��������
���ţ����������һ���յĴ�λ�����¡��ú�˯(sleep)һ���ɣ�
ǰ�����;�������ء�
LONG
	);
	set("sleep_room", "1");
	set("no_fight", "1");
        set("hotel",1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"inn03",

]));
  set("objects", ([ /* sizeof() == 4 */
"/clone/npc/man" : 3,  	
]));
	setup();
	replace_program(ROOM);
}
