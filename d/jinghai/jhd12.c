// Room: /d/jinghai/jhd12.c

inherit ROOM;

void create()
{
	set("short", "԰��С·");
	set("long", @LONG
�˱ǵ��������㾫��һˬ������Ŀ�Ĺˣ����۴����ǲ�֪��
�Ĵش��ʻ����컨��֦����֮�䣬����С·���򻨴��������
�Ǿ�������ǰԺ�Ļ�԰������Ϊ���������߱�����飬�������
԰ɷ�Ƿ���һ�����ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"jhd10",
  "west" : __DIR__"jhd15",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
